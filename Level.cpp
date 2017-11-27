#include <SFML/Graphics.hpp>
#include "Level_1\Level1.h"
#include "Global.h"
#include "GameEngine.h"
#include "Explosion.h"
#include "ClearScreen.h"
#include <cassert>

#include <gl/gl.h>

#include <fstream>
#include <sstream>
#include <iomanip>

#define SIMPLE_DISPLAY() { \
    if (InGame) { \
        Display(); \
        MainWindow.display(); \
    } \
}

#define BEGIN_DIALOGUE_DISPLAY() { \
    if (InGame) { \
        Display(); \
        PostDisplayer(BeginDialogueList[Player->SelectedShotType.ShotTypeID]); \
        MainWindow.display(); \
    } \
}

#define BOSS_DISPLAY() { \
    if (InGame) { \
        Display(); \
        glEnable(GL_SCISSOR_TEST); \
        for (unsigned int i=0; i<LevelBoss->Bullets.size(); i++) \
            MainWindow.draw(LevelBoss->Bullets.at(i)->Sprite); \
        MainWindow.draw(Bar); \
        MainWindow.draw(Lives); \
        /*MainWindow.draw(SpellName);*/ \
        MainWindow.draw(BonusScore); \
        MainWindow.draw(GrazeMultiplier); \
        glDisable(GL_SCISSOR_TEST); \
        MainWindow.display(); \
    } \
}

#define END_DIALOGUE_DISPLAY() { \
    if (InGame) { \
        Display(); \
        PostDisplayer(EndDialogueList[Player->SelectedShotType.ShotTypeID]); \
        MainWindow.display(); \
    } \
}

/* ---------------------
 * Name: SKIPLEVEL
 * Description: Setting to TRUE allows skipping the level, fighting directly the boss
 * Default: FALSE
 * --------------------- */
#define SKIPLEVEL false

///LEVEL
int GameEngine::LevelStart() {
    //Game Loop
    InGame=true;
    bool BossAlive=true;
    Background.SetLevelSection();
    #if (!SKIPLEVEL)
    LevelBoss->Position=sf::Vector2<float>(1000,1000);
    PlayMusic();

    SetMusicLoop(false);
    while (InGame==true && PastTime<=LevelTime) {
        int handleevents_returncode=HandleEvents();
        if (handleevents_returncode==0)
            InGame=false;
        else if (handleevents_returncode==-1)
            return -1;
        SIMPLE_DISPLAY();
        CHECK_EXIT();
    }
    #endif
    //Delete enemies here - save time in boss battle!
    for (unsigned i=0; i<Enemies.size(); i++) {
        for (unsigned j=0; j<Enemies.at(i)->ShootTable.size(); j++)
            delete Enemies.at(i)->ShootTable.at(j);
        delete Enemies.at(i);
    }
    Enemies.clear();
    if (Player->BombTime>0.0f)
        Player->SelectedShotType.Bomb->ActivationTime=-(PastTime-Player->SelectedShotType.Bomb->ActivationTime);
    PastTime=0; //Resets clock
    ZPressed=false;

    //Boss enters
    /*float background_y=LevelBackgroundSprite.getPosition().y;
    while (background_y<-85.f)
        background_y+=110.f;
    LevelBossBackgroundSprite.setPosition(25,background_y-550);*/
    /*float background_y=Background.T;
    LevelBossBackgroundSprite.setPosition(25,25+background_y-550);*/
    Background.SetBossSection();
    while (InGame==true && PastTime<=3) {
        switch (PreHandler(BeginDialogueList[Player->SelectedShotType.ShotTypeID])) {
            case GOTO_MAINMENU: InGame=false; break;
            case GOTO_EXIT: return -1; break;
            default: break;
        }
        HandleEvents();
        CHECK_EXIT();
        LevelBoss->PrevPosition=LevelBoss->Position;
        LevelBoss->Position.x=250;
        LevelBoss->Position.y=PastTime*75;
        if (LevelBoss->Position.y>150)
            LevelBoss->Position.y=150;
        LevelBoss->PrevPosition=LevelBoss->Position;
        for (short i=0; i<4; ++i)
            LevelBoss->Sprite[i].setPosition(LevelBoss->Position);
        BEGIN_DIALOGUE_DISPLAY();
    }

    //Talking
    while (InGame==true && BeginDialogueList[Player->SelectedShotType.ShotTypeID].size() > 0) {
        switch (PreHandler(BeginDialogueList[Player->SelectedShotType.ShotTypeID])) {
            case GOTO_MAINMENU: InGame=false; break;
            case GOTO_EXIT: return -1; break;
            default: break;
        }
        HandleEvents();
        CHECK_EXIT();
        BEGIN_DIALOGUE_DISPLAY();
    }
    //Disappearing graphics
    while (InGame==true && PastTime<=3) {
        switch (PreHandler(BeginDialogueList[Player->SelectedShotType.ShotTypeID])) {
            case GOTO_MAINMENU: InGame=false; break;
            case GOTO_EXIT: return -1; break;
            default: break;
        }
        HandleEvents();
        CHECK_EXIT();
        MsgBoxSprite.setColor(sf::Color(0,0,0,MsgBoxSprite.getColor().a-85*FrameTime));
        PlayerPortraitSprite.setColor(sf::Color(0,0,0,PlayerPortraitSprite.getColor().a-85*FrameTime));
        BossPortraitSprite.setColor(sf::Color(0,0,0,BossPortraitSprite.getColor().a-85*FrameTime));
        BEGIN_DIALOGUE_DISPLAY();
    }
    //Boss battle
    sf::RectangleShape Bar;
        Bar.setPosition(35,35);
        Bar.setFillColor(sf::Color(255,100,200));
        Bar.setOutlineThickness(3);
        Bar.setOutlineColor(sf::Color(0,0,0,255));
    sf::Text Lives;
    sf::Text SpellName;
    sf::Text BonusScore;
    sf::Text GrazeMultiplier;

    long PatternGraze=0;
    unsigned PatternDealtDamage=0;

    Play(BossMusicID);
    SetMusicLoop(true);
    while (InGame==true && BossAlive==true) {
        Bar.setSize(sf::Vector2f(430*LevelBoss->LifeBars.back()->Health/LevelBoss->LifeBars.back()->MaxHealth, 10));
        //Handle events
        short xji=HandleEvents();
        if (xji>=0)
            InGame=xji;
        else if (xji==-1) {
            CrossPressed=true;
        }
        else if (xji==-2) {
            InGame=false;
            return false;
        }
        CHECK_EXIT();
        //Move background
        LevelBossBackgroundSprite.move(0,ceil(160.f*Engine.FrameTime));
        if (LevelBossBackgroundSprite.getPosition().y>25)
            LevelBossBackgroundSprite.setPosition(LevelBossBackgroundSprite.getPosition().x, 25);
        //If boss isn't dead
        if (LevelBoss->LifeBars.size()>0) {
            int DealtDamagePercentage=static_cast<int>(ceilf(PatternDealtDamage/LevelBoss->LifeBars.back()->MaxHealth*100));
            if (LevelBoss->LifeBars.back()->Health>0) {
                LifeBar *barptr=LevelBoss->LifeBars.back();

                //Boss Movements and Shots
                LevelBoss->PrevPosition=LevelBoss->Position;
                barptr->Move(LevelBoss);
                for (short i=0; i<4; ++i)
                    LevelBoss->Sprite[i].setPosition(LevelBoss->Position);
                for (unsigned i=0; i<barptr->ShootTable.size(); i++) { //Has boss to shot?
                    barptr->ShootTable.at(i)->first.first-=FrameTime; //How much time till next shot?
                    while (barptr->ShootTable.at(i)->first.first<=0) { //Yes, boss has to shot
                        barptr->ShootTable.at(i)->second(LevelBoss, PastTime+barptr->ShootTable.at(i)->first.first); //Boss shot
                        barptr->ShootTable.at(i)->first.first=barptr->ShootTable.at(i)->first.second+barptr->ShootTable.at(i)->first.first; //Boss has to wait first.first time before shooting again
                    }
                }

                //Check collision with boss's superbullets
                if (Player->DeathTime==0 && Player->BombTime==0 && Player->ChargeTime==0) {
                    for (unsigned int i=0; i<LevelBoss->Bullets.size(); i++) {
                        double Quad_X=pow(Player->Position.x-LevelBoss->Bullets.at(i)->Sprite.getPosition().x, 2);
                        double Quad_Y=pow(Player->Position.y-LevelBoss->Bullets.at(i)->Sprite.getPosition().y, 2);
                        double QuadDistance=Quad_X+Quad_Y;
                        double QuadHitDistance=pow(Player->SelectedShotType.HitboxRadius+LevelBoss->Bullets.at(i)->Radius,2);
                        double QuadGrazeDistance=pow(Player->SelectedShotType.HitboxRadius+LevelBoss->Bullets.at(i)->Radius+39,2);
                        if (QuadDistance<=QuadGrazeDistance) {
                            if (QuadDistance<=QuadHitDistance) {//Hit
                                #if(DEBUG)
                                    std::fstream f;
                                    f.open("Debug.txt", std::ios::out);
                                    f<<"\n" <<"Player->Position.x=" <<Player->Position.x <<"\n"
                                    <<"Player->Position.y=" <<Player->Position.y <<"\n"
                                    <<"Bullet->Position.x=" <<LevelBoss->Bullets.at(i)->Sprite.getPosition().x <<"\n"
                                    <<"Bullet->Position.y=" <<LevelBoss->Bullets.at(i)->Sprite.getPosition().y <<"\n"
                                    <<"Bullet->Radius=" <<LevelBoss->Bullets.at(i)->Radius <<"\n"
                                    <<"Bullet->Scale=" <<LevelBoss->Bullets.at(i)->Sprite.getScale().x <<"\n"
                                    <<"Bullet->Center.x=" <<LevelBoss->Bullets.at(i)->Sprite.getOrigin().x <<"\n"
                                    <<"Bullet->Center.y=" <<LevelBoss->Bullets.at(i)->Sprite.getOrigin().y <<"\n"
                                    <<"Quad_X=(" <<Player->Position.x <<"-" <<LevelBoss->Bullets.at(i)->Sprite.getPosition().x <<")^2=" <<Quad_X <<"\n"
                                    <<"Quad_y=(" <<Player->Position.y <<"-" <<LevelBoss->Bullets.at(i)->Sprite.getPosition().y <<")^2=" <<Quad_Y <<"\n"
                                    <<"Distance=sqrt(" <<Quad_X <<"+" <<Quad_Y <<")=" <<sqrt(QuadDistance) <<"\n"
                                    <<"HitDistance=" <<Player->SelectedShotType.HitboxRadius <<"+" <<LevelBoss->Bullets.at(i)->Radius <<"=" <<sqrt(QuadHitDistance);
                                    f.close();
                                    MainWindow.Capture().SaveToFile(DEATH_DEBUG_IMAGE);
                                #endif
                                Player->Die();
                            }
                            else if (LevelBoss->Bullets.at(i)->Grazed==false) { //Graze
                                Play(PLAYERGRAZE);
                                LevelBoss->Bullets.at(i)->Grazed=true;
                                if (Player->Charge<1000)
                                    ++Player->Charge;
                                    ++PatternGraze;
                            }
                        }
                    }
                }

                //Collision between player bullets and boss
                double Damage=1;
                for (unsigned i=0; i<PlayerBullets.size(); i++) {
                    double Quad_X=pow(LevelBoss->Position.x-PlayerBullets.at(i)->Sprite.getPosition().x, 2);
                    double Quad_Y=pow(LevelBoss->Position.y-PlayerBullets.at(i)->Sprite.getPosition().y, 2);
                    if (Quad_X+Quad_Y<=pow(PlayerBullets.at(i)->Radius+LevelBoss->Radius,2)) {
                        //Play(ENEMYHIT);
                        DeleteBullet(PlayerBullets.at(i), 1);
                        Score+=20;
                        double& health=LevelBoss->LifeBars.back()->Health;
                        if (Damage>=health) {
                            PatternDealtDamage+=health;
                            health=0;
                        }
                        else {
                            PatternDealtDamage+=Damage;
                            health-=Damage;
                        }
                    }
                }

                //Move Bullets
                for (unsigned i=0; i<LevelBoss->Bullets.size();) { //<--No i++
                    LevelBoss->Bullets.at(i)->Move(LevelBoss->Bullets.at(i));
                    //Has this bullet to be deleted?
                    if (LevelBoss->Bullets.at(i)->Deletable==true){
                        if (LevelBoss->Bullets.at(i)->CheckDeletion(LevelBoss->Bullets.at(i))==true) { //Yes
                            delete LevelBoss->Bullets.at(i);
                            LevelBoss->Bullets.erase(LevelBoss->Bullets.begin()+i);
                        }
                        else i++;
                    }
                    else { //No
                        i++; //To next element
                    }
                }

                //Use of bombs, charge mode or death cause 0 bonus score
                if (Player->BombTime>0 || Player->ChargeTime>0 || Player->DeathTime>0)
                    LevelBoss->LifeBars.back()->BonusScore=0;

                //Things to display
                LevelBoss->LifeBars.back()->Health-=(10.0*Engine.FrameTime);

                Lives.setFont(Font[PRINCEVALIANT]);
                Lives.setColor(sf::Color(0,0,0));
                Lives.setPosition(33,53);
                Lives.setCharacterSize(25);
                char *c=new char[20];
                sprintf(c,"%u",LevelBoss->LifeBars.size()-1);
                Lives.setString(c);
                delete[] c;

                /*SpellName.setFont(Font[TUFFY]);
                SpellName.setString(LevelBoss->LifeBars.back()->Name);
                SpellName.setColor(sf::Color(0,0,0,255)); //Black
                SpellName.setCharacterSize(15);
                SpellName.setOrigin(SpellName.getLocalBounds().width, 0);
                SpellName.setPosition(470,53);*/

                BonusScore.setFont(Font[TUFFY]);
                char *d=new char[20];
                //itoa(LevelBoss->LifeBars.back()->BonusScore, d, 10);
                sprintf(d,"%lu",LevelBoss->LifeBars.back()->BonusScore);
                BonusScore.setString(std::string(std::string("Score Bonus: ") + std::string(d)));
                //delete[] d;
                BonusScore.setColor(sf::Color(0,0,0,255));
                BonusScore.setCharacterSize(15);
                BonusScore.setOrigin(BonusScore.getLocalBounds().width, 0);
                BonusScore.setPosition(470, /*73*/53);

                GrazeMultiplier.setFont(Font[TUFFY]);
                sprintf(d,"%d.%d", DealtDamagePercentage/10, DealtDamagePercentage%10);
                GrazeMultiplier.setString(std::string(std::string("Graze Multiplier: x")+std::string(d)));
                GrazeMultiplier.setColor(sf::Color(0,0,0,255));
                GrazeMultiplier.setCharacterSize(15);
                GrazeMultiplier.setOrigin(GrazeMultiplier.getLocalBounds().width, 0);
                GrazeMultiplier.setPosition(470, /*93*/73);

                delete[] d;
            }
            else { //To next bar
                Play(LevelBoss->LifeBars.size()>1 ? BOSSBAREMPTY : BOSSDEATH);
                Score+=LevelBoss->LifeBars.back()->BonusScore;

                Graze+=PatternGraze*DealtDamagePercentage/10;
                PatternGraze=0;
                PatternDealtDamage=0;

                Items.GenerateFallingItems(LevelBoss);

                for (unsigned i=0; i<LevelBoss->Bullets.size(); i++) {
                    VisualEffects.AddEffect(new EffectExplosion(LevelBoss->Bullets.at(i)->Sprite.getPosition().x,
                                                                LevelBoss->Bullets.at(i)->Sprite.getPosition().y,
                                                                LevelBoss->Bullets.at(i)->Radius,
                                                                0.4f));
                    delete LevelBoss->Bullets.at(i);
                }
                LevelBoss->Bullets.clear();
                LevelBoss->LifeBars.pop_back();
                if (LevelBoss->LifeBars.size()==0)
                    goto boss_is_dead;
                else VisualEffects.AddEffect(new EffectExplosion(LevelBoss->Position.x, LevelBoss->Position.y, 150.f, 0.4f));
            }
        }
        else {
            BossAlive=false;
        }
        BOSS_DISPLAY();
    }
    boss_is_dead:
    //Delete bullets
    for (unsigned i=0; i<LevelBoss->Bullets.size(); i++) {
        VisualEffects.AddEffect(new EffectExplosion(LevelBoss->Bullets.at(i)->Sprite.getPosition().x,
                                                    LevelBoss->Bullets.at(i)->Sprite.getPosition().y,
                                                    LevelBoss->Bullets.at(i)->Radius,
                                                    0.4f));
        delete LevelBoss->Bullets.at(i);
    }
    LevelBoss->Bullets.clear();
    LevelBoss->PrevPosition=LevelBoss->Position;
    VisualEffects.AddEffect(new EffectExplosion(LevelBoss->Position.x, LevelBoss->Position.y, 610.f, 1.5f));
    //Wait a bit
    if (InGame==true) {
        for (unsigned i=0; i<Items.ItemVector.size(); ++i)
            Items.ItemVector.at(i)->BaseTime=0;
        PastTime=0;
        FrameTime=0;
        while (PastTime<1.5 && InGame==true) {
            int handleevents_returncode=HandleEvents();
            if (handleevents_returncode==0)
                InGame=false;
            else if (handleevents_returncode==-1)
                return -1;
            CHECK_EXIT();
            SIMPLE_DISPLAY();
        }
    }
    ZPressed=false;
    //Post-battle dialogue
    while (InGame==true && EndDialogueList[Player->SelectedShotType.ShotTypeID].size()>0) {
        switch (PreHandler(EndDialogueList[Player->SelectedShotType.ShotTypeID])) {
            case GOTO_MAINMENU: InGame=false; break;
            case GOTO_EXIT: return -1; break;
            default: break;
        }
        HandleEvents();
        CHECK_EXIT();
        END_DIALOGUE_DISPLAY();
    }
    //Level End - Score bonus screen
    if (InGame)
        if (LevelClearScreen(this)==-1)
            return -1;

    DestroyLevel();
    while (MainWindow.pollEvent(Event));
    return InGame; //The level ended or the player quitted?*/
}

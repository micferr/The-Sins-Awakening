#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameEngine.h"
#include "Global.h"
#include "DataStruct.h"
#include "Starts.h"
#include "ImageCutScene.h"
#include "ClearScreen.h"

int NewStart() {
    int ShotType;
    int choice=ChooseShotType();
    if (choice==0 || choice==1)
        ShotType=choice;
    else
        return choice;
    //if ShotType==-2 return to main menu, -1 quits
    if (ShotType>=0) {
        CutScene* Intro;
        if (choice==0)
            Intro=new CutScene ({
                                {"Intro1.png", {"A long, long time ago, humans had to fight\nthe seven Deadly Sins.","It was a tremendous battle, but humans managed to win,\nand sealed the demons into a special chest, the Pandora's Box.","However, the evil power derived by men's wicked\nactions ended up breaking the seal, thus freeing the Sins."}},
                                {"Intro2.png", {"The Sins are now rampaging and humans are quickly\nfalling into despair.", "It was known that, sooner or later, the seal had to break.", "Ater knew it too, and had been training for a long time\nwaiting for this day.","Now it's his duty to defeat the Sins once again."}}
                                });
        else if (choice==1)
            Intro=new CutScene({
                                {"Intro1.png", {"A long, long time ago, humans had to fight\nthe seven Deadly Sins.","It was a tremendous battle, but humans managed to win,\nand sealed the demons into a special chest, the Pandora's Box.","However, the evil power derived by men's wicked\nactions ended up breaking the seal, thus freeing the Sins."}},
                                {"Intro3.png", {"The rampage of the Sins is quickly bringing despair\ninto people's mind.", "Alba totally looks like a normal girl, but her\ngrandfather, who fought in the first battle against the Sins,\ntaught her the secrets of magic." ,"Alba decided she wouldn't let anyone destroy\nher lifestyle, and takes up the fight against the Sins."}}
                                });
        if (Intro->Show()==-1) {
            delete Intro;
            return -1;
        }
        delete Intro;
        Engine.InGame=true; //Game has to run till this is true
        Engine.CreateMode(STORY_MODE); //Allocate story-mode only resources
        bool FinalUnlocked=Data.FinalUnlocked;
        //Score goals
        std::vector<long long> scoregoals({2000000,
                                           5000000,
                                           10000000,
                                           20000000,
                                           40000000,
                                           75000000,
                                           100000000});
        Engine.ScoreRewarder.Clear();
        for (auto i: scoregoals)
            Engine.ScoreRewarder.AddReward(i);
        scoregoals.clear();
        //Starting
        for (Level lvl=LEVEL_ONE; lvl<=LEVEL_SEVEN && Engine.InGame==true; lvl=Level(int(lvl)+int(LEVEL_ONE))) {
            Engine.CreateLevel(lvl); //Load data
            if (Engine.LevelStart()==-1) {
                Data.FinalUnlocked=false;
                Engine.DestroyLevel();
                return -1; //Quits the game
            }
            Engine.DestroyLevel();
            if (Data.UnlockedStage<int(lvl))
                Data.UnlockedStage=int(lvl);
        }
        delete Engine.Player->SelectedShotType.Bomb;
        if (Engine.InGame==true) {
            if (GameClearScreen(&Engine)==-1)
                return -1;
            if (Engine.SaveScreen()==-1)
                return -1;
            //When game is finished
            //Data.FinalUnlocked=true;
        }
        else if (FinalUnlocked==false)
            Data.FinalUnlocked=false;
    }
    Play(MENUTHEME);
    return 0;
}

int PracticeStart() {
    sf::Text Title;
    sf::Text Levels[7];
    Title.setFont(Font[PRINCEVALIANT]);
    Title.setColor(sf::Color(27,128,255,255));
    Title.setCharacterSize(80);
    Title.setString("Choose a level");
    Title.setOrigin(Title.getLocalBounds().width/2,0);
    Title.setPosition(400,20);
    for (int i=0; i<7; ++i) {
        Levels[i].setFont(Font[TUFFY]);
        Levels[i].setCharacterSize(50);
        if (i<7) {
            std::string text("Level ");
            text+=(char)(i+49);
            if (Data.UnlockedStage <= i) text+=" -LOCKED-";
            Levels[i].setString(text);
        }
        Levels[i].setPosition(400-Levels[i].getLocalBounds().width/2, 130+60*i);
    }

    //Loop
    int Selected=1;
    bool InPracticeStartMenu=true;
    MainBackgroundSprite.setColor(sf::Color(0,0,128,255));
    while (InPracticeStartMenu) {
        //Event Handling
        while (MainWindow.pollEvent(Event)) {
            if (Event.type==sf::Event::KeyPressed) {
                switch (Event.key.code) {
                    case sf::Keyboard::Up:
                        Play(MENUSCROLL);
                        if (Selected>1) Selected--;
                        break;
                    case sf::Keyboard::Down:
                        Play(MENUSCROLL);
                        if (Selected<7+(Data.ExtraUnlocked==1)) Selected++;
                        break;
                    case sf::Keyboard::Return:
                    case sf::Keyboard::Z:
                        if (Selected>Data.UnlockedStage) {
                            //ERROR SOUND
                        }
                        else {
                            Play(MENUCONFIRM);
                            int choice=ChooseShotType();
                            std::vector<long long> scoregoals({ 2000000,
                                                                5000000,
                                                                10000000,
                                                                25000000,
                                                                50000000,
                                                                100000000,
                                                                150000000,
                                                                250000000});
                            Engine.ScoreRewarder.Clear();
                            for (auto i: scoregoals)
                            Engine.ScoreRewarder.AddReward(i);
                            scoregoals.clear();
                            MainBackgroundSprite.setColor(sf::Color(0,0,128));
                            if (choice>=0) {
                                Level l=LEVEL_ONE;
                                switch (Selected) {
                                    case 1: l=LEVEL_ONE; break;
                                    case 2: l=LEVEL_TWO; break;
                                    case 3: l=LEVEL_THREE; break;
                                    case 4: l=LEVEL_FOUR; break;
                                    case 5: l=LEVEL_FIVE; break;
                                    case 6: l=LEVEL_SIX; break;
                                    case 7: l=LEVEL_SEVEN; break;
                                    default: break;
                                }
                                Engine.CreateMode(PRACTICE_MODE);
                                Engine.CreateLevel(l);
                                if (Engine.LevelStart()==-1) {
                                    Data.FinalUnlocked=false;
                                    Engine.DestroyLevel();
                                    return -1; //Quits the game
                                }
                                delete Engine.Player->SelectedShotType.Bomb;
                                Play(MENUTHEME);
                            }
                            else if (choice==-1) return -1; //Quits the game
                        }
                        break;
                    case sf::Keyboard::Escape:
                    case sf::Keyboard::X:
                        Play(MENUCONFIRM);
                        InPracticeStartMenu=false;
                        break;
                    case sf::Keyboard::P:
                        Engine.ScreenShot();
                        break;
                    case sf::Keyboard::LAlt:
                        Engine.LAltPressed=true;
                        break;
                    case sf::Keyboard::F4:
                        Engine.F4Pressed=true;
                        break;
                    default:
                        break;
                }
            }
            else if (Event.type==sf::Event::KeyReleased) {
                switch (Event.key.code) {
                    case sf::Keyboard::LAlt:
                        Engine.LAltPressed=false;
                        break;
                    case sf::Keyboard::F4:
                        Engine.F4Pressed=false;
                        break;
                    default:
                        break;
                }
            }
            else if (Event.type==sf::Event::Closed)
                Engine.CrossPressed=true;
        }

        CHECK_EXIT();
        //Coloring strings
        for (int i=0; i<7; i++)
            Levels[i].setColor(sf::Color(128+127*(Selected==i+1),128+127*(Selected==i+1),128+127*(Selected==i+1)));

        //Drawing
        MainWindow.clear();
        MainWindow.draw(MainBackgroundSprite);
        MainWindow.draw(Title);
        for (int i=0; i<7; i++) MainWindow.draw(Levels[i]);
        MainWindow.display();
        sf::sleep(sf::milliseconds(17));
    }
    MainBackgroundSprite.setColor(sf::Color(128,0,0,255));
    return 0;
}


int ChooseShotType() {
    ShotType ShotTypes[2];
    ShotTypes[0].NormalMovementSpeed=/*400*/480; ShotTypes[1].NormalMovementSpeed=330;
    ShotTypes[0].FocusedMovementSpeed=/*170*/190; ShotTypes[1].FocusedMovementSpeed=120;
    ShotTypes[0].ChargeMovementSpeed=700; ShotTypes[1].ChargeMovementSpeed=50;
    ShotTypes[0].ChargeFocusedMovementSpeed=300; ShotTypes[1].ChargeFocusedMovementSpeed=20;
    ShotTypes[0].HitboxRadius=1; ShotTypes[1].HitboxRadius=1;
    ShotTypes[0].ShotsPerSecond=12.5; ShotTypes[1].ShotsPerSecond=8.5;
    ShotTypes[0].TextureFile="Hero1.png"; ShotTypes[1].TextureFile="Hero2.png";
    ShotTypes[0].ShootSoundID=ATERSHOOT; ShotTypes[1].ShootSoundID=ALBASHOOT;
    ShotTypes[0].AuxShootSoundID=ATERAUXSHOOT; ShotTypes[1].AuxShootSoundID=ALBAAUXSHOOT;
    ShotTypes[0].BombSoundID=ATERBOMB; ShotTypes[1].BombSoundID=ALBABOMB;
    ShotTypes[0].DeathSoundID=ATERDEATH; ShotTypes[1].DeathSoundID=ALBADEATH;
    ShotTypes[0].ShotTextureFile[0]="PlayerBullet00.png"; ShotTypes[1].ShotTextureFile[0]="PlayerBullet10.png";
    ShotTypes[0].ShotTextureFile[1]="PlayerBullet01.png"; ShotTypes[1].ShotTextureFile[1]="PlayerBullet11.png";
    for (unsigned i=0; i<11; ++i) {
        ShotTypes[0].AuxShotsPerSecond[i]=1+0.5*i+(i==10?5.5:0);
        ShotTypes[1].AuxShotsPerSecond[i]=1+0.3*i+(i==10?16.5:0);
    }
    ShotTypes[0].ShotTypeID=0; ShotTypes[1].ShotTypeID=1;
    ShotTypes[0].Bomb=new Bomb_TypeOne(Engine); ShotTypes[1].Bomb=new Bomb_TypeTwo(Engine);

    //Loading Text
    sf::Text Title;
    sf::Sprite CharacterSprite[2];
    sf::Text AttackType[2];
    sf::Text AttackDescription[2];
    sf::Text AttackData[2];
    sf::Sprite Star, Arrow;
    unsigned Data[2][3]={{5,2,5},{4,5,3}};
    sf::Text Bomb[2], Charge[2];
    sf::Text BombDescription[2], ChargeDescription[2];

    Title.setFont(Font[PRINCEVALIANT]);
    Title.setColor(sf::Color(27,128,255,255));
    Title.setCharacterSize(70);
    Title.setString("Choose your character");
    Title.setPosition(400-Title.getLocalBounds().width/2,20);
    //-
    unsigned x_0[2]={290,170};
    for (unsigned i=0; i<2; ++i) {
        AttackType[i].setFont(Font[TUFFY]);
        AttackType[i].setColor(sf::Color(255,128,128,255));
        AttackType[i].setCharacterSize(40);
        AttackType[i].setString(i==0?"Ater":"Alba");
        AttackType[i].setPosition(400-AttackType[0].getLocalBounds().width/2,120);

        AttackDescription[i].setFont(Font[TUFFY]);
        AttackDescription[i].setColor(sf::Color(255,255,128,255));
        AttackDescription[i].setCharacterSize(20);
        if (i==0)   AttackDescription[i].setString("His rifle has a narrower range,\nbut it is powerful against single\nenemies and bosses.");
        else        AttackDescription[i].setString("Her magic-based attacks cover a\ngreat area, and are useful when\nfacing groups of enemies.");
        AttackDescription[i].setPosition(x_0[i], 185);

        AttackData[i].setFont(Font[TUFFY]);
        AttackData[i].setColor(sf::Color(255,255,128,255));
        AttackData[i].setCharacterSize(20);
        AttackData[i].setString("Attack Power:\nAttack Range:\nMoving Speed:");
        AttackData[i].setPosition(x_0[i],290);

        Bomb[i].setFont(Font[TUFFY]);
        Bomb[i].setColor(sf::Color(128,255,128,255));
        Bomb[i].setCharacterSize(20);
        if (i==0)   Bomb[i].setString("Skill - Explosive Bomb");
        else        Bomb[i].setString("Skill - Bullet-Absorbing Barrier");
        Bomb[i].setPosition(x_0[i],390);

        BombDescription[i].setFont(Font[TUFFY]);
        BombDescription[i].setColor(sf::Color(255,255,255,255));
        BombDescription[i].setCharacterSize(20);
        if (i==0)   BombDescription[i].setString("Trigger a bomb, and let its explosion burn both\nyour enemies and their bullets to ashes!");
        else        BombDescription[i].setString("Cast a barrier, and let it turn enemy\nbullets into power! The more, the better!");
        BombDescription[i].setPosition(x_0[i],420);

        Charge[i].setFont(Font[TUFFY]);
        Charge[i].setColor(sf::Color(64,64,255,255));
        Charge[i].setCharacterSize(20);
        if (i==0)   Charge[i].setString("Spirit Unleashing - Over The Limits");
        else        Charge[i].setString("Spirit Unleashing - Purification Sacrifice");
        Charge[i].setPosition(x_0[i],480);

        ChargeDescription[i].setFont(Font[TUFFY]);
        ChargeDescription[i].setColor(sf::Color(255,255,255,255));
        ChargeDescription[i].setCharacterSize(20);
        if (i==0)   ChargeDescription[i].setString("Push yourself to the limit and get maximized speed\nand power! Devastation has never been this easy!");
        else        ChargeDescription[i].setString("Sacrifice your speed to achieve insane powers!\nWhy would you even need to move?");
        ChargeDescription[i].setPosition(x_0[i],510);
    }
    Star.setTexture(Engine.StarImage);
    Arrow.setTexture(Engine.ArrowImage);
    Arrow.setOrigin(-300, Engine.ArrowImage.getSize().y/2);
    Arrow.setPosition(400,300);

    float scalefactor;
    CharacterSprite[0].setTexture(Engine.PlayerPortraitImage[0]);
    CharacterSprite[0].setPosition(-20,130);
    scalefactor=static_cast<float>(500)/static_cast<float>(Engine.PlayerPortraitImage[0].getSize().y);
    CharacterSprite[0].setScale(scalefactor,scalefactor);

    CharacterSprite[1].setTexture(Engine.PlayerPortraitImage[1]);
    CharacterSprite[1].setPosition(795,130);
    scalefactor=static_cast<float>(500)/static_cast<float>(Engine.PlayerPortraitImage[1].getSize().y);
    CharacterSprite[1].setScale(-scalefactor,scalefactor);

    sf::RenderTexture CharacterDetailsTexture[2];
    sf::Sprite CharacterDetailsSprite[2];
    for (unsigned i=0; i<2; ++i) {
        CharacterDetailsTexture[i].create(800,600);
        CharacterDetailsTexture[i].clear(sf::Color(0,0,0,0));
        CharacterDetailsTexture[i].setRepeated(false);
        CharacterDetailsTexture[i].draw(CharacterSprite[i]);
        CharacterDetailsTexture[i].draw(AttackType[i]);
        CharacterDetailsTexture[i].draw(AttackDescription[i]);
        CharacterDetailsTexture[i].draw(AttackData[i]);
        for (unsigned y=0; y<3; ++y) {
            for (unsigned x=0; x<Data[i][y]; ++x) {
                Star.setPosition(x_0[i]+140+30*x ,292+27*y);
                CharacterDetailsTexture[i].draw(Star);
            }
        }
        Arrow.setScale((i==0?1:-1), 1);
        CharacterDetailsTexture[i].draw(Arrow);
        CharacterDetailsTexture[i].draw(Bomb[i]);
        CharacterDetailsTexture[i].draw(BombDescription[i]);
        CharacterDetailsTexture[i].draw(Charge[i]);
        CharacterDetailsTexture[i].draw(ChargeDescription[i]);
        CharacterDetailsTexture[i].display();

        CharacterDetailsSprite[i].setOrigin(799*i,0);
        CharacterDetailsSprite[i].setPosition(799*i,0);
        CharacterDetailsSprite[i].setTexture(CharacterDetailsTexture[i].getTexture());
    }
    int timeslider_milliseconds=0; //Range 0-250
    sf::Clock Timer;
    int frametime_milliseconds;

    //Loop
    MainBackgroundSprite.setColor(sf::Color(0,128,0,255));
    int Selected=0;
    while (true) {
        while (MainWindow.pollEvent(Event)) {
            if (Event.type==sf::Event::KeyPressed) {
                switch (Event.key.code) {
                    case sf::Keyboard::Up:
                    case sf::Keyboard::Down:
                    case sf::Keyboard::Left:
                    case sf::Keyboard::Right:
                        Play(MENUSCROLL);
                        Selected++;
                        Selected%=2;
                        break;
                    case sf::Keyboard::Return:
                    case sf::Keyboard::Z:
                        Play(MENUCONFIRM);
                        {
                        Engine.PlayerPortraitSprite.setTexture(Engine.PlayerPortraitImage[Selected]);
                        sf::Vector2u texture_size=Engine.PlayerPortraitImage[Selected].getSize();
                        float scalefactor=static_cast<float>(460)/static_cast<float>(texture_size.y);
                        Engine.PlayerPortraitSprite.setScale(scalefactor, scalefactor);
                        Engine.PlayerPortraitSprite.setTextureRect(sf::IntRect(0,0,texture_size.x,texture_size.y));
                        }
                        Engine.Player->SelectedShotType=ShotTypes[Selected];
                        Engine.Player->Load();
                        return Selected;
                        break;
                    case sf::Keyboard::Escape:
                    case sf::Keyboard::X:
                        Play(MENUCONFIRM);
                        return -2; //Code to get to the main menu
                        break;
                    case sf::Keyboard::P:
                        Engine.ScreenShot();
                        break;
                    case sf::Keyboard::LAlt:
                        Engine.LAltPressed=true;
                        break;
                    case sf::Keyboard::F4:
                        Engine.F4Pressed=true;
                        break;
                    default:
                        break;
                }
            }
            else if (Event.type==sf::Event::KeyReleased) {
                switch (Event.key.code) {
                    case sf::Keyboard::LAlt:
                        Engine.LAltPressed=false;
                        break;
                    case sf::Keyboard::F4:
                        Engine.F4Pressed=false;
                        break;
                    default:
                        break;
                }
            }
            else if (Event.type==sf::Event::Closed)
                Engine.CrossPressed=true;
        }

        CHECK_EXIT();
        //Scaling sprites
        frametime_milliseconds=min<int>(Timer.restart().asMilliseconds(), 30);
        timeslider_milliseconds=Selected==0 ?
            max(timeslider_milliseconds-frametime_milliseconds, 0) :
            min(timeslider_milliseconds+frametime_milliseconds, 250);
        CharacterDetailsSprite[0].setScale(1*(250-timeslider_milliseconds)/250.0, 1);
        CharacterDetailsSprite[1].setScale(1*timeslider_milliseconds/250.0, 1);

        //Drawing
        MainWindow.clear();
        MainWindow.draw(MainBackgroundSprite);
        MainWindow.draw(Title);
        MainWindow.draw(CharacterDetailsSprite[0]);
        MainWindow.draw(CharacterDetailsSprite[1]);
        MainWindow.display();
        sf::sleep(sf::milliseconds(10));
    }
    return 0;
}

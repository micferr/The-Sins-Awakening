#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <GL/gl.h>
#include "DataStruct.h"
#include "Global.h"
#include "ResourceFile.h"
#include "ScoreRewards.h"
#include "GameEngine.h"
#include "Explosion.h"

#include "Level_1/Level1.h"
#include "Level_2/Level2.h"
#include "Level_3/Level3.h"
#include "Level_4/Level4.h"
#include "Level_5/Level5.h"
#include "Level_6/Level6.h"
#include "Level_7/Level7.h"

#include <algorithm>

void GameEngine::DeleteBullet(Bullet *bullet, int owner=0) {
    VisualEffects.AddEffect(new EffectExplosion(bullet->Sprite.getPosition().x,bullet->Sprite.getPosition().y,bullet->Radius,0.4f));
    int pos=bullet->VectorPosition;
    if (owner==0) {
        /*EnemyBullets[pos]=EnemyBullets.back();
        EnemyBullets.pop_back();*/
        EnemyBullets.erase(EnemyBullets.begin()+pos);
        for (unsigned int i=0; i<EnemyBullets.size(); ++i)
            EnemyBullets.at(i)->VectorPosition=i;
    }
    else {
        PlayerBullets[pos]=PlayerBullets.back();
        PlayerBullets.pop_back();
        for (unsigned int i=0; i<PlayerBullets.size(); ++i)
            PlayerBullets.at(i)->VectorPosition=i;
    }
    delete bullet;
}

GameEngine::GameEngine() : PastTime(0.0f), ScoreRewarder(this), Score(0), Player(nullptr), LevelBoss(nullptr), Items(this), LevelMusicID(NOMUSIC), BossMusicID(NOMUSIC) {
    //Load player data
    {
        Player=new MyPlayer;
        Player->EnginePointer=this;
        Reader.read();
    }

    //Load strings
    {
        MaxScoreString.setFont(Font[PRINCEVALIANT]);
        MaxScoreValueString.setFont(Font[TUFFY]);
        ScoreString.setFont(Font[PRINCEVALIANT]);
        ScoreValueString.setFont(Font[TUFFY]);
        LivesString.setFont(Font[PRINCEVALIANT]);
        BombsString.setFont(Font[PRINCEVALIANT]);
        PowerString.setFont(Font[PRINCEVALIANT]);
        PowerValueString.setFont(Font[TUFFY]);
        ChargeString.setFont(Font[PRINCEVALIANT]);
        ChargeValueString.setFont(Font[TUFFY]);
        GrazeString.setFont(Font[PRINCEVALIANT]);
        GrazeValueString.setFont(Font[TUFFY]);

        MaxScoreString.setString("High Score");
        ScoreString.setString("Score");
        LivesString.setString("Lives");
        BombsString.setString("Skill");
        PowerString.setString("Power");
        ChargeString.setString("Spirit");
        GrazeString.setString("Graze");

        MaxScoreString.setCharacterSize(40);
        MaxScoreValueString.setCharacterSize(40);
        ScoreString.setCharacterSize(40);
        ScoreValueString.setCharacterSize(40);
        LivesString.setCharacterSize(40);
        BombsString.setCharacterSize(40);
        PowerString.setCharacterSize(40);
        PowerValueString.setCharacterSize(40);
        ChargeString.setCharacterSize(40);
        ChargeValueString.setCharacterSize(40);
        GrazeString.setCharacterSize(40);
        GrazeValueString.setCharacterSize(40);

        MaxScoreString.setColor(sf::Color(192,128,192,255)); //Purple
        MaxScoreValueString.setColor(sf::Color(255,255,255,255)); //White
        ScoreString.setColor(sf::Color(192,128,192,255)); //Purple
        ScoreValueString.setColor(sf::Color(255,255,255,255)); //White
        LivesString.setColor(sf::Color(255,64,64,255)); //Red
        BombsString.setColor(sf::Color(128,255,128,255)); //Green
        PowerString.setColor(sf::Color(255,255,64,255)); //Orange
        PowerValueString.setColor(sf::Color(255,255,255,255)); //White
        ChargeString.setColor(sf::Color(64,64,255,255)); //Blue
        ChargeValueString.setColor(sf::Color(255,255,255,255)); //White
        GrazeString.setColor(sf::Color(128,128,128,255)); //Grey
        GrazeValueString.setColor(sf::Color(255,255,255,255)); //White

        MaxScoreString.setPosition(490,40);
        MaxScoreValueString.setPosition(770,90);
        ScoreString.setPosition(490,140);
        ScoreValueString.setPosition(770,190);
        LivesString.setPosition(490,240);
        BombsString.setPosition(490,290);
        PowerString.setPosition(490,360);
        PowerValueString.setPosition(770,360);
        ChargeString.setPosition(490,450);
        ChargeValueString.setPosition(770,450);
        GrazeString.setPosition(490,510);
        GrazeValueString.setPosition(770,510);
    }

    //Pause gauge
    {
        PauseGaugeBackground.setSize(sf::Vector2f(120.f,20.f));
        PauseGaugeBackground.setPosition(650,420);
        PauseGaugeBackground.setFillColor(sf::Color(0xCC,0x00,0xCC));
        PauseGaugeBackground.setOutlineThickness(3);
        PauseGaugeBackground.setOutlineColor(sf::Color(0x33,0x00,0x33));

        PauseGaugeFill.setSize(sf::Vector2f(120.f,20.f));
        PauseGaugeFill.setPosition(650,420);
        PauseGaugeFill.setFillColor(sf::Color(0x99,0x99,0x99));
    }

    //Load enemies' data
    {
        char *imagebuffer;
        unsigned long imagesize;

        std::vector<std::string> filenames;
        filenames.push_back("Enemy0.png");
        filenames.push_back("Enemy1.png");
        filenames.push_back("Enemy2.png");

        for (unsigned int i=0; i<filenames.size(); i++) {
            imagebuffer=Reader.getFile(filenames[i]);
            imagesize=Reader.getEntryFileSize(filenames[i]);
            EnemyImages.push_back(sf::Texture());
            EnemyImages.back().loadFromMemory(imagebuffer, imagesize);
            EnemyImages.back().setSmooth(true);
            delete[] imagebuffer;
        }
    }

    //Load projectiles' data
    {
        char *imagebuffer;
        unsigned long imagesize;

        std::vector<std::string> filenames;
        filenames.push_back("Bullet1_Red.png");
        filenames.push_back("Bullet1_Red_Wide.png");
        filenames.push_back("Bullet1_Green.png");
        filenames.push_back("Bullet1_Blue.png");
        filenames.push_back("Bullet1_Blue_Wide.png");
        filenames.push_back("Bullet1_Yellow.png");
        filenames.push_back("Bullet1_Grey.png");
        filenames.push_back("Bullet1_LightBlue.png");
        filenames.push_back("Bullet1_Magenta.png");
        filenames.push_back("Bullet1_Black.png");
        filenames.push_back("Bullet2_Red.png");
        filenames.push_back("Bullet2_Green.png");
        filenames.push_back("Bullet2_Blue.png");
        filenames.push_back("Bullet2_Yellow.png");
        filenames.push_back("Bullet2_Grey.png");
        filenames.push_back("Bullet2_Magenta.png");
        filenames.push_back("Bullet3.png");
        filenames.push_back("Bullet3_Wide.png");
        filenames.push_back("Bullet4.png");
        filenames.push_back("Bullet5.png");
        filenames.push_back("Bullet6.png");

        for (unsigned int i=0; i<filenames.size(); i++) {
            imagebuffer=Reader.getFile(filenames[i]);
            imagesize=Reader.getEntryFileSize(filenames[i]);
            BulletImages.push_back(sf::Texture());
            BulletImages.back().loadFromMemory(imagebuffer,imagesize);
            BulletImages.back().setSmooth(true);
            delete[] imagebuffer;
        }
    }

    //Other
    {
        char *imagebuffer;
        unsigned long imagesize;
        sf::Texture Image;

        //Lives and bombs
        imagebuffer=Reader.getFile("Lives.png");
        imagesize=Reader.getEntryFileSize("Lives.png");
        LivesImage.loadFromMemory(imagebuffer,imagesize);
        delete[] imagebuffer;
        imagebuffer=Reader.getFile("Bombs.png");
        imagesize=Reader.getEntryFileSize("Bombs.png");
        BombsImage.loadFromMemory(imagebuffer,imagesize);
        delete[] imagebuffer;
        for (short i=0; i<7; ++i) {
            LivesSprites[i].setTexture(LivesImage);
            LivesSprites[i].setPosition(610+26*i,252);
        }
        for (short i=0; i<8; ++i) {
            BombsSprites[i].setTexture(BombsImage);
            BombsSprites[i].setPosition(610+i*26,302);
        }

        //Outside backgrounds
        imagebuffer=Reader.getFile("StoryBackground.png");
        imagesize=Reader.getEntryFileSize("StoryBackground.png");
        OutsideBackgroundImage[0].loadFromMemory(imagebuffer,imagesize);
        delete[] imagebuffer;
        imagebuffer=Reader.getFile("ExtraBackground.png");
        imagesize=Reader.getEntryFileSize("ExtraBackground.png");
        OutsideBackgroundImage[1].loadFromMemory(imagebuffer,imagesize);
        delete[] imagebuffer;
        OutsideBackgroundSprite.setPosition(0,0);

        //Explosions
        imagebuffer=Reader.getFile("Explosion0.png");
        imagesize=Reader.getEntryFileSize("Explosion0.png");
        ExplosionImages.push_back(sf::Texture());
        ExplosionImages.back().loadFromMemory(imagebuffer,imagesize);
        delete[] imagebuffer;
        imagebuffer=Reader.getFile("Explosion1.png");
        imagesize=Reader.getEntryFileSize("Explosion1.png");
        ExplosionImages.push_back(sf::Texture());
        ExplosionImages.back().loadFromMemory(imagebuffer,imagesize);
        ExplosionImages.back().setSmooth(true);
        delete[] imagebuffer;

        //MessageBox for dialogues
        imagebuffer=Reader.getFile("MsgBox.png");
        imagesize=Reader.getEntryFileSize("MsgBox.png");
        MsgBoxImage.loadFromMemory(imagebuffer,imagesize);
        MsgBoxSprite.setTexture(MsgBoxImage);
        MsgBoxSprite.setOrigin(MsgBoxSprite.getLocalBounds().width/2,0);
        MsgBoxSprite.setPosition(250,410);
        delete[] imagebuffer;

        //Star
        imagebuffer=Reader.getFile("Star.png");
        imagesize=Reader.getEntryFileSize("Star.png");
        StarImage.loadFromMemory(imagebuffer,imagesize);
        delete[] imagebuffer;

        //Arrow
        imagebuffer=Reader.getFile("Arrow.png");
        imagesize=Reader.getEntryFileSize("Arrow.png");
        ArrowImage.loadFromMemory(imagebuffer,imagesize);
        delete[] imagebuffer;

        //Player portrait
        imagebuffer=Reader.getFile("CharPortrait0_1blur.png");
        imagesize=Reader.getEntryFileSize("CharPortrait0_1blur.png");
        PlayerPortraitImage[0].loadFromMemory(imagebuffer,imagesize);
        PlayerPortraitImage[0].setSmooth(true);
        delete[] imagebuffer;
        imagebuffer=Reader.getFile("CharPortrait0_2blur.png");
        imagesize=Reader.getEntryFileSize("CharPortrait0_2blur.png");
        PlayerPortraitImage[1].loadFromMemory(imagebuffer, imagesize);
        PlayerPortraitImage[1].setSmooth(true);
        delete[] imagebuffer;

        PlayerPortraitSprite.setPosition(0,165);

        //Boss Aura
        imagebuffer=Reader.getFile("BossAura.png");
        imagesize=Reader.getEntryFileSize("BossAura.png");
        BossAuraImage.loadFromMemory(imagebuffer,imagesize);
        BossAuraImage.setSmooth(true);

        //Scrolling background
        Background.BindEngine(*this);
        Background.BindWindow(MainWindow);
        Background.BindTextures(LevelBackgroundImage[0], LevelBackgroundImage[1]);
    }

    //Falling items
    {
        char *imagebuffer;
        int imagesize;
        std::vector<std::string> files;
        files.push_back("PowerItem.png");
        files.push_back("ScoreItem.png");
        files.push_back("BombItem.png");
        files.push_back("LifeItem.png");
        for (unsigned int i=0; i<files.size(); i++) {
            imagebuffer=Reader.getFile(files.at(i));
            imagesize=Reader.getEntryFileSize(files.at(i));
            ItemImages.push_back(sf::Texture());
            ItemImages.back().loadFromMemory(imagebuffer,imagesize);
            delete[] imagebuffer;
        }
    }

    UpPressed=DownPressed=LeftPressed=RightPressed=ZPressed=XPressed=CPressed=ShiftPressed=LAltPressed=F4Pressed=CrossPressed=false;
    VisualEffects.BindEngine(this);
    VisualEffects.BindWindow(&MainWindow);
}

void GameEngine::CreateMode(GameMode mode) {
    Mode=mode;
    Score=0;
    switch (Mode) {
        case STORY_MODE:
            MaxScore=Data.Score[0];
            Player->Lives=Data.MaxLives;
            Player->Power=0;
            for (int i=0; i<Player->Lives; i++) LivesSprites[i].setColor(sf::Color(255,255,255,255));
            break;
        case PRACTICE_MODE:
            MaxScore=0; //Don't show it
            Player->Lives=8;
            Player->Power=1000;
            for (int i=0; i<Player->Lives; i++) LivesSprites[i].setColor(sf::Color(255,255,255,255));
            break;
        default: //Should never happen
            break;
    }
    OutsideBackgroundSprite.setTexture(OutsideBackgroundImage[0]);
    Player->Bombs=3;
    char c[15];
    //itoa(MaxScore,c,10);
    #ifdef _WIN32
        sprintf(c,"%I64d",MaxScore);
    #else
        sprintf(c,"%lld",MaxScore);
    #endif
    MaxScoreValueString.setString(c);
    Player->Charge=0.01f;
    Player->ChargeTime=0.f;
    Player->BombTime=0.f;
    Player->DeathTime=0.f;
    Score=0;

    Enemies.reserve(200);
    PlayerBullets.reserve(500);
    EnemyBullets.reserve(500);
}

void GameEngine::CreateLevel(Level level) {
    DestroyLevel();
    PastTime=0.0f; //Set up timer
    Graze=0;
    Player->Position.x=250;
    Player->Position.y=500;
    Player->MainShootTime=Player->AuxShootTime=Player->BombTime=Player->ChargeTime=Player->DeathTime=0.0f;
    Player->PauseGauge=1.f;
    LevelBoss=new Boss;
    for (int i=0; i<2; ++i) {
        BeginDialogueList[i].clear();
        EndDialogueList[i].clear();
    }
    char *imagebuffer;
    unsigned imagesize;
    switch (level) {
        case LEVEL_ONE:
            CREATE_LEVEL_ONE()
            break;
        case LEVEL_TWO:
            CREATE_LEVEL_TWO()
            break;
        case LEVEL_THREE:
            CREATE_LEVEL_THREE()
            break;
        case LEVEL_FOUR:
            CREATE_LEVEL_FOUR()
            break;
        case LEVEL_FIVE:
            CREATE_LEVEL_FIVE()
            break;
        case LEVEL_SIX:
            CREATE_LEVEL_SIX()
            break;
        case LEVEL_SEVEN:
            CREATE_LEVEL_SEVEN()
            break;
        default:
            break;
        //Level Extra
    }
    BossPortraitImage.setSmooth(true);
    BossPortraitSprite.setTexture(BossPortraitImage, true);
    BossPortraitSprite.setOrigin(BossPortraitImage.getSize().x/2,BossPortraitImage.getSize().y-1);
    BossPortraitSprite.setPosition(sf::Vector2<float>(390,640));
    float scalefactor=static_cast<float>(level!=LEVEL_SEVEN?500:550)/static_cast<float>(BossPortraitImage.getSize().y);
    BossPortraitSprite.setScale(scalefactor, scalefactor);
    BossPortraitSprite.setTextureRect(sf::IntRect(0,0,BossPortraitImage.getSize().x-1, BossPortraitImage.getSize().y-1));
    LevelBoss->Texture.setSmooth(true);
    LevelBoss->SetImage(LevelBoss->Texture);
    for (int i=0; i<4; i++) {
        LevelBoss->Sprite[i].setPosition(LevelBoss->Position);
    }
    LevelBackgroundImage[0].setRepeated(true);
    LevelBackgroundSprite.setTexture(LevelBackgroundImage[0]);
    LevelBackgroundSprite.setTextureRect(sf::IntRect(0,0,450,1320));
    LevelBackgroundSprite.setPosition(25,-525);
    LevelBossBackgroundSprite.setTexture(LevelBackgroundImage[1]);
    LevelBossBackgroundSprite.setPosition(25,-525);
    Background.LoadFromTextures(LevelBackgroundImage[0], LevelBackgroundImage[1]);
    LoadMusic(LevelMusicID);
}

void GameEngine::ScreenShot() {
    unsigned long int num=0;
    bool Looking=true;
    while (Looking) {
        std::string s="Screenshots/pic";
        char c[10];
        ///itoa(num,c,10);
        sprintf(c,"%lu",num);
        s+=c;
        s+=".png";
        std::fstream f;
        f.open(s.c_str(), ios::in);
        if (f.is_open()) {
            num++;
            f.close();
        }
        else {
            Looking=false;
            MainWindow.capture().saveToFile(s);
        }
    }
}

int GameEngine::ExitMenu () {
    Play(ESCMENU);
    bool isMusicPlaying=AudioHandle->IsPlaying();
    PauseMusic();
    glReadBuffer(GL_BACK);
    sf::Texture Screen;
    Screen.loadFromImage(MainWindow.capture());
    sf::Sprite ScreenSprite;
    ScreenSprite.setTexture(Screen);
    ScreenSprite.setColor(sf::Color(128,128,128,255));

    sf::Text Options[2];
    for (int i=0; i<2; i++) {
        Options[i].setFont(Font[TUFFY]);
        Options[i].setPosition(180,240+70*i);
        Options[i].setCharacterSize(60);
    }
    Options[0].setString("Continue");
    Options[1].setString("Back to main menu");

    sf::Text Confirm[3];
    for (int i=0; i<3; i++) {
        Confirm[i].setFont(Font[TUFFY]);
        Confirm[i].setPosition(180,205+70*i);
        Confirm[i].setCharacterSize(60);
    }
    Confirm[0].setString("Are you really sure?");
    Confirm[1].setString("Yes");
    Confirm[2].setString("No");

    bool InExitMenu=true;
    bool Quitting=false;
    short Selected=0;
    while (InExitMenu) {
        while (MainWindow.pollEvent(Event)) {
            if (Event.type==sf::Event::KeyPressed) {
                switch (Event.key.code) {
                    case sf::Keyboard::Up:
                    case sf::Keyboard::Down:
                        Play(MENUSCROLL);
                        Selected++;
                        Selected%=2;
                    break;
                    case sf::Keyboard::X:
                        if (Quitting) Quitting=false;
                        else Quitting=true;
                        break;
                    case sf::Keyboard::Z:
                        if (!Quitting) {
                            if (Selected==1) {
                                Play(MENUCONFIRM);
                                Quitting=true;
                                Selected=1;
                            }
                            else {
                                Play(ESCMENU);
                                InExitMenu=false;
                            }
                        }
                        else {
                            if (Selected==0) {
                                Play(ESCMENU);
                                InExitMenu=false;
                                return 0;
                            }
                            else {
                                Play(MENUCONFIRM);
                                Quitting=false;
                                Selected=0;
                            }
                        }
                        break;
                    case sf::Keyboard::LAlt: LAltPressed=true; break;
                    case sf::Keyboard::F4: F4Pressed=true; break;
                    default:
                        break;
                }
            }
            else if (Event.type==sf::Event::KeyReleased) {
                switch (Event.key.code) {
                    case sf::Keyboard::LAlt: LAltPressed=false; break;
                    case sf::Keyboard::F4: F4Pressed=false; break;
                    default: break;
                }
            }
            else if (Event.type==sf::Event::Closed) {
                CrossPressed=true;
            }
        } //End of event handling

        if (CrossPressed || (LAltPressed && F4Pressed))
            return -1;

        //Coloring strings
        for (int i=0; i<2; i++)
            Options[i].setColor(sf::Color(128+127*(Selected==i), 128+127*(Selected==i), 128+127*(Selected==i), 255*(Quitting==false)));
        Confirm[0].setColor(sf::Color(255,255,255,255*(Quitting==true)));
        for (int i=1; i<3; i++)
            Confirm[i].setColor(sf::Color(128+127*(Selected==i-1), 128+127*(Selected==i-1), 128+127*(Selected==i-1), 255*(Quitting==true)));

        MainWindow.clear();
        MainWindow.draw(ScreenSprite);
        for (int i=0; i<2; i++)
            MainWindow.draw(Options[i]);
        for (int i=0; i<3; i++)
            MainWindow.draw(Confirm[i]);
        MainWindow.display();
        sf::sleep(sf::milliseconds(17));
    }
    Timer.restart();
    if (isMusicPlaying)
        PlayMusic();
    return 1;
}

void GameEngine::Display() {
    MainWindow.clear();

    //Outside background
    MainWindow.draw(OutsideBackgroundSprite);

    //Data on right side of the screen
    char container[12];
    //itoa(Score,container,10);
    #ifdef _WIN32
        sprintf(container,"%I64d",Score);
    #else
        sprintf(container,"%lld",Score);
    #endif
    MaxScoreString.setString("High Score");
    ScoreString.setString("Score");
    LivesString.setString("Lives");
    BombsString.setString("Skill");
    PowerString.setString("Power");
    ChargeString.setString("Spirit");
    GrazeString.setString("Graze");
    ScoreValueString.setString(container);
    ScoreValueString.setOrigin(ScoreValueString.getLocalBounds().width, 0);
    MaxScoreValueString.setOrigin(MaxScoreValueString.getLocalBounds().width,0);
    MainWindow.draw(MaxScoreString);
    MainWindow.draw(MaxScoreValueString);
    MainWindow.draw(ScoreString);
    MainWindow.draw(ScoreValueString);
    MainWindow.draw(LivesString);
    for (int i=0; i<(Player->Lives-1); i++)
        MainWindow.draw(LivesSprites[i]);
    MainWindow.draw(BombsString);
    for (int i=0; i<Player->Bombs; i++)
        MainWindow.draw(BombsSprites[i]);

    //Power, charge and graze
    std::ostringstream powos;
    short powdec=Player->Power%100;
    powos<<Player->Power/100 <<".";
    if (powdec<10) powos<<0;
    powos<<powdec;
    PowerValueString.setString(powos.str());
    PowerValueString.setOrigin(PowerValueString.getLocalBounds().width, 0);

    std::ostringstream charos;
    if (Player->ChargeTime > 0){
        short chardec=(Player->ChargeTime-(int)Player->ChargeTime)*100;
        charos<<(int)Player->ChargeTime;charos<<".";
        if (chardec<10) charos<<0;
        charos<<chardec;
    }
    else {
        charos<<Player->Charge/100 <<'.' <<(Player->Charge%100)/10 <<Player->Charge%10;
    }
    ChargeValueString.setString(charos.str());
    ChargeValueString.setOrigin(ChargeValueString.getLocalBounds().width, 0);

    std::ostringstream graze_os;
    graze_os<<Graze;
    GrazeValueString.setString(graze_os.str());
    GrazeValueString.setOrigin(GrazeValueString.getLocalBounds().width, 0);

    MainWindow.draw(PowerString);
    MainWindow.draw(PowerValueString);
    MainWindow.draw(ChargeString);
    MainWindow.draw(ChargeValueString);
    MainWindow.draw(GrazeString);
    MainWindow.draw(GrazeValueString);

    //PauseGauge
    MainWindow.draw(PauseGaugeBackground);
    PauseGaugeFill.setScale(Player->PauseGauge, 1.f);
    sf::Color fillcolor=Player->PauseGauge>=1.0f ? sf::Color(0xFF,0x00,0x00) : sf::Color(0x99,0x00,0x99);
    PauseGaugeFill.setFillColor(fillcolor);
    MainWindow.draw(PauseGaugeFill);

    //Things inside game window
    glEnable(GL_SCISSOR_TEST);
    glScissor(25,25,450,550);

    //Background
    Background.Display();

    //Explosions
    VisualEffects.Show();

    //Player
    Player->Draw();

    //Bomb
    if (Player->BombTime>0.0f) {
        Player->SelectedShotType.Bomb->DrawEffects();
    }

    //Boss
    LevelBoss->Draw();

    //Falling Items
    Items.DrawItems();

    //Player Bullets
    for (unsigned int i=0; i<PlayerBullets.size(); i++)
        MainWindow.draw(PlayerBullets.at(i)->Sprite);

    //Enemies
    for (unsigned int i=0; i<Enemies.size(); i++) {
        Enemies[i]->Draw();
    }

    //Enemies' bullets
    for (unsigned int i=0; i<EnemyBullets.size(); i++)
        MainWindow.draw(EnemyBullets.at(i)->Sprite);

    glDisable(GL_SCISSOR_TEST);
}

int GameEngine::HandleEvents() {
    Player->CheckCollision();
    //Gets frame time
    FrameTime=Timer.getElapsedTime().asSeconds();
    Timer.restart();
    if (FrameTime > 0.04f) FrameTime=0.04f;
    PastTime+=FrameTime;
    //Check which keys are currently pressed
    while (MainWindow.pollEvent(Event)) {
        if (Event.type == sf::Event::KeyPressed) {
            switch (Event.key.code) {
                case sf::Keyboard::Up:
                    UpPressed=true;
                    break;
                case sf::Keyboard::Down:
                    DownPressed=true;
                    break;
                case sf::Keyboard::Left:
                    LeftPressed=true;
                    break;
                case sf::Keyboard::Right:
                    RightPressed=true;
                    break;
                case sf::Keyboard::LShift:
                    ShiftPressed=true;
                    break;
                case sf::Keyboard::Z:
                    ZPressed=true;
                    break;
                case sf::Keyboard::X:
                    XPressed=true;
                    break;
                case sf::Keyboard::C:
                    CPressed=true;
                    break;
                case sf::Keyboard::Escape:
                    {
                        int exitvalue=ExitMenu();
                        if (exitvalue == 0)
                            return false;
                        else if (exitvalue == -1)
                            return -1;
                        break;
                    }
                case sf::Keyboard::LAlt:
                    LAltPressed=true;
                    break;
                case sf::Keyboard::F4:
                    F4Pressed=true;
                    break;
                case sf::Keyboard::P:
                    ScreenShot();
                    break;
                default:
                    break;
            }
        }
        else if (Event.type==sf::Event::KeyReleased) {
            switch (Event.key.code) {
                case sf::Keyboard::Up:
                    UpPressed=false;
                    break;
                case sf::Keyboard::Down:
                    DownPressed=false;
                    break;
                case sf::Keyboard::Left:
                    LeftPressed=false;
                    break;
                case sf::Keyboard::Right:
                    RightPressed=false;
                    break;
                case sf::Keyboard::LShift:
                    ShiftPressed=false;
                    break;
                case sf::Keyboard::Z:
                    ZPressed=false;
                    break;
                case sf::Keyboard::X:
                    XPressed=false;
                    break;
                case sf::Keyboard::C:
                    CPressed=false;
                    break;
                case sf::Keyboard::LAlt:
                    LAltPressed=false;
                    break;
                case sf::Keyboard::F4:
                    F4Pressed=false;
                    break;
                default:
                    break;
            }
        }
        else if (Event.type==sf::Event::Closed)
            CrossPressed=true;
    }

    //Move Enemy bullets
    std::size_t enbullets_size=EnemyBullets.size();
    Bullet* enbullptr; //enemy bullet pointer
    sf::Vector2<float> enbullpos; //enemy bullet position
    float enbullrad; //enemy bullet radius
    for (std::size_t i=0; i<enbullets_size;) {
        enbullptr=EnemyBullets[i];
        enbullptr->Move(enbullptr);
        enbullpos=enbullptr->Sprite.getPosition();
        enbullrad=enbullptr->Radius;
        if (enbullpos.x+enbullrad < 0 ||
            enbullpos.x-enbullrad > 500 ||
            enbullpos.y+enbullrad < 0 ||
            enbullpos.y-enbullrad > 600) {
            DeleteBullet(enbullptr);
            --enbullets_size;
        }
        else ++i;
    }
    //Gameover - DON'T TOUCH THIS if.
    if (InGame==true && Player->Lives==0) {
        StopMusic();
        Play(PLAYERGAMEOVER);
        InGame=false;
        if (SaveScreen()==-1)
            return -1;
        return -2;
    }

    ///Use input flags
    //Moving
    //Update Position
    Player->PrevPosition=Player->Position;
    int speed;
    if (Player->ChargeTime>0) {
        if (ShiftPressed==false) speed=Player->SelectedShotType.ChargeMovementSpeed;
        else speed=Player->SelectedShotType.ChargeFocusedMovementSpeed;
    }
    else {
        if (ShiftPressed==false) speed=Player->SelectedShotType.NormalMovementSpeed;
        else speed=Player->SelectedShotType.FocusedMovementSpeed;
    }
    if ((UpPressed || DownPressed) && (LeftPressed || RightPressed)) // Diagonal Movement
        speed/=1.41421356;
    if (UpPressed) {
        Player->Position.y-=speed*FrameTime;
        if (Player->Position.y < 35) Player->Position.y=35;
    }
    if (DownPressed) {
        Player->Position.y+=speed*FrameTime;
        if (Player->Position.y > 565) Player->Position.y=565;
    }
    if (LeftPressed) {
        Player->Position.x-=speed*FrameTime;
        if (Player->Position.x < 35) Player->Position.x=35;
    }
    if (RightPressed) {
        Player->Position.x+=speed*FrameTime;
        if (Player->Position.x > 465) Player->Position.x=465;
    }
    for (int i=0; i<4; i++) Player->Sprite[i].setPosition(Player->Position.x, Player->Position.y);
    //Shooting
    //Create bullets
    if (ZPressed==true) {
        Bullet* plbullptr;
        if (Player->MainShootTime==0.00) {
            Play(Player->SelectedShotType.ShootSoundID);
            for (int i=0; i<4; i++) {
                PlayerBullets.push_back(new Bullet);
                plbullptr=PlayerBullets.back();
                plbullptr->Grazed=false;
                plbullptr->Radius=7;
                plbullptr->Sprite.setTexture(Player->SelectedShotType.ShotTexture[0]);
                plbullptr->Sprite.setOrigin(15.5,7.5);
                plbullptr->SetAngle(PI/2);
                plbullptr->Sprite.setPosition(Player->Position.x-21+(14*i), Player->Position.y-10);
                plbullptr->VectorPosition=PlayerBullets.size()-1;
            }
            Player->MainShootTime=1.f/Player->SelectedShotType.ShotsPerSecond;
        }
        //AuxShoot
        if (Player->ChargeTime>0) {
            Player->PauseGauge=1;
        }
        else {
            Player->PauseGauge-=Engine.FrameTime/1.f;
            if (Player->PauseGauge<0)
                Player->PauseGauge=0;
        }
        if (Player->AuxShootTime==0 && Player->PauseGauge>0) {
            for (int i=0; i<15; i++) {
                Play(Player->SelectedShotType.AuxShootSoundID);
                PlayerBullets.push_back(new Bullet);
                plbullptr=PlayerBullets.back();
                plbullptr->Grazed=false;
                plbullptr->Radius=7;
                plbullptr->Sprite.setOrigin(15.5,7.5);
                plbullptr->Sprite.setTexture(Player->SelectedShotType.ShotTexture[1]);
                if (Player->SelectedShotType.ShotTypeID==0) {
                    plbullptr->SetAngle((76+i*2)*PI/180);
                }
                else {
                    plbullptr->SetAngle((48+i*6)*PI/180);
                }
                plbullptr->Sprite.setPosition(Player->Position.x, Player->Position.y);
                plbullptr->VectorPosition=PlayerBullets.size()-1;
            }
            Player->AuxShootTime=1.f/Player->SelectedShotType.AuxShotsPerSecond[static_cast<unsigned int>(floor(Player->Power/100))];
        }
    } //ZPressed==true
    else {
        Player->PauseGauge+=Engine.FrameTime/1.00f;
        if (Player->PauseGauge>1.00f)
            Player->PauseGauge=1.00f;
    }
    Player->MainShootTime-=FrameTime;
    Player->AuxShootTime-=FrameTime;
    if (Player->MainShootTime<=0) Player->MainShootTime=0;
    if (Player->AuxShootTime<=0) Player->AuxShootTime=0;
    ///Bomb
    if (Player->BombTime==0 && /*Player->ChargeTime==0 &&*/ Player->DeathTime==0 && XPressed==true && Player->Bombs>0) {
        Player->PauseGauge=1;
        for (int i=0; i<4; i++)
            Player->Sprite[i].setColor(sf::Color(255,128,128,255));
        Player->BombTime=Player->SelectedShotType.Bomb->Duration; //Invincibility time
        Player->SelectedShotType.Bomb->Activate();
        Player->Bombs--; //The player loses a bomb
    }
    //Check bomb end
    if (Player->BombTime>0.0f) {
        Player->SelectedShotType.Bomb->Update();
        Player->BombTime-=FrameTime;
        //If the bomb time ended
        if (Player->BombTime<=0.0f) {
            Player->BombTime=0.0f;
            for (int i=0; i<4; i++)
                Player->Sprite[i].setColor(sf::Color(255,255,255,255));
            Player->SelectedShotType.Bomb->Terminate();
        }
    }
    ///Charge
    //Charge activation
    if (Player->BombTime==0 && Player->ChargeTime==0 && Player->DeathTime==0 && CPressed==true && Player->Charge==1000) {
        Play(PLAYERCHARGE);
        for (int i=0; i<4; i++)
            Player->Sprite[i].setColor(sf::Color(128,128,255,255));
        Player->ChargeTime=10.0f;
        Player->Charge=0;
    }
    //Check charge end
    if (Player->ChargeTime>0.0f) {
        Player->ChargeTime-=FrameTime;
        //If the charge period ended
        if (Player->ChargeTime<=0.0f) {
            Player->ChargeTime=0.0f;
            for (int i=0; i<4; i++)
                Player->Sprite[i].setColor(sf::Color(255,255,255,255));
        }
    }

    //Check conditions for auto-collection
    if (Player->BombTime>0 || Player->ChargeTime>0 || Player->PauseGauge>=1)
        Items.AutoCollect();

    //Check end of death
    if (Player->DeathTime>0.0f) {
        Player->DeathTime-=FrameTime;
        if (Player->DeathTime<=0) {
            Player->DeathTime=0;
            for (int i=0; i<4; i++)
                Player->Sprite[i].setColor(sf::Color(255,255,255,255));
        }
    }

    //Move player bullets
    for (size_t i=0, plb_size=PlayerBullets.size(); i<plb_size;) {
        Bullet* plb_ptr=PlayerBullets[i];
        unsigned int speed=800;
        float mov_x=cos(plb_ptr->Angle)*speed*FrameTime;
        float mov_y=-sin(plb_ptr->Angle)*speed*FrameTime;
        plb_ptr->Sprite.move(mov_x,mov_y);
        if (plb_ptr->Sprite.getPosition().x < 10 ||
            plb_ptr->Sprite.getPosition().x > 485 ||
            plb_ptr->Sprite.getPosition().y < 10 ||
            plb_ptr->Sprite.getPosition().y > 585) {
                DeleteBullet(plb_ptr, 1);
                --plb_size;
        }
        else {
            ++i;
        }
    }
    //Check collisions between player bullets and enemies
    size_t en_size=Enemies.size(), plb_size=PlayerBullets.size();
    Enemy* en_ptr; float en_rad; sf::Vector2<float> en_pos;
    Bullet* plb_ptr; float plb_rad; sf::Vector2<float> plb_pos;
    bool play_enemyhit=false, play_enemydeath=false;
    for (size_t en_index=0; en_index<en_size; ++en_index) {
        en_ptr=Enemies[en_index];
        en_rad=en_ptr->Radius;
        en_pos=en_ptr->Position;
        if (en_pos.x+en_rad<25 || en_pos.x-en_rad>475 || en_pos.y+en_rad<25 || en_pos.y-en_rad>575) {
            continue;
        }
        for (size_t plb_index=0; plb_index<plb_size;) {
            plb_ptr=PlayerBullets[plb_index];
            plb_rad=plb_ptr->Radius;
            plb_pos=plb_ptr->Sprite.getPosition();
            float Quad_X=plb_pos.x-en_pos.x, Quad_Y=plb_pos.y-en_pos.y, Quad_HitDistance=plb_rad+en_rad;
            Quad_X*=Quad_X; Quad_Y*=Quad_Y; Quad_HitDistance*=Quad_HitDistance; //Quad_ ^2
            if (Quad_X+Quad_Y <= Quad_HitDistance) {
                play_enemyhit=true;
                DeleteBullet(plb_ptr, 1);
                --plb_size;
                --(en_ptr->Life);
                Score+=10;
            }
            else {
                ++plb_index;
            }
        }
    }
    if (play_enemyhit) {
        //Play(ENEMYHIT);
    }
    if (play_enemydeath) {
        Play(ENEMYDEATH);
    }

    //Eventually deletes enemies
    for (unsigned int i=0; i<Enemies.size();) {
        if (Enemies.at(i)->Life <= 0) {
            Play(ENEMYDEATH);
            Items.GenerateFallingItems(Enemies.at(i));
            VisualEffects.AddEffect(new EffectExplosion(Enemies[i]->Position.x, Enemies[i]->Position.y, Enemies[i]->Radius*2, 0.4f));
            delete *(Enemies.begin()+i);
            Enemies.erase(Enemies.begin()+i);
            Score+=100;
        }
        else
            i++;
    }

    //Move enemies and check if they have to shoot
    for (unsigned int i=0; i<Enemies.size(); i++) {
        if (Engine.PastTime>=Enemies.at(i)->BaseTime) { //Only if time to go has arrived
            Enemies.at(i)->PrevPosition=Enemies.at(i)->Position;
            Enemies.at(i)->Move(Enemies.at(i));
            for (short j=0; j<4; j++)
                Enemies.at(i)->Sprite[j].setPosition(Enemies.at(i)->Position);
            if (Engine.Enemies.at(i)->ShootTable.size()>0) {
                if (PastTime >= (Enemies.at(i)->ShootTable.at(0)->first+Enemies.at(i)->BaseTime)) {
                    Enemies.at(i)->ShootTable.at(0)->second(Enemies.at(i));
                    delete Enemies.at(i)->ShootTable.at(0);
                    Enemies.at(i)->ShootTable.erase(Enemies.at(i)->ShootTable.begin());
                }
            }
        }
    }

    Items.MoveItems();
    if (ScoreRewarder.CheckReward()) {
        Items.GainLife();
    }

    //Scrolls the background
    LevelBackgroundSprite.move(0,ceil(160.f*FrameTime));
    int pos_y=LevelBackgroundSprite.getPosition().y;
    while (pos_y >= 25) {
        LevelBackgroundSprite.move(0,-550);
        pos_y-=550;
    }

    return true;
}

void GameEngine::DestroyLevel(void) {
    //Decoloring player
    if (Player!=nullptr)
        for (int i=0; i<4; i++)
            Player->Sprite[i].setColor(sf::Color(255,255,255,255));
    //Deallocating visual effects
    VisualEffects.Clear();
    //Deallocating enemies
    for (unsigned i=0; i<Enemies.size(); i++) {
        for (unsigned j=0; j<Enemies.at(i)->ShootTable.size(); j++)
            delete Enemies.at(i)->ShootTable.at(j);
        delete Enemies.at(i);
    }
    Enemies.clear();
    //Deallocating enemy bullets
    for (unsigned i=0; i<EnemyBullets.size(); i++)
        delete EnemyBullets.at(i);
    EnemyBullets.clear();
    //Deallocating player bullets
    for (unsigned i=0; i<PlayerBullets.size(); i++)
        delete PlayerBullets.at(i);
    PlayerBullets.clear();
    //Deallocating falling items
    Items.Clear();

    //Deallocating boss
    delete LevelBoss;
    LevelBoss=nullptr;

    for (int i=0; i<2; ++i) {
        BeginDialogueList[i].clear();
        EndDialogueList[i].clear();
    }

    ZPressed=XPressed=CPressed=ShiftPressed=UpPressed=DownPressed=LeftPressed=RightPressed=CrossPressed=false;
}

PreHandlerState GameEngine::PreHandler(std::vector<std::pair<std::string, Speaker> > &DList) {
    PreHandlerState ReturnValue=GOTO_NEXTFRAME;
    while (MainWindow.pollEvent(Event)) {
        if (Event.type == sf::Event::KeyPressed) {
            switch (Event.key.code) {
                case sf::Keyboard::Up:
                    UpPressed=true;
                    break;
                case sf::Keyboard::Down:
                    DownPressed=true;
                    break;
                case sf::Keyboard::Left:
                    LeftPressed=true;
                    break;
                case sf::Keyboard::Right:
                    RightPressed=true;
                    break;
                case sf::Keyboard::LShift:
                    ShiftPressed=true;
                    break;
                case sf::Keyboard::Z:
                    if (DList.size()>0) {
                        if (PastTime>3) {
                            DList.pop_back();
                            ReturnValue=GOTO_NEXTFRAME;
                        }
                    }
                    else
                        ReturnValue=GOTO_CONTINUE;
                    break;
                case sf::Keyboard::X:
                    break;
                case sf::Keyboard::C:
                    break;
                case sf::Keyboard::Escape:
                    {
                        int exitvalue=ExitMenu();
                        if (exitvalue == 0)
                            ReturnValue=GOTO_MAINMENU;
                        else if (exitvalue == -1)
                            ReturnValue=static_cast<PreHandlerState>(-1);
                        break;
                    }
                case sf::Keyboard::LAlt:
                    LAltPressed=true;
                    break;
                case sf::Keyboard::F4:
                    F4Pressed=true;
                    break;
                case sf::Keyboard::P:
                    ScreenShot();
                    break;
                default:
                    break;
            }
        }
        else if (Event.type==sf::Event::KeyReleased) {
            switch (Event.key.code) {
                case sf::Keyboard::Up:
                    UpPressed=false;
                    break;
                case sf::Keyboard::Down:
                    DownPressed=false;
                    break;
                case sf::Keyboard::Left:
                    LeftPressed=false;
                    break;
                case sf::Keyboard::Right:
                    RightPressed=false;
                    break;
                case sf::Keyboard::LShift:
                    ShiftPressed=false;
                    break;
                case sf::Keyboard::Z:
                    ZPressed=false;
                    break;
                case sf::Keyboard::X:
                    XPressed=false;
                    break;
                case sf::Keyboard::C:
                    CPressed=false;
                    break;
                case sf::Keyboard::LAlt:
                    LAltPressed=false;
                    break;
                case sf::Keyboard::F4:
                    F4Pressed=false;
                    break;
                default:
                    break;
            }
        }
        else if (Event.type==sf::Event::Closed)
            CrossPressed=true;
    }

    LevelBossBackgroundSprite.move(0,ceil(160.f*FrameTime));
    if (LevelBossBackgroundSprite.getPosition().y>25)
        LevelBossBackgroundSprite.setPosition(LevelBossBackgroundSprite.getPosition().x, 25);
    return ReturnValue;
}

void GameEngine::PostDisplayer(std::vector<std::pair<std::string, Speaker> > &DList) { //DList=DialogueList
    sf::Text MsgText; //Current text to be displayed

    //Alpha value for message box, text and portraits
    unsigned short alpha;
    if (PastTime > 3) alpha=255;
    else alpha=85*PastTime;

    if (DList.size() > 0)  { //If there is text to be displayed
        MsgBoxSprite.setColor(sf::Color(255,255,255,alpha));
        MsgText.setFont(Font[TUFFY]);
        MsgText.setColor(sf::Color(0,0,0,alpha));
        MsgText.setString(DList.back().first);
        MsgText.setCharacterSize(20);
        MsgText.setPosition(50,465);
        if (DList.back().second==LEFT_TALKING) { //The player is talking
            MsgBoxSprite.setScale(1.f,1.f);
            PlayerPortraitSprite.setColor(sf::Color(255,255,255,255));
            BossPortraitSprite.setColor(sf::Color(128,128,128,255));
        }
        else if (DList.back().second==RIGHT_TALKING) { //The boss is talking
            MsgBoxSprite.setScale(-1.f,1.f);
            PlayerPortraitSprite.setColor(sf::Color(128,128,128,255));
            BossPortraitSprite.setColor(sf::Color(255,255,255,255));
        }
        else { //Neither the player nor the boss are talking
            MsgBoxSprite.setScale(1.f,1.f);
            PlayerPortraitSprite.setColor(sf::Color(128,128,128,255));
            BossPortraitSprite.setColor(sf::Color(128,128,128,255));
        }
    }
    else { //No more text to be displayed - Head for the battle!
        alpha=255-alpha; //Disappearing sprites
        sf::Color Color(255,255,255,alpha
                        );
        PlayerPortraitSprite.setColor(Color);
        BossPortraitSprite.setColor(Color);
        MsgBoxSprite.setColor(Color);
        MsgText.setColor(Color);
    }

    glDisable(GL_SCISSOR_TEST);
    if (DList.size()>0) { //Speaker covers the other
        if (DList.back().second==RIGHT_TALKING) {
            MainWindow.draw(PlayerPortraitSprite);
            MainWindow.draw(BossPortraitSprite);
        }
        else {
            MainWindow.draw(BossPortraitSprite);
            MainWindow.draw(PlayerPortraitSprite);
        }
    }
    else {
        MainWindow.draw(BossPortraitSprite);
        MainWindow.draw(PlayerPortraitSprite);
    }
    MainWindow.draw(MsgBoxSprite);
    MainWindow.draw(MsgText);
}

GameEngine::~GameEngine() {
    if (AudioHandle!=nullptr)
        delete AudioHandle;
    if (Player!=nullptr)
        delete Player;
    if (LevelBoss!=nullptr) {
        for (unsigned i=0; i<LevelBoss->LifeBars.size(); i++)
            delete LevelBoss->LifeBars.at(i);
        for (unsigned i=0; i<LevelBoss->Bullets.size(); i++)
            delete LevelBoss->Bullets.at(i);
        delete LevelBoss;
    }
    for (unsigned i=0; i<Enemies.size(); i++)
        delete Enemies.at(i);
    for (unsigned i=0; i<PlayerBullets.size(); i++)
        delete PlayerBullets.at(i);
    for (unsigned i=0; i<EnemyBullets.size(); i++)
        delete EnemyBullets.at(i);
}

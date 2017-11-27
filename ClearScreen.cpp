#include "ClearScreen.h"
#include "Global.h"

#include <fstream>
#include <sstream>
#include <iomanip>

int LevelClearScreen(GameEngine* engine_pointer) {
//Setting up all the strings
    sf::RectangleShape Background;
        Background.setSize(sf::Vector2f(800,600));
        Background.setFillColor(sf::Color(102,0,0,255));
    sf::Text LevelCompleted;
        LevelCompleted.setFont(Font[TUFFY]);
        LevelCompleted.setString("Level Completed!");
        LevelCompleted.setCharacterSize(70);
        LevelCompleted.setOrigin(LevelCompleted.getLocalBounds().width/2, 0); //X is centered, Y is still normal
        LevelCompleted.setPosition(400,30);
        LevelCompleted.setFillColor(sf::Color(255, 255, 53, 0));
    sf::Text TextStrings[3];
        for (short i=0; i<3; i++) {
            TextStrings[i].setFont(Font[TUFFY]);
            TextStrings[i].setCharacterSize(55);
            TextStrings[i].setPosition(40,170+70*i);
            TextStrings[i].setFillColor(sf::Color(192,192,192,0));
        }
        TextStrings[0].setString("Base Score:");
        TextStrings[1].setString("Level Bonus:");
        TextStrings[2].setString("Graze Bonus:");
    sf::Text ScoreStrings[3];
        long score;
        std::string scorestring;
        std::stringstream scorestream;
            //First string
            score=engine_pointer->Score;
            scorestream << score;
            scorestring=scorestream.str();
            ScoreStrings[0].setString(scorestring);
            //Second string
            unsigned levelscore=0;
            switch (engine_pointer->CurrentLevel) {
                case LEVEL_ONE: levelscore=100000; break;
                case LEVEL_TWO: levelscore=200000; break;
                case LEVEL_THREE: levelscore=300000; break;
                case LEVEL_FOUR: levelscore=400000; break;
                case LEVEL_FIVE: levelscore=500000; break;
                case LEVEL_SIX: levelscore=600000; break;
                case LEVEL_SEVEN: levelscore=700000; break;
                case LEVEL_EXTRA: levelscore=1500000; break;
                default: break;
            }
            scorestream.clear();
            scorestream.str(std::string());
            scorestream << levelscore;
            scorestring=scorestream.str();
            ScoreStrings[1].setString(scorestring);
            //Third string
            scorestream.clear();
            scorestream.str(std::string());
            scorestream<<"x"<<int(1+engine_pointer->Graze/1000) <<".";
            if (engine_pointer->Graze%1000<100)
                scorestream<<"0";
            if (engine_pointer->Graze%1000<10)
                scorestream<<"0";
            scorestream<<int(engine_pointer->Graze%1000);
            scorestring=scorestream.str();
            ScoreStrings[2].setString(scorestring);
        for (short i=0; i<3; i++) {
            ScoreStrings[i].setFont(Font[TUFFY]);
            ScoreStrings[i].setCharacterSize(55);
            ScoreStrings[i].setOrigin(ScoreStrings[i].getLocalBounds().width, 0);
            ScoreStrings[i].setPosition(760, 170+70*i);
            ScoreStrings[i].setFillColor(sf::Color(192,192,192,0));
        }
    engine_pointer->Score=engine_pointer->Score+levelscore*(1.0+double(engine_pointer->Graze)/1000.0);
    engine_pointer->Score-=engine_pointer->Score%10;
    sf::Text FinalTextString;
        FinalTextString.setFont(Font[TUFFY]);
        FinalTextString.setString("Total Score:");
        FinalTextString.setPosition(40, 450);
        FinalTextString.setCharacterSize(55);
        FinalTextString.setFillColor(sf::Color(192,192,192,255));
    sf::Text FinalScoreString;
        scorestream.clear();
        scorestream.str(std::string());
        scorestream<<engine_pointer->Score;
        scorestring=scorestream.str();
        FinalScoreString.setFont(Font[TUFFY]);
        FinalScoreString.setString(scorestring);
        FinalScoreString.setCharacterSize(55);
        FinalScoreString.setOrigin(FinalScoreString.getLocalBounds().width, 0);
        FinalScoreString.setPosition(760, 450);
        FinalScoreString.setFillColor(sf::Color(192,192,192,255));
    sf::Text ClickMessage;
        ClickMessage.setFont(Font[TUFFY]);
        ClickMessage.setString("Press Z to continue");
        ClickMessage.setCharacterSize(30);
        ClickMessage.setOrigin(ClickMessage.getLocalBounds().width, 0);
        ClickMessage.setPosition(760,540);
        ClickMessage.setFillColor(sf::Color(255,255,255,0));
    engine_pointer->PastTime=0;
    float time=0;
    unsigned alpha=0;
    //The screen becomes bordeaux
    sf::Clock Clock;
    while (engine_pointer->PastTime<=1.2) {
        time=Clock.restart().asSeconds();
        if (time>0.2)
            time=0.2;
        engine_pointer->PastTime+=time;
        if (engine_pointer->PastTime<1.2) {
            alpha=212.5*engine_pointer->PastTime;
            if (alpha>255)
                alpha=255;
            Background.setFillColor(sf::Color(104,0,10,alpha));
            LevelCompleted.setColor(sf::Color(255, 255, 53, alpha));
        }
        else {
            Background.setFillColor(sf::Color(104,0,10,255));
            LevelCompleted.setColor(sf::Color(255, 255, 53, 255));
        }
        while (MainWindow.pollEvent(Event)) {
            if (Event.type==sf::Event::KeyPressed) {
                switch (Event.key.code) {
                    case sf::Keyboard::LAlt:
                        engine_pointer->LAltPressed=true;
                        break;
                    case sf::Keyboard::F4:
                        engine_pointer->F4Pressed=true;
                        break;
                    case sf::Keyboard::P:
                        engine_pointer->ScreenShot();
                        break;
                    default:
                        break;
                }
            }
            else if (Event.type==sf::Event::KeyReleased) {
                switch (Event.key.code) {
                    case sf::Keyboard::LAlt:
                        engine_pointer->LAltPressed=false;
                        break;
                    case sf::Keyboard::F4:
                        engine_pointer->F4Pressed=false;
                        break;
                    default:
                        break;
                }
            }
            else if (Event.type==sf::Event::Closed)
                engine_pointer->CrossPressed=true;
        }
        CHECK_EXIT();
        MainWindow.clear();
        MainWindow.draw(Background);
        MainWindow.draw(LevelCompleted);
        MainWindow.display();
    }
    LevelCompleted.setColor(sf::Color(255, 255, 53, 255));
    //Writings appears, one after another
    for (short i=0; i<3; i++) {
        engine_pointer->PastTime=0;
        while (engine_pointer->PastTime<=1) {
            while (MainWindow.pollEvent(Event)) {
                if (Event.type==sf::Event::KeyPressed) {
                    switch (Event.key.code) {
                        case sf::Keyboard::LAlt:
                            engine_pointer->LAltPressed=true;
                            break;
                        case sf::Keyboard::F4:
                            engine_pointer->F4Pressed=true;
                            break;
                        case sf::Keyboard::P:
                            engine_pointer->ScreenShot();
                            break;
                        default:
                            break;
                    }
                }
                else if (Event.type==sf::Event::KeyReleased) {
                    switch (Event.key.code) {
                        case sf::Keyboard::LAlt:
                            engine_pointer->LAltPressed=false;
                            break;
                        case sf::Keyboard::F4:
                            engine_pointer->F4Pressed=false;
                            break;
                        default:
                            break;
                    }
                }
                else if (Event.type==sf::Event::Closed)
                    engine_pointer->CrossPressed=true;
            }
            CHECK_EXIT();
            time=Clock.restart().asSeconds();
            if (time>0.2)
                time=0.2;
            engine_pointer->PastTime+=time;
            alpha=255*engine_pointer->PastTime;
            if (alpha>255)
                alpha=255;
            TextStrings[i].setFillColor(sf::Color(192,192,192,alpha));
            ScoreStrings[i].setFillColor(sf::Color(192,192,192,alpha));
            MainWindow.clear();
            MainWindow.draw(Background);
            MainWindow.draw(LevelCompleted);
            for (short j=0; j<3;  j++) {
                MainWindow.draw(TextStrings[j]);
                MainWindow.draw(ScoreStrings[j]);
            }
            MainWindow.display();
            sf::sleep(sf::milliseconds(17));
        }
        TextStrings[i].setColor(sf::Color(192,192,192,255));
        ScoreStrings[i].setColor(sf::Color(192,192,192,255));
    }
    if (engine_pointer->ScoreRewarder.CheckReward()) {
        engine_pointer->Items.GainLife();
    }
    //Last writings
    engine_pointer->PastTime=0;
    while (engine_pointer->PastTime<1.5) {
        while (MainWindow.pollEvent(Event)) {
            if (Event.type==sf::Event::KeyPressed) {
                switch (Event.key.code) {
                    case sf::Keyboard::LAlt:
                        engine_pointer->LAltPressed=true;
                        break;
                    case sf::Keyboard::F4:
                        engine_pointer->F4Pressed=true;
                        break;
                    case sf::Keyboard::P:
                        engine_pointer->ScreenShot();
                        break;
                    default:
                        break;
                }
            }
            else if (Event.type==sf::Event::KeyReleased) {
                switch (Event.key.code) {
                    case sf::Keyboard::LAlt:
                        engine_pointer->LAltPressed=false;
                        break;
                    case sf::Keyboard::F4:
                        engine_pointer->F4Pressed=false;
                        break;
                    default:
                        break;
                }
            }
            else if (Event.type==sf::Event::Closed)
                engine_pointer->CrossPressed=true;
        }
        CHECK_EXIT();
        time+=Clock.restart().asSeconds();
        if (time>0.2)
            time=0.2;
        engine_pointer->PastTime+=time;
        if (engine_pointer->PastTime<1) {
            alpha=255*engine_pointer->PastTime;
            if (alpha>255)
                alpha=255;
            FinalTextString.setColor(sf::Color(192,192,192,alpha));
            FinalScoreString.setColor(sf::Color(192,192,192,alpha));
        }
        else {
            FinalTextString.setColor(sf::Color(192,192,192,255));
            FinalScoreString.setColor(sf::Color(192,192,192,255));
        }
        MainWindow.draw(Background);
        MainWindow.draw(LevelCompleted);
        for (int i=0; i<3; i++) {
            MainWindow.draw(TextStrings[i]);
            MainWindow.draw(ScoreStrings[i]);
        }
        MainWindow.draw(FinalTextString);
        MainWindow.draw(FinalScoreString);
        MainWindow.display();
    }
    //Press Z to continue
    while (MainWindow.pollEvent(Event)) {}
    engine_pointer->ZPressed=false;
    engine_pointer->PastTime=0;
    while (engine_pointer->ZPressed==false) {
        while (MainWindow.pollEvent(Event)) {
            if (Event.type==sf::Event::KeyPressed) {
                switch (Event.key.code) {
                    case sf::Keyboard::Z:
                        engine_pointer->ZPressed=true;
                    case sf::Keyboard::LAlt:
                        engine_pointer->LAltPressed=true;
                        break;
                    case sf::Keyboard::F4:
                        engine_pointer->F4Pressed=true;
                        break;
                    case sf::Keyboard::P:
                        engine_pointer->ScreenShot();
                    default:
                        break;
                }
            }
            else if (Event.type==sf::Event::KeyReleased) {
                switch (Event.key.code) {
                    case sf::Keyboard::LAlt:
                        engine_pointer->LAltPressed=false;
                        break;
                    case sf::Keyboard::F4:
                        engine_pointer->F4Pressed=false;
                        break;
                    default:
                        break;
                }
            }
            else if (Event.type==sf::Event::Closed)
                engine_pointer->CrossPressed=true;
        }
        CHECK_EXIT();
        time+=Clock.restart().asSeconds();
        if (time>0.2)
            time=0.2;
        engine_pointer->PastTime+=time;
        if (engine_pointer->PastTime<2) {
            alpha=127.5*engine_pointer->PastTime;
            if (alpha>255)
                alpha=255;
            ClickMessage.setColor(sf::Color(255,255,255,engine_pointer->PastTime*127.5));
        }
        else
            ClickMessage.setColor(sf::Color(255,255,255,255));
        MainWindow.draw(Background);
        MainWindow.draw(LevelCompleted);
        for (int i=0; i<3; i++) {
            MainWindow.draw(TextStrings[i]);
            MainWindow.draw(ScoreStrings[i]);
        }
        MainWindow.draw(FinalTextString);
        MainWindow.draw(FinalScoreString);
        MainWindow.draw(ClickMessage);
        MainWindow.display();
        sf::sleep(sf::milliseconds(17));
    }
    return 0;
}

int GameClearScreen(GameEngine* engine_pointer) {
//Setting up all the strings
    sf::RectangleShape Background;
        Background.setSize(sf::Vector2f(800,600));
        Background.setFillColor(sf::Color(102,0,0,255));
    sf::Text LevelCompleted;
        LevelCompleted.setFont(Font[TUFFY]);
        LevelCompleted.setString("Game Clear! Congratulations!");
        LevelCompleted.setCharacterSize(60);
        LevelCompleted.setOrigin(LevelCompleted.getLocalBounds().width/2, 0); //X is centered, Y is still normal
        LevelCompleted.setPosition(400,45);
        LevelCompleted.setColor(sf::Color(255, 255, 53, 0));
    sf::Text TextStrings[3];
        for (short i=0; i<3; i++) {
            TextStrings[i].setFont(Font[TUFFY]);
            TextStrings[i].setCharacterSize(55);
            TextStrings[i].setPosition(40,170+70*i);
            TextStrings[i].setColor(sf::Color(192,192,192,0));
        }
        TextStrings[0].setString("Base Score:");
        TextStrings[1].setString("Lives Bonus:");
        TextStrings[2].setString("Skill Bonus:");
    sf::Text ScoreStrings[3];
        long score;
        std::string scorestring;
        std::stringstream scorestream;
            //First string
            score=engine_pointer->Score;
            scorestream << score;
            scorestring=scorestream.str();
            ScoreStrings[0].setString(scorestring);
            //Second string
            unsigned livesscore=5000000*engine_pointer->Player->Lives;
            scorestream.clear();
            scorestream.str(std::string());
            scorestream << livesscore;
            scorestring=scorestream.str();
            ScoreStrings[1].setString(scorestring);
            //Third string
            unsigned bombsscore=500000*engine_pointer->Player->Lives;
            scorestream.clear();
            scorestream.str(std::string());
            scorestream<<bombsscore;
            scorestring=scorestream.str();
            ScoreStrings[2].setString(scorestring);
        for (short i=0; i<3; i++) {
            ScoreStrings[i].setFont(Font[TUFFY]);
            ScoreStrings[i].setCharacterSize(55);
            ScoreStrings[i].setOrigin(ScoreStrings[i].getLocalBounds().width, 0);
            ScoreStrings[i].setPosition(760, 170+70*i);
            ScoreStrings[i].setColor(sf::Color(192,192,192,0));
        }
    engine_pointer->Score=engine_pointer->Score+livesscore+bombsscore;
    engine_pointer->Score-=engine_pointer->Score%10;
    sf::Text FinalTextString;
        FinalTextString.setFont(Font[TUFFY]);
        FinalTextString.setString("Total Score:");
        FinalTextString.setPosition(40, 450);
        FinalTextString.setCharacterSize(55);
        FinalTextString.setColor(sf::Color(192,192,192,255));
    sf::Text FinalScoreString;
        scorestream.clear();
        scorestream.str(std::string());
        scorestream<<engine_pointer->Score;
        scorestring=scorestream.str();
        FinalScoreString.setFont(Font[TUFFY]);
        FinalScoreString.setString(scorestring);
        FinalScoreString.setCharacterSize(55);
        FinalScoreString.setOrigin(FinalScoreString.getLocalBounds().width, 0);
        FinalScoreString.setPosition(760, 450);
        FinalScoreString.setColor(sf::Color(192,192,192,255));
    sf::Text ClickMessage;
        ClickMessage.setFont(Font[TUFFY]);
        ClickMessage.setString("Press Z to continue");
        ClickMessage.setCharacterSize(30);
        ClickMessage.setOrigin(ClickMessage.getLocalBounds().width, 0);
        ClickMessage.setPosition(760,540);
        ClickMessage.setColor(sf::Color(255,255,255,0));
    engine_pointer->PastTime=0;
    float time=0;
    unsigned alpha=0;
    //The screen becomes violet
    sf::Clock Clock;
    while (engine_pointer->PastTime<=1.2) {
        time=Clock.restart().asSeconds();
        if (time>0.2)
            time=0.2;
        engine_pointer->PastTime+=time;
        if (engine_pointer->PastTime<1.2) {
            alpha=212.5*engine_pointer->PastTime;
            if (alpha>255)
                alpha=255;
            Background.setFillColor(sf::Color( 64,   0, 128, alpha));
            LevelCompleted.setColor(sf::Color(255, 255,  53, alpha));
        }
        else {
            Background.setFillColor(sf::Color( 64,   0, 128, 255));
            LevelCompleted.setColor(sf::Color(255, 255,  53, 255));
        }
        while (MainWindow.pollEvent(Event)) {
            if (Event.type==sf::Event::KeyPressed) {
                switch (Event.key.code) {
                    case sf::Keyboard::LAlt:
                        engine_pointer->LAltPressed=true;
                        break;
                    case sf::Keyboard::F4:
                        engine_pointer->F4Pressed=true;
                        break;
                    case sf::Keyboard::P:
                        engine_pointer->ScreenShot();
                        break;
                    default:
                        break;
                }
            }
            else if (Event.type==sf::Event::KeyReleased) {
                switch (Event.key.code) {
                    case sf::Keyboard::LAlt:
                        engine_pointer->LAltPressed=false;
                        break;
                    case sf::Keyboard::F4:
                        engine_pointer->F4Pressed=false;
                        break;
                    default:
                        break;
                }
            }
            else if (Event.type==sf::Event::Closed)
                engine_pointer->CrossPressed=true;
        }
        CHECK_EXIT();
        MainWindow.clear();
        MainWindow.draw(Background);
        MainWindow.draw(LevelCompleted);
        MainWindow.display();
    }
    LevelCompleted.setColor(sf::Color(255, 255, 53, 255));
    //Writings appears, one after another
    for (short i=0; i<3; i++) {
        engine_pointer->PastTime=0;
        while (engine_pointer->PastTime<=1) {
            while (MainWindow.pollEvent(Event)) {
                if (Event.type==sf::Event::KeyPressed) {
                    switch (Event.key.code) {
                        case sf::Keyboard::LAlt:
                            engine_pointer->LAltPressed=true;
                            break;
                        case sf::Keyboard::F4:
                            engine_pointer->F4Pressed=true;
                            break;
                        case sf::Keyboard::P:
                            engine_pointer->ScreenShot();
                            break;
                        default:
                            break;
                    }
                }
                else if (Event.type==sf::Event::KeyReleased) {
                    switch (Event.key.code) {
                        case sf::Keyboard::LAlt:
                            engine_pointer->LAltPressed=false;
                            break;
                        case sf::Keyboard::F4:
                            engine_pointer->F4Pressed=false;
                            break;
                        default:
                            break;
                    }
                }
                else if (Event.type==sf::Event::Closed)
                    engine_pointer->CrossPressed=true;
            }
            CHECK_EXIT();
            time=Clock.restart().asSeconds();
            if (time>0.2)
                time=0.2;
            engine_pointer->PastTime+=time;
            alpha=255*engine_pointer->PastTime;
            if (alpha>255)
                alpha=255;
            TextStrings[i].setColor(sf::Color(192,192,192,alpha));
            ScoreStrings[i].setColor(sf::Color(192,192,192,alpha));
            MainWindow.clear();
            MainWindow.draw(Background);
            MainWindow.draw(LevelCompleted);
            for (short j=0; j<3;  j++) {
                MainWindow.draw(TextStrings[j]);
                MainWindow.draw(ScoreStrings[j]);
            }
            MainWindow.display();
            sf::sleep(sf::milliseconds(17));
        }
        TextStrings[i].setColor(sf::Color(192,192,192,255));
        ScoreStrings[i].setColor(sf::Color(192,192,192,255));
    }
    if (engine_pointer->ScoreRewarder.CheckReward()) {
        engine_pointer->Items.GainLife();
    }
    //Last writings
    engine_pointer->PastTime=0;
    while (engine_pointer->PastTime<1.5) {
        while (MainWindow.pollEvent(Event)) {
            if (Event.type==sf::Event::KeyPressed) {
                switch (Event.key.code) {
                    case sf::Keyboard::LAlt:
                        engine_pointer->LAltPressed=true;
                        break;
                    case sf::Keyboard::F4:
                        engine_pointer->F4Pressed=true;
                        break;
                    case sf::Keyboard::P:
                        engine_pointer->ScreenShot();
                        break;
                    default:
                        break;
                }
            }
            else if (Event.type==sf::Event::KeyReleased) {
                switch (Event.key.code) {
                    case sf::Keyboard::LAlt:
                        engine_pointer->LAltPressed=false;
                        break;
                    case sf::Keyboard::F4:
                        engine_pointer->F4Pressed=false;
                        break;
                    default:
                        break;
                }
            }
            else if (Event.type==sf::Event::Closed)
                engine_pointer->CrossPressed=true;
        }
        CHECK_EXIT();
        time+=Clock.restart().asSeconds();
        if (time>0.2)
            time=0.2;
        engine_pointer->PastTime+=time;
        if (engine_pointer->PastTime<1) {
            alpha=255*engine_pointer->PastTime;
            if (alpha>255)
                alpha=255;
            FinalTextString.setColor(sf::Color(192,192,192,alpha));
            FinalScoreString.setColor(sf::Color(192,192,192,alpha));
        }
        else {
            FinalTextString.setColor(sf::Color(192,192,192,255));
            FinalScoreString.setColor(sf::Color(192,192,192,255));
        }
        MainWindow.draw(Background);
        MainWindow.draw(LevelCompleted);
        for (int i=0; i<3; i++) {
            MainWindow.draw(TextStrings[i]);
            MainWindow.draw(ScoreStrings[i]);
        }
        MainWindow.draw(FinalTextString);
        MainWindow.draw(FinalScoreString);
        MainWindow.display();
    }
    //Press Z to continue
    while (MainWindow.pollEvent(Event)) {}
    engine_pointer->ZPressed=false;
    engine_pointer->PastTime=0;
    while (engine_pointer->ZPressed==false) {
        while (MainWindow.pollEvent(Event)) {
            if (Event.type==sf::Event::KeyPressed) {
                switch (Event.key.code) {
                    case sf::Keyboard::Z:
                        engine_pointer->ZPressed=true;
                    case sf::Keyboard::LAlt:
                        engine_pointer->LAltPressed=true;
                        break;
                    case sf::Keyboard::F4:
                        engine_pointer->F4Pressed=true;
                        break;
                    case sf::Keyboard::P:
                        engine_pointer->ScreenShot();
                    default:
                        break;
                }
            }
            else if (Event.type==sf::Event::KeyReleased) {
                switch (Event.key.code) {
                    case sf::Keyboard::LAlt:
                        engine_pointer->LAltPressed=false;
                        break;
                    case sf::Keyboard::F4:
                        engine_pointer->F4Pressed=false;
                        break;
                    default:
                        break;
                }
            }
            else if (Event.type==sf::Event::Closed)
                engine_pointer->CrossPressed=true;
        }
        CHECK_EXIT();
        time+=Clock.restart().asSeconds();
        if (time>0.2)
            time=0.2;
        engine_pointer->PastTime+=time;
        if (engine_pointer->PastTime<2) {
            alpha=127.5*engine_pointer->PastTime;
            if (alpha>255)
                alpha=255;
            ClickMessage.setColor(sf::Color(255,255,255,engine_pointer->PastTime*127.5));
        }
        else
            ClickMessage.setColor(sf::Color(255,255,255,255));
        MainWindow.draw(Background);
        MainWindow.draw(LevelCompleted);
        for (int i=0; i<3; i++) {
            MainWindow.draw(TextStrings[i]);
            MainWindow.draw(ScoreStrings[i]);
        }
        MainWindow.draw(FinalTextString);
        MainWindow.draw(FinalScoreString);
        MainWindow.draw(ClickMessage);
        MainWindow.display();
        sf::sleep(sf::milliseconds(17));
    }
    return 0;
}

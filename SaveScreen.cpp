#include "Global.h"
#include "GameEngine.h"
#include "DataStruct.h"

#define SET_COLOR() { \
    color=PastTime*510; \
    if (color>255) { \
        color=255; \
        time=0.5; \
    } \
    for (int i=0; i<69; i++) \
        StringPtr[i]->setColor(sf::Color(StringPtr[i]->getColor().r, StringPtr[i]->getColor().g, StringPtr[i]->getColor().b, color)); \
    Rect.setFillColor(sf::Color(128,0,128,color)); \
}

#define DRAW() { \
    SET_COLOR(); \
    MainWindow.clear(sf::Color(0, 0, 0)); \
    MainWindow.draw(MainBackgroundSprite); \
    MainWindow.draw(Rect); \
    for(int i=0; i<69; i++) \
        MainWindow.draw(*StringPtr[i]); \
    MainWindow.display(); \
}

int GameEngine::SaveScreen(void) {
    std::uint8_t (*Names)[10][10]=NULL;
    std::uint64_t (*Scores)[10]=NULL;
    switch (Mode) {
        case PRACTICE_MODE:
            return 0; //No savedata for practice mode
            break;
        case STORY_MODE:
            if (Score<=Data.Score[9])
                return 0;
            else {
                Names=&Data.Name;
                Scores=&Data.Score;
            }
            break;
        case FINAL_MODE:
            if (Score<=Data.FinalScore[9])
                return 0;
            else {
                Names=&Data.FinalName;
                Scores=&Data.FinalScore;
            }
            break;
        case EXTRA_MODE:
            if (Score<=Data.ExtraScore[9])
                return 0;
            else {
                Names=&Data.ExtraName;
                Scores=&Data.ExtraScore;
            }
            break;
        default:
            break;
    }

    //Not returning yet = You have to save data

    //Your position on classification
    short Position=1;
    for (short i=0; i<9; i++)
        if (Score<=Scores[0][i])
            Position++;
        else
            break;

    for (short i=9; i>=Position; --i) {
        Scores[0][i]=Scores[0][i-1];
        for (short j=0; j<10; j++)
            Names[0][i][j]=Names[0][i-1][j];
    }
    Scores[0][Position-1]=Score;
    for (short i=0; i<10; ++i)
        Names[0][Position-1][i]='-';

    //Strings
    //Title
    sf::Text MsgString;
    MsgString.setFont(Font[TUFFY]);
    MsgString.setString("Insert your name");
    MsgString.setCharacterSize(70);
    MsgString.setColor(sf::Color(128,0,128));
    MsgString.setOrigin((MsgString.getLocalBounds().width-1)/2, 0);
    MsgString.setPosition(400,70);

    //Position
    sf::Text PositionString;
    PositionString.setFont(Font[TUFFY]);
    std::string pos;
    switch (Position) {
        case 1: pos="01."; break;
        case 2: pos="02."; break;
        case 3: pos="03."; break;
        case 4: pos="04."; break;
        case 5: pos="05."; break;
        case 6: pos="06."; break;
        case 7: pos="07."; break;
        case 8: pos="08."; break;
        case 9: pos="09."; break;
        case 10: pos="10."; break;
    }
    PositionString.setString(pos);
    PositionString.setCharacterSize(30);
    PositionString.setColor(sf::Color(224, 255, 223, 0));
    PositionString.setOrigin(0,0);
    PositionString.setPosition(140, 220);

    //NameString
    std::string namestring;
    for (short i=0; i<10; ++i) {
        namestring+=Names[0][Position-1][i];
    }
    //namestring; //???
    sf::Text NameString;
    NameString.setFont(Font[TUFFY]);
    NameString.setString(namestring);
    NameString.setCharacterSize(30);
    NameString.setColor(sf::Color(224, 255, 223, 0));
    NameString.setOrigin(NameString.getLocalBounds().width/2,0);
    NameString.setPosition(310, 220);

    //ScoreString
    unsigned long score=Score;
    char ch_arr[11];
    for (short i=9; i>=0; i--) {
        ch_arr[i]=char((score%10)+48);
        score/=10;
    }
    ch_arr[10]='\0'; //???
    sf::Text LScoreString; //L stands for Local, otherwise it would refer to the Engine's one
    LScoreString.setFont(Font[TUFFY]);
    LScoreString.setString(std::string(ch_arr));
    LScoreString.setCharacterSize(30);
    LScoreString.setColor(sf::Color(224, 255, 223, 0));
    LScoreString.setOrigin(LScoreString.getLocalBounds().width-1, 0);
    LScoreString.setPosition(660, 220);

    //Letters
    sf::Text Character[64]; //Upper-case letters, Lower-case letters, 0-9 numbers, - and _
    for (unsigned short i=0; i<64; i++) {
        Character[i].setFont(Font[TUFFY]);
        Character[i].setCharacterSize(20);
        Character[i].setColor(sf::Color(224, 255, 223, 0));
        Character[i].setPosition(165.625+(31.25*(i%16)), 300+(35*int(i/16)));
    }
    for (unsigned short i=0; i<26; ++i)
        Character[i].setString(std::string(1, char(65+i))); //Upper-case letters
    for (unsigned short i=26; i<52; ++i)
        Character[i].setString(std::string(1, char(71+i))); //Lower-case letters
    for (unsigned short i=52; i<62; ++i)
        Character[i].setString(std::string(1, char(48-52+i))); //Numbers
    Character[62].setString(std::string(1, char(45))); //-
    Character[63].setString(std::string(1, char(95))); //_

    //Hint string
    sf::Text Hint;
    Hint.setFont(Font[TUFFY]);
    Hint.setString("Press Backspace to delete a character, or Enter to confirm");
    Hint.setCharacterSize(25);
    Hint.setColor(sf::Color(255,255,255));
    Hint.setOrigin(Hint.getLocalBounds().width-1, 0);
    Hint.setPosition(770,550);

    sf::Text *StringPtr[69]; //69 pointers
    StringPtr[0]=&MsgString;
    StringPtr[1]=&PositionString;
    StringPtr[2]=&NameString;
    StringPtr[3]=&LScoreString;
    StringPtr[4]=&Hint;
    for (short i=5; i<69; i++)
        StringPtr[i]=&Character[i-5];

    //sf::Shape Rect=sf::Shape::Rectangle(155.625,300,187.875,332,sf::Color(0, 0xA0, 0xE0));
    sf::RectangleShape Rect;
    Rect.setSize(sf::Vector2f(32.25f, 32.f));
    Rect.setPosition(155.625,300);
    Rect.setFillColor(sf::Color(128, 160, 128));

    double time=0;
    int color=0;
    int cursor=0; //Which letter will you write (array index - range 1-9)
    sf::Vector2<signed short> keypos(0,0); //Which letter is selected from the keyboard?
    PastTime=0;
    sf::Clock Clock;
    MainBackgroundSprite.setColor(sf::Color(64,0,64));
    bool InSaveMenu=true;
    while (InSaveMenu) {
        time=Clock.restart().asSeconds();
        if (time>0.2)
            time=0.2;
        PastTime+=time;
        while (MainWindow.pollEvent(Event)) {
            if (Event.type==sf::Event::KeyPressed) {
                switch (Event.key.code) {
                    case sf::Keyboard::LAlt: LAltPressed=true; break;
                    case sf::Keyboard::F4: F4Pressed=true; break;
                    case sf::Keyboard::P: ScreenShot(); break;
                    case sf::Keyboard::Up:
                        if (keypos.y!=0) {
                            Rect.move(0,-35);
                            --keypos.y;
                        }
                        else {
                            Rect.setPosition(Rect.getPosition().x, 105);
                            keypos.y=3;
                        }
                        break;
                    case sf::Keyboard::Down:
                        if (keypos.y!=3) {
                            Rect.move(0,35);
                            ++keypos.y;
                        }
                        else {
                            Rect.setPosition(Rect.getPosition().x, 0);
                            keypos.y=0;
                        }
                        break;
                    case sf::Keyboard::Left:
                        if (keypos.x!=0) {
                            Rect.move(-31.25,0);
                            keypos.x--;
                        }
                        else {
                            Rect.setPosition(468.75, Rect.getPosition().y);
                            keypos.x=15;
                        }
                        break;;
                    case sf::Keyboard::Right:
                        if (keypos.x!=15) {
                            Rect.move(31.25,0);
                            keypos.x++;
                        }
                        else {
                            Rect.setPosition(0, Rect.getPosition().y);
                            keypos.x=0;
                        }
                        break;
                    case sf::Keyboard::Z:
                        if (cursor!=10) {
                            Names[0][Position-1][cursor]=std::string(Character[(keypos.y*16)+keypos.x].getString()).at(0);
                            char name[11];
                            for (unsigned short i=0; i<10; i++)
                                name[i]=Names[0][Position-1][i];
                            name[10]='\0';
                            NameString.setString(name);
                            cursor++;
                        }
                        else {
                            InSaveMenu=false;
                        }
                        break;
                    case sf::Keyboard::BackSpace:
                        if (cursor!=0) {
                            cursor--;
                            Names[0][Position-1][cursor]='-';
                            char name[11];
                            for (unsigned short i=0; i<10; i++)
                                name[i]=Names[0][Position-1][i];
                            name[10]='\0';
                            NameString.setString(name);
                        }
                        break;
                    case sf::Keyboard::Return:
                        for (int i=cursor; i<10; i++)
                            Names[0][Position-1][i]=char(32);
                        InSaveMenu=false;
                        break;
                    default: break;
                }
            }
            else if (Event.type==sf::Event::KeyReleased) {
                switch (Event.key.code) {
                    case sf::Keyboard::LAlt: LAltPressed=false; break;
                    case sf::Keyboard::F4: F4Pressed=false; break;
                    default: break;
                }
            }
            else if (Event.type==sf::Event::Closed)
                CrossPressed=true;
        }
        CHECK_EXIT();

        Rect.setPosition(155.625+31.25*keypos.x, 300+35*keypos.y);
        DRAW();
        sf::sleep(sf::milliseconds(17));
    }

    WriteDataStruct(Data);
    InGame=false;
    return 0;
}

#undef SET_COLOR
#undef DRAW

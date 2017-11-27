#include <SFML/Graphics.hpp>
#include "Global.h"
#include "Credits.h"

int CreditsScreen(void) {
    //Title String
    sf::Text Title;
    Title.setFont(Font[PRINCEVALIANT]);
    Title.setColor(sf::Color(27,128,255,255));
    Title.setString("Credits");
    Title.setCharacterSize(80);
    Title.setOrigin(Title.getLocalBounds().width/2,0);
    Title.setPosition(400,20);

    //Roles
    sf::Text Roles[2];
    for (int i=0; i<2; ++i) {
        Roles[i].setFont(Font[PRINCEVALIANT]);
        Roles[i].setColor(sf::Color(255,215,0));
        Roles[i].setCharacterSize(60);
        Roles[i].setPosition(120,160+i*170);
    }
    Roles[0].setString("Programming");
    Roles[1].setString("Music / Sound Effects ");

    //Names
    sf::Text Names[2];
    for (int i=0; i<2; ++i) {
        Names[i].setFont(Font[PRINCEVALIANT]);
        Names[i].setColor(sf::Color(255,255,255));
        Names[i].setCharacterSize(60);
        Names[i].setString(i==0?"Michele Ferraro":"Brian Binning");
        Names[i].setOrigin(Names[i].getLocalBounds().width,0);
        Names[i].setPosition(680,240+i*170);
    }

    sf::Text Message;
    Message.setFont(Font[TUFFY]);
    Message.setColor(sf::Color(255,255,128,255));
    Message.setCharacterSize(20);
    Message.setPosition(510,540);
    Message.setString("X/Esc - Back to main menu");

    bool InRecordMenu=true;
    MainBackgroundSprite.setColor(sf::Color(0,0,128,255));
    while (InRecordMenu) {
        while (MainWindow.pollEvent(Event)) {
            if (Event.type==sf::Event::KeyPressed) {
                switch (Event.key.code) {
                    case sf::Keyboard::X:
                    case sf::Keyboard::Escape:
                        InRecordMenu=false;
                        Play(MENUCONFIRM);
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
        MainWindow.clear();

        //Draw the title and background
        MainWindow.draw(MainBackgroundSprite);
        MainWindow.draw(Title);

        //Roles and Names
        for (size_t i=0; i<2; ++i) {
            MainWindow.draw(Roles[i]);
            MainWindow.draw(Names[i]);
        }

        //Draw Message
        MainWindow.draw(Message);

        MainWindow.display();
    }
    MainBackgroundSprite.setColor(sf::Color(128,0,0,255));

    return 0;
}

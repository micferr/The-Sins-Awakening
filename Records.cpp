#include <SFML/Graphics.hpp>
#include "DataStruct.h"
#include "Global.h"
#include "Records.h"

int RecordScreen (void) {
    //Title string
    sf::Text Title[1/*3*/];
    for (int i=0; i<1/*3*/; i++) {
        Title[i].setFont(Font[PRINCEVALIANT]);
        Title[i].setColor(sf::Color(27,128,255,255));
        Title[i].setPosition(80, 20);
        Title[i].setCharacterSize(80);
    }

    Title[0].setString("High Scores");
    Title[0].setPosition(250,20);
    //Title[1].setText("Record Final");
    //Title[2].setText("Record Extra");

    //"Pos", "Giocatore" and "Punteggio" strings
    sf::Text Posizione, Giocatore, Punteggio;

    Posizione.setFont(Font[TUFFY]);
    Posizione.setColor(sf::Color(255,255,128,255));
    Posizione.setCharacterSize(30);
    Posizione.setPosition(90,130);
    Posizione.setString("Pos.");

    Giocatore.setFont(Font[TUFFY]);
    Giocatore.setColor(sf::Color(255,255,128,255));
    Giocatore.setCharacterSize(30);
    Giocatore.setPosition(280,130);
    Giocatore.setString("Player");

    Punteggio.setFont(Font[TUFFY]);
    Punteggio.setColor(sf::Color(255,255,128,255));
    Punteggio.setCharacterSize(30);
    Punteggio.setPosition(525,130);
    Punteggio.setString("Score");

    //Message String
    sf::Text Message;
    Message.setFont(Font[TUFFY]);
    Message.setColor(sf::Color(255,255,128,255));
    Message.setCharacterSize(20);
    Message.setPosition(510,540);
    std::string mess;
    std::string temp_mess="";//Z - Record Storia/Final"; //Saving from double hardcode of the same string
    if (Data.FinalUnlocked) mess=temp_mess+"";//"\n";
    if (Data.ExtraUnlocked) mess=temp_mess+"";//"Extra\n";
    mess+="X/Esc - Back to main menu";
    Message.setString(mess);

    //Position numbers' strings
    sf::Text Position[10];
    std::string pos[10]={"01.", "02.", "03.", "04.", "05.", "06.", "07.", "08.", "09.", "10."};
    for (int i=0; i<10; i++) {
        Position[i].setFont(Font[TUFFY]);
        Position[i].setString(pos[i]);
        Position[i].setColor(sf::Color(255,255,128,255));
        Position[i].setPosition(100,180+i*35);
        Position[i].setCharacterSize(25);
    }

    //Name strings
    sf::Text Names[/*3*/1][10];
    for (int i=0; i</*3*/1; i++) {
        for (int j=0; j<10; j++) {
            Names[i][j].setFont(Font[TUFFY]);
            Names[i][j].setColor(sf::Color(255,255,128,255));
            Names[i][j].setPosition(285,180+j*35);
            Names[i][j].setCharacterSize(25);
            char name[11];
            if (i==0) for (int k=0; k<10; k++) name[k]=Data.Name[j][k];
            else if (i==1) for (int k=0; k<10; k++) name[k]=Data.FinalName[j][k];
            else for (int k=0; k<10; k++)   name[k]=Data.ExtraName[j][k];
            name[10]='\0';
            Names[i][j].setString(name);
        }
    }

    //Points strings
    sf::Text Points[3][10];
    for (int i=0; i<3; i++) {
        for (int j=0; j<10; j++) {
            Points[i][j].setFont(Font[TUFFY]);
            Points[i][j].setColor(sf::Color(255,255,128,255));
            Points[i][j].setPosition(520,180+j*35);
            Points[i][j].setCharacterSize(25);
            char name[11];
            unsigned long num;
            if (i==0)
                num=Data.Score[j];
            else if (i==1)
                num=Data.FinalScore[j];
            else
                num=Data.ExtraScore[j];
            for (int k=9; k>=0; k--) {
                name[k]=(num%10)+48;
                num/=10;
            }
            name[10]='\0';
            Points[i][j].setString(name);
        }
    }

    //Loop
    bool InRecordMenu=true;
    short Screen=0;
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
                    case sf::Keyboard::Z:
                        if (Data.FinalUnlocked) {
                            Play(MENUSCROLL);
                            ++Screen;
                            if (Data.ExtraUnlocked)
                                Screen%=3;
                            else
                                Screen%=2;
                        }
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
        MainWindow.draw(Title[Screen]);

        //Draw Fields' strings
        MainWindow.draw(Posizione);
        MainWindow.draw(Giocatore);
        MainWindow.draw(Punteggio);

        //Draw position numbers, players' names and scores
        for (int i=0; i<10; i++) {
            MainWindow.draw(Position[i]);
            MainWindow.draw(Names[Screen][i]);
            MainWindow.draw(Points[Screen][i]);
        }

        //Draw Message
        MainWindow.draw(Message);

        MainWindow.display();
        sf::sleep(sf::milliseconds(17));
    }
    MainBackgroundSprite.setColor(sf::Color(128,0,0,255));

    return 0;
}

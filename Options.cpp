#include <SFML/Graphics.hpp>
#include "DataStruct.h"
#include "Global.h"
#include "Options.h"

int OptionsScreen(void) {
    //Title string
    sf::Text Title;
    Title.setFont(Font[PRINCEVALIANT]);
    Title.setString("Options");
    Title.setCharacterSize(80);
    Title.setColor(sf::Color(27,128,255,255));
    Title.setOrigin(Title.getGlobalBounds().width/2,0);
    Title.setPosition(400,20);

    //Options' Strings
    sf::Text MaxLives, BGMVolume, SEVolume;

    MaxLives.setFont(Font[PRINCEVALIANT]);
    MaxLives.setPosition(20,150);
    MaxLives.setCharacterSize(60);
    MaxLives.setString("Starting lives");

    BGMVolume.setFont(Font[PRINCEVALIANT]);
    BGMVolume.setPosition(20,250);
    BGMVolume.setCharacterSize(60);
    BGMVolume.setString("Music Volume");

    SEVolume.setFont(Font[PRINCEVALIANT]);
    SEVolume.setPosition(20,350);
    SEVolume.setCharacterSize(60);
    SEVolume.setString("SFX Volume");

    //"Torna al menu principale" string
    sf::Text Exit;
    Exit.setFont(Font[PRINCEVALIANT]);
    Exit.setPosition(20,490);
    Exit.setCharacterSize(60);
    Exit.setString("Back to main menu");

    //Values strings
    sf::Text Lives[5], BGM, SEV;

    for (int i=0; i<5; i++) {
        Lives[i].setFont(Font[PRINCEVALIANT]);
        Lives[i].setPosition(520+i*50, 150);
        Lives[i].setCharacterSize(60);
    }
    Lives[0].setString("1");
    Lives[1].setString("2");
    Lives[2].setString("3");
    Lives[3].setString("4");
    Lives[4].setString("5");

    BGM.setFont(Font[PRINCEVALIANT]);
    BGM.setPosition(630, 250);
    BGM.setCharacterSize(60);

    SEV.setFont(Font[PRINCEVALIANT]);
    SEV.setPosition(630,350);
    SEV.setCharacterSize(60);

    //Loop
    short Selected=1;
    bool InOptionsMenu=true;
    MainBackgroundSprite.setColor(sf::Color(0,0,128,255));
    while (InOptionsMenu) {
        while (MainWindow.pollEvent(Event)) {
            if (Event.type==sf::Event::KeyPressed) {
                switch (Event.key.code) {
                    case sf::Keyboard::Up:
                        if (Selected > 1) Selected--;
                        else Selected=4;
                        Play(MENUSCROLL);
                        break;
                    case sf::Keyboard::Down:
                        if (Selected < 4) Selected++;
                        else Selected=1;
                        Play(MENUSCROLL);
                        break;
                    case sf::Keyboard::Left:
                        switch (Selected) {
                            case 1:
                                if (Data.MaxLives > 1) Data.MaxLives--;
                                break;
                            case 2:
                                if (Data.BGMVolume > 0) Data.BGMVolume-=5;
                                SetMusicVolume(Data.BGMVolume);
                                break;
                            case 3:
                                if (Data.SEVolume > 0) Data.SEVolume-=5;
                                SetSEVolume(Data.SEVolume);
                                break;
                            default:
                                break;
                        }
                        Play(MENUSCROLL);
                        break;
                    case sf::Keyboard::Right:
                        switch (Selected) {
                            case 1:
                                if (Data.MaxLives < 5) Data.MaxLives++;
                                break;
                            case 2:
                                if (Data.BGMVolume < 100) Data.BGMVolume+=5;
                                Engine.AudioHandle->SetMusicVolume(Data.BGMVolume);
                                break;
                            case 3:
                                if (Data.SEVolume < 100) Data.SEVolume+=5;
                                Engine.AudioHandle->SetSEVolume(Data.SEVolume);
                                break;
                            default:
                                break;
                        }
                        Play(MENUSCROLL);
                        break;
                    case sf::Keyboard::X:
                    case sf::Keyboard::Escape:
                        if (Selected!=4) {
                            Selected=4;
                            Play(MENUSCROLL);
                            break;
                        }
                        //No break -> else case Z
                    case sf::Keyboard::Z:
                        if (Selected==4) {
                            InOptionsMenu=false;
                            Play(MENUCONFIRM);
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
                    default: break;
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

        //Coloring writings
        MaxLives.setColor(sf::Color((Selected==1)*127+128, (Selected==1)*127+128, (Selected==1)*127+128, 255));
        BGMVolume.setColor(sf::Color((Selected==2)*127+128, (Selected==2)*127+128, (Selected==2)*127+128, 255));
        SEVolume.setColor(sf::Color((Selected==3)*127+128, (Selected==3)*127+128, (Selected==3)*127+128, 255));
        Exit.setColor(sf::Color((Selected==4)*127+128, (Selected==4)*127+128, (Selected==4)*127+128, 255));
        for (int i=0; i<5; i++) {
            if (Data.MaxLives-1==i) Lives[i].setColor(sf::Color(128+127*(Selected==1),128+127*(Selected==1),32+32*(Selected==1),255));
            else                    Lives[i].setColor(sf::Color(128+127*(Selected==1),128+127*(Selected==1),128+127*(Selected==1),255));
        }
        BGM.setColor(sf::Color(128+127*(Selected==2),128+127*(Selected==2),128+127*(Selected==2),255));
        SEV.setColor(sf::Color(128+127*(Selected==3),128+127*(Selected==3),128+127*(Selected==3),255));

        //Text for volume strings
        char volume_char[4];
        short volume_num;
        volume_num=Data.BGMVolume;
        for (int i=0; i<3; i++) {
            volume_char[2-i]=(volume_num%10)+48;
            volume_num/=10;
        }
        volume_char[3]='\0';
        BGM.setString(volume_char);
        volume_num=Data.SEVolume;
        for (int i=0; i<3; i++) {
            volume_char[2-i]=(volume_num%10)+48;
            volume_num/=10;
        }
        volume_char[3]='\0';
        SEV.setString(volume_char);

        //Displaying
        MainWindow.draw(MainBackgroundSprite);
        MainWindow.draw(Title);
        MainWindow.draw(MaxLives);
        for (int i=0; i<5; i++) MainWindow.draw(Lives[i]);
        MainWindow.draw(BGMVolume);
        MainWindow.draw(BGM);
        MainWindow.draw(SEVolume);
        MainWindow.draw(SEV);
        MainWindow.draw(Exit);

        MainWindow.display();
        sf::sleep(sf::milliseconds(17));
    }
    WriteDataStruct(Data);
    MainBackgroundSprite.setColor(sf::Color(128,0,0,255));
    return 0;
}

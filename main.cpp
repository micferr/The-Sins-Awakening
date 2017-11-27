#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <gl/gl.h>

#include "ResourceFile.h"
#include "Global.h"
#include "DataStruct.h"
#include "Records.h"
#include "Options.h"
#include "HowToPlay.h"
#include "Credits.h"
#include "Starts.h"
#include "GameEngine.h"

int main() {
    Engine.AudioHandle=new AudioHandler;
    Engine.Player->Hitbox.Load();

    //Icon
    sf::Image WindowIcon;
    char* imagedata=Reader.getFile("Icon.png");
    size_t imagesize=Reader.getEntryFileSize("Icon.png");
    WindowIcon.loadFromMemory(imagedata, imagesize);
    delete[] imagedata;

    //Initializing window
    uint32_t WindowStyle=sf::Style::Close;
    bool MouseCursorVisible=true;
    MainWindow.create(sf::VideoMode(800,600,32), " The Sins Awakening", WindowStyle, sf::ContextSettings(32,8,4));
    MainWindow.setIcon(32,32,WindowIcon.getPixelsPtr());
    MainWindow.setMouseCursorVisible(MouseCursorVisible);
    MainWindow.setKeyRepeatEnabled(false);
    //MainWindow.setFramerateLimit(120);
    //MainWindow.setVerticalSyncEnabled(true);
    glClearColor(1,1,1,1);
    glReadBuffer(GL_BACK); //Reads from the front buffer
    glDisable(GL_DITHER);

    //Initializing data
    LoadDataStruct(Data);
    char *EngGothicBuffer=Reader.getFile("PrinceValiant.ttf");
    Font[PRINCEVALIANT].loadFromMemory(EngGothicBuffer,Reader.getEntryFileSize("PrinceValiant.ttf"));
    //delete [] FontBuffer;
    char *TuffyBuffer=Reader.getFile("Tuffy.ttf");
    Font[TUFFY].loadFromMemory(TuffyBuffer,Reader.getEntryFileSize("Tuffy.ttf"));
    //delete [] FontBuffer;

    //Set Audio volume
    SetMusicVolume(Data.BGMVolume);
    SetSEVolume(Data.SEVolume);

    //Set up the background
    char *BackgroundBuffer=Reader.getFile("MainBackground.png");
    sf::Texture BackgroundImage;
    BackgroundImage.loadFromMemory(BackgroundBuffer,Reader.getEntryFileSize("MainBackground.png"));
    delete [] BackgroundBuffer;
    MainBackgroundSprite.setTexture(BackgroundImage);
    MainBackgroundSprite.setOrigin(199,199);
    MainBackgroundSprite.setPosition(399,299);
    MainBackgroundSprite.setColor(sf::Color(128,0,0,255));

    ///Main loop
    int Selected=1; //Selected voice of the menu
    //Title
    sf::Text Title("The Sins Awakening",Font[PRINCEVALIANT],90);
    Title.setColor(sf::Color(27,128,255,255));
    Title.setPosition(400-Title.getLocalBounds().width/2,25);
    //Menu voices
    sf::Text MenuWritings[7]; //Voices of the menu
    MenuWritings[0].setString("New Game");
    MenuWritings[1].setString("Level Practice");
    MenuWritings[2].setString("High Scores");
    MenuWritings[3].setString("Game Settings");
    MenuWritings[4].setString("How To Play");
    MenuWritings[5].setString("Credits");
    MenuWritings[6].setString("Quit Game");

    for (int i=0; i<7; i++) {
        MenuWritings[i].setFont(Font[PRINCEVALIANT]);
        MenuWritings[i].setCharacterSize(45);
        MenuWritings[i].setPosition(35,160+(60*i));
    }

    //Displaying the background adding zoom effect
    {
        sf::Clock Clock;
        bool Zooming=true;
        while (Zooming) {
            MainWindow.clear();
            float ZoomTime=Clock.getElapsedTime().asSeconds();
            MainBackgroundSprite.setScale(20-ZoomTime*12, 15-ZoomTime*9);
            if (MainBackgroundSprite.getScale().x <= 2) {
                MainBackgroundSprite.setScale(2,1.5);
                Zooming=false;
            }
            MainWindow.draw(MainBackgroundSprite);
            MainWindow.display();
            sf::sleep(sf::milliseconds(17));
            while (MainWindow.pollEvent(Event)); //Flush events
        }
    }

    //Starts playing main theme
    Play(MENUTHEME);
    //Play(LEVEL1_THEME);
    //Loop start
    bool Running=true;
    while (Running) {
        //Get frame time
        //Event handling
        while (MainWindow.pollEvent(Event)) {
            if (Event.type==sf::Event::Closed)
                Running=false;
            //If a key is pressed
            else if (Event.type==sf::Event::KeyPressed) {
                switch (Event.key.code) {
                    case sf::Keyboard::X:
                    case sf::Keyboard::Escape:
                        if (Selected==7) {
                            Running=false;
                            Play(MENUCONFIRM);
                        }
                        else {
                            Selected=7;
                            Play(MENUSCROLL);
                        }
                        break;
                    case sf::Keyboard::Up:
                        if (Selected!=1) Selected--;
                        else Selected=7;
                        Play(MENUSCROLL);
                        break;
                    case sf::Keyboard::Down:
                        if (Selected!=7) Selected++;
                        else Selected=1;
                        Play(MENUSCROLL);
                        break;
                    case sf::Keyboard::Z:
                    case sf::Keyboard::Return:
                        Play(MENUCONFIRM);
                        switch (Selected) {
                            case 1:
                                if (NewStart()==-1) Engine.CrossPressed=true;
                                break;
                            case 2:
                                if (PracticeStart()==-1) Engine.CrossPressed=true;
                                break;
                            case 3:
                                if (RecordScreen()==-1) Engine.CrossPressed=true;
                                break;
                            case 4:
                                if (OptionsScreen()==-1) Engine.CrossPressed=true;
                                break;
                            case 5:
                                if (HowtoplayScreen()==-1) Engine.CrossPressed=true;
                                break;
                            case 6:
                                if (CreditsScreen()==-1) Engine.CrossPressed=true;
                                break;
                            case 7:
                                Running=false;
                                break;
                            default:
                                break;
                        }
                        if (!Engine.CrossPressed)
                            Play(MENUTHEME);
                        break;
                    case sf::Keyboard::P:
                        Engine.ScreenShot();
                        break;
                    case sf::Keyboard::F1:
                        if (WindowStyle==sf::Style::Close) {
                            WindowStyle=sf::Style::Fullscreen;
                            MouseCursorVisible=false;
                        }
                        else {
                            WindowStyle=sf::Style::Close;
                            MouseCursorVisible=true;
                        }
                        MainWindow.close();
                        MainWindow.create(sf::VideoMode(800,600,32), " The Sins Awakening", WindowStyle, sf::ContextSettings(32,8,4));
                        MainWindow.setIcon(32,32,WindowIcon.getPixelsPtr());
                        MainWindow.setMouseCursorVisible(MouseCursorVisible);
                        MainWindow.setKeyRepeatEnabled(false);
                        //MainWindow.setFramerateLimit(120);
                        if (WindowStyle==sf::Style::Fullscreen)
                            MainWindow.setVerticalSyncEnabled(true);
                        else
                            MainWindow.setVerticalSyncEnabled(false);
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
        }
        MainBackgroundSprite.setColor(sf::Color(128,0,0,255));
        if (Engine.CrossPressed || (Engine.LAltPressed && Engine.F4Pressed))
            Running=false;
        if (Running) { //Draws scene only if the game is running
            MainWindow.clear();
            //Displaying background
            MainWindow.draw(MainBackgroundSprite);

            //Displaying menu voices
            MainWindow.draw(Title);
            for (int i=0; i<7; ++i) {
                MenuWritings[i].setColor(sf::Color(127+(Selected==i+1)*128,127+(Selected==i+1)*128,127+(Selected==i+1)*128,255));
                MainWindow.draw(MenuWritings[i]);
            }

            //Updating screen
            MainWindow.display();
            sf::sleep(sf::milliseconds(17));
        }
    }

    MainWindow.close();

    delete[] EngGothicBuffer;
    delete[] TuffyBuffer;

    return 0;
}

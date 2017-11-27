#ifndef GLOBAL_H
#define GLOBAL_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ResourceFile.h"
#include "DataStruct.h"
#include "GameEngine.h"
#include "Random.h"
#include <cassert>

constexpr unsigned PRINCEVALIANT=0;
constexpr unsigned TUFFY=1;

constexpr double PI=3.141592653589793;

extern ResourceFileReader Reader;
extern DataStruct Data;
extern sf::RenderWindow MainWindow;
extern sf::Sprite MainBackgroundSprite;
extern sf::Font Font[2];
extern sf::Event Event;
extern GameEngine Engine;
extern Random Randomizer;

//referring to Engine.something to allow global use
#define CHECK_EXIT()  \
    if ((Engine.LAltPressed==true && Engine.F4Pressed) || Engine.CrossPressed) { \
        Engine.InGame=false; \
        return -1; \
    }

#endif

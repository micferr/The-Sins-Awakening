#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ResourceFile.h"
#include "DataStruct.h"
#include "GameEngine.h"
#include "Random.h"

ResourceFileReader Reader("tsares.dat");
DataStruct Data;
sf::RenderWindow MainWindow;
sf::Sprite MainBackgroundSprite;
sf::Font Font[2];
sf::Event Event;
struct GameEngine Engine;
Random Randomizer;

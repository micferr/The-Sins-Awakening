#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Enemies.h"

struct GameEngine;

enum ItemID : unsigned int {
    POWER_ITEM = 0,
    SCORE_ITEM = 1,
    BOMB_ITEM = 2,
    LIFE_ITEM = 3
};

struct Item {
    sf::Vector2<float> BasePosition;
    bool AutoCollected;
    long double Angle;
    float BaseTime;
    sf::Sprite Sprite;
    ItemID ID;

    Item();
};

class ItemPool {
    std::vector<Item*> ItemVector;
    GameEngine* pEngine;

    public:
    ItemPool()=default;
    ItemPool(GameEngine* EnginePointer);
    ~ItemPool();
    void BindEngine(GameEngine* EnginePointer);
    void Clear();
    void GenerateFallingItems(Enemy* enemy);
    void GenerateFallingItems(Boss* boss);
    void MoveItems(void);
    void AutoCollect();
    void GainLife();
    void DrawItems();

    friend struct GameEngine;
};

#endif // ITEM_H

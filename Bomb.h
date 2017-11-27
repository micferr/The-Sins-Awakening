#ifndef BOMB_H
#define BOMB_H

#include <SFML/Graphics.hpp>

struct GameEngine;

class AbstractBomb {
    public:
    AbstractBomb();
    virtual ~AbstractBomb();
    virtual void Activate()=0;
    virtual void Terminate()=0;
    virtual void Update()=0;
    virtual void DrawEffects()=0;

    float Duration;
    float ActivationTime;
    GameEngine* EnginePointer;
};

class Bomb_TypeOne : public AbstractBomb {
    sf::Sprite BombSprite;
    sf::Texture BombTexture;
    float ActivationPositionX, ActivationPositionY;

    public:
    Bomb_TypeOne(GameEngine* engine_pointer);
    Bomb_TypeOne(GameEngine& engine_reference);
    ~Bomb_TypeOne();
    virtual void Activate();
    virtual void Terminate();
    virtual void Update();
    virtual void DrawEffects();
};

class Bomb_TypeTwo : public AbstractBomb {
    sf::Sprite BombSprite;
    sf::Texture BombTexture;

    public:
    Bomb_TypeTwo(GameEngine* engine_pointer);
    Bomb_TypeTwo(GameEngine& engine_reference);
    ~Bomb_TypeTwo();
    virtual void Activate();
    virtual void Terminate();
    virtual void Update();
    virtual void DrawEffects();
};

#endif // SHOTTYPE_H

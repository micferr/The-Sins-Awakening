#ifndef EFFECT_H
#define EFFECT_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "AttribList.h"

struct GameEngine;

class BaseEffect : public AttribList {
    protected:
    virtual void Display(sf::RenderWindow& window) = 0;

    public:
    float pos_x, pos_y; //Position
    float animation_time; //Past time since birth

    BaseEffect();
    virtual ~BaseEffect()=default;
    void Show(sf::RenderWindow& window, float frametime);
    virtual bool CheckEnd() const =0; //True when effect expires
};

class EffectList {
    std::vector<std::unique_ptr<BaseEffect>> effects;
    GameEngine* engine_ptr;
    sf::RenderWindow* window_ptr;

    public:

    EffectList()=default;

    void BindEngine(GameEngine* ptr);
    void BindWindow(sf::RenderWindow* ptr);
    void AddEffect(BaseEffect* ptr);
    void DeleteEffect(size_t index);
    void Clear();
    void Show();
};

#endif // EFFECT_H

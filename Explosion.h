#ifndef EFFECT_EXPLOSION
#define EFFECT_EXPLOSION

#include "EffectList.h"

class EffectExplosion : public BaseEffect {
    float max_radius, time_length;
    sf::Sprite sprite;

    public:
    EffectExplosion()=delete;
    EffectExplosion(float x, float y, float rad, float duration);
    ~EffectExplosion()=default;
    void Display(sf::RenderWindow& window) override;
    bool CheckEnd() const override;
};

#endif // EFFECT_EXPLOSION

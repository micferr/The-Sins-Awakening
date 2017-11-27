#include "Explosion.h"
#include "Global.h"

EffectExplosion::EffectExplosion(float x, float y, float rad, float duration) {
    pos_x=x;
    pos_y=y;
    max_radius=rad;
    time_length=duration;

    sprite.setTexture(Engine.ExplosionImages[1]);
    sprite.setOrigin(Engine.ExplosionImages[1].getSize().x/2, Engine.ExplosionImages[1].getSize().y/2);
    sprite.setPosition(pos_x, pos_y);
    sprite.setScale(0.f,0.f);
}

void EffectExplosion::Display(sf::RenderWindow& window) {
    float time_ratio=animation_time/time_length;
    float scalefactor=(max_radius/(sprite.getTexture()->getSize().x/2))*time_ratio;
    sprite.setScale(scalefactor,scalefactor);
    sprite.setColor(sf::Color(255,255,255,std::max<float>(255-192*time_ratio,0.f)));
    window.draw(sprite);
}

bool EffectExplosion::CheckEnd() const {
    return animation_time>=time_length;
}

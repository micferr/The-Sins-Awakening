#include "EffectList.h"
#include "GameEngine.h"

///BaseEffect

void BaseEffect::Show(sf::RenderWindow& window, float frametime) {
    animation_time+=frametime;
    Display(window);
}

BaseEffect::BaseEffect() : pos_x(0.f), pos_y(0.f), animation_time(0.f) {}

///EffectList

void EffectList::BindEngine(GameEngine* ptr) {
    engine_ptr=ptr;
}

void EffectList::BindWindow(sf::RenderWindow* ptr) {
    window_ptr=ptr;
}

void EffectList::AddEffect(BaseEffect* ptr) {
    effects.emplace_back(std::unique_ptr<BaseEffect>(ptr));
}

void EffectList::DeleteEffect(size_t index) {
    effects.erase(effects.begin()+index);
};

void EffectList::Clear() {
    effects.clear();
}

void EffectList::Show() {
    for (size_t i=0; i<effects.size();) {
        effects[i]->Show(*window_ptr, engine_ptr->FrameTime);
        if (effects[i]->CheckEnd()) {
            DeleteEffect(i);
        }
        else
            ++i;
    }
}

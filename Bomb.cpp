#include "Bomb.h"
#include "Global.h"
#include "Explosion.h"

/// AbstractBomb

AbstractBomb::AbstractBomb() {}

AbstractBomb::~AbstractBomb() {}

/// Bomb_TypeOne

Bomb_TypeOne::Bomb_TypeOne(GameEngine* engine_pointer) {
    char* texture_data=Reader.getFile("Bomb1.png");
    size_t texture_size=Reader.getEntryFileSize("Bomb1.png");
    BombTexture.loadFromMemory(texture_data, texture_size);
    delete[] texture_data;
    BombTexture.setSmooth(true);
    BombSprite.setTexture(BombTexture);
    BombSprite.setOrigin(BombTexture.getSize().x/2, BombTexture.getSize().y/2);

    Duration=1.5;
    EnginePointer=engine_pointer;
}

Bomb_TypeOne::Bomb_TypeOne(GameEngine& engine_reference) : Bomb_TypeOne(&engine_reference) {}

Bomb_TypeOne::~Bomb_TypeOne() {}

void Bomb_TypeOne::Activate() {
    ActivationTime=EnginePointer->PastTime;
    BombSprite.setPosition(EnginePointer->Player->Position);
    BombSprite.setScale(1.f,1.f);
    EnginePointer->Player->PauseGauge=1.f;
    ActivationPositionX=EnginePointer->Player->Position.x;
    ActivationPositionY=EnginePointer->Player->Position.y;
    Play(ATERBOMB);
}

void Bomb_TypeOne::Update() {
    float PastTime=EnginePointer->PastTime-ActivationTime;
    float scalefactor=1+pow(PastTime,15);
    BombSprite.setScale(scalefactor,scalefactor);
    BombSprite.setColor(sf::Color(255,255,255,PastTime>=0.75f?255-(PastTime-0.75f)/0.75f*255:255));
    EnginePointer->Player->PauseGauge=1.f;
    //Enemies
    for (auto enemy : EnginePointer->Enemies) {
        if (enemy->Position.x>=25 && enemy->Position.x<=475 && enemy->Position.y>=25 && enemy->Position.y<=575) {
            if (pow(enemy->Position.x-ActivationPositionX,2)+pow(enemy->Position.y-ActivationPositionY,2)<=2*(pow(50*scalefactor,2))) {
                enemy->Life-=160*EnginePointer->FrameTime;
                if (enemy->Life<0)
                    enemy->Life=0;
            }
        }
    }
    //Boss
    Boss* boss=EnginePointer->LevelBoss;
    if (boss->Position.x>=25 && boss->Position.x<=475 && boss->Position.y>=25 && boss->Position.y<=575) {
        if (pow(boss->Position.x-ActivationPositionX,2)+pow(boss->Position.y-ActivationPositionY,2)<=2*(pow(50*scalefactor,2))) {
            if (boss->LifeBars.size()>0) {
                boss->LifeBars.back()->Health-=160*EnginePointer->FrameTime;
            }
        }
    }
    //Enemies' Bullets
    std::vector<Bullet*>* enemybullets=&EnginePointer->EnemyBullets;
    for (size_t i=0; i<enemybullets->size();) {
        float quad_x=pow(enemybullets->at(i)->Sprite.getPosition().x-ActivationPositionX,2);
        float quad_y=pow(enemybullets->at(i)->Sprite.getPosition().y-ActivationPositionY,2);
        if (quad_x+quad_y<=pow(50*scalefactor,2)) {
            EnginePointer->DeleteBullet((Bullet*)(enemybullets->at(i)), 0);
        }
        else {
            ++i;
        }
    }
    //Boss's Bullets
    for (unsigned i=0; i<EnginePointer->LevelBoss->Bullets.size();) {
        if (EnginePointer->LevelBoss->Bullets.at(i)->Deletable==true) {
            float quad_x=pow(EnginePointer->LevelBoss->Bullets.at(i)->Sprite.getPosition().x-ActivationPositionX,2);
            float quad_y=pow(EnginePointer->LevelBoss->Bullets.at(i)->Sprite.getPosition().y-ActivationPositionY,2);
            if (quad_x+quad_y<=pow(50*scalefactor,2)) {
                EnginePointer->VisualEffects.AddEffect(new EffectExplosion(EnginePointer->LevelBoss->Bullets.at(i)->Sprite.getPosition().x,
                                                                           EnginePointer->LevelBoss->Bullets.at(i)->Sprite.getPosition().y,
                                                                           EnginePointer->LevelBoss->Bullets.at(i)->Radius,
                                                                           0.4f));
                delete EnginePointer->LevelBoss->Bullets.at(i);
                EnginePointer->LevelBoss->Bullets.erase(EnginePointer->LevelBoss->Bullets.begin()+i);
            }
            else {
                ++i;
            }
        }
        else {
            ++i;
        }
    }
}

void Bomb_TypeOne::Terminate() {}

void Bomb_TypeOne::DrawEffects() {
    MainWindow.draw(BombSprite);
}

/// Bomb_TypeTwo

Bomb_TypeTwo::Bomb_TypeTwo(GameEngine* engine_pointer) {
    char* texture_data=Reader.getFile("Bomb2.png");
    size_t texture_size=Reader.getEntryFileSize("Bomb2.png");
    BombTexture.loadFromMemory(texture_data, texture_size);
    delete[] texture_data;
    BombTexture.setSmooth(true);
    BombSprite.setTexture(BombTexture);
    BombSprite.setColor(sf::Color(255,255,255,128));
    BombSprite.setOrigin(BombTexture.getSize().x/2, BombTexture.getSize().y/2);

    Duration=6;
    EnginePointer=engine_pointer;
}

Bomb_TypeTwo::Bomb_TypeTwo(GameEngine& engine_reference) : Bomb_TypeTwo(&engine_reference) {}

Bomb_TypeTwo::~Bomb_TypeTwo() {}

void Bomb_TypeTwo::Activate() {
    ActivationTime=EnginePointer->PastTime;
    BombSprite.setPosition(EnginePointer->Player->Position);
    Play(ALBABOMB);
    EnginePointer->Player->PauseGauge=1.f;
}

void Bomb_TypeTwo::Update() {
    float PastTime=EnginePointer->PastTime-ActivationTime;
    BombSprite.setPosition(EnginePointer->Player->Position);
    float scalefactor;
    if (PastTime<=0.15f)
        scalefactor=1.5f*PastTime/0.15f;
    else if (PastTime<=0.7f)
        scalefactor=1.5f;
    else
        scalefactor=1.5-1.5*std::max((PastTime-0.7f)/(Duration-0.7f),0.f);
    BombSprite.setScale(scalefactor,scalefactor);
    BombSprite.rotate(150.f*EnginePointer->FrameTime);

    //Enemies' Bullets
    std::vector<Bullet*>* enemybullets=&EnginePointer->EnemyBullets;
    float player_x=EnginePointer->Player->Position.x, player_y=EnginePointer->Player->Position.y;
    for (size_t i=0; i<enemybullets->size();) {
        float quad_x=pow(enemybullets->at(i)->Sprite.getPosition().x-player_x,2);
        float quad_y=pow(enemybullets->at(i)->Sprite.getPosition().y-player_y,2);
        if (quad_x+quad_y<=max(pow(50*scalefactor+enemybullets->at(i)->Radius,2), pow(enemybullets->at(i)->Radius,2))) {
            EnginePointer->Player->Power=min<unsigned>(EnginePointer->Player->Power+1,1000);
            EnginePointer->DeleteBullet((Bullet*)(enemybullets->at(i)), 0);
        }
        else {
            ++i;
        }
    }
    //Boss's Bullets
    for (unsigned i=0; i<EnginePointer->LevelBoss->Bullets.size();) {
        if (EnginePointer->LevelBoss->Bullets.at(i)->Deletable==true) {
            float quad_x=pow(EnginePointer->LevelBoss->Bullets.at(i)->Sprite.getPosition().x-player_x,2);
            float quad_y=pow(EnginePointer->LevelBoss->Bullets.at(i)->Sprite.getPosition().y-player_y,2);
            if (quad_x+quad_y<=max(pow(50*scalefactor+EnginePointer->LevelBoss->Bullets.at(i)->Radius,2),pow(EnginePointer->LevelBoss->Bullets.at(i)->Radius,2))) {
                EnginePointer->Player->Power=min<unsigned>(EnginePointer->Player->Power+1,1000);
                EnginePointer->VisualEffects.AddEffect(new EffectExplosion(EnginePointer->LevelBoss->Bullets.at(i)->Sprite.getPosition().x,
                                                                           EnginePointer->LevelBoss->Bullets.at(i)->Sprite.getPosition().y,
                                                                           EnginePointer->LevelBoss->Bullets.at(i)->Radius,
                                                                           0.4f));
                delete EnginePointer->LevelBoss->Bullets.at(i);
                EnginePointer->LevelBoss->Bullets.erase(EnginePointer->LevelBoss->Bullets.begin()+i);
            }
            else {
                ++i;
            }
        }
        else {
            ++i;
        }
    }
}

void Bomb_TypeTwo::Terminate() {}

void Bomb_TypeTwo::DrawEffects() {
    MainWindow.draw(BombSprite);
}

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Bomb.h"
#include "Audio.h"

struct GameEngine;
struct MyPlayer;
class AbstractBomb;

struct ShotType {
    //Owner player
    MyPlayer* PlayerPointer;
    //Game Data
    float NormalMovementSpeed; //In pixels per second
    float FocusedMovementSpeed; //In pixels per second
    float ChargeMovementSpeed; //In pixels per second
    float ChargeFocusedMovementSpeed; //In pixels per second
    float ShotsPerSecond; //Main shot
    float AuxShotsPerSecond[11]; //For each power level;
    unsigned int HitboxRadius;
    unsigned int ShotTypeID;
    SoundID ShootSoundID, AuxShootSoundID, BombSoundID, DeathSoundID;
    std::string TextureFile;
    std::string ShotTextureFile[2]; sf::Texture ShotTexture[2];

    AbstractBomb* Bomb;
};

class FocusHitbox {
    sf::Texture Texture;
    sf::Sprite Sprite[4];
    MyPlayer* PlayerPointer;

    public:
    FocusHitbox();
    ~FocusHitbox()=default;
    void Load();
    void Draw();
};

struct MyPlayer {
    public:
    sf::Texture Image;
    sf::Sprite Sprite[4];
    float MainShootTime;
    float AuxShootTime;
    float ChargeTime;
    float BombTime;
    float DeathTime;
    float PauseGauge; //Non-shoot gauge
    sf::Vector2<float> Position;
    sf::Vector2<float> PrevPosition;
    unsigned Power;
    signed short Lives; //Lives left to the player
    short Bombs; //Bombs left to the player
    unsigned Charge;
    FocusHitbox Hitbox;

    GameEngine* EnginePointer;
    ShotType SelectedShotType;

    void Load();
    void CheckCollision();
    void Die();
    void Draw();
};

#endif // PLAYER_H

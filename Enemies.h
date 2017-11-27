#ifndef ENEMIES_H
#define ENEMIES_H

#include <SFML/Graphics.hpp>

struct Bullet;
struct SuperBullet;
struct Enemy;

typedef std::pair<float, void(*)(Enemy*)> EnemyShoot;

struct Foe {
    public:
    sf::Sprite Sprite[4];
    sf::Vector2<float> Position, PrevPosition;
    short Radius;

    virtual ~Foe()=default;
    void SetImage(sf::Texture &texture);
    virtual void Draw()=0;
};

struct Enemy : public Foe {
    public:
    int Life;
    float BaseTime;
    std::vector<short> Loot; //Falling items' list
    std::vector<std::pair<float, void(*)(Enemy*) >*> ShootTable;

    void (*Move)(Enemy*);
    Enemy();
    virtual void Draw();
};

///Enemies subspecies

///ENEMY 0
/* Enemy 0:
 * Most common enemy, with low life but numerical strenght
 */
#define ENEMY_0_RADIUS 17

struct Enemy_0 : public Enemy {
    Enemy_0();
};

///ENEMY 1
/* Enemy 1:
 * Stronger enemy, with more life and more complex patterns
 */
#define ENEMY_1_RADIUS 20

struct Enemy_1 : public Enemy {
    Enemy_1();
};

///ENEMY 2
/* Enemy 2:
 * Very rare, the strongest kind of enemy. Very big, hard-as-hell patterns, gives high rewards
 */
#define ENEMY_2_RADIUS 25

struct Enemy_2 : public Enemy {
    sf::Sprite AuraSprite;

    Enemy_2();
    virtual void Draw();
};

///BOSS

///Lifebar - boss is belove
struct Boss;
typedef std::pair<std::pair<float, float> , void(*)(Boss*, float)>  TableElement;
struct LifeBar {
    double MaxHealth;
    double Health;
    std::vector<short> Loot;
    std::string Name;
    long BonusScore;

    //remaining time till next shot - total time between shots, shot func(boss, sbullet->basetime) *sbullet=super-bullet
    std::vector<TableElement*> ShootTable;

    void (*Move)(Boss*);
};

struct Boss : public Foe {
    public:
    sf::Texture Texture;
    sf::Sprite AuraSprite;
    std::vector<LifeBar*> LifeBars;
    std::vector<SuperBullet*> Bullets;
    std::vector<double> Data;

    Boss();
    virtual ~Boss();
    virtual void Draw();
};

#endif // ENEMIES_H

#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

#ifndef BULLET_1_CENTER
    #define BULLET_1_CENTER 25,25
#endif

#ifndef BULLET_1WIDE_CENTER
    #define BULLET_1WIDE_CENTER 149.5,149.5
#endif

#ifndef BULLET_2_CENTER
    #define BULLET_2_CENTER 29.5,29.5
#endif

#ifndef BULLET_3_CENTER
    #define BULLET_3_CENTER 24.5,24.5
#endif

#ifndef BULLET_3WIDE_CENTER
    #define BULLET_3WIDE_CENTER 149.5,149.5
#endif

#ifndef BULLET_4_CENTER
    #define BULLET_4_CENTER 24.5,24.5
#endif

#ifndef BULLET_5_CENTER
    #define BULLET_5_CENTER 80.0,35.0
#endif

#ifndef BULLET_6_CENTER
    #define BULLET_6_CENTER 24.5,24.5
#endif

struct Enemy;

enum BulletType {
    BULLET_1_RED=0,
    BULLET_1_RED_WIDE=1,
    BULLET_1_GREEN=2,
    BULLET_1_BLUE=3,
    BULLET_1_BLUE_WIDE=4,
    BULLET_1_YELLOW=5,
    BULLET_1_GREY=6,
    BULLET_1_LIGHTBLUE=7,
    BULLET_1_MAGENTA=8,
    BULLET_1_BLACK=9,
    BULLET_2_RED=10,
    BULLET_2_GREEN=11,
    BULLET_2_BLUE=12,
    BULLET_2_YELLOW=13,
    BULLET_2_GREY=14,
    BULLET_2_MAGENTA=15,
    BULLET_3=16, //SetColor for this
    BULLET_3_WIDE=17, //SetColor for this
    BULLET_4=18, //SetColor for this
    BULLET_5=19, //SetColor for this
    BULLET_6=20 //SetColor for this
};

struct BaseBullet {
    sf::Sprite Sprite;
    double Radius;
    bool Grazed;
    float Angle;
    float BaseTime;
    float Speed;

    BaseBullet();
    BaseBullet(float speed);
    virtual ~BaseBullet();
    void Travel(float mov_x, float mov_y);
    void Travel(float mov);
    void TravelAtSpeed(float speed);
    void SetPosition(float x, float y);
    void SetRadius(float radius);
    void SetAngle(float radians);
    void SetImage(const sf::Texture& texture);
    void SetImageColor(unsigned short r, unsigned short g, unsigned short b, unsigned short a=255);
    void SetImageCenter(float x, float y);
    void SetBaseTime(float basetime);
    void SetBaseTime(Enemy* enemy); //Auto-calculated from first shoottable element
    void SetSpeed(float newspeed);
};

struct DanmakuSpecificBaseBullet : public BaseBullet {
    DanmakuSpecificBaseBullet();
    DanmakuSpecificBaseBullet(float speed);

    using BaseBullet::SetPosition;
    void SetPosition(sf::Vector2<float> pos);
    void SetImage(size_t index);
};

struct Bullet : public DanmakuSpecificBaseBullet {
    unsigned long VectorPosition;
    void (*Move)(Bullet*);

    Bullet();
    Bullet(float speed);
    ~Bullet();
    void SetMoveFunc(void(&)(Bullet*));
};

struct SuperBullet : public DanmakuSpecificBaseBullet {
    bool Deletable;
    void (*Move)(SuperBullet*);
    bool (*CheckDeletion)(SuperBullet*);

    SuperBullet();
    SuperBullet(float speed);
    void SetDeletable(bool deletable);
    void SetMoveFunc(void(&)(SuperBullet*));
    void SetDeleteFunc(bool(&)(SuperBullet*));
};

struct SpeedBullet : public SuperBullet {
    SpeedBullet();
    SpeedBullet(float speed);
};

/// Delete funcs

namespace DeleteFuncs {
    bool OutOfBound(SuperBullet*);
    bool Directed_OutOfBound(SuperBullet*); //Delete only after entering the screen
}

#endif

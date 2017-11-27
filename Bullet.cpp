#include "Bullet.h"
#include "GameEngine.h"
#include "Global.h"

BaseBullet::BaseBullet() : Grazed(false) {}

BaseBullet::BaseBullet(float speed) : Grazed(false), Speed(speed) {}

BaseBullet::~BaseBullet() {}

void BaseBullet::Travel(float mov_x, float mov_y) {
    Sprite.move(mov_x, mov_y);
}

void BaseBullet::Travel(float mov) {
    Sprite.move(cos(this->Angle)*mov, -sin(this->Angle)*mov);
}

void BaseBullet::TravelAtSpeed(float speed) {
    Travel(speed*Engine.FrameTime);
}

void BaseBullet::SetPosition(float x, float y) {
    Sprite.setPosition(x,y);
}

void BaseBullet::SetRadius(float radius) {
    //Radius=max(radius*8/10,radius-5);
    Radius=radius-3;
    float scalevalue=radius/25;
    Sprite.setScale(scalevalue, scalevalue);
}

void BaseBullet::SetAngle(float radians) {
    Angle=radians;
    Sprite.setRotation(-radians*180/PI);
}

void BaseBullet::SetImage (const sf::Texture& texture) {
    Sprite.setTexture(texture);
}

void BaseBullet::SetImageColor(unsigned short r, unsigned short g, unsigned short b, unsigned short a) {
    Sprite.setColor(sf::Color(r,g,b,a));
}

void BaseBullet::SetImageCenter(float x, float y) {
    Sprite.setOrigin(x,y);
}

void BaseBullet::SetBaseTime(float basetime) {
    BaseTime=basetime;
}

void BaseBullet::SetBaseTime(Enemy* enemy) {
    BaseTime=enemy->BaseTime+enemy->ShootTable.front()->first;
}

void BaseBullet::SetSpeed(float speed) {
    Speed=speed;
}

///

DanmakuSpecificBaseBullet::DanmakuSpecificBaseBullet() {}

DanmakuSpecificBaseBullet::DanmakuSpecificBaseBullet(float speed) : BaseBullet(speed) {}

void DanmakuSpecificBaseBullet::SetPosition(sf::Vector2<float> pos) {
    Sprite.setPosition(pos);
}

void DanmakuSpecificBaseBullet::SetImage (size_t index) {
    Sprite.setTexture(Engine.BulletImages[index]);
    if (index==0) SetImageCenter(BULLET_1_CENTER);
    else if (index==1 or index==4) SetImageCenter(BULLET_1WIDE_CENTER);
    else if (index<=9) SetImageCenter(BULLET_1_CENTER);
    else if (index<=15) SetImageCenter(BULLET_2_CENTER);
    else if (index==16) SetImageCenter(BULLET_3_CENTER);
    else if (index==17) SetImageCenter(BULLET_3WIDE_CENTER);
    else if (index==18) SetImageCenter(BULLET_4_CENTER);
    else if (index==19) SetImageCenter(BULLET_5_CENTER);
    else if (index==20) SetImageCenter(BULLET_6_CENTER);
}

///

Bullet::Bullet() : VectorPosition(Engine.EnemyBullets.size()) {}

namespace {
    void BulletSpeedMove(Bullet* bullet) {
        bullet->TravelAtSpeed(bullet->Speed);
    }
}
Bullet::Bullet(float speed) : DanmakuSpecificBaseBullet(speed), VectorPosition(Engine.EnemyBullets.size()), Move(BulletSpeedMove) {}

Bullet::~Bullet() {}

void Bullet::SetMoveFunc(void(&func)(Bullet*)) {
    Move=func;
}

///

namespace {
    void SuperBulletSpeedMove(SuperBullet* sbullet) {
        sbullet->TravelAtSpeed(sbullet->Speed);
    }
}

SuperBullet::SuperBullet() : Deletable(true), CheckDeletion(DeleteFuncs::OutOfBound) {}

SuperBullet::SuperBullet(float speed) : DanmakuSpecificBaseBullet(speed), Deletable(true), Move(SuperBulletSpeedMove), CheckDeletion(DeleteFuncs::OutOfBound) {}

void SuperBullet::SetDeletable(bool deletable) {
    Deletable=deletable;
}

void SuperBullet::SetMoveFunc(void(&func)(SuperBullet*)) {
    Move=func;
}

void SuperBullet::SetDeleteFunc(bool(&func)(SuperBullet*)) {
    CheckDeletion=func;
}

SpeedBullet::SpeedBullet() {
    SetMoveFunc(SuperBulletSpeedMove);
}

SpeedBullet::SpeedBullet(float speed) {
    Speed=speed;
    SetMoveFunc(SuperBulletSpeedMove);
}

namespace DeleteFuncs {
    bool OutOfBound(SuperBullet* sbullet) {
        float x=sbullet->Sprite.getPosition().x, y=sbullet->Sprite.getPosition().y;
        return x<0-sbullet->Radius || x>500+sbullet->Radius || y<0-sbullet->Radius || y>600+sbullet->Radius;
    }

    bool Directed_OutOfBound(SuperBullet* sbullet) {
        float x=sbullet->Sprite.getPosition().x, y=sbullet->Sprite.getPosition().y, radius=sbullet->Radius, angle=sbullet->Angle, deg360=2*PI;
        while (angle>deg360)
            angle-=deg360;
        return  (x<25-radius && angle>=PI/2 && angle<=PI*3/2) ||
                (x>475+radius && (angle<=PI || angle>=PI*3/2)) ||
                (y<25-radius && angle>=0 && angle<=PI) ||
                (y>475+radius && angle>=PI && (angle==0 || angle<=2*PI));
    }
}

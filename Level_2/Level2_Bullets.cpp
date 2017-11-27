#include "Level2.h"

void Level2::BulletMove_ID_10_1 (Bullet* bullet) {
    float time=Engine.PastTime-bullet->BaseTime;
    if (time<=0.5)
        bullet->TravelAtSpeed(100);
    else if (time<=1.5)
        bullet->TravelAtSpeed(20);
    else {
        bullet->SetAngle(-atan2f(Engine.Player->Position.y-bullet->Sprite.getPosition().y, Engine.Player->Position.x-bullet->Sprite.getPosition().x));
        bullet->SetMoveFunc(Level2::BulletMove_ID_10_2);
    }
}

void Level2::BulletMove_ID_10_2 (Bullet* bullet){
    bullet->TravelAtSpeed(350);
}

///BOSS

void Level2::BossBulletMove_ID_1 (SuperBullet* sbullet) {
    sbullet->SetPosition(250+cos(sbullet->Angle)*(400-(Engine.PastTime-sbullet->BaseTime)*90),
                                300-sin(sbullet->Angle)*(400-(Engine.PastTime-sbullet->BaseTime)*90));
}

bool Level2::DeleteBullet_ID_1 (SuperBullet* sbullet) {
    if (Engine.PastTime-sbullet->BaseTime>=4.4)
        return true;
    else return false;
}

void Level2::BossBulletMove_ID_2_1 (SuperBullet* sbullet) {
    sbullet->SetPosition(250+cos(sbullet->Angle)*(400-(Engine.PastTime-sbullet->BaseTime)*120),
                         300+sin(sbullet->Angle)*(400-(Engine.PastTime-sbullet->BaseTime)*120));
}

bool Level2::DeleteBullet_ID_2_1 (SuperBullet* sbullet) {
    if (Engine.PastTime-sbullet->BaseTime>=8)
        return true;
    else return false;
}

void Level2::BossBulletMove_ID_2_2 (SuperBullet* sbullet) {
    sbullet->TravelAtSpeed(60);
}

bool Level2::DeleteBullet_ID_2_2 (SuperBullet* sbullet) {
    if  (Engine.PastTime-sbullet->BaseTime>15)
        return true;
    else return false;
}

void Level2::BossBulletMove_ID_3_1 (SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    sbullet->SetPosition(250+cos(sbullet->Angle)*(600-60*time),
                         100-sin(sbullet->Angle)*(600-60*time));
    sbullet->Angle+=0.15*Engine.FrameTime;
}

void Level2::BossBulletMove_ID_3_2 (SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    sbullet->SetPosition(250+cos(sbullet->Angle)*(600-60*time),
                         100-sin(sbullet->Angle)*(600-60*time));
    sbullet->Angle-=0.15*Engine.FrameTime;
}

bool Level2::DeleteBullet_ID_3 (SuperBullet* sbullet) {
    if (Engine.PastTime-sbullet->BaseTime>=10)
        return true;
    else return false;
}

#define ANGLE_SPEED 1.1
#define MOVING_SPEED 130
void Level2::BossBulletMove_ID_4_1 (SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    sbullet->SetPosition(250+cos(sbullet->Angle+ANGLE_SPEED*time)*MOVING_SPEED*time, 180-sin(sbullet->Angle+ANGLE_SPEED*time)*MOVING_SPEED*time);
}

void Level2::BossBulletMove_ID_4_2 (SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    sbullet->SetPosition(250+cos(sbullet->Angle-ANGLE_SPEED*time)*MOVING_SPEED*time, 180-sin(sbullet->Angle-ANGLE_SPEED*time)*MOVING_SPEED*time);
}
#undef ANGLE_SPEED
#undef MOVING_SPEED

bool Level2::DeleteBullet_ID_4 (SuperBullet* sbullet) {
    if (Engine.PastTime-sbullet->BaseTime>5)
        return true;
    else return false;
}

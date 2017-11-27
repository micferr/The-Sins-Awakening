#include "Level3.h"

void Level3::BulletMove_ID_2 (Bullet* bullet) {
    float time=Engine.PastTime-bullet->BaseTime;
    if (time<0.4)
        bullet->TravelAtSpeed(40);
    //0.4 - 1.6: stops
    else if (time>1.6) {
        bullet->TravelAtSpeed(460);
    }
}

void Level3::BulletMove_ID_5 (Bullet* bullet) {
    float time=Engine.PastTime-bullet->BaseTime;
    bullet->Travel(cos(bullet->Angle)*70*time*Engine.FrameTime, -sin(bullet->Angle)*70*time*Engine.FrameTime);
}

void Level3::BulletMove_ID_11_1 (Bullet* bullet) {
    if (Engine.PastTime-bullet->BaseTime<=1)
        bullet->TravelAtSpeed(140);
    else
        bullet->Move=&Level3::BulletMove_ID_11_3_PREPARE;
}

void Level3::BulletMove_ID_11_2 (Bullet* bullet) {
    if (Engine.PastTime-bullet->BaseTime<=1)
        bullet->TravelAtSpeed(120);
    else
        bullet->Move=&Level3::BulletMove_ID_11_3_PREPARE;
}

void Level3::BulletMove_ID_11_3_PREPARE (Bullet* bullet) {
    float time=Engine.PastTime-bullet->BaseTime;
    if (time>1) { //else it doesn't move
        time-=1;
        bullet->SetAngle(-atan2f(Engine.Player->Position.y-bullet->Sprite.getPosition().y, Engine.Player->Position.x-bullet->Sprite.getPosition().x));
        bullet->Move=&Level3::BulletMove_ID_11_3;
    }
}

void Level3::BulletMove_ID_11_3 (Bullet* bullet) {
    bullet->TravelAtSpeed(180);
}

/// Boss

void Level3::BossBulletMove_ID_1 (SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    sbullet->SetPosition(   Engine.LevelBoss->Position.x+cos(sbullet->Angle)*300*time,
                            Engine.LevelBoss->Position.y-sin(sbullet->Angle)*300*time);
}

bool Level3::DeleteBullet_ID_1 (SuperBullet* sbullet) {
    if (Engine.PastTime-sbullet->BaseTime>4)
        return true;
    else return false;
}

void Level3::BossBulletMove_ID_2_1 (SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime, Angle=sbullet->Angle+time*PI/6;
    sbullet->SetPosition(250+cos(Angle)*100*time,
                         300-sin(Angle)*100*time);
}

bool Level3::DeleteBullet_ID_2_1 (SuperBullet* sbullet) {
    if (Engine.PastTime-sbullet->BaseTime>4)
        return true;
    else return false;
}

void Level3::BossBulletMove_ID_2_2 (SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    float Angle=sbullet->Angle-time*PI*1/6;
    sbullet->SetPosition(250+cos(Angle)*(400-time*40),
                         300-sin(Angle)*(400-time*40));
    sbullet->Sprite.setRotation(Angle*180/PI);
}

bool Level3::DeleteBullet_ID_2_2 (SuperBullet* sbullet) {
    if (Engine.PastTime-sbullet->BaseTime>=10)
        return true;
    else return false;
}

void Level3::BossBulletMove_ID_3_1 (SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    sbullet->SetPosition(250+cos(sbullet->Angle)*50*time,
                         300-sin(sbullet->Angle)*50*time);
    sbullet->Sprite.setRotation(time*45);
}

bool Level3::DeleteBullet_ID_3_1 (SuperBullet* sbullet) {
    if (Engine.PastTime-sbullet->BaseTime>=8)
        return true;
    else return false;
}

void Level3::BossBulletMove_ID_3_2 (SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    sbullet->SetPosition(250+cos(sbullet->Angle)*(400-100*time),
                         300-sin(sbullet->Angle)*(400-100*time));
}

bool Level3::DeleteBullet_ID_3_2 (SuperBullet* sbullet) {
    if (Engine.PastTime-sbullet->BaseTime>=4)
        return true;
    else return false;
}

void Level3::BossBulletMove_ID_4_1 (SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    float Angle=sbullet->Angle+time*PI/3, Radius=700-70*time;
    sbullet->SetPosition(250+cos(Angle)*Radius,
                                110-sin(Angle)*Radius);
}

bool Level3::DeleteBullet_ID_4_1 (SuperBullet* sbullet) {
    if (Engine.PastTime-sbullet->BaseTime>=10)
        return true;
    else return false;
}

void Level3::BossBulletMove_ID_4_2 (SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    float Angle=sbullet->Angle-time*PI/3, Radius=700-70*time;
    sbullet->SetPosition(250+cos(Angle)*Radius,
                                110-sin(Angle)*Radius);
}

bool Level3::DeleteBullet_ID_4_2 (SuperBullet* sbullet) {
    return Level3::DeleteBullet_ID_4_1(sbullet);
}

void Level3::BossBulletMove_ID_4_3 (SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    sbullet->SetPosition(250+cos(sbullet->Angle)*160*time,
                                110-sin(sbullet->Angle)*160*time);
}

bool Level3::DeleteBullet_ID_4_3 (SuperBullet* sbullet) {
    float x=sbullet->Sprite.getPosition().x, y=sbullet->Sprite.getPosition().y;
    if (x<25-sbullet->Radius ||
        x>475+sbullet->Radius ||
        y<25-sbullet->Radius ||
        y>575+sbullet->Radius)
        return true;
    else return false;
}

void Level3::BossBulletMove_ID_5_1_1 (SuperBullet* sbullet) {
    SpeedBullet* casted_sbullet=dynamic_cast<SpeedBullet*>(sbullet);
    float time=Engine.PastTime-casted_sbullet->BaseTime;
    if (time<1)
        sbullet->SetPosition(250-casted_sbullet->Speed*time, sbullet->Sprite.getPosition().y);
    else {
        sbullet->SetPosition(250-casted_sbullet->Speed, sbullet->Sprite.getPosition().y);
        sbullet->SetMoveFunc(Level3::BossBulletMove_ID_5_1_2);
    }
}

void Level3::BossBulletMove_ID_5_1_2 (SuperBullet* sbullet) {
    sbullet->Travel(0, 70*Engine.FrameTime);
}

bool Level3::DeleteBullet_ID_5_1 (SuperBullet* sbullet) {
    if (sbullet->Sprite.getPosition().y>575+sbullet->Radius)
        return true;
    else return false;
}

void Level3::BossBulletMove_ID_5_2_1 (SuperBullet* sbullet) {
    SpeedBullet* casted_sbullet=static_cast<SpeedBullet*>(sbullet);
    float time=Engine.PastTime-casted_sbullet->BaseTime;
    if (time<1)
        sbullet->SetPosition(250+casted_sbullet->Speed*time, sbullet->Sprite.getPosition().y);
    else {
        sbullet->SetPosition(250+casted_sbullet->Speed, sbullet->Sprite.getPosition().y);
        sbullet->SetMoveFunc(Level3::BossBulletMove_ID_5_2_2);
    }
}

void Level3::BossBulletMove_ID_5_2_2 (SuperBullet* sbullet) {
    sbullet->Travel(0, 70*Engine.FrameTime);
}

bool Level3::DeleteBullet_ID_5_2 (SuperBullet* sbullet) {
    if (sbullet->Sprite.getPosition().y>575+sbullet->Radius)
        return true;
    else return false;
}

void Level3::BossBulletMove_ID_5_3_1 (SuperBullet* sbullet) {
    float mult=(Engine.PastTime-sbullet->BaseTime)*static_cast<SpeedBullet*>(sbullet)->Speed;
    sbullet->TravelAtSpeed(mult);
    sbullet->Angle+=0.1*Engine.FrameTime;
    if (Engine.PastTime-sbullet->BaseTime>=1)
        sbullet->SetImageColor(255,255,255,255);
    else
        sbullet->SetImageColor(255,255,255,(Engine.PastTime-sbullet->BaseTime)*255);
}

void Level3::BossBulletMove_ID_5_3_2 (SuperBullet* sbullet) {
    float mult=(Engine.PastTime-sbullet->BaseTime)*static_cast<SpeedBullet*>(sbullet)->Speed;
    sbullet->TravelAtSpeed(mult);
}

bool Level3::DeleteBullet_ID_5_3 (SuperBullet* sbullet) {
    float x=sbullet->Sprite.getPosition().x, y=sbullet->Sprite.getPosition().y;
    if (x<25-sbullet->Radius || x>475+sbullet->Radius ||
        y<25-sbullet->Radius || y>575+sbullet->Radius)
        return true;
    else return false;
}

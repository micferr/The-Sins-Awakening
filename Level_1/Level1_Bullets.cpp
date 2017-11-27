#include "Level1.h"

void Level1::BulletMove_ID_6(Bullet* bullet) {
    float time=Engine.PastTime-bullet->BaseTime;
    int Speed;
    if (time<0.5)
        Speed=150;
    else
        Speed=100;
    bullet->TravelAtSpeed(Speed);
}

void Level1::BulletMove_ID_7(Bullet* bullet) {
    float time=Engine.PastTime-bullet->BaseTime;
    if (time<=0.5 || time>=1.5)
        bullet->Sprite.move(cos(bullet->Angle) * 200 * Engine.FrameTime, -sin(bullet->Angle) * 200 * Engine.FrameTime);
}

void Level1::BulletMove_ID_8(Bullet* bullet) {
    float time=Engine.PastTime-bullet->BaseTime;
    bullet->Sprite.move(cos(bullet->Angle) * (200*time) * Engine.FrameTime, -sin(bullet->Angle) * (200*time) * Engine.FrameTime);
}

void Level1::BossBulletMove_ID_2(SuperBullet *sbullet) {
    sbullet->SetPosition(sbullet->Sprite.getPosition().x, -120+500*(Engine.PastTime-sbullet->BaseTime));
}

bool Level1::DeleteBullet_ID_2(SuperBullet *sbullet) {
    return sbullet->Sprite.getPosition().y>=695;
}

void Level1::BossBulletMove_ID_3_1(SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    if (time<2) {
        sbullet->Sprite.setPosition(250+cos(sbullet->Angle)*68.75*time, //X
                                    300-sin(sbullet->Angle)*68.75*time);//Y
    }
    else {
        time-=2;
        if (Engine.LevelBoss->LifeBars.back()->Health>800)
            sbullet->Angle+=(22.5*PI/180)*Engine.FrameTime;
        else if (Engine.LevelBoss->LifeBars.back()->Health>400)
            sbullet->Angle+=(37.75*PI/180)*Engine.FrameTime;
        else
            sbullet->Angle+=(45*PI/180)*Engine.FrameTime;
        sbullet->Sprite.setRotation(-sbullet->Angle);
        sbullet->Sprite.setPosition(250+cos(sbullet->Angle)*137.5, //X
                                    300-sin(sbullet->Angle)*137.5);//Y
    }
}

void Level1::BossBulletMove_ID_3_2(SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    if (time<2) {
        sbullet->Sprite.setPosition(250+cos(sbullet->Angle)*137.5*time, //X
                                    300-sin(sbullet->Angle)*137.5*time);//Y
    }
    else {
        time-=2;
        if (Engine.LevelBoss->LifeBars.back()->Health>800)
            sbullet->Angle-=(22.5*PI/180)*Engine.FrameTime;
        else if (Engine.LevelBoss->LifeBars.back()->Health>400)
            sbullet->Angle-=(37.75*PI/180)*Engine.FrameTime;
        else
            sbullet->Angle-=(45*PI/180)*Engine.FrameTime;
        sbullet->Sprite.setRotation(-sbullet->Angle);
        sbullet->Sprite.setPosition(250+cos(sbullet->Angle)*275, //X
                                    300-sin(sbullet->Angle)*275);//Y

    }
}

void Level1::BossBulletMove_ID_3_3(SuperBullet* sbullet) {}

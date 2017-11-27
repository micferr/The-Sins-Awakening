#include "Level5.h"

void Level5::BulletMove_ID_1 (Bullet* bullet) {
    bullet->TravelAtSpeed(280);
}

void Level5::BulletMove_ID_2_1 (Bullet* bullet) {
    bullet->TravelAtSpeed(240);
}

void Level5::BulletMove_ID_2_2 (Bullet* bullet) {
    bullet->TravelAtSpeed(120);
}

void Level5::BulletMove_ID_3_1 (Bullet* bullet) {
    float time=Engine.PastTime-bullet->BaseTime;
    float position=120*time;
    bullet->SetPosition(250+cos(bullet->Angle)*position, 121-sin(bullet->Angle)*position);
}

void Level5::BulletMove_ID_3_2 (Bullet* bullet) {
    float time=Engine.PastTime-bullet->BaseTime;
    float position=100*time;
    bullet->SetPosition(250+cos(bullet->Angle)*position, 121-sin(bullet->Angle)*position);
}

void Level5::BulletMove_ID_3_3 (Bullet* bullet) {
    float time=Engine.PastTime-bullet->BaseTime;
    float position=80*time;
    bullet->SetPosition(250+cos(bullet->Angle)*position, 121-sin(bullet->Angle)*position);
}

void Level5::BulletMove_ID_4 (Bullet* bullet) {
    float movement=(Engine.PastTime-bullet->BaseTime<=0.6 ? 210 : 105)*Engine.FrameTime;
    bullet->Travel(cos(bullet->Angle)*movement, -sin(bullet->Angle)*movement);
}

void Level5::BulletMove_ID_5 (Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*180*Engine.FrameTime, -sin(bullet->Angle)*180*Engine.FrameTime);
}

void Level5::BulletMove_ID_6 (Bullet* bullet) {
    bullet->Travel(0, -sin(bullet->Angle)*100*Engine.FrameTime);
}

void Level5::BulletMove_ID_7 (Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*300*Engine.FrameTime, -sin(bullet->Angle)*300*Engine.FrameTime);
}

void Level5::BulletMove_ID_8 (Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*180*Engine.FrameTime, -sin(bullet->Angle)*180*Engine.FrameTime);
}

void Level5::BulletMove_ID_9 (Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*200*Engine.FrameTime, -sin(bullet->Angle)*200*Engine.FrameTime);
}

void Level5::BulletMove_ID_10_1 (Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*120*Engine.FrameTime, -sin(bullet->Angle)*120*Engine.FrameTime);
}

void Level5::BulletMove_ID_10_2 (Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*90*Engine.FrameTime, -sin(bullet->Angle)*90*Engine.FrameTime);
}

void Level5::BulletMove_ID_11 (Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*90*Engine.FrameTime, -sin(bullet->Angle)*90*Engine.FrameTime);
}

void Level5::BulletMove_ID_12 (Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*210*Engine.FrameTime, -sin(bullet->Angle)*210*Engine.FrameTime);
}

void Level5::BulletMove_ID_13 (Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*400*Engine.FrameTime, -sin(bullet->Angle)*400*Engine.FrameTime);
}

void Level5::BulletMove_ID_14 (Bullet* bullet) {
    float speed=Engine.PastTime-bullet->BaseTime<0.3?300:180;
    bullet->Travel(cos(bullet->Angle)*speed*Engine.FrameTime, -sin(bullet->Angle)*speed*Engine.FrameTime);
}

void Level5::BulletMove_ID_15 (Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*200*Engine.FrameTime, -sin(bullet->Angle)*200*Engine.FrameTime);
}

void Level5::BulletMove_ID_16 (Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*380*Engine.FrameTime, -sin(bullet->Angle)*380*Engine.FrameTime);
}

void Level5::BulletMove_ID_17 (Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*130*Engine.FrameTime, -sin(bullet->Angle)*130*Engine.FrameTime);
}

void Level5::BulletMove_ID_18 (Bullet* bullet) {
    float time=Engine.PastTime-bullet->BaseTime;
    if (time<0.3)
        bullet->Travel(cos(bullet->Angle)*200*Engine.FrameTime, -sin(bullet->Angle)*200*Engine.FrameTime);
    else {
        time-=0.3;
        bullet->Travel(0, -60/2*Engine.FrameTime*(Engine.FrameTime+2*(bullet->BaseTime-Engine.PastTime)));
    }
}

/// Boss

void Level5::BossBulletMove_ID_1_1 (SuperBullet* sbullet) {
    float movement=(Engine.PastTime-sbullet->BaseTime>0.6?static_cast<SpeedBullet*>(sbullet)->Speed:120)*Engine.FrameTime;
    sbullet->Travel(cos(sbullet->Angle)*movement, -sin(sbullet->Angle)*movement);
}

void Level5::BossBulletMove_ID_1_2 (SuperBullet* sbullet) {
    float speed=static_cast<SpeedBullet*>(sbullet)->Speed;
    float movement=-(speed/1.3/2)*Engine.FrameTime*(Engine.FrameTime+2*(sbullet->BaseTime-Engine.PastTime));
    sbullet->Travel(cos(sbullet->Angle)*movement, -sin(sbullet->Angle)*movement);
    sbullet->Sprite.setRotation(atan2f(Engine.Player->Position.y-sbullet->Sprite.getPosition().y, Engine.Player->Position.x-sbullet->Sprite.getPosition().x)*180/PI);
}

bool Level5::DeleteBullet_ID_1_2 (SuperBullet* sbullet) {
    bool returnvalue=Engine.PastTime-sbullet->BaseTime>=1.3;
    if (returnvalue) {
        float BaseAngle=-atan2f(Engine.Player->Position.y-sbullet->Sprite.getPosition().y, Engine.Player->Position.x-sbullet->Sprite.getPosition().x)-0.1;
        for (unsigned i=0; i<5; ++i) {
            Engine.LevelBoss->Bullets.push_back(new SuperBullet);
            SuperBullet* explosionbullet=Engine.LevelBoss->Bullets.back();
            explosionbullet->SetImage(BULLET_2_RED);
            explosionbullet->SetImageColor(255,0,0);
            explosionbullet->SetRadius(12);
            explosionbullet->SetPosition(sbullet->Sprite.getPosition());
            explosionbullet->SetAngle(BaseAngle+0.05*i);
            explosionbullet->SetMoveFunc(Level5::BossBulletMove_ID_1_3);
            explosionbullet->SetDeleteFunc(DeleteFuncs::Directed_OutOfBound);
        }
    }
    return returnvalue;
}

void Level5::BossBulletMove_ID_1_3 (SuperBullet* sbullet) {
    sbullet->Travel(cos(sbullet->Angle)*230*Engine.FrameTime, -sin(sbullet->Angle)*230*Engine.FrameTime);
}

void Level5::BossBulletMove_ID_2_1_1 (SuperBullet* sbullet) {
    SpeedBullet* speedbullet=static_cast<SpeedBullet*>(sbullet);
    float time=Engine.PastTime-speedbullet->BaseTime;
    if (time<=0.8) sbullet->SetPosition(250+120*cos(speedbullet->Angle)*time, 120-120*sin(speedbullet->Angle)*time);
    else if (time>=2.6) {
        time-=2.6;
        sf::Vector2<float> PrevPosition=sbullet->Sprite.getPosition();
        sbullet->SetPosition(250+120*cos(speedbullet->Angle)*0.8-speedbullet->Speed*time*cos(speedbullet->Angle-0.4*time),
                             120-120*sin(speedbullet->Angle)*0.8+speedbullet->Speed*time*sin(speedbullet->Angle-0.4*time));
        sbullet->Sprite.setRotation(atan2f(sbullet->Sprite.getPosition().y-PrevPosition.y, sbullet->Sprite.getPosition().x-PrevPosition.x)*180/PI);
    }
}

void Level5::BossBulletMove_ID_2_1_2 (SuperBullet* sbullet) {
    SpeedBullet* speedbullet=static_cast<SpeedBullet*>(sbullet);
    float time=Engine.PastTime-speedbullet->BaseTime;
    if (time<=0.8) sbullet->SetPosition(250+120*cos(speedbullet->Angle)*time, 120-120*sin(speedbullet->Angle)*time);
    else if (time>=2.6) {
        time-=2.6;
        sf::Vector2<float> PrevPosition=sbullet->Sprite.getPosition();
        sbullet->SetPosition(250+120*cos(speedbullet->Angle)*0.8-speedbullet->Speed*time*cos(speedbullet->Angle+0.4*time),
                             120-120*sin(speedbullet->Angle)*0.8+speedbullet->Speed*time*sin(speedbullet->Angle+0.4*time));
        sbullet->Sprite.setRotation(atan2f(sbullet->Sprite.getPosition().y-PrevPosition.y, sbullet->Sprite.getPosition().x-PrevPosition.x)*180/PI);
    }
}

void Level5::BossBulletMove_ID_2_2 (SuperBullet* sbullet) {
    SpeedBullet* speedbullet=static_cast<SpeedBullet*>(sbullet);
    speedbullet->TravelAtSpeed(speedbullet->Speed);
}

void Level5::BossBulletMove_ID_3_1_START (SuperBullet* sbullet) {
    SpeedBullet* speedbullet=static_cast<SpeedBullet*>(sbullet);
    float time=Engine.PastTime-sbullet->BaseTime;
    if (time<=1) speedbullet->SetPosition(250+cos(speedbullet->Angle)*speedbullet->Speed*time-speedbullet->Speed/2*time*time*cos(speedbullet->Angle),
                                          300-sin(speedbullet->Angle)*speedbullet->Speed*time-speedbullet->Speed/2*time*time*-sin(speedbullet->Angle));
    else {
        sbullet->SetMoveFunc(BossBulletMove_ID_3_1_GO);
        sbullet->SetAngle(-atan2f(Engine.Player->Position.y-sbullet->Sprite.getPosition().y, Engine.Player->Position.x-sbullet->Sprite.getPosition().x));
        sbullet->Move(sbullet);
    }
}

void Level5::BossBulletMove_ID_3_1_GO (SuperBullet* sbullet) {
    sbullet->TravelAtSpeed(80);
}

bool Level5::DeleteBullet_ID_3_1 (SuperBullet* sbullet) {
    return DeleteFuncs::OutOfBound(sbullet) && Engine.PastTime-sbullet->BaseTime>3;
}

void Level5::BossBulletMove_ID_3_2 (SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    sbullet->SetPosition(250+cos(sbullet->Angle)*200*time, 300-sin(sbullet->Angle)*200*time);
}

void Level5::BossBulletMove_ID_4_1_1 (SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    sf::Vector2<float> PrevPosition=sbullet->Sprite.getPosition();

    if (time<=1.2) {
        sbullet->SetPosition(Engine.LevelBoss->Position.x+cos(sbullet->Angle)*60+cos(sbullet->Angle+PI+2*PI*time/1.2)*60,
                             Engine.LevelBoss->Position.y-sin(sbullet->Angle)*60-sin(sbullet->Angle+PI+2*PI*time/1.2)*60);
    }
    else {
        time-=1.2;
        sbullet->SetImageColor(0xFF,0x3A,0x3A);
        sbullet->SetPosition(Engine.LevelBoss->Position.x+cos(sbullet->Angle-PI/2-PI*(time/16))*90*time,
                             Engine.LevelBoss->Position.y-sin(sbullet->Angle-PI/2-PI*(time/16))*90*time);
    }

    sbullet->Sprite.setRotation(atan2f(sbullet->Sprite.getPosition().y-PrevPosition.y, sbullet->Sprite.getPosition().x-PrevPosition.x)*180/PI);
}

void Level5::BossBulletMove_ID_4_1_2 (SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    sf::Vector2<float> PrevPosition=sbullet->Sprite.getPosition();

    if (time<=1.2) {
        sbullet->SetPosition(Engine.LevelBoss->Position.x+cos(sbullet->Angle)*60+cos(sbullet->Angle+PI-2*PI*time/1.2)*60,
                             Engine.LevelBoss->Position.y-sin(sbullet->Angle)*60-sin(sbullet->Angle+PI-2*PI*time/1.2)*60);
    }
    else {
        time-=1.2;
        sbullet->SetImageColor(0xFF,0x3A,0x3A);
        sbullet->SetPosition(Engine.LevelBoss->Position.x+cos(sbullet->Angle-PI/2+PI*(time/16))*90*time,
                             Engine.LevelBoss->Position.y-sin(sbullet->Angle-PI/2+PI*(time/16))*90*time);
    }

    sbullet->Sprite.setRotation(atan2f(sbullet->Sprite.getPosition().y-PrevPosition.y, sbullet->Sprite.getPosition().x-PrevPosition.x)*180/PI);
}

bool Level5::DeleteBullet_ID_4_1 (SuperBullet* sbullet) {
    return Engine.PastTime-sbullet->BaseTime>18;
}

void Level5::BossBulletMove_ID_4_2(SuperBullet* sbullet) {
    sbullet->TravelAtSpeed(240);
}

void Level5::BossBulletMove_ID_5_1_1(SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    float Radius=550-std::min(470.f,time*50);
    sbullet->SetPosition(250+cos(sbullet->Angle+2*time)*Radius, 400-sin(sbullet->Angle+2*time)*Radius);
    sbullet->Sprite.setRotation(-atan2f(sbullet->Sprite.getPosition().y-400, sbullet->Sprite.getPosition().x-250)*180/PI);
}

void Level5::BossBulletMove_ID_5_1_2(SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    float Radius=550-std::min(470.f,time*50);
    sbullet->SetPosition(250+cos(sbullet->Angle-2*time)*Radius, 400-sin(sbullet->Angle-2*time)*Radius);
    sbullet->Sprite.setRotation(-atan2f(sbullet->Sprite.getPosition().y-400, sbullet->Sprite.getPosition().x-250)*180/PI);
}

void Level5::BossBulletMove_ID_5_2(SuperBullet* sbullet) {
    sbullet->TravelAtSpeed(150);
}

void Level5::BossBulletMove_ID_5_3(SuperBullet* sbullet) {
    sbullet->TravelAtSpeed(sbullet->Speed);
}

void Level5::BossBulletMove_ID_6_1(SuperBullet* sbullet) {
    sbullet->TravelAtSpeed(300);
}

bool Level5::DeleteBullet_ID_6_1(SuperBullet* sbullet) {
    bool Delete=Engine.PastTime-sbullet->BaseTime>=1.2;
    if (Delete) {
        Engine.LevelBoss->Bullets.push_back(new SuperBullet);
        SuperBullet* ssbullet=Engine.LevelBoss->Bullets.back();
        ssbullet->SetImage(BULLET_6);
        ssbullet->SetImageColor(0,128,0);
        ssbullet->SetRadius(9);
        ssbullet->SetPosition(sbullet->Sprite.getPosition());
        ssbullet->SetAngle(-atan2f(Engine.Player->Position.y-sbullet->Sprite.getPosition().y, Engine.Player->Position.x-sbullet->Sprite.getPosition().x));
        ssbullet->SetMoveFunc(Level5::BossBulletMove_ID_6_2);
    }
    return Delete;
}

void Level5::BossBulletMove_ID_6_2(SuperBullet* sbullet) {
    sbullet->TravelAtSpeed(90);
}

void Level5::BossBulletMove_ID_7_1_1(SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    sbullet->SetPosition(Engine.LevelBoss->Position.x+cos(sbullet->Angle)*70*time, Engine.LevelBoss->Position.y-sin(sbullet->Angle)*70*time);
}

void Level5::BossBulletMove_ID_7_1_2(SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    sbullet->SetPosition(Engine.LevelBoss->Position.x+cos(sbullet->Angle-0.3*time)*70*time, Engine.LevelBoss->Position.y-sin(sbullet->Angle-0.3*time)*70*time);
}

void Level5::BossBulletMove_ID_7_1_3(SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    sbullet->SetPosition(Engine.LevelBoss->Position.x+cos(sbullet->Angle+0.3*time)*70*time, Engine.LevelBoss->Position.y-sin(sbullet->Angle+0.3*time)*70*time);
}

bool Level5::DeleteBullet_ID_7_1(SuperBullet* sbullet) {
    return Engine.PastTime-sbullet->BaseTime>9;
}

void Level5::BossBulletMove_ID_7_2(SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    sbullet->SetPosition(Engine.LevelBoss->Position.x+cos(sbullet->Angle)*210*time, Engine.LevelBoss->Position.y-sin(sbullet->Angle)*210*time);
}

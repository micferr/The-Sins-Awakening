#include "Level7.h"

void Level7::OriginBullet::SetOrigin(float x, float y) {
    SetOrigin({x,y});
}

void Level7::OriginBullet::SetOrigin(const sf::Vector2<float>& origin) {
    OriginPosition=origin;
}

sf::Vector2<float> Level7::OriginBullet::GetOrigin() {
    return OriginPosition;
}

void Level7::BossBulletMove_ID_1_1(SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    float Movement= min(time,0.7f)*150+
                    max(time-0.7f,0.f)*sbullet->Speed;
    sbullet->SetPosition(250+cos(sbullet->Angle)*Movement,
                         150-sin(sbullet->Angle)*Movement);
}

#define RADIAL_SPEED 200
void Level7::BossBulletMove_ID_1_2_1(SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    float angle=sbullet->Angle+0.75*time;
    sf::Vector2<float> prevpos=sbullet->Sprite.getPosition();
    sbullet->SetPosition(250+cos(angle)*RADIAL_SPEED*time,
                         150-sin(angle)*RADIAL_SPEED*time);
    const sf::Vector2<float>& pos=sbullet->Sprite.getPosition();
    sbullet->Sprite.setRotation(180+atan2f(prevpos.y-pos.y, prevpos.x-pos.x)*180/PI);
}

void Level7::BossBulletMove_ID_1_2_2(SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    float angle=sbullet->Angle-0.75*time;
    sf::Vector2<float> prevpos=sbullet->Sprite.getPosition();
    sbullet->SetPosition(250+cos(angle)*RADIAL_SPEED*time,
                         150-sin(angle)*RADIAL_SPEED*time);
    const sf::Vector2<float>& pos=sbullet->Sprite.getPosition();
    sbullet->Sprite.setRotation(180+atan2f(prevpos.y-pos.y, prevpos.x-pos.x)*180/PI);
}
#undef RADIAL_SPEED

bool Level7::DeleteBullet_ID_1_2(SuperBullet* sbullet) {
    return Engine.PastTime-sbullet->BaseTime>3.3f;
}

void Level7::BossBulletMove_ID_2_1_1(SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    if (time>0.75 && time<=1.25)
        return;
    float angle=sbullet->Angle+1.6f*max(time-1.25f,0.f);
    float radius=min(time,0.75f)*270 + max(time-1.25f, 0.f)*160;
    sf::Vector2<float> prevpos=sbullet->Sprite.getPosition();
    sbullet->SetPosition(250+cos(angle)*radius, 300-sin(angle)*radius);
    const sf::Vector2<float> pos=sbullet->Sprite.getPosition();
    sbullet->Sprite.setRotation(-180+atan2f(prevpos.y-pos.y, prevpos.x-pos.x)*180/PI);
    if (time>1.25)
        sbullet->SetImageColor(128,0,0);
}

void Level7::BossBulletMove_ID_2_1_2(SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    if (time>0.75 && time<=1.25)
        return;
    float angle=sbullet->Angle-1.6f*max(time-1.25f,0.f);
    float radius=min(time,0.75f)*270 + max(time-1.25f, 0.f)*160;
    sf::Vector2<float> prevpos=sbullet->Sprite.getPosition();
    sbullet->SetPosition(250+cos(angle)*radius, 300-sin(angle)*radius);
    const sf::Vector2<float> pos=sbullet->Sprite.getPosition();
    sbullet->Sprite.setRotation(-180+atan2f(prevpos.y-pos.y, prevpos.x-pos.x)*180/PI);
    if (time>1.25)
        sbullet->SetImageColor(0,0,128);
}

bool Level7::DeleteBullet_ID_2_1(SuperBullet* sbullet) {
    return Engine.PastTime-sbullet->BaseTime>=4;
}

void Level7::BossBulletMove_ID_3_1(SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    float newangle=sbullet->Angle-0.8*time;
    float radius=min(90*time, 400.f);

    sbullet->SetPosition(250+cos(newangle)*radius, 300-sin(newangle)*radius);
}

bool Level7::DeleteBullet_ID_3_2(SuperBullet* sbullet) {
    float x=sbullet->Sprite.getPosition().x, y=sbullet->Sprite.getPosition().y;
    return (x>248 && x<252 && y>298 && y<302);
}

void Level7::BossBulletMove_ID_4_1_1(SuperBullet* sbullet) {
    OriginBullet* obullet=dynamic_cast<OriginBullet*>(sbullet);
    float time=Engine.PastTime-obullet->BaseTime;
    if (time<=0) return;

    float radius=time*50; //was 160
    float angle=obullet->Angle+0.7*time*2;
    sf::Vector2<float> prevpos=obullet->Sprite.getPosition();
    obullet->SetPosition(obullet->OriginPosition.x + radius*cos(angle),
                         obullet->OriginPosition.y - radius*sin(angle));
    sf::Vector2<float> pos=obullet->Sprite.getPosition();
    obullet->Sprite.setRotation(-180+atan2f(prevpos.y-pos.y, prevpos.x-pos.x)*180/PI);

    //obullet->SetRadius(8+10*time);
}

void Level7::BossBulletMove_ID_4_1_2(SuperBullet* sbullet) {
    OriginBullet* obullet=dynamic_cast<OriginBullet*>(sbullet);
    float time=Engine.PastTime-obullet->BaseTime;
    if (time<=0) return;

    float radius=time*50;
    float angle=obullet->Angle-0.7*time*2;
    sf::Vector2<float> prevpos=obullet->Sprite.getPosition();
    obullet->SetPosition(obullet->OriginPosition.x + radius*cos(angle),
                         obullet->OriginPosition.y - radius*sin(angle));
    sf::Vector2<float> pos=obullet->Sprite.getPosition();
    obullet->Sprite.setRotation(-180+atan2f(prevpos.y-pos.y, prevpos.x-pos.x)*180/PI);

    //obullet->SetRadius(8+10*time);
}

bool Level7::DeleteBullet_ID_4_1(SuperBullet* sbullet) {
    return Engine.PastTime-sbullet->BaseTime>12.f;
}

void Level7::BossBulletMove_ID_4_2(SuperBullet* sbullet) {
    sbullet->TravelAtSpeed(sbullet->Speed);
    sbullet->SetRadius(max(50.f-static_cast<float>(Engine.PastTime-sbullet->BaseTime)*40,7.f));
}

bool Level7::DeleteBullet_ID_4_2(SuperBullet* sbullet) {
    return Engine.PastTime-sbullet->BaseTime>5;
}

void Level7::BossBulletMove_ID_5_1(SuperBullet* sbullet) {
    sf::Vector2<float> pos=sbullet->Sprite.getPosition();
    float Angle=-atan2f(Engine.Player->Position.y-pos.y, Engine.Player->Position.x-pos.x);
    sbullet->Travel(60*cos(Angle)*Engine.FrameTime, 60*-sin(Angle)*Engine.FrameTime);
}

void Level7::BossBulletMove_ID_5_2_1(SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    float Angle=sbullet->Angle+0.7*time;
    sbullet->SetPosition(250+cos(Angle)*300*time, 120-sin(Angle)*300*time);
}

void Level7::BossBulletMove_ID_5_2_2(SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    float Angle=sbullet->Angle-0.7*time;
    sbullet->SetPosition(250+cos(Angle)*300*time, 120-sin(Angle)*300*time);
}

bool Level7::DeleteBullet_ID_5_2(SuperBullet* sbullet) {
    return (Engine.PastTime-sbullet->BaseTime>2.5f);
}

void Level7::BossBulletMove_ID_6_2(SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    if (time<0.f)
        return;

    sbullet->SetRadius(10+200*time);
    sbullet->Radius-=10;
    sbullet->SetPosition(250+cos(sbullet->Angle)*280*time,
                         120-sin(sbullet->Angle)*280*time);
}

void Level7::BossBulletMove_ID_6_3(SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    if (time<0.f)
        return;

    float newangle=sbullet->Angle-0.9f*time;
    float movement=130*time;
    sf::Vector2<float> prevpos=sbullet->Sprite.getPosition();
    sbullet->SetPosition(250+cos(newangle)*movement,
                         120-sin(newangle)*movement);
    sf::Vector2<float> pos=sbullet->Sprite.getPosition();
    sbullet->Sprite.setRotation(-180+atan2f(prevpos.y-pos.y, prevpos.x-pos.x)*180/PI);
}

bool Level7::DeleteBullet_ID_6_3(SuperBullet* sbullet) {
    return (Engine.PastTime-sbullet->BaseTime>4.f);
}

/*void Level7::BossBulletMove_ID_7_1(SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    if (time<=0)
        return;

    sbullet->TravelAtSpeed(150);
}

bool Level7::DeleteBullet_ID_7_1(SuperBullet* sbullet) {
    float x=sbullet->Sprite.getPosition().x, y=sbullet->Sprite.getPosition().y;
    //if (sbullet->Sprite.getColor().r==255) {
        if (DeleteFuncs::OutOfBound(sbullet))
            return true;
    return false;
}
*/

void Level7::BossBulletMove_ID_7_1(SuperBullet* sbullet) {
    SpeedBullet* spbullet=dynamic_cast<SpeedBullet*>(sbullet);
    float time=min<float>(1.f, Engine.PastTime-sbullet->BaseTime);
    spbullet->SetPosition(Engine.LevelBoss->Position.x+cos(spbullet->Angle)*spbullet->Speed*time,
                          Engine.LevelBoss->Position.y-sin(spbullet->Angle)*spbullet->Speed*time);
}

void Level7::BossBulletMove_ID_7_2(SuperBullet* sbullet) {
    OriginBullet* obullet=dynamic_cast<OriginBullet*>(sbullet);
    float time=Engine.PastTime-obullet->BaseTime;
    obullet->SetPosition(obullet->OriginPosition.x+cos(obullet->Angle)*320*time,
                         obullet->OriginPosition.y-sin(obullet->Angle)*320*time);
}

void Level7::BossBulletMove_ID_7_4(SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime-0.1;
    if (time<=0) {
        sbullet->SetImageColor(255,255,255,min<float>(255.f, 192*(time/0.1)));
        sbullet->SetRadius(55-22*(time/0.1));
    }
    else {
        sbullet->SetImageColor(255,255,255,192);
        sbullet->SetRadius(33);
        sbullet->Radius=20;
        sbullet->TravelAtSpeed(160);
    }
}

void Level7::BossBulletMove_ID_7_5(SuperBullet* sbullet) {
    if (Engine.PastTime-sbullet->BaseTime<0.f)
        return;

    sbullet->TravelAtSpeed(130);
    float x=sbullet->Sprite.getPosition().x, y=sbullet->Sprite.getPosition().y;
    if (x<=30 || x>480 || y<30) {
        sbullet->SetImageColor(255, 192, 203);
        float Angle;
        if (x<30) Angle=Randomizer.GetRandom(280.f,315.f);
        else if (x>480) Angle=Randomizer.GetRandom(225.f, 260.f);
        else Angle=Randomizer.GetRandom(240.f,300.f);
        Angle*=PI/180;
        sbullet->SetAngle(Angle);
    }
}

/*void Level7::BossBulletMove_ID_9_2(SuperBullet* sbullet) {
    float speed=Engine.PastTime-sbullet->BaseTime<0.6?320:55;
    sbullet->TravelAtSpeed(speed);
}*/

/*void Level7::BossBulletMove_ID_9_3(SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    float speed=time>1.f?200.f:60.f;
    sbullet->TravelAtSpeed(speed);
}*/

bool Level7::DeleteBullet_ID_9_3(SuperBullet* sbullet) {
    sf::Vector2f pos=sbullet->Sprite.getPosition();
    return pos.x<-25||pos.x>525||pos.y<-25||pos.y>625;
}

/*void Level7::BossBulletMove_ID_9_4(SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    float xSpeed=dynamic_cast<SpeedBullet*>(sbullet)->Speed;
    sf::Vector2f prevpos=sbullet->Sprite.GetPosition();
    sbullet->SetPosition(250+xSpeed*time, 120-70*time+20*time*time);
    sf::Vector2f pos=sbullet->Sprite.GetPosition();
    sbullet->SetAngle(PI-atan2f(prevpos.y-pos.y, prevpos.x-pos.x));
}

bool Level7::DeleteBullet_ID_9_4(SuperBullet* sbullet) {
    return sbullet->Sprite.GetPosition().y>575+sbullet->Radius;
}*/

void Level7::BossBulletMove_ID_9_4(SuperBullet* sbullet) {
    float BulletToPlayerAngle=-atan2f(Engine.Player->Position.y-sbullet->Sprite.getPosition().y, Engine.Player->Position.x-sbullet->Sprite.getPosition().x);
    float BulletAngle=fmodf(sbullet->Angle, 2*PI);

    BulletToPlayerAngle=fmodf(BulletToPlayerAngle+(PI/2-BulletAngle), 2*PI);
    if (BulletToPlayerAngle>PI/2 && BulletToPlayerAngle<3/2*PI)
        BulletAngle+=0.4*Engine.FrameTime;
    else if (BulletToPlayerAngle<PI/2 || BulletToPlayerAngle>3/2*PI)
        BulletAngle-=0.4*Engine.FrameTime;

    sbullet->SetAngle(BulletAngle);
    sbullet->TravelAtSpeed(130);
}

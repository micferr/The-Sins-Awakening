#include "Level4.h"

void Level4::BulletMove_ID_1_1(Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*180*Engine.FrameTime, -sin(bullet->Angle)*180*Engine.FrameTime);
}

void Level4::BulletMove_ID_1_2(Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*90*Engine.FrameTime, -sin(bullet->Angle)*90*Engine.FrameTime);
}

void Level4::BulletMove_ID_2(Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*150*Engine.FrameTime, -sin(bullet->Angle)*150*Engine.FrameTime);
}

void Level4::BulletMove_ID_3_1(Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*180*Engine.FrameTime, -sin(bullet->Angle)*175*Engine.FrameTime);
}

void Level4::BulletMove_ID_3_2(Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*90*Engine.FrameTime, -sin(bullet->Angle)*90*Engine.FrameTime);
}

void Level4::BulletMove_ID_4 (Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*110*Engine.FrameTime, -sin(bullet->Angle)*110*Engine.FrameTime);
}

void Level4::BulletMove_ID_5_BOMB (Bullet* bullet) {
    float time=Engine.PastTime-bullet->BaseTime;
    float angle=-atan2f(Engine.Player->Position.y-bullet->Sprite.getPosition().y, Engine.Player->Position.x-bullet->Sprite.getPosition().x);
    bullet->Sprite.setRotation(-angle*180/PI);
    if (time<2) {
        bullet->SetPosition(bullet->Sprite.getPosition().x, 80+50*time*time);
    }
    else {
        Level4::BulletMove_ID_5_START_EXPLOSION(bullet);
        bullet->SetPosition(1000,1000); //Out of screen, will be deleted soon
    }
}

void Level4::BulletMove_ID_5_START_EXPLOSION (Bullet* bullet) {
    float AngleRad=-atan2f(Engine.Player->Position.y-bullet->Sprite.getPosition().y, Engine.Player->Position.x-bullet->Sprite.getPosition().x)-0.3;
    for (unsigned i=0; i<13; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_2_RED);
        bullptr->SetImageColor(255,0,0); //Total red
        bullptr->SetPosition(bullet->Sprite.getPosition());
        bullptr->SetRadius(15);
        bullptr->SetAngle(AngleRad+0.05*i);
        bullptr->SetMoveFunc(Level4::BulletMove_ID_5_EXPLOSION);
    }
}

void Level4::BulletMove_ID_5_EXPLOSION (Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*160*Engine.FrameTime, -sin(bullet->Angle)*160*Engine.FrameTime);
}

void Level4::BulletMove_ID_6 (Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*170*Engine.FrameTime, -sin(bullet->Angle)*170*Engine.FrameTime);
}

void Level4::BulletMove_ID_7 (Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*130*Engine.FrameTime, -sin(bullet->Angle)*130*Engine.FrameTime);
}

void Level4::BulletMove_ID_8_1 (Bullet* bullet) {
    float time=Engine.PastTime-bullet->BaseTime;
    bullet->SetPosition(250+cos(bullet->Angle)*50*time*time, 210-sin(bullet->Angle)*50*time*time);
}

void Level4::BulletMove_ID_8_2 (Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*80*Engine.FrameTime, -sin(bullet->Angle)*80*Engine.FrameTime);
}

void Level4::BulletMove_ID_9 (Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*150*Engine.FrameTime, -sin(bullet->Angle)*150*Engine.FrameTime);
}

void Level4::BulletMove_ID_10 (Bullet* bullet) {
    /*  Explanation:
        Data: {
            a - Acceleration, given value
            t2 - This frame's time
            t1 - Last frame's time
            P(t) - Position at time t, calculated via the formula: P(t)=1/2*a*(t^2)
            B->bT - Bullet->BaseTime
            En.fT - Engine.FrameTime
            En.pT - Engine.PastTime
        }
        Process: {
            We want to calculate dP, but Delta P is fine too.
            DeltaP=P(t2)-P(t1) //Find the Delta P, calculated by simply making the difference between two instants
            Now, let's develop the formula
            DeltaP = 1/2*a*(t2^2) - 1/2*a*(t1^2)
            DeltaP = a/2*(En.pT -B->bT -En.fT)^2 -a/2*(En.pT -b->bT)^2 //Expand t1 and t2
            DeltaP = a/2*(En.pT^2 +B->bT^2 +En.fT^2 -2En.pT*B->bT -2En.pT*En.fT +2B->bT*En.fT -En.pT^2 -B->bT^2 +2En.pT*B->bT) //Group everything for a/2, then expand the pow's (paper writing helps a lot)
            DeltaP = a/2*(En.fT^2 -2En.pT*En.fT +2B->bT*En.fT)
            DeltaP = a/2*En.fT*(En.fT -2En.pT +2B->bT) //Group by En.fT
            DeltaP = a/2*En.fT*[En.fT +2(B->bT-En.pT)] //Group by 2
            // END !!! :)
        }
    */
    float DeltaP=-60/2*Engine.FrameTime*(Engine.FrameTime+2*(bullet->BaseTime-Engine.PastTime)); //Why minus?
    bullet->Travel(DeltaP*cos(bullet->Angle), DeltaP*(-sin(bullet->Angle)));
}

void Level4::BulletMove_ID_11_1_START (Bullet* bullet) {
    float time=Engine.PastTime-bullet->BaseTime;
    if (time<1) {
        float Position=300*time-120*time*time;
        bullet->SetPosition(250+cos(bullet->Angle)*Position, 200-sin(bullet->Angle)*Position);
    }
    else {
        bullet->SetAngle(-atan2f(Engine.Player->Position.y-bullet->Sprite.getPosition().y, Engine.Player->Position.x-bullet->Sprite.getPosition().x));
        bullet->SetBaseTime(Engine.PastTime);
        bullet->SetMoveFunc(Level4::BulletMove_ID_11_1_GOSTRAIGHT);
    }
}

void Level4::BulletMove_ID_11_1_GOSTRAIGHT (Bullet* bullet) {
    //Level4::BulletMove_ID_10 for info
    float DeltaP=-150/2*Engine.FrameTime*(Engine.FrameTime+2*(bullet->BaseTime-Engine.PastTime));
    bullet->Travel(DeltaP*cos(bullet->Angle), DeltaP*-sin(bullet->Angle));
}

void Level4::BulletMove_ID_11_2 (Bullet* bullet) {
    bullet->Travel(cos(bullet->Angle)*110*Engine.FrameTime, -sin(bullet->Angle)*110*Engine.FrameTime);
}

//Boss

void Level4::BossBulletMove_ID_1_1_CLOCKWISE (SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    float angle=sbullet->Angle-1.7*time;
    sbullet->SetPosition(250+cos(angle)*100*time, 90-sin(angle)*100*time);
    sbullet->SetRadius(7+10*time);
    //sbullet->Sprite.setScale(0.28+0.4*pow(time,1.3), 0.28+0.4*pow(time,1.3)); //?
}

void Level4::BossBulletMove_ID_1_1_ANTICLOCKWISE (SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    float angle=sbullet->Angle-1.7*time;
    sbullet->SetPosition(250+cos(angle)*100*time, 90+sin(angle)*100*time);
    sbullet->SetRadius(7+10*time);
    //sbullet->Sprite.SetScale(0.28+0.4*pow(time,1.3), 0.28+0.4*pow(time,1.3)); //?
}

bool Level4::DeleteBullet_ID_1_1 (SuperBullet* sbullet) {
    if (Engine.PastTime-sbullet->BaseTime>=6.5)
        return true;
    return false;
}

void Level4::BossBulletMove_ID_1_2 (SuperBullet* sbullet) {
    sbullet->TravelAtSpeed(400);
}

bool Level4::DeleteBullet_ID_1_2 (SuperBullet* sbullet) {
    sf::Vector2<float> Position=sbullet->Sprite.getPosition();
    if (Position.x<-sbullet->Radius || Position.x>475+sbullet->Radius ||
        Position.y<-sbullet->Radius || Position.y>600+sbullet->Radius)
        return true;
    else return false;
}

void Level4::BossBulletMove_ID_2_1_FIRSTPART_1 (SuperBullet* sbullet) {
    SpeedBullet* speedbullet=dynamic_cast<SpeedBullet*>(sbullet);
    speedbullet->TravelAtSpeed(170);
    if (Engine.PastTime-speedbullet->BaseTime>=1) {
        float Angle=-atan2f(Engine.Player->Position.y-(-150), Engine.Player->Position.x-(-150));
        speedbullet->SetAngle(Randomizer.GetRandom(Angle-0.2f, Angle+0.2f));
        speedbullet->SetMoveFunc(Level4::BossBulletMove_ID_2_1_SECONDPART_1);
        speedbullet->SetDeleteFunc(Level4::DeleteBullet_ID_2_1_SECONDPART);
        speedbullet->SetSpeed(Randomizer.GetRandom(5.f,12.f));
        speedbullet->SetBaseTime(Engine.PastTime);
    }
}

void Level4::BossBulletMove_ID_2_1_FIRSTPART_2 (SuperBullet* sbullet) {
    SpeedBullet* speedbullet=dynamic_cast<SpeedBullet*>(sbullet);
    speedbullet->TravelAtSpeed(170);
    if (Engine.PastTime-speedbullet->BaseTime>=1) {
        float Angle=-atan2f(Engine.Player->Position.y-(-150), Engine.Player->Position.x-(650));
        speedbullet->SetAngle(Randomizer.GetRandom(Angle-0.2f, Angle+0.2f));
        speedbullet->SetMoveFunc(Level4::BossBulletMove_ID_2_1_SECONDPART_2);
        speedbullet->SetDeleteFunc(Level4::DeleteBullet_ID_2_1_SECONDPART);
        speedbullet->SetSpeed(Randomizer.GetRandom(5.f,12.f));
        speedbullet->SetBaseTime(Engine.PastTime);
    }
}

bool Level4::DeleteBullet_ID_2_1_FIRSTPART (SuperBullet* sbullet) {
    return false;
}

void Level4::BossBulletMove_ID_2_1_SECONDPART_1 (SuperBullet* sbullet) {
    SpeedBullet* speedbullet=dynamic_cast<SpeedBullet*>(sbullet);
    float time=Engine.PastTime-sbullet->BaseTime;
    sbullet->SetRadius(time*time*0.8);
    float formula_helper=(speedbullet->Speed*time+20*time*time);
    //sbullet->Sprite.SetPosition(-150 + cos(speedbullet->Angle)*speedbullet->Speed*time +cos(speedbullet->Angle)*20*time*time, [...]); This becomes
    sbullet->SetPosition(-150+cos(speedbullet->Angle)*formula_helper,
                         -150-sin(speedbullet->Angle)*formula_helper);
}

void Level4::BossBulletMove_ID_2_1_SECONDPART_2 (SuperBullet* sbullet) {
    SpeedBullet* speedbullet=dynamic_cast<SpeedBullet*>(sbullet);
    float time=Engine.PastTime-sbullet->BaseTime;
    sbullet->SetRadius(time*time*0.8);
    float formula_helper=(speedbullet->Speed*time+20*time*time);
    sbullet->SetPosition(+650+cos(speedbullet->Angle)*formula_helper,
                         -150-sin(speedbullet->Angle)*formula_helper);
}

bool Level4::DeleteBullet_ID_2_1_SECONDPART (SuperBullet* sbullet) {
    if (Engine.PastTime-sbullet->BaseTime>10) return true;
    else return false;
}

void Level4::BossBulletMove_ID_2_2 (SuperBullet* sbullet) {
    sbullet->TravelAtSpeed(400);
}

bool Level4::DeleteBullet_ID_2_2 (SuperBullet* sbullet) {
    sf::Vector2<float> Position=sbullet->Sprite.getPosition();
    if (Position.x<-sbullet->Radius || Position.x>475+sbullet->Radius ||
        Position.y<-sbullet->Radius || Position.y>600+sbullet->Radius)
        return true;
    else return false;
}

void Level4::BossBulletMove_ID_3_1 (SuperBullet* sbullet) {
    sbullet->TravelAtSpeed(230);
}

bool Level4::DeleteBullet_ID_3_1 (SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    if (time>2) {
        if (sbullet->Sprite.getColor().r==100) {
            sbullet->SetImageColor(255,60,60);
            sbullet->SetPosition(250,800);
        }
        if (sbullet->Sprite.getPosition().x<-15 || sbullet->Sprite.getPosition().x>515 || sbullet->Sprite.getPosition().y<-15)
            return true;
    }
    return false;
}

void Level4::BossBulletMove_ID_3_2_FIRSTPART (SuperBullet* sbullet) {
    SpeedBullet* speedbullet=dynamic_cast<SpeedBullet*>(sbullet);
    float time=Engine.PastTime-speedbullet->BaseTime;
    sf::Vector2<float> pos={cos(speedbullet->Angle)*speedbullet->Speed*time, -sin(speedbullet->Angle)*speedbullet->Speed*time+30*time*time};
    speedbullet->SetPosition(Engine.LevelBoss->Position.x+pos.x,
                             Engine.LevelBoss->Position.y+pos.y);
    speedbullet->Sprite.setRotation(atanf(pos.y/pos.x)*180/PI);
    if (speedbullet->Angle>PI/2)
        speedbullet->Sprite.setRotation(speedbullet->Sprite.getRotation()+180);
    if (time>=3) {
        float Angle=-atan2f(Engine.Player->Position.y-speedbullet->Sprite.getPosition().y, Engine.Player->Position.x-speedbullet->Sprite.getPosition().x);
        speedbullet->SetImageColor(200,40,40);
        speedbullet->SetAngle(Angle);
        speedbullet->SetMoveFunc(Level4::BossBulletMove_ID_3_2_SECONDPART);
    }
}

void Level4::BossBulletMove_ID_3_2_SECONDPART (SuperBullet* sbullet) {
    sbullet->TravelAtSpeed(95);
}

bool Level4::DeleteBullet_ID_3_2 (SuperBullet* sbullet) {
    if (sbullet->Sprite.getPosition().x<-40 || sbullet->Sprite.getPosition().y>540 ||
        sbullet->Sprite.getPosition().y<-40 || sbullet->Sprite.getPosition().y>640)
        return true;
    else return false;
}

void Level4::BossBulletMove_ID_4_1 (SuperBullet* sbullet) {
    float mov=((100+60*Engine.LevelBoss->Data[1])*Engine.FrameTime);
    sbullet->Travel(cos(sbullet->Angle)*mov, -sin(sbullet->Angle)*mov);
}

bool Level4::DeleteBullet_ID_4_1 (SuperBullet* sbullet) {
    if (Engine.PastTime-sbullet->BaseTime>15)
        return false;
    else return false;
}

void Level4::BossBulletMove_ID_5_1 (SuperBullet* sbullet) {
    sf::Vector2<float> newpos(sbullet->Sprite.getPosition().x+cos(sbullet->Angle)*200*Engine.FrameTime,
                              sbullet->Sprite.getPosition().y-sin(sbullet->Angle)*200*Engine.FrameTime);
    if (newpos.y>300)
        newpos.y=300;
    if (newpos.x<25)
        newpos.x=25;
    if (newpos.x>475)
        newpos.x=475;
    sbullet->SetPosition(newpos);
    float time=Engine.PastTime-sbullet->BaseTime;
    if (time>2) {
        sbullet->SetRadius(7+3*(time-2));
        if (sbullet->Radius>50)
            sbullet->SetRadius(50);
    }
}

bool Level4::DeleteBullet_ID_5_1 (SuperBullet* sbullet) {
    return false;
}

void Level4::BossBulletMove_ID_5_2_1 (SuperBullet* sbullet) {
    ///do not uncomment this /**/
    //SpeedBullet* speedbullet=dynamic_cast<SpeedBullet*>(sbullet);
    /*float time=Engine.PastTime-sbullet->BaseTime;
    sf::Vector2<float> pos={cos(speedbullet->Angle)*speedbullet->Speed*time, -sin(speedbullet->Angle)*speedbullet->Speed*time+30*time*time};
    speedbullet->Sprite.SetPosition(Engine.LevelBoss->Position.x+pos.x,
                                    Engine.LevelBoss->Position.y+pos.y);
    speedbullet->Sprite.SetRotation(-atanf(pos.y/pos.x)*180/PI);
    if (speedbullet->Angle>PI/2)
        speedbullet->Sprite.SetRotation(speedbullet->Sprite.GetRotation()+180);
    if (time>=4) {
        float Angle=-atan2f(Engine.Player->Position.y-sbullet->Sprite.GetPosition().y, Engine.Player->Position.x-sbullet->Sprite.GetPosition().x);
        speedbullet->Angle=Angle;
        speedbullet->Sprite.SetRotation(Angle*180/PI);
        speedbullet->Move=&Level4::BossBulletMove_ID_5_2_2;
        speedbullet->BaseTime=Engine.PastTime;
    }*/
    sbullet->TravelAtSpeed(sbullet->Speed);
}

void Level4::BossBulletMove_ID_5_2_2 (SuperBullet* sbullet) {
    ///do not uncomment
    /*float DeltaP=-60/2*Engine.FrameTime*(Engine.FrameTime+2*(sbullet->BaseTime-Engine.PastTime)); //Why minus?
    sbullet->Sprite.Move(DeltaP*cos(sbullet->Angle), DeltaP*(-sin(sbullet->Angle)));*/
}

bool Level4::DeleteBullet_ID_5_2 (SuperBullet* sbullet) {
    ///do not uncomment
    /*if (sbullet->Move==&Level4::BossBulletMove_ID_5_2_2 &&
        (sbullet->Sprite.GetPosition().x<25-sbullet->Radius || sbullet->Sprite.GetPosition().x>475+sbullet->Radius ||
         sbullet->Sprite.GetPosition().y<25-sbullet->Radius || sbullet->Sprite.GetPosition().y>575+sbullet->Radius))
        return true;
    else return false;*/
    return false; //Anti-warning
}

void Level4::BossBulletMove_ID_5_3 (SuperBullet* sbullet) {
    sbullet->TravelAtSpeed(100);
}

bool Level4::DeleteBullet_ID_5_3 (SuperBullet* sbullet) {
    if (sbullet->Sprite.getPosition().x<25-sbullet->Radius || sbullet->Sprite.getPosition().x>475+sbullet->Radius ||
        sbullet->Sprite.getPosition().y<25-sbullet->Radius || sbullet->Sprite.getPosition().y>575+sbullet->Radius)
        return true;
    else return false;
}

void Level4::BossBulletMove_ID_6_1 (SuperBullet* sbullet) {
    sbullet->SetPosition(Engine.LevelBoss->Position);
    //sbullet->Sprite.SetRotation(-90);
    float Radius=5+(Engine.PastTime-sbullet->BaseTime)*10;
    sbullet->SetRadius(Radius<=150?Radius:150);
    for (unsigned int i=0; i<Engine.PlayerBullets.size();) {
        if (pow(Engine.PlayerBullets.at(i)->Sprite.getPosition().x-sbullet->Sprite.getPosition().x,2) +
            pow(Engine.PlayerBullets.at(i)->Sprite.getPosition().y-sbullet->Sprite.getPosition().y,2) <=
            pow(sbullet->Radius, 2))
            Engine.DeleteBullet(Engine.PlayerBullets.at(i), 1);
        else
            ++i;
    }
}

bool Level4::DeleteBullet_ID_6_1 (SuperBullet* sbullet) {
    return false;
}

void Level4::BossBulletMove_ID_6_2 (SuperBullet* sbullet) {
    sbullet->TravelAtSpeed(120);
}

bool Level4::DeleteBullet_ID_6_2 (SuperBullet* sbullet) {
    if (sbullet->Sprite.getPosition().x<-25 || sbullet->Sprite.getPosition().x>525 ||
        sbullet->Sprite.getPosition().y>625)
        return true;
    else return false;
}

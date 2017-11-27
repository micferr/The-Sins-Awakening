#include "Level4.h"

void Level4::Shoot_ID_1(Enemy* enemy) {
    float Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)-0.6;
    for (short i=0; i<2; ++i) {
        for (short j=0; j<7; ++j) {
            Engine.EnemyBullets.push_back(new Bullet);
            Bullet* bullptr=Engine.EnemyBullets.back();
            bullptr->SetImage(BULLET_1_GREY);
            bullptr->SetPosition(enemy->Position);
            bullptr->SetRadius(15-i*5);
            bullptr->SetAngle(Angle+j*0.2);
            if (i==0)
                bullptr->SetMoveFunc(Level4::BulletMove_ID_1_1);
            else
                bullptr->SetMoveFunc(Level4::BulletMove_ID_1_2);
        }
    }
}

void Level4::Shoot_ID_2(Enemy* enemy) {
    float Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x);
    Engine.EnemyBullets.push_back(new Bullet);
    Bullet* bullptr=Engine.EnemyBullets.back();
    bullptr->SetImage(BULLET_1_MAGENTA);
    bullptr->SetPosition(enemy->Position);
    bullptr->SetRadius(8);
    bullptr->SetAngle(Angle);
    bullptr->SetMoveFunc(Level4::BulletMove_ID_2);
}

void Level4::Shoot_ID_3(Enemy* enemy) {
    float Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x);
    for (unsigned short i=0; i<2; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        if (i==0)
            bullptr->SetImage(BULLET_2_BLUE);
        else
            bullptr->SetImage(BULLET_1_BLUE);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(14-4*i);
        bullptr->SetAngle(Angle);
        if (i==0)
            bullptr->SetMoveFunc(Level4::BulletMove_ID_3_1);
        else
            bullptr->SetMoveFunc(Level4::BulletMove_ID_3_2);
    }
}

void Level4::Shoot_ID_4_1 (Enemy* enemy) {
    for (unsigned short i=0; i<10; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_3);
        bullptr->SetImageColor(0,0,10.625*(20-enemy->ShootTable.size()));
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(12);
        bullptr->SetAngle(PI/2+2*PI*i/10+enemy->ShootTable.size()*0.05);
        bullptr->SetMoveFunc(Level4::BulletMove_ID_4);
    }
}

void Level4::Shoot_ID_4_2(Enemy* enemy) {
    for (unsigned short i=0; i<10; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_3);
        bullptr->SetImageColor(0,0,10.625*(20-enemy->ShootTable.size()));
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(12);
        bullptr->SetAngle(PI/2-2*PI*i/10-enemy->ShootTable.size()*0.05);
        bullptr->SetMoveFunc(Level4::BulletMove_ID_4);
    }
}

void Level4::Shoot_ID_5 (Enemy* enemy) {
    Engine.EnemyBullets.push_back(new Bullet);
    Bullet* bullptr=Engine.EnemyBullets.back();
    bullptr->SetImage(BULLET_2_RED);
    bullptr->SetPosition(enemy->Position);
    bullptr->SetRadius(18);
    bullptr->SetAngle(-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.y));
    bullptr->SetMoveFunc(Level4::BulletMove_ID_5_BOMB);
    bullptr->SetBaseTime(Engine.PastTime);
}

void Level4::Shoot_ID_6 (Enemy* enemy) {
    Engine.EnemyBullets.push_back(new Bullet);
    Bullet* bullptr=Engine.EnemyBullets.back();
    bullptr->SetImage(BULLET_1_GREEN);
    bullptr->SetPosition(enemy->Position);
    bullptr->SetRadius(9);
    bullptr->SetAngle(-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x));
    bullptr->SetMoveFunc(Level4::BulletMove_ID_6);
}

void Level4::Shoot_ID_7 (Enemy* enemy) {
    float Angle;
    if (enemy->ShootTable.at(enemy->ShootTable.size()-2)->first==0) {
        Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)+(2*PI/24*enemy->ShootTable.size())-3*(2*PI/192);
        enemy->ShootTable.at(enemy->ShootTable.size()-1)->first=Angle;
    }
    else
        Angle=enemy->ShootTable.at(enemy->ShootTable.size()-1)->first;
    Angle+=2*PI/24*(enemy->ShootTable.size()%2);
    for (unsigned short i=0; i<12; ++i) {
        for (unsigned short j=0; j<7; ++j) {
            Engine.EnemyBullets.push_back(new Bullet);
            Bullet* bullptr=Engine.EnemyBullets.back();
            bullptr->SetImage(BULLET_2_BLUE);
            bullptr->SetPosition(enemy->Position);
            bullptr->SetRadius(6);
            bullptr->SetAngle(Angle + 2*PI/12*i + 2*PI/192*j);
            bullptr->SetMoveFunc(Level4::BulletMove_ID_7);
        }
    }
    if (++enemy->ShootTable.at(enemy->ShootTable.size()-2)->first==3) {
        for (unsigned short i=0; i<2; ++i) {
            delete enemy->ShootTable.back();
            enemy->ShootTable.pop_back();
        }
    }
}

void Level4::Shoot_ID_8_1 (Enemy* enemy) {
    float ClockWiseAngle=enemy->ShootTable.back()->first;
    enemy->ShootTable.back()->first-=PI/2/12.2;
    for (unsigned short i=0; i<10; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_1_BLACK);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(10);
        bullptr->SetAngle(ClockWiseAngle+2*PI/5*i);
        if (i>=5) bullptr->SetAngle(-PI/2-bullptr->Angle);
        bullptr->SetMoveFunc(Level4::BulletMove_ID_8_1);
        bullptr->SetBaseTime(enemy->BaseTime+enemy->ShootTable.front()->first);
    }
}

void Level4::Shoot_ID_8_2 (Enemy* enemy) {
    float Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x);
    for (unsigned short i=0; i<20; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_2_BLUE);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(13);
        bullptr->SetAngle(Angle+2*PI/20*i);
        bullptr->SetMoveFunc(Level4::BulletMove_ID_8_2);
    }
    if (enemy->ShootTable.size()==2) {
        delete enemy->ShootTable.back();
        enemy->ShootTable.pop_back();
    }
}

void Level4::Shoot_ID_9 (Enemy* enemy) {
    float Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)-0.6;
    for (unsigned short i=0; i<3; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_1_RED);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(11);
        bullptr->SetAngle(Angle+0.6*i);
        bullptr->SetMoveFunc(Level4::BulletMove_ID_9);
    }
}

void Level4::Shoot_ID_10_1 (Enemy* enemy) {
    if (enemy->ShootTable.size()==62) {
        enemy->ShootTable.at(enemy->ShootTable.size()-2)->first=Engine.Player->Position.y;
        enemy->ShootTable.at(enemy->ShootTable.size()-1)->first=Engine.Player->Position.x;
    }
    long double Angle=-atan2f(enemy->ShootTable.at(enemy->ShootTable.size()-2)->first-enemy->Position.y, enemy->ShootTable.at(enemy->ShootTable.size()-1)->first-enemy->Position.x)-0.002*pow(62-enemy->ShootTable.size(),2)+0.15;
    Engine.EnemyBullets.push_back((new Bullet));
    Bullet* bullptr=Engine.EnemyBullets.back();
    bullptr->SetImage(BULLET_2_BLUE);
    bullptr->SetPosition(170*enemy->ShootTable.front()->first, 130-20*enemy->ShootTable.front()->first);
    bullptr->SetRadius(16);
    bullptr->SetAngle(Angle);
    bullptr->SetMoveFunc(Level4::BulletMove_ID_10);
    bullptr->SetBaseTime(enemy->BaseTime+enemy->ShootTable.front()->first);
    if (enemy->ShootTable.size()==3) {
        delete enemy->ShootTable.back();
        enemy->ShootTable.pop_back();
        delete enemy->ShootTable.back();
        enemy->ShootTable.pop_back();
    }
}

void Level4::Shoot_ID_10_2 (Enemy* enemy) {
    if (enemy->ShootTable.size()==62) {
        enemy->ShootTable.at(enemy->ShootTable.size()-2)->first=Engine.Player->Position.y;
        enemy->ShootTable.at(enemy->ShootTable.size()-1)->first=Engine.Player->Position.x;
    }
    long double Angle=-atan2f(enemy->ShootTable.at(enemy->ShootTable.size()-2)->first-enemy->Position.y, enemy->ShootTable.at(enemy->ShootTable.size()-1)->first-enemy->Position.x)+0.002*pow(62-enemy->ShootTable.size(),2)-0.15;
    Engine.EnemyBullets.push_back((new Bullet));
    Bullet* bullptr=Engine.EnemyBullets.back();
    bullptr->SetImage(BULLET_2_BLUE);
    bullptr->SetPosition(500-170*enemy->ShootTable.front()->first, 130-20*enemy->ShootTable.front()->first);
    bullptr->SetRadius(16);
    bullptr->SetAngle(Angle);
    bullptr->SetMoveFunc(Level4::BulletMove_ID_10);
    bullptr->SetBaseTime(enemy->BaseTime+enemy->ShootTable.front()->first);
    if (enemy->ShootTable.size()==3) {
        delete enemy->ShootTable.back();
        enemy->ShootTable.pop_back();
        delete enemy->ShootTable.back();
        enemy->ShootTable.pop_back();
    }
}

void Level4::Shoot_ID_11_1 (Enemy* enemy) {
    float Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x);
    for (unsigned short i=0; i<20; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_2_GREY);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(8);
        bullptr->SetAngle(Angle+2*PI/20*i);
        bullptr->SetMoveFunc(Level4::BulletMove_ID_11_1_START);
        bullptr->SetBaseTime(enemy->BaseTime+enemy->ShootTable.front()->first);
    }
}

void Level4::Shoot_ID_11_2 (Enemy* enemy) {
    float Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)-0.1;
    for (unsigned short i=0; i<5; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_1_BLACK);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(12);
        bullptr->SetAngle(Angle+0.05*i);
        bullptr->SetMoveFunc(Level4::BulletMove_ID_11_2);
    }
}

///Boss

void Level4::BossShoot_ID_1_SETDATA (Boss* LevelBoss, float basetime) {
    LevelBoss->Data.clear();
    LevelBoss->Data.push_back(-1); //-1 or 1, do the bullets have to move clockwise (-1) or anticlockwise (+1) ?
    LevelBoss->Data.push_back(0); //Data[0]'s sign is flipped when this hits 5 (i.e. 5 shots)
    LevelBoss->Data.push_back(0); //Boss-to-Player angle
    LevelBoss->Data.push_back(0); //Unused value, needed for next spellcard
}

void Level4::BossShoot_ID_1_1 (Boss* LevelBoss, float basetime) {
    //Angle
    float Angle;
    if (LevelBoss->Data[1]==0) { //If this is the first shot
        LevelBoss->Data[2]=-atan2f(Engine.Player->Position.y-LevelBoss->Position.y, Engine.Player->Position.x-LevelBoss->Position.x); //Set Angle
    }
    Angle=LevelBoss->Data[2]+(LevelBoss->Data[1]*0.1*LevelBoss->Data[0]); //Original boss-to-player angle + <WhatShotThisIs>*<ClockwiseOrAntiClockwise>*0.1
    //Bullets
    for (unsigned short i=0; i<8; ++i) {
        LevelBoss->Bullets.push_back(new SuperBullet);
        SuperBullet* sbullet=LevelBoss->Bullets.back();
        sbullet->SetImage(BULLET_1_MAGENTA);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetRadius(7);
        sbullet->SetAngle(Angle+2*PI*i/8);
        if (LevelBoss->Data[0]==-1)
            sbullet->SetMoveFunc(Level4::BossBulletMove_ID_1_1_ANTICLOCKWISE);
        else
            sbullet->SetMoveFunc(Level4::BossBulletMove_ID_1_1_CLOCKWISE);
        sbullet->SetDeleteFunc(Level4::DeleteBullet_ID_1_1);
        sbullet->SetBaseTime(basetime);
    }
    //End
    ++LevelBoss->Data[1];
    if (LevelBoss->Data[1]==5) {
        LevelBoss->Data[0]=-LevelBoss->Data[0]; //Sign flip
        LevelBoss->Data[1]=0; //Restart
    }
}

void Level4::BossShoot_ID_1_2 (Boss* LevelBoss, float basetime) {
    if (pow(Engine.Player->Position.x-LevelBoss->Position.x, 2)+pow(Engine.Player->Position.y-LevelBoss->Position.y, 2) <= 4900) {
        float Angle=-atan2f(Engine.Player->Position.y-LevelBoss->Position.y, Engine.Player->Position.x-LevelBoss->Position.x)-0.1;
        for (unsigned short i=0; i<5; ++i) {
            LevelBoss->Bullets.push_back(new SuperBullet);
            SuperBullet* sbullet=LevelBoss->Bullets.back();
            sbullet->SetImage(BULLET_2_BLUE);
            sbullet->SetPosition(LevelBoss->Position);
            sbullet->SetRadius(21);
            if (i==0) sbullet->SetAngle(Angle);
            else if (i==1) sbullet->SetAngle(Angle+0.2);
            else if (i==2) sbullet->SetAngle(Angle+0.05);
            else if (i==3) sbullet->SetAngle(Angle+0.15);
            else sbullet->SetAngle(Angle+0.1);
            sbullet->SetMoveFunc(Level4::BossBulletMove_ID_1_2);
            sbullet->SetDeleteFunc(Level4::DeleteBullet_ID_1_2);
            sbullet->SetBaseTime(basetime);
            sbullet->SetDeletable(false);
        }
    }
}

void Level4::BossShoot_ID_2_SETDATA (Boss* LevelBoss, float basetime) {
    LevelBoss->Data.clear();
    LevelBoss->Data.push_back(Engine.PastTime);
    LevelBoss->Data.push_back(-atan2f(Engine.Player->Position.y-LevelBoss->Position.y, Engine.Player->Position.x-LevelBoss->Position.x)); //Just a random angle
    LevelBoss->Data.push_back(0); //0 or 1, specifies if Shoot_2_1 shoots FIRSTPART_1 or FIRSTPART_2
}

void Level4::BossShoot_ID_2_1 (Boss* LevelBoss, float basetime) {
    float Angle=Randomizer.GetRandom(float(PI/2-0.4f), float(PI/2+0.4f));
    LevelBoss->Bullets.push_back(new SpeedBullet);
    SuperBullet* sbullet=LevelBoss->Bullets.back();
    sbullet->SetImage(BULLET_5);
    sbullet->SetImageColor(255,60,60,255);
    sbullet->SetPosition(LevelBoss->Position);
    sbullet->SetRadius(9);
    sbullet->SetAngle(Angle);
    if (LevelBoss->Data[1]==0) sbullet->SetMoveFunc(Level4::BossBulletMove_ID_2_1_FIRSTPART_1);
    else sbullet->SetMoveFunc(Level4::BossBulletMove_ID_2_1_FIRSTPART_2);
    LevelBoss->Data[1]=static_cast<int>(LevelBoss->Data[1]+1)%2;
    sbullet->SetDeleteFunc(Level4::DeleteBullet_ID_2_1_FIRSTPART);
    sbullet->SetBaseTime(basetime);
}

void Level4::BossShoot_ID_2_2 (Boss* LevelBoss, float basetime) {
    if (pow(Engine.Player->Position.y-LevelBoss->Position.y,2)+pow(Engine.Player->Position.x-LevelBoss->Position.x,2)<=8100) { //If there is less than 70 distance between player and boss
        float Angle=-atan2f(Engine.Player->Position.y-LevelBoss->Position.y, Engine.Player->Position.x-LevelBoss->Position.x)-0.1;
        for (unsigned short i=0; i<5; ++i) {
            LevelBoss->Bullets.push_back(new SuperBullet);
            SuperBullet* sbullet=LevelBoss->Bullets.back();
            sbullet->SetImage(BULLET_2_BLUE);
            sbullet->SetPosition(LevelBoss->Position);
            sbullet->SetRadius(21);
            if (i==0) sbullet->SetAngle(Angle);
            else if (i==1) sbullet->SetAngle(Angle+0.2);
            else if (i==2) sbullet->SetAngle(Angle+0.05);
            else if (i==3) sbullet->SetAngle(Angle+0.15);
            else sbullet->SetAngle(Angle+0.1);
            sbullet->SetMoveFunc(Level4::BossBulletMove_ID_2_2);
            sbullet->SetDeleteFunc(Level4::DeleteBullet_ID_2_2);
            sbullet->SetBaseTime(basetime);
            sbullet->SetDeletable(false);
        }
    }
}

void Level4::BossShoot_ID_3_SETDATA (Boss* LevelBoss, float basetime) {
    LevelBoss->Data.clear();
    LevelBoss->Data.push_back(0); //Angle for Shoot_1
    LevelBoss->Data.push_back(-1); //Missile direction, +-1
    LevelBoss->Data.push_back(1); //Rotation sense for Shoot_1
}

void Level4::BossShoot_ID_3_1 (Boss* LevelBoss, float basetime) {
    float Angle=LevelBoss->Data[0];
    LevelBoss->Data[0]+=0.062*LevelBoss->Data[2];
    if (LevelBoss->Data[0]>PI) {
        LevelBoss->Data[0]=PI-(LevelBoss->Data[0]-PI);
        LevelBoss->Data[2]*=-1;
    }
    else if (LevelBoss->Data[0]<0) {
        LevelBoss->Data[0]*=-1;
        LevelBoss->Data[2]*=-1;
    }
    LevelBoss->Bullets.push_back(new SuperBullet);
    SuperBullet* sbullet=LevelBoss->Bullets.back();
    sbullet->SetImage(BULLET_5);
    sbullet->SetImageColor(100,10,10);
    sbullet->SetPosition(LevelBoss->Position);
    sbullet->SetRadius(7);
    sbullet->SetAngle(Angle);
    sbullet->SetMoveFunc(Level4::BossBulletMove_ID_3_1);
    sbullet->SetDeleteFunc(Level4::DeleteBullet_ID_3_1);
    sbullet->SetBaseTime(basetime);
}

void Level4::BossShoot_ID_3_2 (Boss* LevelBoss, float basetime) {
    float Angle=PI/2+(1.3+Randomizer.GetRandom(0.1f, 0.3f))*LevelBoss->Data[1];
    LevelBoss->Data[1]*=-1;
    LevelBoss->Bullets.push_back(new SpeedBullet);
    SpeedBullet* speedbullet=dynamic_cast<SpeedBullet*>(LevelBoss->Bullets.back());
    speedbullet->SetImage(BULLET_2_RED);
    speedbullet->SetPosition(LevelBoss->Position);
    speedbullet->SetRadius(13);
    speedbullet->SetAngle(Angle);
    speedbullet->SetMoveFunc(Level4::BossBulletMove_ID_3_2_FIRSTPART);
    speedbullet->SetDeleteFunc(Level4::DeleteBullet_ID_3_2);
    speedbullet->SetBaseTime(basetime);
    speedbullet->SetSpeed(Randomizer.GetRandom(40.f,60.f));
}

void Level4::BossShoot_ID_3_3 (Boss* LevelBoss, float basetime) {
    Level4::BossShoot_ID_2_2(LevelBoss, basetime);
}

void Level4::BossShoot_ID_4_SETDATA (Boss* LevelBoss, float basetime) {
    LevelBoss->Data.clear();
    LevelBoss->Data.push_back(0); //Main angle
    LevelBoss->Data.push_back(0.01); //Absorb and Bullet speed
    LevelBoss->Data.push_back(0); //Random value, needed for 6th lifebar
}

void Level4::BossShoot_ID_4_1 (Boss* LevelBoss, float basetime) {
    float Angle=LevelBoss->Data[0];
    LevelBoss->Data[0]+=0.09;
    for (unsigned short i=0; i<16; ++i) {
        LevelBoss->Bullets.push_back(new SuperBullet);
        SuperBullet* sbullet=Engine.LevelBoss->Bullets.back();
        sbullet->SetImage(BULLET_1_MAGENTA);
        sbullet->SetRadius(11);
        sbullet->SetAngle(Angle+2*PI*i/16);
        sbullet->SetPosition(Engine.Player->Position.x+cos(PI+sbullet->Angle)*700, Engine.Player->Position.y-sin(PI+sbullet->Angle)*700);
        sbullet->SetMoveFunc(Level4::BossBulletMove_ID_4_1);
        sbullet->SetDeleteFunc(Level4::DeleteBullet_ID_4_1);
        sbullet->SetBaseTime(basetime);
    }
}

void Level4::BossShoot_ID_4_2 (Boss* LevelBoss, float basetime) {
    Level4::BossShoot_ID_2_2(LevelBoss, basetime);
}

void Level4::BossShoot_ID_5_1 (Boss* LevelBoss, float basetime) {
    for (unsigned short i=0; i<2; ++i) {
        LevelBoss->Bullets.push_back(new SuperBullet);
        SuperBullet* sbullet=LevelBoss->Bullets.back();
        sbullet->SetImage(BULLET_1_RED);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetRadius(7);
        if (i==0)
            sbullet->SetAngle(-atan2f(300-100, 25-250));
        else
            sbullet->SetAngle(-atan2f(300-100, 475-250));
        sbullet->SetMoveFunc(Level4::BossBulletMove_ID_5_1);
        sbullet->SetDeleteFunc(Level4::DeleteBullet_ID_5_1);
        sbullet->SetBaseTime(basetime);
        sbullet->SetDeletable(false);
    }
}

void Level4::BossShoot_ID_5_2 (Boss* LevelBoss, float basetime) {
    ///do not uncomment
    /*LevelBoss->Bullets.push_back(new SpeedBullet);
    SpeedBullet* speedbullet=dynamic_cast<SpeedBullet*>(LevelBoss->Bullets.back());
    speedbullet->Sprite.SetImage(Engine.BulletImages[BULLET_2_BLUE]);
    speedbullet->Sprite.SetCenter(BULLET_2_CENTER);
    speedbullet->Sprite.SetPosition(LevelBoss->Position);
    speedbullet->Radius=6;
    speedbullet->Sprite.SetScale(0.24,0.24);
    if (sf::Randomizer::Random(0,1)<0.5)
        speedbullet->Angle=sf::Randomizer::Random(0.5f, 1.f);
    else
        speedbullet->Angle=sf::Randomizer::Random(float(PI-0.5f), PI-1.f);
    speedbullet->Sprite.SetRotation(speedbullet->Angle*180/PI);
    speedbullet->Move=&Level4::BossBulletMove_ID_5_2_1;
    speedbullet->CheckDeletion=&Level4::DeleteBullet_ID_5_2;
    speedbullet->BaseTime=basetime;
    speedbullet->Speed=sf::Randomizer::Random(60.f,75.f);*/
    ///do uncomment
    float Angle1=-atan2f(Engine.Player->Position.y-300, Engine.Player->Position.x-25);
    float Angle2=-atan2f(Engine.Player->Position.y-300, Engine.Player->Position.x-475);
    for (unsigned i=0; i<5; ++i) {
        for (unsigned j=0; j<2; ++j) {
            LevelBoss->Bullets.push_back(new SpeedBullet);
            SpeedBullet* speedbullet=dynamic_cast<SpeedBullet*>(LevelBoss->Bullets.back());
            speedbullet->SetImage(BULLET_2_BLUE);
            speedbullet->SetPosition(j==0?25:475,300);
            speedbullet->SetRadius(9);
            speedbullet->SetAngle(j==0?Angle1:Angle2);
            speedbullet->SetMoveFunc(Level4::BossBulletMove_ID_5_2_1);
            speedbullet->SetDeleteFunc(DeleteFuncs::OutOfBound);
            speedbullet->SetSpeed(140+i*10);
        }
    }
}

void Level4::BossShoot_ID_5_3 (Boss* LevelBoss, float basetime) {
    for (unsigned short i=0; i<2; ++i) {
        for (unsigned short j=0; j<18; ++j) {
            LevelBoss->Bullets.push_back(new SuperBullet);
            SuperBullet* sbullet=LevelBoss->Bullets.back();
            sbullet->SetImage(BULLET_1_RED);
            sbullet->SetPosition(25+450*i, 300);
            sbullet->SetRadius(10);
            sbullet->SetAngle(j*2*PI/18);
            sbullet->SetMoveFunc(Level4::BossBulletMove_ID_5_3);
            sbullet->SetDeleteFunc(Level4::DeleteBullet_ID_5_3);
        }
    }
}

void Level4::BossShoot_ID_5_4 (Boss* LevelBoss, float basetime) {
    Level4::BossShoot_ID_2_2(LevelBoss,basetime);
}

void Level4::BossShoot_ID_6_1 (Boss* LevelBoss, float basetime) {
    LevelBoss->Bullets.push_back(new SuperBullet);
    SuperBullet* sbullet=LevelBoss->Bullets.back();
    sbullet->SetImage(BULLET_5);
    sbullet->SetImageColor(255,60,60,192);
    sbullet->SetPosition(LevelBoss->Position);
    sbullet->SetRadius(5);
    sbullet->SetAngle(-PI/2);
    sbullet->SetMoveFunc(Level4::BossBulletMove_ID_6_1);
    sbullet->SetDeleteFunc(Level4::DeleteBullet_ID_6_1);
    sbullet->SetDeletable(false);
    sbullet->SetBaseTime(basetime);
    LevelBoss->Data.clear();
    LevelBoss->Data.push_back(0);
    LevelBoss->Data.push_back(basetime);
}

void Level4::BossShoot_ID_6_2 (Boss* LevelBoss, float basetime) {
    for (unsigned short i=0; i<8; ++i) {
        LevelBoss->Bullets.push_back(new SuperBullet);
        SuperBullet* sbullet=LevelBoss->Bullets.back();
        sbullet->SetImage(BULLET_5);
        sbullet->SetImageColor(100,10,10);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetRadius(9);
        sbullet->SetAngle(2*PI/8*i+2*PI/16);
        sbullet->SetMoveFunc(Level4::BossBulletMove_ID_6_2);
        sbullet->SetDeleteFunc(Level4::DeleteBullet_ID_6_2);
    }
}

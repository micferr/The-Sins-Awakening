#include "Level6.h"

void Level6::Shoot_ID_1(Enemy* enemy) {
    float Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x);
    for (unsigned i=0; i<24; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_2_BLUE);
        bullptr->SetRadius(11);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetAngle(Angle+2*PI/24*i);
        bullptr->SetMoveFunc(Level6::BulletMove_ID_1);
        bullptr->SetBaseTime(enemy);
    }
}

void Level6::Shoot_ID_2(Enemy* enemy) {
    float Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x);
    Engine.EnemyBullets.push_back(new Bullet);
    Bullet* bullet=Engine.EnemyBullets.back();
    bullet->SetImage(BULLET_1_LIGHTBLUE);
    bullet->SetRadius(9);
    bullet->SetPosition(enemy->Position);
    bullet->SetAngle(Angle);
    bullet->SetMoveFunc(Level6::BulletMove_ID_2);
}

void Level6::Shoot_ID_3(Enemy* enemy) {
    float BaseAngle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)-0.4;
    for (unsigned i=0; i<5; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullet=Engine.EnemyBullets.back();
        bullet->SetImage(BULLET_2_YELLOW);
        bullet->SetRadius(8);
        bullet->SetPosition(enemy->Position);
        bullet->SetAngle(BaseAngle+i*0.2);
        bullet->SetMoveFunc(Level6::BulletMove_ID_3);
    }
}

void Level6::Shoot_ID_4(Enemy* enemy) {
    float BaseAngle=Randomizer.GetRandom(0.f,PI);
    for (unsigned i=0; i<32; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullet=Engine.EnemyBullets.back();
        bullet->SetImage(BULLET_1_RED);
        bullet->SetRadius(10);
        bullet->SetPosition(enemy->Position);
        bullet->SetAngle(BaseAngle+2*PI/32*i);
        bullet->SetMoveFunc(Level6::BulletMove_ID_4);
        bullet->SetBaseTime(enemy);
    }
}

void Level6::Shoot_ID_5(Enemy* enemy) {
    float BaseAngle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)-0.9;
    for (unsigned i=0; i<7; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullet=Engine.EnemyBullets.back();
        bullet->SetImage(BULLET_1_BLUE);
        bullet->SetRadius(11);
        bullet->SetPosition(enemy->Position);
        bullet->SetAngle(BaseAngle+0.3*i);
        bullet->SetMoveFunc(BulletMove_ID_5);
    }
}

void Level6::Shoot_ID_6_1(Enemy* enemy) {
    float BaseAngle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)-0.05;
    for (unsigned i=0; i<3; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullet=Engine.EnemyBullets.back();
        bullet->SetImage(BULLET_5);
        bullet->SetImageColor(255,60,60);
        bullet->SetRadius(8);
        bullet->SetPosition(enemy->Position);
        bullet->SetAngle(BaseAngle+0.05*i);
        bullet->SetMoveFunc(BulletMove_ID_6_1);
    }
}

void Level6::Shoot_ID_6_2(Enemy* enemy) {
    float BaseAngle=enemy->ShootTable.size()%2==0?2*PI/36:0;
    for (unsigned i=0; i<18; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullet=Engine.EnemyBullets.back();
        bullet->SetImage(BULLET_1_YELLOW);
        bullet->SetRadius(9);
        bullet->SetPosition(enemy->Position);
        bullet->SetAngle(BaseAngle+2*PI/18*i);
        bullet->SetMoveFunc(BulletMove_ID_6_2);
        bullet->SetBaseTime(enemy);
    }
}

void Level6::Shoot_ID_7(Enemy* enemy) {
    float BaseAngle=Randomizer.GetRandom(0,PI);
    for (unsigned i=0; i<8; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullet=Engine.EnemyBullets.back();
        bullet->SetImage(BULLET_1_LIGHTBLUE);
        bullet->SetRadius(9);
        bullet->SetPosition(enemy->Position);
        bullet->SetAngle(BaseAngle+2*PI/8*i);
        bullet->SetMoveFunc(BulletMove_ID_7);
    }
}

void Level6::Shoot_ID_8_1(Enemy* enemy) {
    float BaseAngle=PI*3/2-0.19+((enemy->ShootTable.size()-1)%20)*0.04;
    for (unsigned i=0; i<16; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullet=Engine.EnemyBullets.back();
        bullet->SetImage(BULLET_1_BLACK);
        bullet->SetRadius(10);
        bullet->SetPosition(enemy->Position);
        bullet->SetAngle(BaseAngle+2*PI/16*i);
        bullet->SetMoveFunc(BulletMove_ID_8_1);
        bullet->SetBaseTime(enemy);
    }
}

void Level6::Shoot_ID_8_2(Enemy* enemy) {
    float BaseAngle=PI*3/2+0.19-((enemy->ShootTable.size()-1)%20)*0.04;
    for (unsigned i=0; i<16; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullet=Engine.EnemyBullets.back();
        bullet->SetImage(BULLET_1_BLACK);
        bullet->SetRadius(10);
        bullet->SetPosition(enemy->Position);
        bullet->SetAngle(BaseAngle+2*PI/16*i);
        bullet->SetMoveFunc(BulletMove_ID_8_1);
        bullet->SetBaseTime(enemy);
    }
}

void Level6::Shoot_ID_8_3(Enemy* enemy) {
    float BaseAngle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x);
    for (unsigned i=0; i<12; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullet=Engine.EnemyBullets.back();
        bullet->SetPosition(enemy->Position);
        bullet->SetImage(BULLET_1_RED);
        bullet->SetRadius(11);
        bullet->SetAngle(BaseAngle+2*PI/12*i);
        bullet->SetMoveFunc(BulletMove_ID_8_3);
    }
}

void Level6::Shoot_ID_9(Enemy* enemy) {
    float BaseAngle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)-0.25;
    for (unsigned i=0; i<11; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullet=Engine.EnemyBullets.back();
        bullet->SetPosition(enemy->Position);
        bullet->SetImage(BULLET_2_GREEN);
        bullet->SetRadius(11);
        bullet->SetAngle(BaseAngle+0.05*i);
        bullet->SetMoveFunc(BulletMove_ID_9);
    }
}

void Level6::Shoot_ID_10(Enemy* enemy) {
    float BaseAngle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x);
    for (unsigned i=0; i<12; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullet=Engine.EnemyBullets.back();
        bullet->SetImage(BULLET_1_RED);
        bullet->SetPosition(enemy->Position);
        bullet->SetRadius(9);
        bullet->SetAngle(BaseAngle+2*PI/12*i);
        bullet->SetMoveFunc(BulletMove_ID_10);
        bullet->SetBaseTime(enemy);
    }
}

void Level6::Shoot_ID_11 (Enemy*enemy) {
    float BaseAngle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)-0.03;
    for (unsigned i=0; i<3; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullet=Engine.EnemyBullets.back();
        bullet->SetImage(BULLET_1_RED);
        bullet->SetPosition(enemy->Position);
        bullet->SetRadius(9);
        bullet->SetAngle(BaseAngle+0.03*i);
        bullet->SetMoveFunc(BulletMove_ID_11);
    }
}

void Level6::Shoot_ID_12(Enemy* enemy) {
    float BaseAngle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)+Randomizer.GetRandom(-0.2f, +0.2f)-0.4;
    for (unsigned i=0; i<5; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullet=Engine.EnemyBullets.back();
        bullet->SetImage(BULLET_5);
        bullet->SetImageColor(255,60,60);
        bullet->SetPosition(enemy->Position);
        bullet->SetRadius(10);
        bullet->SetAngle(BaseAngle+0.2*i);
        bullet->SetMoveFunc(BulletMove_ID_12_FIRSTPHASE);
        bullet->SetBaseTime(enemy);
    }
}

void Level6::Shoot_ID_13_1(Enemy* enemy) {
    float BaseAngle=Randomizer.GetRandom(0.f,PI);
    for (unsigned i=0; i<3; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullet=Engine.EnemyBullets.back();
        bullet->SetImage(BULLET_1_LIGHTBLUE);
        bullet->SetPosition(enemy->Position);
        bullet->SetRadius(9);
        bullet->SetAngle(BaseAngle+2*PI/4*i);
        bullet->SetMoveFunc(BulletMove_ID_13);
    }
}

void Level6::Shoot_ID_13_2(Enemy* enemy) {
    float BaseAngle=Randomizer.GetRandom(0.f,PI);
    for (unsigned i=0; i<4; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullet=Engine.EnemyBullets.back();
        bullet->SetImage(BULLET_1_LIGHTBLUE);
        bullet->SetPosition(enemy->Position);
        bullet->SetRadius(9);
        bullet->SetAngle(BaseAngle+2*PI/4*i);
        bullet->SetMoveFunc(BulletMove_ID_13);
    }
}

void Level6::Shoot_ID_13_3(Enemy* enemy) {
    float BaseAngle=Randomizer.GetRandom(0.f,PI);
    for (unsigned i=0; i<5; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullet=Engine.EnemyBullets.back();
        bullet->SetImage(BULLET_1_LIGHTBLUE);
        bullet->SetPosition(enemy->Position);
        bullet->SetRadius(9);
        bullet->SetAngle(BaseAngle+2*PI/5*i);
        bullet->SetMoveFunc(BulletMove_ID_13);
    }
}

/// - BOSS

void Level6::BossShoot_ID_1_SETDATA(Boss* LevelBoss, float basetime) {
    LevelBoss->Data.clear();
    LevelBoss->Data.push_back(Randomizer.GetRandom(0.f,1.f));
    LevelBoss->Data.push_back(0);
}

void Level6::BossShoot_ID_1(Boss* LevelBoss, float basetime) {
    ++LevelBoss->Data[1];
    LevelBoss->Data[0]-=0.006*LevelBoss->Data[1];
    for (unsigned i=0; i<8; ++i) {
        LevelBoss->Bullets.push_back(new SuperBullet);
        SuperBullet* sbullet=LevelBoss->Bullets.back();
        sbullet->SetImage(BULLET_6);
        sbullet->SetImageColor(64,5,5);
        sbullet->SetRadius(7);
        sbullet->SetPosition(250,150);
        sbullet->SetAngle(LevelBoss->Data[0]+2*PI/8*i);
        sbullet->SetMoveFunc(BossBulletMove_ID_1);
        sbullet->SetBaseTime(basetime);
    }
}

void Level6::BossShoot_ID_2_1(Boss* LevelBoss, float basetime) {
    float BaseAngle=Randomizer.GetRandom(0.f,PI);
    for (unsigned i=0; i<30; ++i) {
        LevelBoss->Bullets.push_back(new SpeedBullet(180));
        SuperBullet* sbullet=LevelBoss->Bullets.back();
        sbullet->SetImage(BULLET_6);
        sbullet->SetImageColor(50,50,50);
        sbullet->SetRadius(8);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetAngle(BaseAngle+2*PI/30*i);
    }
}

void Level6::BossShoot_ID_2_2(Boss* LevelBoss, float basetime) {
    float BaseAngle=-atan2f(Engine.Player->Position.y-LevelBoss->Position.y, Engine.Player->Position.x-LevelBoss->Position.x);
    for (unsigned i=0; i<5; ++i) {
        for (unsigned j=0; j<10; ++j) {
            LevelBoss->Bullets.push_back(new SpeedBullet(100+j*10));
            SuperBullet* sbullet=LevelBoss->Bullets.back();
            sbullet->SetImage(BULLET_1_RED_WIDE);
            sbullet->SetImageColor(128,128,128);
            sbullet->Radius=90-3;
            sbullet->Sprite.setScale(90.f/25/6,90.f/25/6);
            sbullet->SetPosition(LevelBoss->Position);
            sbullet->SetAngle(BaseAngle+2*PI/5*i);
        }
    }
}

void Level6::BossShoot_ID_3_SETDATA(Boss* LevelBoss, float basetime) {
    LevelBoss->Data.clear();
    LevelBoss->Data.push_back(Randomizer.GetRandom(0.f,1.f));
    LevelBoss->Data.push_back(0);
}

void Level6::BossShoot_ID_3(Boss* LevelBoss, float basetime) {
    LevelBoss->Data[0]+=0.421;
    for (unsigned i=0; i<25; ++i) {
        for (unsigned j=0; j<5; ++j) {
            LevelBoss->Bullets.push_back(new SpeedBullet(Randomizer.GetRandom(150,250)));
            SuperBullet* sbullet=LevelBoss->Bullets.back();
            sbullet->SetImage(BULLET_6);
            sbullet->SetImageColor(20,20,100);
            sbullet->SetRadius(9);
            sbullet->SetPosition(LevelBoss->Position);
            sbullet->SetAngle(LevelBoss->Data[0]+2*PI/5*j+Randomizer.GetRandom(-0.25f,+0.25f));
        }
    }
}

void Level6::BossShoot_ID_4_SETDATA(Boss* LevelBoss, float basetime) {
    LevelBoss->Data.clear();
    LevelBoss->Data.push_back(Engine.PastTime);
}

void Level6::BossShoot_ID_4_1(Boss* LevelBoss, float basetime) {
    float BaseAngle=-atan2f(Engine.Player->Position.y-LevelBoss->Position.y, Engine.Player->Position.x-LevelBoss->Position.x);
    for (unsigned i=0; i<22; ++i) {
        LevelBoss->Bullets.push_back(new SpeedBullet(90));
        SuperBullet* sbullet=LevelBoss->Bullets.back();
        sbullet->SetImage(BULLET_6);
        sbullet->SetImageColor(20,100,20);
        sbullet->SetRadius(9);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetAngle(BaseAngle+2*PI/22*i);
    }
}

void Level6::BossShoot_ID_4_2(Boss* LevelBoss, float basetime) {
    for (unsigned i=0; i<6; ++i) {
        LevelBoss->Bullets.push_back(new SpeedBullet(130));
        SuperBullet* sbullet=LevelBoss->Bullets.back();
        sbullet->SetImage(BULLET_1_BLACK);
        sbullet->SetImageColor(100,100,100);
        sbullet->SetRadius(28);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetAngle(2*PI/6*i);
    }
}

void Level6::BossShoot_ID_4_3(Boss* LevelBoss, float basetime) {
    for (unsigned i=0; i<LevelBoss->Bullets.size(); ++i) {
        if (LevelBoss->Bullets[i]->Sprite.getColor()==sf::Color(100,100,100)) {
            for (unsigned j=1; j<3; ++j) {
                LevelBoss->Bullets.push_back(new SpeedBullet(80));
                SuperBullet* sbullet=LevelBoss->Bullets.back();
                sbullet->SetImage(BULLET_1_GREY);
                sbullet->SetRadius(8);
                sbullet->SetPosition(LevelBoss->Bullets[i]->Sprite.getPosition());
                sbullet->SetAngle(LevelBoss->Bullets[i]->Angle+2*PI/6*j);
            }
        }
    }
}

void Level6::BossShoot_ID_5_SETDATA(Boss* LevelBoss, float basetime) {
    LevelBoss->Data.clear();
    LevelBoss->Data.push_back(Engine.PastTime);
    LevelBoss->Data.push_back(0);
}

void Level6::BossShoot_ID_5(Boss* LevelBoss, float basetime) {
    LevelBoss->Data[1]+=0.12;
    for (unsigned i=0; i<6; ++i) {
        LevelBoss->Bullets.push_back(new SpeedBullet(290));
        SuperBullet* sbullet=LevelBoss->Bullets.back();
        sbullet->SetImage(BULLET_6);
        unsigned short color=i%2==0?25:128;
        sbullet->SetImageColor(color,color,color);
        sbullet->SetRadius(9);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetAngle(2*PI/6*i + sin(LevelBoss->Data[1])*2*PI/5*pow(-1,i));
    }
}

void Level6::BossShoot_ID_6_SETDATA(Boss* LevelBoss, float basetime) {
    LevelBoss->Data.clear();
    LevelBoss->Data.push_back(0);
}

void Level6::BossShoot_ID_6_1(Boss* LevelBoss, float basetime) {
    float BaseAngle=-atan2f(Engine.Player->Position.y-LevelBoss->Position.y, Engine.Player->Position.x-LevelBoss->Position.x);
    for (unsigned i=2; i<3; ++i) {
        for (unsigned j=0; j<8; ++j) {
            LevelBoss->Bullets.push_back(new SpeedBullet(70*pow(2,i)));
            SuperBullet* sbullet=LevelBoss->Bullets.back();
            sbullet->SetImage(BULLET_1_GREEN);
            sbullet->SetImageColor(128,128,128);
            sbullet->SetRadius(40);
            sbullet->SetPosition(LevelBoss->Position);
            sbullet->SetAngle(BaseAngle+2*PI/8*(float(j)+float(i)/2));
            if (i==2) {
                sbullet->SetDeleteFunc(Level6::DeleteBullet_ID_6_1);
                sbullet->SetBaseTime(basetime);
            }
        }
    }
}

void Level6::BossShoot_ID_7_SETDATA(Boss* LevelBoss, float basetime) {
    LevelBoss->Data.clear();
    LevelBoss->Data.push_back(Randomizer.GetRandom(0.f,1.f));
}

void Level6::BossShoot_ID_7_1(Boss* LevelBoss, float basetime) {
    LevelBoss->Data[0]+=0.25;
    #define RADIUS 100
    #define STRETCH 3
    #define NUM_OF_BULLETS 22
    for (unsigned i=0; i<NUM_OF_BULLETS; ++i) {
        LevelBoss->Bullets.push_back(new SpeedBullet);
        SpeedBullet* sbullet=dynamic_cast<SpeedBullet*>(LevelBoss->Bullets.back());
        sbullet->SetImage(BULLET_2_RED);
        sbullet->SetImageColor(128,128,128);
        sbullet->SetRadius(9.f);
        sbullet->SetPosition(LevelBoss->Position);
        float Angle_0 = 2*PI/NUM_OF_BULLETS*i;
        float X = cos(Angle_0)*RADIUS*STRETCH;
        float Y = sin(Angle_0)*RADIUS;
        float Angle = atan2f(Y, X);
        sbullet->SetAngle(Angle+LevelBoss->Data[0]);
        float Speed=sqrt(X*X + Y*Y);
        sbullet->SetSpeed(Speed);
    }
    #undef RADIUS
    #undef STRETCH
    #undef NUM_OF_BULLETS
}

void Level6::BossShoot_ID_8_SETDATA(Boss* LevelBoss, float basetime) {
    LevelBoss->Data.clear();
    LevelBoss->Data.push_back(0);
    LevelBoss->Data.push_back(0);
}

void Level6::BossShoot_ID_8_1(Boss* LevelBoss, float basetime) {
    /*LevelBoss->Data[0]=fmod(LevelBoss->Data[0]+1,2);
    #define RADIUS 80
    #define STRETCH 2.5
    #define NUM_OF_BULLETS 32
    SpeedBullet* sbullet;
    for (unsigned i=0; i<NUM_OF_BULLETS; ++i) {
        for (unsigned j=0; j<2; ++j) {
            LevelBoss->Bullets.push_back(new SpeedBullet);
            sbullet=dynamic_cast<SpeedBullet*>(LevelBoss->Bullets.back());
            sbullet->SetImage(BULLET_1_RED);
            sbullet->SetImageColor(128,128,128);
            sbullet->SetRadius(9);
            sbullet->SetPosition(LevelBoss->Position);
            float Angle_0=2*PI/NUM_OF_BULLETS*i;
            float X=cos(Angle_0)*RADIUS*STRETCH;
            float Y=sin(Angle_0)*RADIUS;
            float Angle=atan2f(Y,X);
            sbullet->SetAngle(Angle + j*PI/2 + LevelBoss->Data[0]*PI/4);
            float Speed=sqrt(X*X + Y*Y);
            sbullet->SetSpeed(Speed);
        }
    }
    float Speed=RADIUS*cos(PI/4*LevelBoss->Data[0])*STRETCH;
    for (unsigned i=0; i<32; ++i) {
        LevelBoss->Bullets.push_back(new SpeedBullet(Speed));
        sbullet=dynamic_cast<SpeedBullet*>(LevelBoss->Bullets.back());
        sbullet->SetImage(BULLET_1_RED);
        sbullet->SetImageColor(128,128,128);
        sbullet->SetRadius(9);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetAngle(2*PI/NUM_OF_BULLETS*i);
    }
    #undef RADIUS
    #undef STRETCH
    #undef NUM_OF_BULLETS*/
    float BaseAngle=-atan2f(Engine.Player->Position.y-LevelBoss->Position.y, Engine.Player->Position.x-LevelBoss->Position.x);
    for (unsigned i=0; i<44; ++i) {
        LevelBoss->Bullets.push_back(new SpeedBullet(340));
        SuperBullet* sbullet=LevelBoss->Bullets.back();
        sbullet->SetImage(BULLET_6);
        sbullet->SetImageColor(128,26,26);
        sbullet->SetRadius(9);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetAngle(BaseAngle+2*PI/44*i);
    }
}

void Level6::BossShoot_ID_8_2(Boss* LevelBoss, float basetime) {
    LevelBoss->Data[1]=fmod(LevelBoss->Data[1]+1,2);
    float LifePercentage=LevelBoss->LifeBars.back()->Health/1800*100;
    unsigned num_of_shoots= LifePercentage>=80?2:
                            LifePercentage>=60?4:
                            LifePercentage>=40?6:
                            LifePercentage>=20?8:
                            LifePercentage>=10?10:12;
    for (unsigned i=0; i<num_of_shoots; ++i) {
        LevelBoss->Bullets.push_back(new SuperBullet);
        SuperBullet* sbullet=LevelBoss->Bullets.back();
        sbullet->SetImage(BULLET_1_RED);
        sbullet->SetRadius(19);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetAngle(2*PI/num_of_shoots*i + LevelBoss->Data[1]*PI/num_of_shoots);
        sbullet->SetMoveFunc(Level6::BossBulletMove_ID_8_2);
        sbullet->SetDeleteFunc(Level6::DeleteBullet_ID_8_2);
        sbullet->SetBaseTime(basetime);
    }
}

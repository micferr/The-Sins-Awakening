#include "Level5.h"

void Level5::Shoot_ID_1 (Enemy* enemy) {
    float Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)-0.1;
    for (unsigned short i=0; i<3; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_2_RED);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(13);
        bullptr->SetAngle(Angle+0.1*i);
        bullptr->SetMoveFunc(Level5::BulletMove_ID_1);
    }
}

void Level5::Shoot_ID_2 (Enemy* enemy) {
    float Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x);
    for (unsigned short i=0; i<2; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        if (i==0)
            bullptr->SetImage(BULLET_1_RED);
        else
            bullptr->SetImage(BULLET_1_YELLOW);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(10);
        bullptr->SetAngle(Angle);
        if (i==0)
            bullptr->SetMoveFunc(Level5::BulletMove_ID_2_1);
        else
            bullptr->SetMoveFunc(Level5::BulletMove_ID_2_2);
    }
}

void Level5::Shoot_ID_3_1 (Enemy* enemy) {
    float BaseAngle=Randomizer.GetRandom(0.f,PI);
    for (unsigned short i=0; i<3; ++i) {
        for (unsigned short j=0; j<10; ++j) {
            Engine.EnemyBullets.push_back(new Bullet);
            Bullet* bullptr=Engine.EnemyBullets.back();
            bullptr->SetImage(BULLET_1_BLUE);
            bullptr->SetPosition(enemy->Position);
            bullptr->SetRadius(12);
            bullptr->SetAngle(BaseAngle-i*0.2+j*2*PI/10);
            if (i==0) bullptr->SetMoveFunc(BulletMove_ID_3_1);
            else if (i==1) bullptr->SetMoveFunc(BulletMove_ID_3_2);
            else bullptr->SetMoveFunc(BulletMove_ID_3_3);
            bullptr->SetBaseTime(Engine.PastTime);
        }
    }
}

void Level5::Shoot_ID_3_2 (Enemy* enemy) {
    float BaseAngle=Randomizer.GetRandom(0.f, PI);
    for (unsigned short i=0; i<3; ++i) {
        for (unsigned short j=0; j<10; ++j) {
            Engine.EnemyBullets.push_back(new Bullet);
            Bullet* bullptr=Engine.EnemyBullets.back();
            bullptr->SetImage(BULLET_1_BLUE);
            bullptr->SetPosition(enemy->Position);
            bullptr->SetRadius(12);
            bullptr->SetAngle(BaseAngle+i*0.2-j*2*PI/10);
            if (i==0) bullptr->SetMoveFunc(BulletMove_ID_3_1);
            else if (i==1) bullptr->SetMoveFunc(BulletMove_ID_3_2);
            else bullptr->SetMoveFunc(BulletMove_ID_3_3);
            bullptr->SetBaseTime(Engine.PastTime);
        }
    }
}

void Level5::Shoot_ID_4 (Enemy* enemy) {
    float Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)-0.1-0.5;
    for (unsigned short i=0; i<3; ++i) {
        for (unsigned short j=0; j<5; ++j) {
            Engine.EnemyBullets.push_back(new Bullet);
            Bullet* bullptr=Engine.EnemyBullets.back();
            bullptr->SetImage(BULLET_2_GREY);
            bullptr->SetPosition(enemy->Position);
            bullptr->SetRadius(13);
            bullptr->SetAngle(Angle+i*0.4+j*0.05);
            bullptr->SetMoveFunc(BulletMove_ID_4);
            bullptr->SetBaseTime(enemy);
        }
    }
}

void Level5::Shoot_ID_5 (Enemy* enemy) {
    float Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)-0.05;
    for (unsigned short i=0; i<3; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_2_RED);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(9);
        bullptr->SetAngle(Angle+i*0.05);
        bullptr->SetMoveFunc(BulletMove_ID_5);
    }
}

void Level5::Shoot_ID_6 (Enemy* enemy) {
    for (unsigned short i=0; i<2; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_2_GREY);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(12);
        bullptr->SetAngle(PI/2+PI*i);
        bullptr->SetMoveFunc(BulletMove_ID_6);
        bullptr->SetBaseTime(enemy);
    }
}

void Level5::Shoot_ID_7 (Enemy* enemy) {
    float BaseAngle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)-0.05;
    for (unsigned short i=0; i<3; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_2_RED);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(11);
        bullptr->SetAngle(BaseAngle+0.05*i);
        bullptr->SetMoveFunc(BulletMove_ID_7);
    }
}

void Level5::Shoot_ID_8 (Enemy* enemy) {
    for (unsigned short i=0; i<40; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_2_BLUE);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(8);
        bullptr->SetAngle(2*PI/80+2*PI/40*i);
        bullptr->SetMoveFunc(BulletMove_ID_8);
    }
}

void Level5::Shoot_ID_9 (Enemy* enemy) {
    Engine.EnemyBullets.push_back(new Bullet);
    Bullet* bullptr=Engine.EnemyBullets.back();
    bullptr->SetImage(BULLET_2_GREEN);
    bullptr->SetPosition(enemy->Position);
    bullptr->SetRadius(9);
    bullptr->SetAngle(-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x));
    bullptr->SetMoveFunc(BulletMove_ID_9);
}

void Level5::Shoot_ID_10 (Enemy* enemy) {
    float Angle=Randomizer.GetRandom(0,PI);
    Bullet* bullptr(nullptr);
    for (unsigned short i=0; i<40; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_2_RED);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(12);
        bullptr->SetAngle(Angle+2*PI/40*i);
        bullptr->SetMoveFunc(BulletMove_ID_10_1);
    }
    Angle+=2*PI/60;
    for (unsigned short i=0; i<40; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_2_YELLOW);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(8);
        bullptr->SetAngle(Angle+2*PI/40*i);
        bullptr->SetMoveFunc(BulletMove_ID_10_2);
    }
}

void Level5::Shoot_ID_11 (Enemy* enemy) {
    float Angle=PI/2+2*PI/40*(enemy->ShootTable.size()%2==0);
    for (unsigned short i=0; i<20; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_1_GREEN);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(25);
        bullptr->SetAngle(Angle+2*PI/20*i);
        bullptr->SetMoveFunc(BulletMove_ID_11);
    }
}

void Level5::Shoot_ID_12 (Enemy* enemy) {
    float num=30-enemy->ShootTable.size();
    for (unsigned short i=0; i<10; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(i<5 ? BULLET_2_RED : BULLET_2_BLUE);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(8);
        bullptr->SetAngle(i<5 ? (num*0.15+2*PI/5*i) : PI-(num*0.15+2*PI/5*i));
        bullptr->SetMoveFunc(BulletMove_ID_12);
        bullptr->SetBaseTime(enemy);
    }
}

void Level5::Shoot_ID_13 (Enemy* enemy) {
    float Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x);
    for (unsigned short i=0; i<16; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(enemy->Move==&Level5::Move_ID_13_1 ? BULLET_1_MAGENTA : BULLET_1_LIGHTBLUE);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(9);
        bullptr->SetAngle(Angle+2*PI/16*i);
        bullptr->SetMoveFunc(BulletMove_ID_13);
    }
}

void Level5::Shoot_ID_14 (Enemy* enemy) {
    float Angle=Randomizer.GetRandom(0,PI);
    for (unsigned short i=0; i<24; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_1_RED);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(8);
        bullptr->SetAngle(Angle+2*PI/24*i);
        bullptr->SetMoveFunc(BulletMove_ID_14);
        bullptr->SetBaseTime(enemy);
    }
}

void Level5::Shoot_ID_15 (Enemy* enemy) {
    float Angle=enemy->ShootTable.size()*0.08*(enemy->Move==&Level5::Move_ID_15_2 ? 1 : -1);
    for (unsigned short i=0; i<4; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_2_GREEN);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(10);
        bullptr->SetAngle(Angle+2*PI/4*i);
        bullptr->SetMoveFunc(BulletMove_ID_15);
    }
}

void Level5::Shoot_ID_16 (Enemy* enemy) {
    float Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x);
    Engine.EnemyBullets.push_back(new Bullet);
    Bullet* bullptr=Engine.EnemyBullets.back();
    bullptr->SetImage(BULLET_2_BLUE);
    bullptr->SetPosition(enemy->Position);
    bullptr->SetRadius(15);
    bullptr->SetAngle(Angle);
    bullptr->SetMoveFunc(BulletMove_ID_16);
}

void Level5::Shoot_ID_17 (Enemy* enemy) {
    for (unsigned short i=0; i<6; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_1_BLUE);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(50);
        bullptr->SetAngle(2*PI/6*i);
        bullptr->Sprite.setRotation(0);
        bullptr->SetMoveFunc(BulletMove_ID_17);
    }
}

void Level5::Shoot_ID_18 (Enemy* enemy) {
    float BaseAngle=Randomizer.GetRandom(0,2*PI);
    for (unsigned short i=0; i<3; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_1_YELLOW);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(10);
        bullptr->SetAngle(BaseAngle+2*PI/3*i);
        bullptr->SetMoveFunc(BulletMove_ID_18);
        bullptr->SetBaseTime(enemy);
    }
}

/// Boss

void Level5::BossShoot_ID_1_SETDATA (Boss* LevelBoss, float basetime) {
    LevelBoss->Data.push_back(basetime); //basetime
}

void Level5::BossShoot_ID_1_1 (Boss* LevelBoss, float basetime) {
    float BaseAngle=-atan2f(Engine.Player->Position.y-LevelBoss->Position.y, Engine.Player->Position.x-LevelBoss->Position.x);
    for (unsigned i=0; i<10; ++i) {
        for (unsigned j=0; j<2; ++j) {
            LevelBoss->Bullets.push_back(new SpeedBullet);
            SpeedBullet* sbullet=static_cast<SpeedBullet*>(LevelBoss->Bullets.back());
            sbullet->SetImage(BULLET_1_GREEN);
            sbullet->SetRadius(20);
            sbullet->SetPosition(LevelBoss->Position);
            sbullet->SetAngle(BaseAngle+2*PI/10*i);
            sbullet->SetMoveFunc(BossBulletMove_ID_1_1);
            sbullet->SetBaseTime(basetime);
            sbullet->SetSpeed(120*(j+1));
        }
    }
}

void Level5::BossShoot_ID_1_2 (Boss* LevelBoss, float basetime) {
    float BaseAngle=-atan2f(Engine.Player->Position.y-LevelBoss->Position.y, Engine.Player->Position.x-LevelBoss->Position.x)-0.4;
    for (unsigned short i=0; i<2; ++i) {
        LevelBoss->Bullets.push_back(new SpeedBullet);
        SuperBullet* sbullet=LevelBoss->Bullets.back();
        sbullet->SetImage(BULLET_2_RED);
        sbullet->SetRadius(12);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetAngle(BaseAngle+0.8*i);
        sbullet->SetMoveFunc(BossBulletMove_ID_1_2);
        sbullet->SetDeleteFunc(DeleteBullet_ID_1_2);
        sbullet->SetBaseTime(basetime);
        static_cast<SpeedBullet*>(sbullet)->SetSpeed(sqrt(pow(Engine.Player->Position.x-LevelBoss->Position.x,2)+
                                                          pow(Engine.Player->Position.y-LevelBoss->Position.y,2)/1.3));
    }
}

void Level5::BossShoot_ID_2_SETDATA (Boss* LevelBoss, float basetime) {
    LevelBoss->Data.clear();
    LevelBoss->Data.push_back(Engine.PastTime); //BaseTime
    LevelBoss->Data.push_back(0); //Shoot_1 rotation sense
    LevelBoss->Data.push_back(0); //Lateral shoots
}

void Level5::BossShoot_ID_2_1 (Boss* LevelBoss, float basetime) {
    float BaseAngle=Randomizer.GetRandom(0,PI);
    for (unsigned i=0; i<12; ++i) {
        for (unsigned j=0; j<16; ++j) {
            LevelBoss->Bullets.push_back(new SpeedBullet);
            SpeedBullet* sbullet=static_cast<SpeedBullet*>(LevelBoss->Bullets.back());
            sbullet->SetImage(BULLET_6);
            sbullet->SetImageColor(30,30,160);
            sbullet->SetRadius(7);
            sbullet->SetAngle(BaseAngle+2*PI/12*i+2*PI/16/6*j);
            sbullet->SetBaseTime(basetime);
            if (LevelBoss->Data[1]==0) {
                sbullet->SetMoveFunc(BossBulletMove_ID_2_1_1);
                sbullet->SetSpeed(50+j*10);
            }
            else {
                sbullet->SetMoveFunc(BossBulletMove_ID_2_1_2);
                sbullet->SetSpeed(190-j*10);
            }
        }
    }
    LevelBoss->Data[1]=fmod(LevelBoss->Data[1]+1.0,2.0);
}

void Level5::BossShoot_ID_2_2 (Boss* LevelBoss, float basetime) {
    if (++LevelBoss->Data[2]==3) {
        LevelBoss->Data[2]=0;
        return;
    }

    float Angle=-atan2f(Engine.Player->Position.y-LevelBoss->Position.y, Engine.Player->Position.x-LevelBoss->Position.x);
    for (int i=0; i<3; ++i) {
        LevelBoss->Bullets.push_back(new SpeedBullet);
        SpeedBullet* sbullet=static_cast<SpeedBullet*>(LevelBoss->Bullets.back());
        sbullet->SetImage(BULLET_1_GREEN);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetRadius(10);
        sbullet->SetAngle(Angle);
        sbullet->SetBaseTime(basetime);
        sbullet->SetSpeed(60*(i+1));
        sbullet->SetMoveFunc(BossBulletMove_ID_2_2);
    }
}

void Level5::BossShoot_ID_3_SETDATA (Boss* LevelBoss, float basetime) {
    LevelBoss->Data.clear();
    LevelBoss->Data.push_back(4); //Number of Shoot_3_2 - resets at 20
    LevelBoss->Data.push_back(0); //Angle to player
}

void Level5::BossShoot_ID_3_1 (Boss* LevelBoss, float basetime) {
    for (int i=0; i<120; ++i) {
        LevelBoss->Bullets.push_back(new SpeedBullet);
        SpeedBullet* speedbullet=static_cast<SpeedBullet*>(LevelBoss->Bullets.back());
        speedbullet->SetImage(BULLET_6);
        #define RANDOMCOLOR Randomizer.GetRandom(50,205)
        speedbullet->SetImageColor(RANDOMCOLOR,RANDOMCOLOR,RANDOMCOLOR);
        #undef RANDOMCOLOR
        speedbullet->SetPosition(LevelBoss->Position);
        speedbullet->SetRadius(8);
        speedbullet->SetAngle(Randomizer.GetRandom(0.f,2.f*PI));
        speedbullet->SetBaseTime(basetime);
        speedbullet->SetSpeed(Randomizer.GetRandom(30.f,550.f));
        speedbullet->SetMoveFunc(BossBulletMove_ID_3_1_START);
        speedbullet->SetDeleteFunc(DeleteBullet_ID_3_1);
    }
}

void Level5::BossShoot_ID_3_2 (Boss* LevelBoss, float basetime) {
    if (++LevelBoss->Data[0]==5) {
        LevelBoss->Data[0]=0;
        LevelBoss->Data[1]=-atan2f(Engine.Player->Position.y-LevelBoss->Position.y, Engine.Player->Position.x-LevelBoss->Position.x);
    }

    LevelBoss->Bullets.push_back(new SuperBullet);
    SuperBullet* sbullet=LevelBoss->Bullets.back();
    sbullet->SetImage(BULLET_2_GREEN);
    sbullet->SetRadius(11);
    sbullet->SetPosition(LevelBoss->Position);
    sbullet->SetAngle(LevelBoss->Data[1]);
    sbullet->SetBaseTime(basetime);
    sbullet->SetMoveFunc(BossBulletMove_ID_3_2);
}

void Level5::BossShoot_ID_4_SETDATA (Boss* LevelBoss, float basetime) {
    LevelBoss->Data.clear();
    LevelBoss->Data.push_back(0);
    LevelBoss->Data.push_back(0); //num of shots
}

void Level5::BossShoot_ID_4_1 (Boss* LevelBoss, float basetime) {
    ++LevelBoss->Data[1];
    for (unsigned i=0; i<2; ++i) {
        for (unsigned j=0; j<5; ++j) {
            LevelBoss->Bullets.push_back(new SuperBullet);
            SuperBullet* sbullet=LevelBoss->Bullets.back();
            sbullet->SetImage(BULLET_6);
            sbullet->SetImageColor(0x6A,0x6A,0xFF);
            sbullet->SetRadius(7);
            sbullet->SetPosition(LevelBoss->Position);
            sbullet->SetAngle(LevelBoss->Data[0]+2*PI/5*j+LevelBoss->Data[1]*PI/20*(i==1?-1:1));
            sbullet->SetBaseTime(basetime);
            sbullet->SetMoveFunc(i==0?BossBulletMove_ID_4_1_1:BossBulletMove_ID_4_1_2);
            sbullet->SetDeleteFunc(Level5::DeleteBullet_ID_4_1);
        }
    }
}

void Level5::BossShoot_ID_4_2 (Boss* LevelBoss, float basetime) {
    float Angle=-atan2f(Engine.Player->Position.y-LevelBoss->Position.y, Engine.Player->Position.x-LevelBoss->Position.x);
    LevelBoss->Bullets.push_back(new SuperBullet);
    SuperBullet* sbullet=LevelBoss->Bullets.back();
    sbullet->SetImage(BULLET_2_GREEN);
    sbullet->SetRadius(10);
    sbullet->SetPosition(LevelBoss->Position);
    sbullet->SetAngle(Angle);
    sbullet->SetBaseTime(basetime);
    sbullet->SetMoveFunc(BossBulletMove_ID_4_2);
}

void Level5::BossShoot_ID_5_1 (Boss* LevelBoss, float basetime) {
    for (unsigned i=0; i<4; ++i) {
        for (unsigned j=0; j<2; ++j) {
            LevelBoss->Bullets.push_back(new SuperBullet);
            SuperBullet* sbullet=LevelBoss->Bullets.back();
            sbullet->SetImage(BULLET_1_LIGHTBLUE);
            sbullet->SetRadius(23);
            sbullet->SetPosition(-100,-100);
            sbullet->SetAngle(90*PI/180*i);
            sbullet->SetBaseTime(basetime);
            sbullet->SetMoveFunc(j==0 ? BossBulletMove_ID_5_1_1 : BossBulletMove_ID_5_1_2);
            sbullet->Deletable=false;
        }
    }
}

void Level5::BossShoot_ID_5_2 (Boss* LevelBoss, float basetime) {
    for (unsigned i=0; i<8; ++i) {
        float BaseAngle=(LevelBoss->Bullets.at(i)->Sprite.getRotation()*PI/180);
        for (unsigned j=0; j<1; ++j) {
            LevelBoss->Bullets.push_back(new SuperBullet);
            SuperBullet* sbullet=LevelBoss->Bullets.back();
            sbullet->SetImage(LevelBoss->Bullets.at(i)->Move==Level5::BossBulletMove_ID_5_1_1?BULLET_1_BLUE:BULLET_1_RED);
            sbullet->SetRadius(9);
            sbullet->SetPosition(LevelBoss->Bullets.at(i)->Sprite.getPosition());
            sbullet->SetAngle(BaseAngle);
            sbullet->SetMoveFunc(BossBulletMove_ID_5_2);
        }
    }
}

void Level5::BossShoot_ID_5_3 (Boss* LevelBoss, float basetime) {
    float BaseAngle=-atan2f(Engine.Player->Position.y-LevelBoss->Position.y, Engine.Player->Position.x-LevelBoss->Position.x)-0.1;
    for (unsigned i=0; i<3; ++i) {
        LevelBoss->Bullets.push_back(new SpeedBullet);
        SpeedBullet* sbullet=static_cast<SpeedBullet*>(LevelBoss->Bullets.back());
        sbullet->SetImage(BULLET_1_GREEN);
        sbullet->SetRadius(10);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetAngle(BaseAngle+0.1*i);
        sbullet->SetMoveFunc(BossBulletMove_ID_5_3);
        sbullet->SetSpeed(50+150*(i==1?1:0));
    }
}

void Level5::BossShoot_ID_6_SETDATA(Boss* LevelBoss, float basetime) {
    LevelBoss->Data.clear();
    LevelBoss->Data.push_back(Engine.PastTime);
}

void Level5::BossShoot_ID_6_1(Boss* LevelBoss, float basetime) {
    float BaseAngle=-atan2f(Engine.Player->Position.y-LevelBoss->Position.y, Engine.Player->Position.x-LevelBoss->Position.x)-1;
    for (unsigned i=0; i<9; ++i) {
        LevelBoss->Bullets.push_back(new SuperBullet);
        SuperBullet* sbullet=LevelBoss->Bullets.back();
        sbullet->SetImage(BULLET_1_GREEN);
        sbullet->SetRadius(20);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetAngle(BaseAngle+0.25*i);
        sbullet->SetMoveFunc(BossBulletMove_ID_6_1);
        sbullet->SetDeleteFunc(DeleteBullet_ID_6_1);
        sbullet->SetBaseTime(basetime);
    }
}

void Level5::BossShoot_ID_7_SETDATA(Boss* LevelBoss, float basetime) {
    LevelBoss->Data.clear();
    LevelBoss->Data.push_back(-1);
}

void Level5::BossShoot_ID_7_1_MAIN(Boss* LevelBoss, float basetime) {
    switch (static_cast<int>(fmod(++LevelBoss->Data[0],4))) {
        case 0: BossShoot_ID_7_1_1(LevelBoss, basetime); break;
        case 1: BossShoot_ID_7_1_2(LevelBoss, basetime); break;
        case 2: BossShoot_ID_7_1_1(LevelBoss, basetime); break;
        case 3: BossShoot_ID_7_1_3(LevelBoss, basetime); break;
        default: break;
    }
    LevelBoss->LifeBars.back()->ShootTable[1]->first.second=1.4-((LevelBoss->LifeBars.back()->MaxHealth-LevelBoss->LifeBars.back()->Health)/LevelBoss->LifeBars.back()->MaxHealth)*0.8;
}

namespace {
    SuperBullet* BossShoot_ID_7_1_CREATEBULLET(Boss* LevelBoss, float basetime) {
        LevelBoss->Bullets.push_back(new SuperBullet);
        SuperBullet* sbullet=LevelBoss->Bullets.back();
        sbullet->SetImage(BULLET_1_GREEN);
        sbullet->SetRadius(8);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetDeleteFunc(Level5::DeleteBullet_ID_7_1);
        sbullet->SetBaseTime(basetime);

        return sbullet;
    }
}

void Level5::BossShoot_ID_7_1_1(Boss* LevelBoss, float basetime) {
    float Angle=-atan2f(Engine.Player->Position.y-LevelBoss->Position.y, Engine.Player->Position.x-LevelBoss->Position.x);
    for (unsigned i=0; i<60; ++i) {
        SuperBullet* sbullet=BossShoot_ID_7_1_CREATEBULLET(LevelBoss, basetime);
        sbullet->SetAngle(Angle+2*PI*i/60);
        sbullet->SetMoveFunc(BossBulletMove_ID_7_1_1);
    }
}

void Level5::BossShoot_ID_7_1_2(Boss* LevelBoss, float basetime) {
    float Angle=-atan2f(Engine.Player->Position.y-LevelBoss->Position.y, Engine.Player->Position.x-LevelBoss->Position.x);
    for (unsigned i=0; i<60; ++i) {
        SuperBullet* sbullet=BossShoot_ID_7_1_CREATEBULLET(LevelBoss, basetime);
        sbullet->SetAngle(Angle+2*PI*i/60);
        sbullet->SetMoveFunc(BossBulletMove_ID_7_1_2);
    }
}

void Level5::BossShoot_ID_7_1_3(Boss* LevelBoss, float basetime) {
    float Angle=-atan2f(Engine.Player->Position.y-LevelBoss->Position.y, Engine.Player->Position.x-LevelBoss->Position.x);
    for (unsigned i=0; i<60; ++i) {
        SuperBullet* sbullet=BossShoot_ID_7_1_CREATEBULLET(LevelBoss, basetime);
        sbullet->SetAngle(Angle+2*PI*i/60);
        sbullet->SetMoveFunc(BossBulletMove_ID_7_1_3);
    }
}

void Level5::BossShoot_ID_7_2(Boss* LevelBoss, float basetime) {
    float Angle=-atan2f(Engine.Player->Position.y-LevelBoss->Position.y, Engine.Player->Position.x-LevelBoss->Position.x)-0.03;
    for (unsigned i=0; i<3; ++i) {
        SuperBullet* sbullet=BossShoot_ID_7_1_CREATEBULLET(LevelBoss, basetime);
        sbullet->SetAngle(Angle+0.03*i);
        sbullet->SetMoveFunc(BossBulletMove_ID_7_2);
    }
    LevelBoss->LifeBars.back()->ShootTable.back()->first.second=1.4-((LevelBoss->LifeBars.back()->MaxHealth-LevelBoss->LifeBars.back()->Health)/LevelBoss->LifeBars.back()->MaxHealth)*1.1;
}

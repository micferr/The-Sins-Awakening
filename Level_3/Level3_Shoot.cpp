#include "Level3.h"

void Level3::Shoot_ID_1 (Enemy* enemy) {
    float Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x);
    for (short i=0; i<3; ++i) {
        Engine.EnemyBullets.push_back(new Bullet(0));
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_2_BLUE);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(7);
        bullptr->SetAngle(Angle);
        if (i==0) bullptr->SetSpeed(260);
        else if  (i==1) bullptr->SetSpeed(180);
        else bullptr->SetSpeed(100);
    }
}

void Level3::Shoot_ID_2 (Enemy* enemy) {
    float Angle_in_Degrees=-(enemy->ShootTable.at(0)->first-0.8)/0.025*(360/40);
    Engine.EnemyBullets.push_back(new Bullet);
    Bullet* bullptr=Engine.EnemyBullets.back();
    bullptr->SetImage(BULLET_1_GREEN);
    bullptr->SetPosition(enemy->Position);
    bullptr->SetRadius(10);
    bullptr->SetAngle(Angle_in_Degrees*PI/180);
    bullptr->SetBaseTime(Engine.PastTime);
    bullptr->SetMoveFunc(Level3::BulletMove_ID_2);
}

void Level3::Shoot_ID_3 (Enemy* enemy) {
    float Angle=-atan2f(enemy->Position.y-enemy->PrevPosition.y, enemy->Position.x-enemy->PrevPosition.x)+PI/2;
    Bullet* bullptr=NULL;
    for (short i=0; i<15; ++i) {
        Engine.EnemyBullets.push_back(new Bullet(150));
        bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_1_YELLOW);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(9);
        bullptr->SetAngle(Angle+PI/15*i);
    }
    Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)+PI/2;
    for (short i=0; i<5; ++i) {
        Engine.EnemyBullets.push_back(new Bullet(150));
        bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_1_RED);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(9);
        bullptr->SetAngle(Angle-PI/4*i);
    }
}

void Level3::Shoot_ID_4 (Enemy* enemy) {
    float Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)-PI+PI/6;
    for (unsigned i=0; i<60; ++i) {
        Engine.EnemyBullets.push_back(new Bullet(60));
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_3);
        bullptr->SetImageColor(0,0,128);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(14);
        bullptr->SetAngle(Angle+(5*i*PI/180));
    }
}

void Level3::Shoot_ID_5 (Enemy* enemy) {
    float Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)-0.6;
    for (short i=0; i<5; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_2_GREEN);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(12);
        bullptr->SetAngle(Angle+0.3*i);
        bullptr->SetMoveFunc(Level3::BulletMove_ID_5);
        bullptr->SetBaseTime(Engine.PastTime);
    }
}

void Level3::Shoot_ID_6_1 (Enemy* enemy) {
    float Angle=enemy->ShootTable.size()*0.2;
    for (short i=0; i<6; ++i) {
        Engine.EnemyBullets.push_back(new Bullet(160));
        Bullet* bullptr=Engine.EnemyBullets.back();
        if (i%2==0)
            bullptr->SetImage(BULLET_2_BLUE);
        else
            bullptr->SetImage(BULLET_2_RED);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(8);
        bullptr->SetAngle(Angle+PI/3*i); //360 deg /6 *i = 60deg*i
    }
}

void Level3::Shoot_ID_6_2 (Enemy* enemy) {
    float Angle=enemy->ShootTable.size()*(-0.2);
    for (short i=0; i<6; ++i) {
        Engine.EnemyBullets.push_back(new Bullet(160));
        Bullet* bullptr=Engine.EnemyBullets.back();
        if (i%2==0)
            bullptr->SetImage(BULLET_2_BLUE);
        else
            bullptr->SetImage(BULLET_2_RED);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(8);
        bullptr->SetAngle(Angle+PI/3*i); //360 deg /6 *i = 60deg*i
    }
}

void Level3::Shoot_ID_7 (Enemy* enemy) {
    float Angle=enemy->ShootTable.size()*0.1;
    for (short i=0; i<2; ++i) {
        for (short j=0; j<2; ++j) {
            Engine.EnemyBullets.push_back(new Bullet(200));
            Bullet* bullptr=Engine.EnemyBullets.back();
            bullptr->SetImage(BULLET_1_BLUE);
            bullptr->SetPosition(enemy->Position);
            bullptr->SetRadius(9);
            bullptr->SetAngle(Angle+i*PI-j*0.24);
        }
    }
}

void Level3::Shoot_ID_8 (Enemy* enemy) {
    float Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x);
    Engine.EnemyBullets.push_back(new Bullet(300));
    Bullet* bullptr=Engine.EnemyBullets.back();
    bullptr->SetImage(BULLET_2_GREY);
    bullptr->SetPosition(enemy->Position);
    bullptr->SetRadius(15);
    bullptr->SetAngle(Angle);
}

void Level3::Shoot_ID_9 (Enemy* enemy) {
    float Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)-0.05;
    for (short i=0; i<3; ++i) {
        Engine.EnemyBullets.push_back(new Bullet(190));
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_2_RED);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(13);
        bullptr->SetAngle(Angle+0.05*i);
    }
}

void Level3::Shoot_ID_10_1 (Enemy* enemy) {
    float Angle=-atan2f(enemy->Position.y-enemy->PrevPosition.y, enemy->Position.x-enemy->PrevPosition.x);
    for (short i=0; i<4; ++i) {
        Engine.EnemyBullets.push_back(new Bullet(100));
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_1_GREY);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(9);
        bullptr->SetAngle(Angle+PI/2*i);
    }
}

void Level3::Shoot_ID_10_2 (Enemy* enemy) {
    float Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x);
    for (short i=0; i<4; ++i) {
        Engine.EnemyBullets.push_back(new Bullet(100));
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_1_GREY);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(9);
        bullptr->SetAngle(Angle+PI/2*i);
    }
}

void Level3::Shoot_ID_11 (Enemy* enemy) {
    float anglestep=0.1256637061436; //7.2*PI/180;
    for (short i=0; i<100; ++i) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullptr=Engine.EnemyBullets.back();
        if (i>=50)
            bullptr->SetImage(BULLET_2_RED);
        else
            bullptr->SetImage(BULLET_2_YELLOW);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(10);
        bullptr->SetAngle(i*anglestep);
        if (i<50)
            bullptr->Move=&Level3::BulletMove_ID_11_1;
        else
            bullptr->Move=&Level3::BulletMove_ID_11_2;
        bullptr->SetBaseTime(Engine.PastTime);
    }
}

/// Boss

void Level3::BossShoot_ID_1 (Boss* LevelBoss, float basetime) {
    float Angle=-atan2f(Engine.Player->Position.y-LevelBoss->Position.y, Engine.Player->Position.x-LevelBoss->Position.x);
    for (short i=0; i<24; ++i) {
        LevelBoss->Bullets.push_back(new SuperBullet);
        SuperBullet* sbullet=LevelBoss->Bullets.back();
        sbullet->SetImage(BULLET_1_BLUE);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetRadius(11);
        sbullet->SetAngle(Angle+(15*i*PI/180));
        sbullet->SetMoveFunc(Level3::BossBulletMove_ID_1);
        sbullet->SetDeleteFunc(Level3::DeleteBullet_ID_1);
        sbullet->SetBaseTime(basetime);
    }
}

void Level3::BossShoot_ID_2_1 (Boss* LevelBoss, float basetime) {
    for (short i=0; i<4; ++i) {
        LevelBoss->Bullets.push_back(new SuperBullet);
        SuperBullet* sbullet=LevelBoss->Bullets.back();
        sbullet->SetImage(BULLET_3);
        sbullet->SetImageColor(LevelBoss->Data[0]*10,0,0,255);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetRadius(13);
        sbullet->SetAngle(LevelBoss->Data[2]+i*PI/2);
        sbullet->SetMoveFunc(Level3::BossBulletMove_ID_2_1);
        sbullet->SetDeleteFunc(Level3::DeleteBullet_ID_2_1);
        sbullet->SetBaseTime(basetime);
    }
    if (LevelBoss->Data[1]==1) { //Has to go black->red?
        if (LevelBoss->Data[0]==25) //Total red?
            LevelBoss->Data[1]=0; //Set to "red->black"
        else //Color!=Total Red
            LevelBoss->Data[0]++;
    }
    else { //Has to go red->black
        if (LevelBoss->Data[0]==0) //Total black
            LevelBoss->Data[1]=1; //Set to "black->red"
        else //Color!=Total black
            LevelBoss->Data[0]--;
    }
    LevelBoss->Data[2]+=6*PI/180;
}

void Level3::BossShoot_ID_2_2 (Boss* LevelBoss, float basetime) {
    for (short i=0; i<12; ++i) {
        LevelBoss->Bullets.push_back(new SuperBullet);
        SuperBullet* sbullet=LevelBoss->Bullets.back();
        sbullet->SetImage(BULLET_4);
        sbullet->SetImageColor(0xFF, 0x81, 0x00, 255);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetRadius(8);
        sbullet->SetAngle(i*PI/6);
        sbullet->SetMoveFunc(Level3::BossBulletMove_ID_2_2);
        sbullet->SetDeleteFunc(Level3::DeleteBullet_ID_2_2);
        sbullet->SetBaseTime(basetime);
    }
}

void Level3::BossShoot_ID_2_SET (Boss* LevelBoss, float basetime) {
    LevelBoss->Data.clear();
    LevelBoss->Data.push_back(0); //Range 0-51 - Multiplied x5 gives red component of #1 bullets
    LevelBoss->Data.push_back(1); //1 or 0: Going from black to red or red to black
    LevelBoss->Data.push_back(Randomizer.GetRandom(0.f,PI)); //Angle for double x
    LevelBoss->Data.push_back(Randomizer.GetRandom(0.f,PI)); //Angle for coins
}

void Level3::BossShoot_ID_3_1 (Boss* LevelBoss, float basetime) {
    for (short i=0; i<24; ++i) {
        LevelBoss->Bullets.push_back(new SuperBullet);
        SuperBullet* sbullet=LevelBoss->Bullets.back();
        sbullet->SetImage(BULLET_4);
        sbullet->SetImageColor(0xFF, 0x81, 0x00, 255);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetRadius(10);
        sbullet->SetAngle(i*PI/12+LevelBoss->Data[2]);
        sbullet->SetMoveFunc(Level3::BossBulletMove_ID_3_1);
        sbullet->SetDeleteFunc(Level3::DeleteBullet_ID_3_1);
        sbullet->SetBaseTime(basetime);
    }
    LevelBoss->Data[0]+=0.04;
}

void Level3::BossShoot_ID_3_2 (Boss* LevelBoss, float basetime) {
    float Angle=Randomizer.GetRandom(0.f,PI);
    for (short i=0; i<6; ++i) {
        for (short j=0; j<5; ++j) {
            LevelBoss->Bullets.push_back(new SuperBullet);
            SuperBullet* sbullet=LevelBoss->Bullets.back();
            sbullet->SetImage(BULLET_1_RED);
            sbullet->SetPosition(LevelBoss->Position);
            sbullet->SetRadius(11);
            sbullet->SetAngle(Angle+i*PI/3+j*PI/45);
            sbullet->SetMoveFunc(Level3::BossBulletMove_ID_3_2);
            sbullet->SetDeleteFunc(Level3::DeleteBullet_ID_3_2);
            sbullet->SetBaseTime(basetime);
        }
    }
}

void Level3::BossShoot_ID_3_SET (Boss* LevelBoss, float basetime) {
    LevelBoss->Data.clear();
    LevelBoss->Data.push_back(0);
}

void Level3::BossShoot_ID_4_1 (Boss* LevelBoss, float basetime) {
    float Angle=Randomizer.GetRandom(0.f, PI);
    for (short i=0; i<8; ++i) {
        for (short  j=0; j<11; ++j) {
            LevelBoss->Bullets.push_back(new SuperBullet);
            SuperBullet* sbullet=LevelBoss->Bullets.back();
            sbullet->SetImage(BULLET_4);
            sbullet->SetImageColor(0xFF, 0x81, 0x00, 0xFF);
            sbullet->SetPosition(LevelBoss->Position);
            sbullet->SetRadius(9);
            sbullet->SetAngle(Angle+(i*45+j*2.5)*PI/180);
            sbullet->SetMoveFunc(Level3::BossBulletMove_ID_4_1);
            sbullet->SetDeleteFunc(Level3::DeleteBullet_ID_4_1);
            sbullet->SetBaseTime(basetime);
        }
    }
}

void Level3::BossShoot_ID_4_2 (Boss* LevelBoss, float basetime) {
    float Angle=Randomizer.GetRandom(0.f, PI);
    for (short i=0; i<8; ++i) {
        for (short j=0; j<11; ++j) {
            LevelBoss->Bullets.push_back(new SuperBullet);
            SuperBullet* sbullet=LevelBoss->Bullets.back();
            sbullet->SetImage(BULLET_4);
            sbullet->SetImageColor(0xFF, 0x81, 0x00, 0xFF);
            sbullet->SetPosition(LevelBoss->Position);
            sbullet->SetRadius(9);
            sbullet->SetAngle(Angle+(i*45+j*2.5)*PI/180);
            sbullet->SetMoveFunc(Level3::BossBulletMove_ID_4_2);
            sbullet->SetDeleteFunc(Level3::DeleteBullet_ID_4_2);
            sbullet->SetBaseTime(basetime);
        }
    }
}

void Level3::BossShoot_ID_4_3 (Boss* LevelBoss, float basetime) {
    float Angle=-atan2f(Engine.Player->Position.y-LevelBoss->Position.y, Engine.Player->Position.x-LevelBoss->Position.x)-0.1;
    for (short i=0; i<3; ++i) {
        LevelBoss->Bullets.push_back(new SuperBullet);
        SuperBullet* sbullet=LevelBoss->Bullets.back();
        sbullet->SetImage(BULLET_1_RED);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetRadius(14);
        sbullet->SetAngle(Angle+i*0.1);
        sbullet->SetMoveFunc(Level3::BossBulletMove_ID_4_3);
        sbullet->SetDeleteFunc(Level3::DeleteBullet_ID_4_3);
        sbullet->SetBaseTime(basetime);
    }
}

void Level3::BossShoot_ID_5_1 (Boss* LevelBoss, float basetime) {
    float y=Randomizer.GetRandom(LevelBoss->Position.y-15, LevelBoss->Position.y+15);
    short v[]={9,10,10,10,11,11,11,12,12,13,13,13,14,15};
    short n=Randomizer.GetRandom(0,13);
    for (short i=16-v[n]; i<16; ++i) { //Seven times
        LevelBoss->Bullets.push_back(new SpeedBullet);
        SpeedBullet* sbullet=static_cast<SpeedBullet*>(LevelBoss->Bullets.back());
        sbullet->SetImage(BULLET_1_YELLOW);
        sbullet->SetPosition(LevelBoss->Position.x, y);
        sbullet->SetRadius(7.5);
        sbullet->SetMoveFunc(Level3::BossBulletMove_ID_5_1_1);
        sbullet->SetDeleteFunc(Level3::DeleteBullet_ID_5_1);
        sbullet->SetBaseTime(basetime);
        sbullet->SetSpeed(14.5*i);
    }
}

void Level3::BossShoot_ID_5_2 (Boss* LevelBoss, float basetime) {
    float y=Randomizer.GetRandom(LevelBoss->Position.y-15, LevelBoss->Position.y+15);
    short v[]={9,10,10,10,11,11,11,12,12,13,13,13,14,15};
    short n=Randomizer.GetRandom(0,13);
    for (short i=16-v[n]; i<16; ++i) { //Seven times
        LevelBoss->Bullets.push_back(new SpeedBullet);
        SpeedBullet* sbullet=static_cast<SpeedBullet*>(LevelBoss->Bullets.back());
        sbullet->SetImage(BULLET_1_YELLOW);
        sbullet->SetPosition(LevelBoss->Position.x, y);
        sbullet->SetRadius(7.5);
        sbullet->SetMoveFunc(Level3::BossBulletMove_ID_5_2_1);
        sbullet->SetDeleteFunc(Level3::DeleteBullet_ID_5_2);
        sbullet->SetBaseTime(basetime);
        sbullet->SetSpeed(14.5*i);
    }
}

void Level3::BossShoot_ID_5_3_1 (Boss* LevelBoss, float basetime) {
    float Angle=LevelBoss->Data[0]+Randomizer.GetRandom(-0.1f,+0.1f);
    for (short i=0; i<4; ++i) {
        LevelBoss->Bullets.push_back(new SpeedBullet);
        SpeedBullet* sbullet=static_cast<SpeedBullet*>(LevelBoss->Bullets.back());
        sbullet->SetImage(BULLET_1_GREEN);
        sbullet->SetImageColor(255,255,255,0);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetRadius(10);
        sbullet->SetAngle(Angle+PI/2*i);
        sbullet->SetMoveFunc(Level3::BossBulletMove_ID_5_3_1);
        sbullet->SetDeleteFunc(Level3::DeleteBullet_ID_5_3);
        sbullet->SetBaseTime(basetime);
        sbullet->SetSpeed(Randomizer.GetRandom(80,90));
    }
    LevelBoss->Data[0]-=PI/45;
}

void Level3::BossShoot_ID_5_3_2 (Boss* LevelBoss, float basetime) {
    float Angle=LevelBoss->Data[1]+Randomizer.GetRandom(-0.1f,+0.1f);
    for (short i=0; i<4; ++i) {
        LevelBoss->Bullets.push_back(new SpeedBullet);
        SpeedBullet* sbullet=static_cast<SpeedBullet*>(LevelBoss->Bullets.back());
        sbullet->SetImage(BULLET_1_LIGHTBLUE);
        sbullet->SetImageColor(255,255,255,0);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetRadius(10);
        sbullet->SetAngle(Angle+PI/2*i);
        sbullet->SetMoveFunc(Level3::BossBulletMove_ID_5_3_1);
        sbullet->SetDeleteFunc(Level3::DeleteBullet_ID_5_3);
        sbullet->SetBaseTime(basetime);
        sbullet->SetSpeed(Randomizer.GetRandom(100,110));
    }
    LevelBoss->Data[1]+=PI/30;
}

void Level3::BossShoot_ID_5_3_3 (Boss* LevelBoss, float basetime) {
    float Angle=LevelBoss->Data[2]+Randomizer.GetRandom(-0.1f,+0.1f);
    for (short i=0; i<4; ++i) {
        LevelBoss->Bullets.push_back(new SpeedBullet);
        SpeedBullet* sbullet=static_cast<SpeedBullet*>(LevelBoss->Bullets.back());
        sbullet->SetImage(BULLET_1_BLUE);
        sbullet->SetImageColor(255,255,255,0);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetRadius(10);
        sbullet->SetAngle(Angle+PI/2*i);
        sbullet->SetMoveFunc(Level3::BossBulletMove_ID_5_3_1);
        sbullet->SetDeleteFunc(Level3::DeleteBullet_ID_5_3);
        sbullet->SetBaseTime(basetime);
        sbullet->SetSpeed(Randomizer.GetRandom(120,130));
    }
    LevelBoss->Data[2]-=PI/20;
}

void Level3::BossShoot_ID_5_3_4 (Boss* LevelBoss, float basetime) {
    float Angle=LevelBoss->Data[3]+Randomizer.GetRandom(-0.1f,+0.1f);
    for (short i=0; i<4; ++i) {
        LevelBoss->Bullets.push_back(new SpeedBullet);
        SpeedBullet* sbullet=static_cast<SpeedBullet*>(LevelBoss->Bullets.back());
        sbullet->SetImage(BULLET_1_MAGENTA);
        sbullet->SetImageColor(255,255,255,0);
        sbullet->SetPosition(LevelBoss->Position);
        sbullet->SetRadius(10);
        sbullet->SetAngle(Angle+PI/2*i);
        sbullet->SetMoveFunc(Level3::BossBulletMove_ID_5_3_1);
        sbullet->SetDeleteFunc(Level3::DeleteBullet_ID_5_3);
        sbullet->SetBaseTime(basetime);
        sbullet->SetSpeed(Randomizer.GetRandom(135,145));
    }
    LevelBoss->Data[3]+=PI/20;
}

void Level3::BossShoot_ID_5_SET (Boss* LevelBoss, float basetime) {
    LevelBoss->Data.clear();
    LevelBoss->Data.push_back(PI/4);
    LevelBoss->Data.push_back(PI/4);
    LevelBoss->Data.push_back(PI/4);
    LevelBoss->Data.push_back(PI/4);
}

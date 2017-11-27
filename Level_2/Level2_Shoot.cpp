#include "Level2.h"

void Level2::Shoot_ID_1(Enemy* enemy) {
    for (short i=0; i<2; ++i) {
        Engine.EnemyBullets.push_back(new Bullet(200));
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_2_BLUE);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetAngle((i*180+90)*PI/180);
        bullptr->SetRadius(7.5);
    }
}

void Level2::Shoot_ID_2(Enemy* enemy) {
    float Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)-PI/4;
    //8 waves - 17 bullets each (last one 16)
    for (short i=0; i<135; ++i) {
        unsigned speed;
        switch (static_cast<unsigned>(i%8)) {
            case 0: speed=350; break;
            case 1: speed=310; break;
            case 2: speed=270; break;
            case 3: speed=230; break;
            case 4: speed=200; break;
            case 5: speed=170; break;
            case 6: speed=140; break;
            case 7: speed=110; break;
        }
        Engine.EnemyBullets.push_back(new Bullet(speed));
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_1_GREEN);
        bullptr->SetPosition(enemy->Position);
        float localAngle=(Angle+(5*(i%17)*PI/180)); //PI/72 = 5 degrees
        if (i%8==7)
            localAngle+=(2.5*PI/180); //2.5 degrees
        bullptr->SetAngle(localAngle);
        bullptr->SetRadius(7.5);
    }
}

void Level2::Shoot_ID_3 (Enemy* enemy) {
    double Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x);
    Engine.EnemyBullets.push_back(new Bullet(180));
    Bullet* bullptr=Engine.EnemyBullets.back();
    bullptr->SetImage(BULLET_1_BLUE);
    bullptr->SetPosition(enemy->Position);
    bullptr->SetAngle(Angle);
    bullptr->SetRadius(12);
}

void Level2::Shoot_ID_4 (Enemy* enemy) {
    double Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)*180/PI+12;
    for (short i=0; i<30; ++i) { //Two circles of 15 bullets
        Engine.EnemyBullets.push_back(new Bullet(i%2==0?150:70));
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_1_GREY);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(12);
        bullptr->SetAngle((Angle+i*24)*PI/180);
    }
}

void Level2::Shoot_ID_5 (Enemy* enemy) {
    double Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)*180/PI-5;
    for (short i=0; i<10; ++i) {
        Engine.EnemyBullets.push_back(new Bullet(135));
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_3);
        bullptr->SetImageColor(230,180,180);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(15);
        bullptr->SetAngle((Angle+i*1.25)*PI/180);
    }
}

void Level2::Shoot_ID_6 (Enemy* enemy) {
    double Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x);
    for (short i=0; i<12; ++i) {
        Engine.EnemyBullets.push_back(new Bullet(40));
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_2_GREEN);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(18);
        bullptr->SetAngle(Angle+(30*i*PI/180));
    }
}

void Level2::Shoot_ID_7 (Enemy* enemy) {
    double Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)*180/PI-15;
    for (short i=0; i<3; ++i) {
        for (short j=0; j<3; ++j) {
            Engine.EnemyBullets.push_back(new Bullet(0));
            Bullet* bullptr=Engine.EnemyBullets.back();
            if (i==0) bullptr->SetImage(BULLET_1_RED);
            else if (i==1) bullptr->SetImage(BULLET_1_YELLOW);
            else bullptr->SetImage(BULLET_1_GREY);
            bullptr->SetPosition(enemy->Position);
            bullptr->SetRadius(12);
            bullptr->SetAngle((Angle+15*j)*PI/180);
            if (i==0) bullptr->SetSpeed(200);
            else if (i==1) bullptr->SetSpeed(140);
            else bullptr->SetSpeed(80);
        }
    }
}

void Level2::Shoot_ID_8 (Enemy* enemy) {
    double Angle=Randomizer.GetRandom(0.f, 2*PI);
    for (short i=0; i<20; ++i) {
        Engine.EnemyBullets.push_back(new Bullet(400));
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_3);
        bullptr->SetImageColor(0,0,0,255); //Black
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(18);
        bullptr->SetAngle(Angle+(2*PI/20*i));
    }
}

void Level2::Shoot_ID_9 (Enemy* enemy) {
    double Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x);
    for (short i=0; i<40; ++i) {
        Engine.EnemyBullets.push_back(new Bullet(200));
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_2_RED);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(15);
        bullptr->SetAngle(Angle+PI/20*i);
    }
}

void Level2::Shoot_ID_10_1 (Enemy* enemy) {
    double Angle=0.32*enemy->ShootTable.size()+PI/2;
    Engine.EnemyBullets.push_back(new Bullet);
    Bullet* bullptr=Engine.EnemyBullets.back();
    bullptr->SetImage(BULLET_3);
    bullptr->SetImageColor(100,100,255);
    bullptr->SetPosition(enemy->Position);
    bullptr->SetRadius(18);
    bullptr->SetAngle(Angle);
    bullptr->SetBaseTime(Engine.PastTime);
    bullptr->SetMoveFunc(Level2::BulletMove_ID_10_1);
}

void Level2::Shoot_ID_10_2 (Enemy* enemy) {
    double Angle=-(0.32*enemy->ShootTable.size())+PI/2;
    Engine.EnemyBullets.push_back(new Bullet);
    Bullet* bullptr=Engine.EnemyBullets.back();
    bullptr->SetImage(BULLET_3);
    bullptr->SetImageColor(100,100,255);
    bullptr->SetPosition(enemy->Position);
    bullptr->SetRadius(18);
    bullptr->SetAngle(Angle);
    bullptr->SetBaseTime(Engine.PastTime);
    bullptr->SetMoveFunc(Level2::BulletMove_ID_10_1);
}

void Level2::Shoot_ID_11 (Enemy* enemy) {
    double Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)-0.6; //+0.3*i
    for (short i=0; i<5; ++i) {
        Engine.EnemyBullets.push_back(new Bullet(120));
        Bullet* bullptr=Engine.EnemyBullets.back();
        bullptr->SetImage(BULLET_2_YELLOW);
        bullptr->SetPosition(enemy->Position);
        bullptr->SetRadius(8);
        bullptr->SetAngle(Angle+0.3*i);
        bullptr->SetBaseTime(Engine.PastTime);
    }
}

///Boss

void Level2::BossShoot_ID_1 (Boss* LevelBoss, float basetime) {
    double Angle=Randomizer.GetRandom(0.f, 2*PI);
    for (unsigned i=0; i<36; ++i) {
        Engine.LevelBoss->Bullets.push_back(new SuperBullet);
        SuperBullet* sbullet=Engine.LevelBoss->Bullets.back();
        sbullet->SetImage(BULLET_1_GREEN);
        sbullet->SetRadius(10);
        sbullet->SetAngle(Angle+PI/18*i);
        sbullet->SetBaseTime(basetime);
        sbullet->SetMoveFunc(Level2::BossBulletMove_ID_1);
        sbullet->SetDeleteFunc(Level2::DeleteBullet_ID_1);
    }
}

void Level2::BossShoot_ID_2_1 (Boss* LevelBoss, float basetime) {
    for (short i=0; i<5; ++i) {
        Engine.LevelBoss->Bullets.push_back(new SuperBullet);
        SuperBullet* sbullet=Engine.LevelBoss->Bullets.back();
        sbullet->SetImage(BULLET_2_RED);
        sbullet->SetRadius(8);
        sbullet->SetAngle(LevelBoss->Data.at(0)+(i*PI*2/5));
        sbullet->Sprite.setRotation((sbullet->Angle+PI)*180/PI);
        sbullet->SetBaseTime(basetime);
        sbullet->SetMoveFunc(Level2::BossBulletMove_ID_2_1);
        sbullet->SetDeleteFunc(Level2::DeleteBullet_ID_2_1);
    }
    LevelBoss->Data[0]+=0.08;
}

void Level2::BossShoot_ID_2_2 (Boss* LevelBoss, float basetime) {
    std::vector<std::pair<float,float> > vec;
    vec.push_back(std::pair<float,float>(0,0));
    vec.push_back(std::pair<float,float>(500,0));
    vec.push_back(std::pair<float,float>(500,600));
    vec.push_back(std::pair<float,float>(0,600));
    for (short i=0; i<8; ++i) {
        Engine.LevelBoss->Bullets.push_back(new SuperBullet);
        SuperBullet* sbullet=Engine.LevelBoss->Bullets.back();
        sbullet->SetImage(BULLET_1_YELLOW);
        sbullet->SetPosition(vec[int(i/2)].first, vec[int(i/2)].second);
        sbullet->SetRadius(8);
        sbullet->SetAngle(int(i/2)*(-PI/2) - ((i%2)+1)*PI/6);
        sbullet->SetBaseTime(basetime);
        sbullet->SetMoveFunc(Level2::BossBulletMove_ID_2_2);
        sbullet->SetDeleteFunc(Level2::DeleteBullet_ID_2_2);
    }
}

void Level2::BossShoot_ID_3 (Boss* LevelBoss, float basetime) {
    float Angle=Randomizer.GetRandom(0.f, 2*PI);
    for (short i=0; i<2; i++) {
        for (short j=0; j<36; ++j) {
            Engine.LevelBoss->Bullets.push_back(new SuperBullet);
            SuperBullet* sbullet=Engine.LevelBoss->Bullets.back();
            sbullet->SetImage(BULLET_1_GREY);
            sbullet->SetAngle(Angle+j*2*PI/36); //10 degrees
            sbullet->SetPosition(LevelBoss->Position.x+cos(sbullet->Angle)*600, LevelBoss->Position.y-sin(sbullet->Angle)*600);
            sbullet->SetRadius(12);
            sbullet->SetBaseTime(basetime);
            sbullet->SetMoveFunc(i==0?Level2::BossBulletMove_ID_3_1:Level2::BossBulletMove_ID_3_2);
            sbullet->SetDeleteFunc(Level2::DeleteBullet_ID_3);
        }
    }
}

void Level2::BossShoot_ID_4 (Boss* LevelBoss, float basetime) {
    for (short i=0; i<2; ++i) {
        for (short j=0; j<5; j++) {
            Engine.LevelBoss->Bullets.push_back(new SuperBullet);
            SuperBullet* sbullet=Engine.LevelBoss->Bullets.back();
            sbullet->SetImage(i==0?BULLET_1_RED:BULLET_1_GREEN);
            sbullet->SetPosition(LevelBoss->Position);
            if (i==0)
                sbullet->SetAngle(LevelBoss->Data[0]+j*2*PI/5);
            else
                sbullet->SetAngle(-LevelBoss->Data[0]+j*2*PI/5);
            sbullet->SetRadius(11);
            sbullet->SetBaseTime(basetime);
            sbullet->SetMoveFunc(i==0?Level2::BossBulletMove_ID_4_1:Level2::BossBulletMove_ID_4_2);
            sbullet->SetDeleteFunc(Level2::DeleteBullet_ID_4);
            sbullet->SetPosition(LevelBoss->Position);
        }
    }
    LevelBoss->Data[0]+=0.14;
}

#include "Level7.h"

///ENEMIES

void Level7::Shoot_ID_1(Enemy* enemy) {
    float BaseAngle=Randomizer.GetRandom(0.f, PI);
    for (unsigned i=0; i<36; ++i) {
        Engine.EnemyBullets.push_back(new Bullet(150));
        Bullet* bullet=Engine.EnemyBullets.back();
        bullet->SetImage(BULLET_1_RED);
        bullet->SetRadius(8);
        bullet->SetPosition(enemy->Position);
        bullet->SetAngle(BaseAngle+2*PI/36*i);
    }
}

void Level7::Shoot_ID_2(Enemy* enemy) {
    Engine.EnemyBullets.push_back(new Bullet(320));
    Bullet* bullet=Engine.EnemyBullets.back();
    bullet->SetImage(BULLET_2_GREEN);
    bullet->SetRadius(9);
    bullet->SetPosition(enemy->Position);
    bullet->SetAngle(-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x));
}

void Level7::Shoot_ID_3(Enemy* enemy) {
    float BaseAngle=Randomizer.GetRandom(0.f,PI);
    Bullet* bullet;
    for (unsigned i=0; i<24; ++i) {
        Engine.EnemyBullets.push_back(new Bullet(250));
        bullet=Engine.EnemyBullets.back();
        bullet->SetImage(BULLET_1_BLUE);
        bullet->SetRadius(20);
        bullet->SetPosition(enemy->Position);
        bullet->SetAngle(BaseAngle+2*PI/24*i);
    }
}

void Level7::Shoot_ID_4(Enemy* enemy) {
    float BaseAngle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)+2*PI/12/2;
    for (unsigned i=0; i<12; ++i) {
        float speed;
        if (i==0 || i==11) speed=320;
        else if (i==1 || i==10) speed=230;
        else if (i==2 || i==9) speed=150;
        else if (i==3 || i==8) speed=80;
        else if (i==4 || i==7) speed=40;
        else speed=20;
        Engine.EnemyBullets.push_back(new Bullet(speed));
        Bullet* bullet=Engine.EnemyBullets.back();
        bullet->SetImage(BULLET_3);
        bullet->SetImageColor(255,128,128);
        bullet->SetRadius(22);
        bullet->SetPosition(enemy->Position);
        bullet->SetAngle(BaseAngle+2*PI/12*i);
    }
}

void Level7::Shoot_ID_5(Enemy* enemy) {
    float BaseAngle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)-0.05;
    for (unsigned i=0; i<4; ++i) {
        for (unsigned j=0; j<5; ++j) {
            Engine.EnemyBullets.push_back(new Bullet(270));
            Bullet* bullet=Engine.EnemyBullets.back();
            bullet->SetImage(BULLET_2_BLUE);
            bullet->SetImageColor(0,0,0,255);
            bullet->SetRadius(18);
            bullet->SetPosition(enemy->Position);
            bullet->SetAngle(BaseAngle+i*PI/2+j*0.025);
        }
    }
}

///BOSS

void Level7::BossShoot_ID_1_SETDATA(Boss* boss, float basetime) {
    boss->Data.push_back(0); //If 0, _1_1 doesn't aim at the player
    boss->Data.push_back(0); //Num of _1_2 shots
    boss->Data.push_back(Randomizer.GetRandom(0.f,1.5f)); //BaseAngle for _1_2
}

void Level7::BossShoot_ID_1_1(Boss* boss, float basetime) {
    float BaseAngle=(boss->Data[0]++!=0)*(-atan2f(Engine.Player->Position.y-boss->Position.y, Engine.Player->Position.x-boss->Position.x));
    for (unsigned i=0; i<12; ++i) {
        for (unsigned j=0; j<5; ++j) {
            boss->Bullets.push_back(new SuperBullet(210+j*30));
            SuperBullet* sbullet=boss->Bullets.back();
            sbullet->SetImage(BULLET_1_MAGENTA);
            sbullet->SetRadius(50);
            sbullet->SetPosition(boss->Position);
            sbullet->SetAngle(BaseAngle+2*PI/12*i);
            sbullet->SetMoveFunc(Level7::BossBulletMove_ID_1_1);
            sbullet->SetBaseTime(basetime);
            sbullet->Deletable=true;
        }
    }
}

void Level7::BossShoot_ID_1_2(Boss* boss, float basetime) {
    ++boss->Data[1];
    if (boss->Data[1]==32) {
        boss->Data[1]=0;
        boss->LifeBars.back()->ShootTable.back()->first.second=0.6;
    }
    else if (boss->Data[1]==1) {
        ++boss->Data[0];
        boss->Data[2]=Randomizer.GetRandom(0.f,PI);
        boss->LifeBars.back()->ShootTable.back()->first.second=0.025;
        Level7::BossShoot_ID_1_1(boss, basetime);
    }

    float BaseAngle=boss->Data[2];
    for (unsigned i=0; i<8; ++i) {
        for (unsigned j=0; j<2; ++j) {
            boss->Bullets.push_back(new SuperBullet);
            SuperBullet* sbullet=boss->Bullets.back();
            sbullet->SetImage(BULLET_6);
            sbullet->SetImageColor(0,0,0,255);
            sbullet->SetRadius(8);
            sbullet->SetPosition(boss->Position);
            sbullet->SetAngle(BaseAngle+2*PI/8*i);
            sbullet->SetMoveFunc(j==0 ? Level7::BossBulletMove_ID_1_2_1 : Level7::BossBulletMove_ID_1_2_2);
            sbullet->SetBaseTime(basetime);
            sbullet->SetDeleteFunc(Level7::DeleteBullet_ID_1_2);
        }
    }
}

void Level7::BossShoot_ID_2_SETDATA(Boss* boss, float basetime) {
    boss->Data.clear();
    boss->Data.push_back(basetime);
    boss->Data.push_back(0); //Num of shots for _2_1
    boss->Data.push_back(0); //BaseAngle for _2_1
    boss->Data.push_back(0); //Needed by Move_2
}

void Level7::BossShoot_ID_2_1(Boss* boss, float basetime) {
    boss->Data[1]++;
    if (boss->Data[1]==1) {
        boss->Data[2]=Randomizer.GetRandom(0.f,1.5f);
        boss->LifeBars.back()->ShootTable[1]->first.second=0.025;
    }
    else if (boss->Data[1]==8) {
        boss->Data[1]=0;
        boss->LifeBars.back()->ShootTable[1]->first.second=0.5f;
    }

    void(*movefunc[2])(SuperBullet*);
    movefunc[0]=&Level7::BossBulletMove_ID_2_1_1;
    movefunc[1]=&Level7::BossBulletMove_ID_2_1_2;

    for (unsigned i=0; i<24; ++i) {
        for (unsigned j=0; j<2; ++j) {
            boss->Bullets.push_back(new SuperBullet);
            SuperBullet* sbullet=boss->Bullets.back();
            sbullet->SetImage(BULLET_6);
            sbullet->SetImageColor(0,0,0);
            sbullet->SetRadius(8);
            sbullet->SetPosition(boss->Position);
            sbullet->SetAngle(-boss->Data[2]+2*PI/24*i);
            sbullet->SetMoveFunc(*movefunc[j]);
            sbullet->SetDeleteFunc(Level7::DeleteBullet_ID_2_1);
            sbullet->SetBaseTime(basetime);
        }
    }
}

void Level7::BossShoot_ID_3_SETDATA(Boss* boss, float basetime) {
    boss->Data.clear();
    boss->Data.push_back(basetime);
    boss->Data.push_back(Randomizer.GetRandom(0.f,1.5f));
    boss->Data.push_back(0); //Num of _3_2 shots
    boss->Data.push_back(Randomizer.GetRandom(0.f,1.5f)); //BaseAngle for_3_3
    boss->Data.push_back(0); //Num of 3_3*/
}

void Level7::BossShoot_ID_3_1(Boss* boss, float basetime) {
    float BaseAngle=boss->Data[1];

    for (unsigned i=0; i<8; ++i) {
        boss->Bullets.push_back(new SuperBullet);
        SuperBullet* sbullet=boss->Bullets.back();
        sbullet->SetImage(BULLET_1_MAGENTA);
        sbullet->SetImageColor(128,128,128);
        sbullet->SetRadius(22);
        sbullet->SetPosition(250,300);
        sbullet->SetAngle(BaseAngle+2*PI/8*i);
        sbullet->SetMoveFunc(Level7::BossBulletMove_ID_3_1);
        sbullet->Deletable=false;
        sbullet->SetBaseTime(basetime);
    }
}

void Level7::BossShoot_ID_3_2(Boss* boss, float basetime) {
    ++boss->Data[2];
    if (boss->Data[2]==1) {
        boss->LifeBars.back()->ShootTable[2]->first.second=0.01f;
    }
    if (boss->Data[2]==8) {
        boss->Data[2]=0;
        boss->LifeBars.back()->ShootTable[2]->first.second=0.29f;
    }

    float time=basetime-(boss->Data[0]+0.6);
    float AddedAngle=-0.8*time;
    float radius=min(90*time, 400.f);
    for (unsigned i=0; i<8; ++i) {
        boss->Bullets.push_back(new SpeedBullet(120));
        SuperBullet* sbullet=dynamic_cast<SpeedBullet*>(boss->Bullets.back());
        sbullet->SetImage(BULLET_6);
        sbullet->SetImageColor(0xFF*1/3, 0xD7*1/3, 0x00); //Gold
        sbullet->SetImageColor(0,0,0);
        sbullet->SetRadius(8);
        sbullet->SetAngle(boss->Data[1]+2*PI/8*i+AddedAngle);
        sbullet->SetPosition(250+cos(sbullet->Angle+PI)*radius, 300-sin(sbullet->Angle+PI)*radius);
        sbullet->SetDeleteFunc(Level7::DeleteBullet_ID_3_2);
        sbullet->SetBaseTime(basetime);
    }
}

void Level7::BossShoot_ID_3_3(Boss* boss, float basetime) {
    float BaseAngle=boss->Data[3]+(++boss->Data[4])*0.16;
    for (unsigned i=0; i<8; ++i) {
        boss->Bullets.push_back(new SpeedBullet(110));
        SuperBullet* sbullet=dynamic_cast<SpeedBullet*>(boss->Bullets.back());
        sbullet->SetImage(BULLET_6);
        sbullet->SetImageColor(128, 0, 128); //Gold
        sbullet->SetRadius(8);
        sbullet->SetAngle(BaseAngle+2*PI/8*i);
        sbullet->SetPosition(250, 300);
        sbullet->SetBaseTime(basetime);
    }
}

void Level7::BossShoot_ID_4_SETDATA(Boss* boss, float basetime) {
    boss->Data.clear();
    boss->Data.push_back(basetime);
}

void Level7::BossShoot_ID_4_1(Boss* boss, float basetime) {
    float BaseAngle=Randomizer.GetRandom(0.f,PI);
    void(*movefuncs[2])(SuperBullet*);
    movefuncs[0]=Level7::BossBulletMove_ID_4_1_1;
    movefuncs[1]=Level7::BossBulletMove_ID_4_1_2;
    OriginBullet* sbullet;
    for (unsigned i=0; i<6; ++i) {
        for (unsigned j=0; j<10; ++j) {
            for (unsigned k=0; k<2; ++k) {
                boss->Bullets.push_back(new OriginBullet);
                sbullet=dynamic_cast<OriginBullet*>(boss->Bullets.back());
                sbullet->SetImage(BULLET_6);
                sbullet->SetImageColor(0,0,0);
                sbullet->SetRadius(8);
                //sbullet->SetAngle(BaseAngle+2*PI/6*i);
                sbullet->SetAngle(PI/6+2*PI/6*i);
                sbullet->SetPosition(boss->Position);
                sbullet->SetOrigin(boss->Position);
                sbullet->SetMoveFunc(*movefuncs[k]);
                sbullet->SetDeleteFunc(Level7::DeleteBullet_ID_4_1);
                sbullet->SetBaseTime(basetime+j*0.0125);
            }
        }
        BaseAngle+=2*PI/5;
    }
}

void Level7::BossShoot_ID_4_2(Boss* boss, float basetime) {
    float BaseAngle=Randomizer.GetRandom(0.f,PI);
    for (unsigned i=0; i<16; ++i) {
        boss->Bullets.push_back(new SpeedBullet(195));
        SuperBullet* sbullet=boss->Bullets.back();
        sbullet->SetImage(BULLET_5);
        sbullet->SetImageColor(255,90,90);
        sbullet->SetPosition(boss->Position);
        sbullet->SetRadius(50);
        sbullet->SetAngle(BaseAngle+2*PI/16*i);
        sbullet->SetBaseTime(basetime);
        sbullet->SetMoveFunc(Level7::BossBulletMove_ID_4_2);
        sbullet->SetDeleteFunc(Level7::DeleteBullet_ID_4_2);
    }
}

void Level7::BossShoot_ID_5_SETDATA(Boss* boss, float basetime) {
    boss->Data.clear();
    boss->Data.push_back(-atan2f(120-boss->Position.y, 250-boss->Position.x));
    boss->Data.push_back(0); //Needed for Data.size()!=1
}

void Level7::BossShoot_ID_5_1(Boss* boss, float basetime) {
    boss->Bullets.push_back(new SpeedBullet(200));
    SuperBullet* sbullet=boss->Bullets.back();
    sbullet->SetImage(BULLET_1_BLACK);
    sbullet->SetRadius(42);
    sbullet->SetImageColor(255,128,128);
    sbullet->SetPosition(boss->Position);
    sbullet->SetMoveFunc(Level7::BossBulletMove_ID_5_1);
    sbullet->Deletable=false;
}

void Level7::BossShoot_ID_5_2(Boss* boss, float basetime) {
    float BaseAngle=Randomizer.GetRandom(0.f,PI);
    void(*movefuncs[2])(SuperBullet*);
    movefuncs[0]=Level7::BossBulletMove_ID_5_2_1;
    movefuncs[1]=Level7::BossBulletMove_ID_5_2_2;
    SuperBullet* sbullet;
    for (unsigned i=0; i<16; ++i) {
        for (unsigned j=0; j<24; ++j) {
            for (unsigned k=0; k<2; ++k) {
                boss->Bullets.push_back(new SuperBullet);
                sbullet=boss->Bullets.back();
                sbullet->SetImage(BULLET_3);
                sbullet->SetImageColor(0,0,0);
                sbullet->SetRadius(8);
                sbullet->SetAngle(BaseAngle);
                sbullet->SetPosition(boss->Position);
                sbullet->SetMoveFunc(*movefuncs[k]);
                sbullet->SetDeleteFunc(Level7::DeleteBullet_ID_5_2);
                sbullet->SetBaseTime(basetime+j*0.0125);
            }
        }
        BaseAngle+=2*PI/16;
    }
}

void Level7::BossShoot_ID_5_3(Boss* boss, float basetime) {
    float BaseAngle=Randomizer.GetRandom(0.f,PI);
    for (unsigned i=0; i<14; ++i) {
        boss->Bullets.push_back(new SpeedBullet(110));
        SuperBullet* sbullet=boss->Bullets.back();
        sbullet->SetImage(BULLET_5);
        sbullet->SetImageColor(128,64,64);
        sbullet->SetRadius(8);
        sbullet->SetAngle(BaseAngle+2*PI/14*i);
        sbullet->SetPosition(boss->Bullets[0]->Sprite.getPosition());
    }
}

void Level7::BossShoot_ID_6_SETDATA(Boss* boss, float basetime) {
    boss->Data.clear();
    boss->Data.push_back(0); //Angle for _2, modified by _1
    boss->Data.push_back(Randomizer.GetRandom(0.f,PI)); //Angle for _3
}

void Level7::BossShoot_ID_6_1(Boss* boss, float basetime) {
    float Angle=boss->Data[0]=-atan2f(Engine.Player->Position.y-boss->Position.y, Engine.Player->Position.x-boss->Position.x);
    boss->Bullets.push_back(new SpeedBullet(190));
    SuperBullet* sbullet=boss->Bullets.back();
    sbullet->SetImage(BULLET_2_BLUE);
    sbullet->SetImageColor(128,128,128);
    sbullet->SetRadius(13);
    sbullet->SetPosition(boss->Position);
    sbullet->SetAngle(Angle);
}

void Level7::BossShoot_ID_6_2(Boss* boss, float basetime) {
    float BaseAngle=boss->Data[0];
    for (unsigned i=0; i<60; ++i) {
        //for (unsigned j=0; j<13; ++j) {
            boss->Bullets.push_back(new SuperBullet);
            SuperBullet* sbullet=boss->Bullets.back();
            sbullet->SetImage(BULLET_3);
            sbullet->SetImageColor(255,255,255);
            sbullet->SetRadius(10);
            sbullet->SetPosition(boss->Position);
            sbullet->SetAngle(BaseAngle/*+0.05*j*/);
            sbullet->SetMoveFunc(Level7::BossBulletMove_ID_6_2);
            sbullet->SetBaseTime(basetime+0.1*i);
        //}
    }
}

void Level7::BossShoot_ID_6_3(Boss* boss, float basetime) {
    float BaseAngle=boss->Data[1]=boss->Data[1]-0.181;
    for (unsigned i=0; i<8; ++i) {
        for (unsigned j=0; j<7; ++j) {
            boss->Bullets.push_back(new SuperBullet);
            SuperBullet* sbullet=boss->Bullets.back();
            sbullet->SetImage(BULLET_6);
            sbullet->SetImageColor(0,0,0);
            sbullet->SetRadius(8);
            sbullet->SetPosition(boss->Position);
            sbullet->SetAngle(BaseAngle+2*PI/8*i);
            sbullet->SetMoveFunc(Level7::BossBulletMove_ID_6_3);
            sbullet->SetDeleteFunc(Level7::DeleteBullet_ID_6_3);
            sbullet->SetBaseTime(basetime+0.025*j);
        }
    }
}

/*void Level7::BossShoot_ID_7_SETDATA(Boss* boss, float basetime) {
    boss->Data.clear();
    boss->Data.push_back(basetime);
    //boss->Data.push_back(1); //Sign switch by _1
}

void Level7::BossShoot_ID_7_1(Boss* boss, float basetime) {
    float BaseAngle=Randomizer.GetRandom(0.f,PI);
    signed short sign=boss->Data[1];
    boss->Data[1]*=-1;
    for (unsigned i=0; i<12; ++i) {
        for (unsigned j=0; j<40; ++j) {
            boss->Bullets.push_back(new SuperBullet);
            SuperBullet* sbullet=boss->Bullets.back();
            sbullet->SetImage(BULLET_3);
            sbullet->SetImageColor(0,0,0);
            sbullet->SetRadius(8);
            sbullet->SetPosition(boss->Position);
            sbullet->SetAngle(BaseAngle+2*PI/12*i+0.001*j*sign);
            sbullet->SetBaseTime(basetime+0.02*j);
            sbullet->SetMoveFunc(Level7::BossBulletMove_ID_7_1);
            sbullet->SetDeleteFunc(Level7::DeleteBullet_ID_7_1);
        }
    }
}

void Level7::BossShoot_ID_7_2(Boss* boss, float basetime) {
    float BaseAngle=Randomizer.GetRandom(0.f,PI);
    for (unsigned i=0; i<22; ++i) {
        boss->Bullets.push_back(new SpeedBullet(140));
        SuperBullet *sbullet=boss->Bullets.back();
        sbullet->SetImage(BULLET_1_RED);
        sbullet->SetRadius(9);
        sbullet->SetPosition(boss->Position);
        sbullet->SetAngle(BaseAngle+2*PI/22*i);
        sbullet->SetBaseTime(basetime);
    }
}*/

void Level7::BossShoot_ID_7_SETDATA(Boss* boss, float basetime) {
    boss->Data.clear();
    boss->Data.push_back(0); //How many _2
    boss->Data.push_back(1); //How many _5
    boss->Data.push_back(0); //How many _6
    boss->Data.push_back(0); //Can _4 shoot?
    boss->Data.push_back(0); //Can _5 shoot?
    boss->Data.push_back(0); //Can _6 shoot?
    boss->Data.push_back(0); //Can _7 shoot?
}

void Level7::BossShoot_ID_7_1(Boss* boss, float basetime) {
    for (unsigned i=0; i<4; ++i) {
        boss->Bullets.push_back(new SpeedBullet(i<2?125:175));
        SuperBullet* sbullet=boss->Bullets.back();
        sbullet->SetImage(BULLET_1_RED);
        sbullet->SetRadius(21);
        float Angle;
        switch (i) {
            case 0: Angle=45.f; break;
            case 1: Angle=135.f; break;
            case 2: Angle=210.f; break;
            case 3: Angle=330.f; break;
            default: break;
        }
        sbullet->SetAngle(Angle*PI/180);
        sbullet->SetPosition(boss->Position);
        sbullet->SetMoveFunc(Level7::BossBulletMove_ID_7_1);
        sbullet->Deletable=false;
        sbullet->SetBaseTime(basetime);
    }
}

void Level7::BossShoot_ID_7_2(Boss* boss, float basetime) {
    ++boss->Data[0];
    double d=boss->Data[0];
    if (d<=60) {
        for (unsigned i=0; i<4; ++i) {
            for (unsigned j=0; j<2; ++j) {
                boss->Bullets.push_back(new OriginBullet);
                OriginBullet* sbullet=dynamic_cast<OriginBullet*>(boss->Bullets.back());
                sbullet->SetImage(BULLET_2_BLUE);
                sbullet->SetImageColor(128,128,255);
                sbullet->SetRadius(8);
                //sbullet->SetAngle((90+2*d*(1-2*j))*PI/180);
                sbullet->SetAngle((j==0?90+2*d:90-2*d)*PI/180);
                sbullet->SetPosition(boss->Bullets[i]->Sprite.getPosition());
                sbullet->SetBaseTime(basetime);
                sbullet->SetMoveFunc(Level7::BossBulletMove_ID_7_2);
                sbullet->SetOrigin(sbullet->Sprite.getPosition());
            }
        }
    }
    else {
        d-=60; //Starts from 0
        d+=5; //Actual start not 0
        while (d>=50)
            d-=50;
        for (unsigned i=0; i<4; ++i) {
            for (unsigned j=0; j<3; ++j) {
                boss->Bullets.push_back(new OriginBullet);
                OriginBullet* sbullet=dynamic_cast<OriginBullet*>(boss->Bullets.back());
                sbullet->SetImage(BULLET_2_BLUE);
                sbullet->SetImageColor(128,128,255);
                sbullet->SetRadius(8);
                float Angle=
                            (
                            i==0||i==2?
                                (d<25?270-5+d:270+20-(d-25))
                                :
                                (d<25?270+5-d:270-20+(d-25))
                            )-60;
                sbullet->SetAngle((Angle+60*j)*PI/180);
                sbullet->SetPosition(boss->Bullets[i]->Sprite.getPosition());
                sbullet->SetBaseTime(basetime);
                sbullet->SetMoveFunc(Level7::BossBulletMove_ID_7_2);
                sbullet->SetOrigin(sbullet->Sprite.getPosition());
            }
        }
    }
}

void Level7::BossShoot_ID_7_3(Boss* boss, float basetime) {
    float x=Randomizer.GetRandom(35.f,465.f);
    float y=Randomizer.GetRandom(35.f,140.f);
    boss->Bullets.push_back(new SpeedBullet(Randomizer.GetRandom(100.f,130.f)));
    SuperBullet* sbullet=boss->Bullets.back();
    sbullet->SetImage(BULLET_3);
    sbullet->SetImageColor(255, 192, 203); //Pink
    sbullet->SetRadius(12);
    sbullet->SetPosition(x,y);
    sbullet->SetAngle((250.f+Randomizer.GetRandom(0.f,40.f))*PI/180);
}

void Level7::BossShoot_ID_7_4(Boss* boss, float basetime) {
    float Angle=-atan2f(Engine.Player->Position.y-boss->Position.y, Engine.Player->Position.x-boss->Position.x)-40*PI/180;
    for (unsigned i=0; i<3; ++i) {
        boss->Bullets.push_back(new SuperBullet);
        SuperBullet* sbullet=boss->Bullets.back();
        sbullet->SetImage(BULLET_1_RED);
        sbullet->SetRadius(55);
        sbullet->SetPosition(boss->Position);
        sbullet->SetAngle(Angle+40*PI/180*i);
        sbullet->SetBaseTime(basetime);
        sbullet->SetMoveFunc(Level7::BossBulletMove_ID_7_4);
    }
}

void Level7::BossShoot_ID_7_5(Boss* boss, float basetime) {
    boss->Data[1]=-boss->Data[1];
    for (unsigned i=0; i<8; ++i) {
        boss->Bullets.push_back(new SuperBullet);
        SuperBullet* sbullet=boss->Bullets.back();
        sbullet->SetImage(BULLET_3);
        sbullet->SetImageColor(255,64,255);
        sbullet->SetRadius(12);
        sbullet->SetPosition(boss->Position);
        sbullet->SetAngle(boss->Data[1]>0?0.45*i:PI-0.45*i);
        sbullet->SetBaseTime(basetime+0.08*i);
        sbullet->SetMoveFunc(Level7::BossBulletMove_ID_7_5);
    }
}

void Level7::BossShoot_ID_7_6(Boss* boss, float basetime) {
    boss->Data[2]=fmod(boss->Data[2]+1, 40);
    float Angle=(static_cast<int>(boss->Data[2])<20?5-10*boss->Data[2]:175+10*(boss->Data[2]-20))*PI/180;

    boss->Bullets.push_back(new SpeedBullet(130));
    SuperBullet* sbullet=boss->Bullets.back();
    sbullet->SetImage(BULLET_3);
    sbullet->SetImageColor(255,192,203);
    sbullet->SetRadius(12);
    sbullet->SetPosition(boss->Position);
    sbullet->SetAngle(Angle);
}

void Level7::BossShoot_ID_7_7(Boss* boss, float basetime) {
    float BaseAngle=Randomizer.GetRandom(1.f,PI);
    for (unsigned i=0; i<16; ++i) {
        boss->Bullets.push_back(new SpeedBullet(180));
        SuperBullet* sbullet=boss->Bullets.back();
        sbullet->SetImage(BULLET_1_RED);
        sbullet->SetRadius(9);
        sbullet->SetPosition(boss->Position);
        sbullet->SetAngle(BaseAngle+2*PI/16*i);
    }
}

void Level7::BossShoot_ID_8_SETDATA(Boss* boss, float basetime) {
    boss->Data.clear();
    boss->Data.push_back(basetime);
    for (unsigned i=0; i<6; ++i) //Bosses
        boss->Data.push_back(-1);
    boss->Data.push_back(0); //Num of _2
    boss->Data.push_back(0); //Num of _3
    boss->Data.push_back(0); //Num of _4
    boss->Data.push_back(0); //Num of _5
    boss->Data.push_back(0); //Num of _6

}

namespace {
    template<int BossNumber>
    void Bar8_BossMove(Enemy* enemy) {
        float time=min<float>(Engine.PastTime-enemy->BaseTime,3.f);
        if (BossNumber%2==0)
            enemy->Position.x=500-300*time;
        else
            enemy->Position.x=300*time;
        enemy->Position.y=250-50*time*time*time;
    }

    template<>
    void Bar8_BossMove<1>(Enemy* enemy) {
        float time=min<float>(Engine.PastTime-enemy->BaseTime,4.f);
        if (time>1.f) {
            time-=1.f;
            if (time<1.f)
                return;
        }
        enemy->Position.x=250*time;
        enemy->Position.y=350-50*time*time*time;
    }

    struct BossEnemy : public Enemy {
        sf::Sprite AuraSprite;

        BossEnemy() {
            AuraSprite.setTexture(Engine.BossAuraImage);
            AuraSprite.setOrigin(Engine.BossAuraImage.getSize().x/2, Engine.BossAuraImage.getSize().y/2);
            AuraSprite.setPosition(Position);
        }
        virtual ~BossEnemy()=default;
        virtual void Draw() {
            AuraSprite.setPosition(Position);
            MainWindow.draw(AuraSprite);
            float f=fmodf(Engine.PastTime,0.4f);
            short w=f>=0.2f?1:0;
            if (Position.x == PrevPosition.x)
                MainWindow.draw(Sprite[w]);
            else if (Position.x < PrevPosition.x)
                MainWindow.draw(Sprite[2]);
            else
                MainWindow.draw(Sprite[3]);
        };
    };

    template<int BossNumber> //Several generated functions --> Several 'static sf::Image'
    void ShootBoss(Boss* boss, float basetime) {
        Engine.Enemies.push_back(new BossEnemy);
        BossEnemy* enemy=dynamic_cast<BossEnemy*>(Engine.Enemies.back());
        static sf::Texture Image;
        std::string file;
        sf::Color auracolor;
        switch (BossNumber) {
            case 1: file="Boss1.png"; auracolor={0,127,255}; break;
            case 2: file="Boss2.png"; auracolor={255,128,0}; break;
            case 3: file="Boss3.png"; auracolor={255,215,0}; break;
            case 4: file="Boss4.png"; auracolor={255,192,203}; break;
            case 5: file="Boss5.png"; auracolor={0,128,0}; break;
            case 6: file="Boss6.png"; auracolor={64,0,0}; break;
            case 7: file="Boss7.png"; auracolor={255,255,255}; break;
            default: break;
        }
        char* imagedata=Reader.getFile(file);
        size_t imagesize=Reader.getEntryFileSize(file);
        Image.loadFromMemory(imagedata, imagesize);
        Image.setSmooth(true);
        delete[] imagedata;
        enemy->SetImage(Image);
        enemy->AuraSprite.setColor(auracolor);
        enemy->Radius=25;
        enemy->BaseTime=basetime;
        enemy->Life=1000000;
        enemy->Move=Bar8_BossMove<BossNumber>;
    }
};

void Level7::BossShoot_ID_8_BOSS1(Boss* boss, float basetime) {
    ShootBoss<1>(boss, basetime);
}

namespace {
    template<int N>
    void BossBulletMove_ID_8_1_N(SuperBullet* sbullet) {
        float time=Engine.PastTime-sbullet->BaseTime;
        float speed=N%2==1?225:275;
        float DamagePercentage=(1.f-Engine.LevelBoss->LifeBars.back()->Health/Engine.LevelBoss->LifeBars.back()->MaxHealth);
        sbullet->SetRadius(25+125*DamagePercentage);
        sbullet->Sprite.setScale((25+125*DamagePercentage)/25/6,(25+125*DamagePercentage)/25/6);
        if (time<2) {
            time=min<float>(time,1.f);
            sbullet->SetPosition(250+cos(sbullet->Angle)*speed*time, 300-sin(sbullet->Angle)*speed*time);
            return;
        }
        time=fmodf((time+2*N)-2, 8.f);
        float perimetral_distance=250*time;
        if (perimetral_distance<=275) sbullet->SetPosition(475,300-perimetral_distance);
        else if (perimetral_distance<=725) sbullet->SetPosition(475-(perimetral_distance-275), 25);
        else if (perimetral_distance<=1275) sbullet->SetPosition(25, 25+perimetral_distance-725);
        else if (perimetral_distance<=1725) sbullet->SetPosition(25+perimetral_distance-1275, 575);
        else sbullet->SetPosition(475, 575-(perimetral_distance-1725));
    }
}

void Level7::BossShoot_ID_8_1(Boss* boss, float basetime) {
    for (unsigned i=0; i<4; ++i) {
        boss->Bullets.push_back(new SuperBullet);
        SuperBullet* sbullet=boss->Bullets.back();
        sbullet->SetImage(BULLET_1_RED_WIDE);
        sbullet->SetRadius(25);
        sbullet->Sprite.setScale(25/25/6,25/25/6);
        sbullet->SetPosition(250,300);
        sbullet->SetAngle(i*PI/2);
        sbullet->SetBaseTime(basetime);
        void (*movefuncs[4])(SuperBullet*)={BossBulletMove_ID_8_1_N<1>, BossBulletMove_ID_8_1_N<2>, BossBulletMove_ID_8_1_N<3>, BossBulletMove_ID_8_1_N<4>};
        sbullet->SetMoveFunc(*movefuncs[i]);
        sbullet->Deletable=false;
    }
}

void Level7::BossShoot_ID_8_BOSS2(Boss* boss, float basetime) {
    ShootBoss<2>(boss, basetime);
}

void Level7::BossShoot_ID_8_2(Boss* boss, float basetime) {
    float BaseAngle=Randomizer.GetRandom(0.f,PI);
    int n=boss->Data[7]=static_cast<int>(fmod(boss->Data[7]+1,4));
    for (unsigned i=0; i<20; ++i) {
        boss->Bullets.push_back(new SpeedBullet(60));
        SuperBullet* sbullet=boss->Bullets.back();
        sbullet->SetImage(BULLET_1_BLUE);
        sbullet->SetRadius(13);
        sbullet->SetPosition(boss->Bullets[n]->Sprite.getPosition());
        sbullet->SetAngle(BaseAngle+2*PI/20*i);
    }
}

void Level7::BossShoot_ID_8_BOSS3(Boss* boss, float basetime) {
    ShootBoss<3>(boss, basetime);
}

void Level7::BossShoot_ID_8_3(Boss* boss, float basetime) {
    float BaseAngle=Randomizer.GetRandom(0.f,PI);
    sf::Vector2<float> v[4]={{25,25},{25,575},{475,575},{475,25}};
    int n=fmod(++boss->Data[8], 4);
    for (unsigned i=0; i<20; ++i) {
        boss->Bullets.push_back(new SpeedBullet(60));
        SuperBullet* sbullet=boss->Bullets.back();
        sbullet->SetImage(BULLET_1_YELLOW);
        sbullet->SetRadius(9);
        sbullet->SetPosition(v[n]);
        sbullet->SetAngle(BaseAngle+2*PI/20*i);
    }
}

void Level7::BossShoot_ID_8_BOSS4(Boss* boss, float basetime) {
    ShootBoss<4>(boss,basetime);
}

void Level7::BossShoot_ID_8_4(Boss* boss, float basetime) {
    float BaseAngle=Randomizer.GetRandom(0.f,PI);
    int n=fmodf(++boss->Data[8], 4);
    sf::Vector2f v[4]={{25,150},{475,150},{475,450},{25,450}};
    for (unsigned j=0; j<20; ++j) {
        boss->Bullets.push_back(new SpeedBullet(60));
        SuperBullet* sbullet=boss->Bullets.back();
        sbullet->SetImage(BULLET_1_MAGENTA);
        sbullet->SetRadius(9);
        sbullet->SetPosition(v[n]);
        sbullet->SetAngle(BaseAngle+2*PI/20*j);
    }
}

void Level7::BossShoot_ID_8_BOSS5(Boss* boss, float basetime) {
    ShootBoss<5>(boss,basetime);
}

void Level7::BossShoot_ID_8_5(Boss* boss, float basetime) {
    int n=fmodf(++boss->Data[8], 4);
    float BaseAngle=-atan2f(Engine.Player->Position.y-boss->Bullets[n]->Sprite.getPosition().y, Engine.Player->Position.x-boss->Bullets[n]->Sprite.getPosition().x);
    boss->Bullets.push_back(new SpeedBullet(150));
    SuperBullet* sbullet=boss->Bullets.back();
    sbullet->SetImage(BULLET_2_GREEN);
    sbullet->SetRadius(9);
    sbullet->SetAngle(BaseAngle);
    sbullet->SetPosition(boss->Bullets[n]->Sprite.getPosition());
}

void Level7::BossShoot_ID_8_BOSS6(Boss* boss, float basetime) {
    ShootBoss<6>(boss,basetime);
}

void Level7::BossShoot_ID_8_6(Boss* boss, float basetime) {
    sf::Vector2f v[4]={{137.5,25},{387.5,25},{387.5,575},{137.5,575}};
    int n=fmodf(++boss->Data[9],4.f);
    float BaseAngle=Randomizer.GetRandom(0.f,PI);
    for (unsigned i=0; i<20; ++i) {
        boss->Bullets.push_back(new SpeedBullet(70));
        SuperBullet* sbullet=boss->Bullets.back();
        sbullet->SetImage(BULLET_1_RED);
        sbullet->SetRadius(9);
        sbullet->SetPosition(v[n]);
        sbullet->SetAngle(BaseAngle+2*PI/20*i);
    }
}

void Level7::BossShoot_ID_8_BOSS7(Boss* boss, float basetime) {}

void Level7::BossShoot_ID_8_7(Boss* boss, float basetime) {}

namespace {
    void AuxBossMove_ID_9(Enemy* enemy, int N) {
        float x;
        switch(N) {
            case 1: x=70; break;
            case 2: x=430; break;
            case 3: x=130; break;
            case 4: x=370; break;
            case 5: x=190; break;
            case 6: x=310; break;
            default: break;
        }
        float yDiff;
        switch (static_cast<int>(floor((N+1)/2))) {
            case 1: yDiff=0; break;
            case 2: yDiff=40; break;
            case 3: yDiff=60; break;
            default: break;
        }
        float yMax=210-yDiff;
        enemy->Position.x=x;
        enemy->Position.y=min<float>(enemy->Position.y+120.f*Engine.FrameTime, yMax);
    }

    template<int N>
    void AuxBossMoveCaller(Enemy* enemy) {AuxBossMove_ID_9(enemy, N);}
}

void Level7::BossShoot_ID_9_SETDATA(Boss* boss, float basetime) {
    boss->Data.clear();
    boss->Data.push_back(100); //Life Percentage
    boss->Data.push_back(0); //Num of _1
    boss->Data.push_back(0); //Num of _2
    boss->Data.push_back(Engine.PastTime);

    Engine.Enemies[0]->Move=AuxBossMoveCaller<1>;
    Engine.Enemies[1]->Move=AuxBossMoveCaller<2>;
    Engine.Enemies[2]->Move=AuxBossMoveCaller<3>;
    Engine.Enemies[3]->Move=AuxBossMoveCaller<4>;
    Engine.Enemies[4]->Move=AuxBossMoveCaller<5>;
    Engine.Enemies[5]->Move=AuxBossMoveCaller<6>;
    for (int i=0; i<6; ++i)
        Engine.Enemies[i]->Position.y=-50;

    boss->Position={250.f,static_cast<float>(-50.f+120.f*Engine.FrameTime)};
}

void Level7::BossShoot_ID_9_1(Boss* boss, float basetime) {
    boss->Data[1]=fmodf(++boss->Data[1],2);
    sf::Vector2f pos=Engine.Enemies[boss->Data[1]]->Position;
    float BaseAngle=-atan2f(Engine.Player->Position.y-pos.y, Engine.Player->Position.x-pos.x)-PI/16;
    for (unsigned i=0; i<6; ++i) {
        for (unsigned j=0; j<21; ++j) {
            boss->Bullets.push_back(new SpeedBullet(190));
            SuperBullet* sbullet=boss->Bullets.back();
            sbullet->SetImage(BULLET_1_BLUE);
            //sbullet->SetImageColor(0,0,255);
            sbullet->SetRadius(9);
            sbullet->SetAngle(BaseAngle+PI/3*i+PI/16/10*j);
            sbullet->SetPosition(pos);
        }
    }
}

/*void Level7::BossShoot_ID_9_2(Boss* boss, float basetime) {
    if (boss->Data[0]>75)
        return;

    ++boss->Data[2];
    for (unsigned i=0; i<2; ++i) {
        boss->Bullets.push_back(new SpeedBullet(80));
        SuperBullet* sbullet=boss->Bullets.back();
        sbullet->SetImage(BULLET_2_GREY);
        sbullet->SetImageColor(128,128,128);
        sbullet->SetRadius(13);
        sbullet->SetAngle(-atan2f(Engine.Player->Position.y-Engine.Enemies[2+i]->Position.y, Engine.Player->Position.x-Engine.Enemies[2+i]->Position.x));
        sbullet->SetPosition(Engine.Enemies[2+i]->Position);
    }
    if (boss->Data[2]==5) {
        boss->Data[2]=0;
        boss->LifeBars.back()->ShootTable[2]->first.second=0.8;
    }
    else {
        boss->LifeBars.back()->ShootTable[2]->first.second=0.07;
    }
}*/

void Level7::BossShoot_ID_9_2(Boss* boss, float basetime) {
    if (boss->Data[0]>75)
        return;

    for (unsigned i=0; i<2; ++i) {
        boss->Bullets.push_back(new SpeedBullet(200));
        SuperBullet* sbullet=boss->Bullets.back();
        sbullet->SetImage(BULLET_2_GREY);
        sbullet->SetImageColor(128,128,128);
        sbullet->SetRadius(13);
        sbullet->SetAngle(-atan2f(Engine.Player->Position.y-Engine.Enemies[2+i]->Position.y, Engine.Player->Position.x-Engine.Enemies[2+i]->Position.x));
        sbullet->SetPosition(Engine.Enemies[2+i]->Position);
        /*sbullet->SetBaseTime(basetime);
        sbullet->SetMoveFunc(&Level7::BossBulletMove_ID_9_2);*/
    }
}

void Level7::BossShoot_ID_9_3(Boss* boss, float basetime) {
    if (boss->Data[0]>50)
        return;

    Enemy* enemy=Engine.Enemies[4];
    for (unsigned i=0; i<2; ++i) {
        float BaseAngle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x)-0.5;
        for (unsigned j=0; j<2; ++j) {
            boss->Bullets.push_back(new SpeedBullet(100));
            SuperBullet* sbullet=boss->Bullets.back();
            sbullet->SetImage(BULLET_5);
            sbullet->SetImageColor(255,60,60);
            sbullet->SetRadius(12);
            sbullet->SetAngle(BaseAngle+j*1.f);
            sbullet->SetPosition(enemy->Position);
            sbullet->SetBaseTime(basetime);
            //sbullet->SetMoveFunc(Level7::BossBulletMove_ID_9_3);
            sbullet->SetDeleteFunc(Level7::DeleteBullet_ID_9_3);
        }
        enemy=Engine.Enemies[5];
    }
}

/*void Level7::BossShoot_ID_9_4(Boss* boss, float basetime) {
    if (boss->Data[0]>25)
        return;

    for (unsigned i=0; i<10; ++i) {
        for (unsigned j=0; j<2; ++j) {
            boss->Bullets.push_back(new SpeedBullet((10+5*(i+1))*pow(-1,j)));
            SuperBullet* sbullet=boss->Bullets.back();
            sbullet->SetImage(BULLET_6);
            sbullet->SetImageColor(0,0,0);
            sbullet->SetRadius(9);
            sbullet->SetPosition(boss->Position);
            sbullet->SetBaseTime(basetime);
            sbullet->SetMoveFunc(Level7::BossBulletMove_ID_9_4);
            sbullet->SetDeleteFunc(Level7::DeleteBullet_ID_9_4);
        }
    }
}*/

void Level7::BossShoot_ID_9_4(Boss* boss, float basetime) {
    if (boss->Data[0]>25)
        return;

    float BaseAngle=-atan2f(Engine.Player->Position.y-boss->Position.y, Engine.Player->Position.x-boss->Position.x)-1.5f;
    for (unsigned i=0; i<7; ++i) {
        boss->Bullets.push_back(new SuperBullet);
        SuperBullet* sbullet=boss->Bullets.back();
        sbullet->SetImage(BULLET_2_RED);
        sbullet->SetImageColor(128,128,128);
        sbullet->SetRadius(13);
        sbullet->SetPosition(boss->Position);
        sbullet->SetBaseTime(basetime);
        sbullet->SetAngle(BaseAngle+0.5f*i);
        sbullet->SetMoveFunc(Level7::BossBulletMove_ID_9_4);
    }
}

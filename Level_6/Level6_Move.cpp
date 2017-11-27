#include "Level6.h"

void Level6::Move_ID_1_1(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=0.8) {
        enemy->Position.x=130;
        enemy->Position.y=200*time;
    }
    else if (time<=6.3) {
        enemy->Position.y=160;
    }
    else if (time<8.5) {
        time-=6.3;
        enemy->Position.x=130-80*time;
        enemy->Position.y=160-40*time;
    }
}

void Level6::Move_ID_1_2(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=0.8) {
        enemy->Position.x=370;
        enemy->Position.y=200*time;
    }
    else if (time<=6.3) {
        enemy->Position.y=160;
    }
    else if (time<8.5) {
        time-=6.3;
        enemy->Position.x=370+80*time;
        enemy->Position.y=160-40*time;
    }
}

void Level6::Move_ID_2_1(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<5.5) {
        enemy->Position.x=100+cos(time*2)*60;
        enemy->Position.y=120*time;
    }
}

void Level6::Move_ID_2_2(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<5.5) {
        enemy->Position.x=100-cos(time*2)*60;
        enemy->Position.y=120*time;
    }
}

void Level6::Move_ID_2_3(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<5.5) {
        enemy->Position.x=400+cos(time*2)*60;
        enemy->Position.y=120*time;
    }
}

void Level6::Move_ID_2_4(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<5.5) {
        enemy->Position.x=400-cos(time*2)*60;
        enemy->Position.y=120*time;
    }
}

void Level6::Move_ID_3_1(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=0.5) {
        enemy->Position.x=160*time;
        enemy->Position.y=90+60*time;
    }
    else if (time<=0.8) {
        enemy->Position.x=80;
        enemy->Position.y=120;
    }
    else  if (time<5) {
        time-=0.8;
        enemy->Position.x=80+160*time;
        enemy->Position.y=120+60*time;
    }
}

void Level6::Move_ID_3_2(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=0.5) {
        enemy->Position.x=500-160*time;
        enemy->Position.y=90+60*time;
    }
    else if (time<=0.8) {
        enemy->Position.x=420;
        enemy->Position.y=120;
    }
    else if (time<5) {
        time-=0.8;
        enemy->Position.x=420-160*time;
        enemy->Position.y=120+60*time;
    }
}

void Level6::Move_ID_4_1(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<7) {
        enemy->Position.x=100*time;
        enemy->Position.y=120;
    }
}

void Level6::Move_ID_4_2(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<7) {
        enemy->Position.x=500-100*time;
        enemy->Position.y=160;
    }
}

void Level6::Move_ID_5_1(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<3) {
        enemy->Position.x=250*time;
        enemy->Position.y=45+80*time*time;
    }
}

void Level6::Move_ID_5_2(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<3) {
        enemy->Position.x=500-250*time;
        enemy->Position.y=45+80*time*time;
    }
}

void Level6::Move_ID_6(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=1) {
        enemy->Position.x=250;
        enemy->Position.y=300*time-140*time*time;
    }
    else if (time<=14) {
        enemy->Position.x=250;
        enemy->Position.y=160;
    }
    else {
        time-=14;
        enemy->Position.x=250-60*time*time;
        enemy->Position.y=160-20*time*time;
    }
}

void Level6::Move_ID_7_1(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    enemy->Position.x=90+35*time*time;
    enemy->Position.y=180*time;
}

void Level6::Move_ID_7_2(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    enemy->Position.x=410-35*time*time;
    enemy->Position.y=180*time;
}

void Level6::Move_ID_8(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=1) {
        enemy->Position.x=350-100*time;
        enemy->Position.y=-50+250*time;
    }
    else if (time<=32) {
        enemy->Position.x=250;
        enemy->Position.y=200;
    }
    else if (time<=36) {
        time-=32;
        enemy->Position.x=250-50*time*time;
        enemy->Position.y=200-30*time*time;
    }
}

void Level6::Move_ID_9_WAIT_1(Enemy* enemy) {
    bool go=true;
    for (unsigned i=0; i<Engine.Enemies.size(); ++i) {
        if (Engine.Enemies.at(i)->Move==&Move_ID_8) {
            go=false;
            break;
        }
    }

    enemy->Move=go?Move_ID_9_1:Move_ID_9_DONTGO;
}

void Level6::Move_ID_9_WAIT_2(Enemy* enemy) {
    bool go=true;
    for (unsigned i=0; i<Engine.Enemies.size(); ++i) {
        if (Engine.Enemies.at(i)->Move==&Move_ID_8) {
            go=false;
            break;
        }
    }

    enemy->Move=go?Move_ID_9_2:Move_ID_9_DONTGO;
}

void Level6::Move_ID_9_DONTGO(Enemy* enemy) {
    /* empty */
}

void Level6::Move_ID_9_1(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<2.5) {
        enemy->Position.x=230*time;
        enemy->Position.y=50+50*time*time;
    }
}

void Level6::Move_ID_9_2(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<2.5) {
        enemy->Position.x=500-230*time;
        enemy->Position.y=50+50*time*time;
    }
}

void Level6::Move_ID_10_1(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<2) {
        enemy->Position.x=300*time;
        enemy->Position.y=120+40*time;
    }
}

void Level6::Move_ID_10_2(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<2) {
        enemy->Position.x=500-300*time;
        enemy->Position.y=120-40*time;
    }
}

void Level6::Move_ID_11_1_FIRSTPHASE(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<3.3) {
        enemy->Position.x=80;
        enemy->Position.y=210*time;
        if (enemy->Position.y>Engine.Player->Position.y) {
            enemy->BaseTime=Engine.PastTime;
            enemy->Move=Move_ID_11_1_SECONDPHASE;
        }
    }
}

void Level6::Move_ID_11_2_FIRSTPHASE(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<3.3) {
        enemy->Position.x=420;
        enemy->Position.y=210*time;
        if (enemy->Position.y>Engine.Player->Position.y) {
            enemy->BaseTime=Engine.PastTime;
            enemy->Move=Move_ID_11_2_SECONDPHASE;
        }
    }
}

void Level6::Move_ID_11_1_SECONDPHASE(Enemy* enemy) {
    if (Engine.PastTime-enemy->BaseTime<3)
        enemy->Position.x+=180*Engine.FrameTime;
}

void Level6::Move_ID_11_2_SECONDPHASE(Enemy* enemy) {
    if (Engine.PastTime-enemy->BaseTime<3)
        enemy->Position.x-=180*Engine.FrameTime;
}

void Level6::Move_ID_12_1(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<0.8) {
        enemy->Position.x=250;
        enemy->Position.y=120*time;
    }
    else if (time<11.6)  {
        enemy->Position.y=96;
    }
    else if (time<13) {
        time-=11.6;
        enemy->Position.y=96-120*time;
    }
}

void Level6::Move_ID_12_2_1(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<0.8) {
        enemy->Position.x=100;
        enemy->Position.y=150*time;
    }
    else if (time<16) {
        enemy->Position.x=100;
        enemy->Position.y=120;
    }
    else if (time<18) {
        time-=16;
        enemy->Position.x=100-20*time*time;
        enemy->Position.y=120-60*time*time;
    }
}

void Level6::Move_ID_12_2_2(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<0.8) {
        enemy->Position.x=400;
        enemy->Position.y=150*time;
    }
    else if (time<16) {
        enemy->Position.x=400;
        enemy->Position.y=120;
    }
    else if (time<18) {
        time-=16;
        enemy->Position.x=400+20*time*time;
        enemy->Position.y=120-60*time*time;
    }
}

void Level6::Move_ID_12_3_1(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<0.8) {
        enemy->Position.x=110;
        enemy->Position.y=200*time;
    }
    else if (time<19) {
        enemy->Position.x=110;
        enemy->Position.y=160;
    }
    else if (time<21) {
        time-=19;
        enemy->Position.x=110-20*time*time;
        enemy->Position.y=160-60*time*time;
    }
}

void Level6::Move_ID_12_3_2(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<0.8) {
        enemy->Position.x=250;
        enemy->Position.y=150*time;
    }
    else if (time<19) {
        enemy->Position.x=250;
        enemy->Position.y=120;
    }
    else if (time<21) {
        time-=19;
        enemy->Position.x=250;
        enemy->Position.y=120-60*time*time;
    }
}

void Level6::Move_ID_12_3_3(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<0.8) {
        enemy->Position.x=390;
        enemy->Position.y=200*time;
    }
    else if (time<19) {
        enemy->Position.x=390;
        enemy->Position.y=160;
    }
    else if (time<21) {
        time-=19;
        enemy->Position.x=390+20*time*time;
        enemy->Position.y=160-60*time*time;
    }
}

void Level6::Move_ID_13_1_1(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<1.3) {
        enemy->Position.x=430*time;
        enemy->Position.y=200-70*time;
    }
}

void Level6::Move_ID_13_1_2(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<1.3) {
        enemy->Position.x=500-430*time;
        enemy->Position.y=200-70*time;
    }
}

void Level6::Move_ID_13_2_1_1(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<1.3) {
        enemy->Position.x=190*time;
        enemy->Position.y=400-350*time;
    }
}

void Level6::Move_ID_13_2_1_2(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<1.3) {
        enemy->Position.x=400*time;
        enemy->Position.y=180-120*time;
    }
}

void Level6::Move_ID_13_2_2_1(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<1.3) {
        enemy->Position.x=500-190*time;
        enemy->Position.y=400-350*time;
    }
}

void Level6::Move_ID_13_2_2_2(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<1.3) {
        enemy->Position.x=500-400*time;
        enemy->Position.y=180-120*time;
    }
}

void Level6::Move_ID_13_3_1_1(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<1) {
        enemy->Position.x=300*time;
        enemy->Position.y=250-300*time;
    }
}

void Level6::Move_ID_13_3_1_2(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<1) {
        enemy->Position.x=500-300*time;
        enemy->Position.y=250-300*time;
    }
}

void Level6::Move_ID_13_3_2_1(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<1) {
        enemy->Position.x=550*time;
        enemy->Position.y=250-200*time;
    }
}

void Level6::Move_ID_13_3_2_2(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<1) {
        enemy->Position.x=500-550*time;
        enemy->Position.y=250-200*time;
    }
}

/// - BOSS

void Level6::BossMove_ID_1(Boss* LevelBoss) {
    //Don't move (250,150)
}

void Level6::BossMove_ID_2(Boss* LevelBoss) {
    LevelBoss->Position.y-=50*Engine.FrameTime;
    if (LevelBoss->Position.y<90)
        LevelBoss->Position.y=90;
}

void Level6::BossMove_ID_3(Boss* LevelBoss) {
    LevelBoss->Position.y+=45*Engine.FrameTime;
    if (LevelBoss->Position.y>140)
        LevelBoss->Position.y=140;
}

void Level6::BossMove_ID_4(Boss* LevelBoss) {
    float time=LevelBoss->Data.size()!=1?0:Engine.PastTime-LevelBoss->Data[0];
    if (time<=1.3f)
        LevelBoss->Position.y=140+170*time-(61/1.69)*time*time;
    else
        LevelBoss->Position.y=300;
}

void Level6::BossMove_ID_5(Boss* LevelBoss) {
    float time=LevelBoss->Data.size()==2?Engine.PastTime-LevelBoss->Data[0]:0;
    LevelBoss->Position.y=300-min(1.2f,time)*150; //Up to 180
    LevelBoss->Position.x=250+sin(time*PI*0.25)*180;
}

void Level6::BossMove_ID_6(Boss* LevelBoss) {
    if (LevelBoss->Position.x<250)
        LevelBoss->Position.x=min(250.0, LevelBoss->Position.x+70*Engine.FrameTime);
    else
        LevelBoss->Position.x=max(250.0, LevelBoss->Position.x-70*Engine.FrameTime);
}

void Level6::BossMove_ID_7(Boss* LevelBoss) {
    //250 - 180
}

void Level6::BossMove_ID_8(Boss* LevelBoss) {
    LevelBoss->Position.y=max(LevelBoss->Position.y-30*Engine.FrameTime, 150.0);
    float DamagePercentage=(1800-LevelBoss->LifeBars.back()->Health)/1800*100;
    LevelBoss->LifeBars.back()->ShootTable[1]->first.second=2.4-2.0*DamagePercentage/100;
    LevelBoss->LifeBars.back()->ShootTable[2]->first.second=4.2-3.2*DamagePercentage/100;
}

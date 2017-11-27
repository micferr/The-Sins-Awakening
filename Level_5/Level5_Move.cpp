#include "Level5.h"

void Level5::Move_ID_1_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=2) {
        enemy->Position.x=160+185*(-cos(PI/2*time));
        enemy->Position.y=180-11*time*time;
    }
    else if (time<4) {
        time-=2;
        enemy->Position.x=345+5*time*time;
        enemy->Position.y=134-88*time*time;
    }
}

void Level5::Move_ID_1_2 (Enemy* enemy) {
    Level5::Move_ID_1_1(enemy);
    enemy->Position.x=500-enemy->Position.x;
}

void Level5::Move_ID_2_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    enemy->Position.x=100*time;
    enemy->Position.y=170+sin(PI/2*time/0.3)*35;
}

void Level5::Move_ID_2_2 (Enemy* enemy) {
    Level5::Move_ID_2_1(enemy);
    enemy->Position.x=500-enemy->Position.x;
}

void Level5::Move_ID_3 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    enemy->Position.x=250;
    if (time<=8) {
        if (time<=1.1) enemy->Position.y=220*time-100*time*time;
        else if (time<=2.6) enemy->Position.y=121;
        else {
            time-=2.6;
            enemy->Position.x=250+120*time*time;
            enemy->Position.y=121-100*time*time;
        }
    }
}

void Level5::Move_ID_4 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<5) {
        if (time<=1)
            enemy->Position.y=150*time-75*time*time;
        else if (time<=3)
            enemy->Position.y=75;
        else
            enemy->Position.y=75-75*pow(time-3,2);
    }
}

void Level5::Move_ID_5_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=3) {
        enemy->Position.x=250+cos(PI/3*time)*350;
        enemy->Position.y=300-sin(PI/3*time)*250;
    }
}

void Level5::Move_ID_5_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=3) {
        enemy->Position.x=250+cos(PI-PI/3*time)*350;
        enemy->Position.y=300-sin(PI-PI/3*time)*250;
    }
}

void Level5::Move_ID_6_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<5) {
        enemy->Position.x=125*time;
        enemy->Position.y=90;
    }
}

void Level5::Move_ID_6_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<5) {
        enemy->Position.x=500-125*time;
        enemy->Position.y=90;
    }
}

void Level5::Move_ID_7_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<2.2) {
        enemy->Position.x=190+30*time;
        enemy->Position.y=300*time;
    }
}

void Level5::Move_ID_7_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<2.2) {
        enemy->Position.x=310-30*time;
        enemy->Position.y=300*time;
    }
}

void Level5::Move_ID_8_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=1) {
        enemy->Position.x=500*time-250*time*time;
        enemy->Position.y=enemy->Position.x-50;
    }
    else if (time<=11) {
        enemy->Position.x=250;
        enemy->Position.y=200;
    }
    else if (time<=13) {
        time-=11;
        enemy->Position.x=250+70*time*time;
    }
}

void Level5::Move_ID_8_2 (Enemy* enemy) {
    Level5::Move_ID_8_1(enemy);
    if (Engine.PastTime-enemy->BaseTime<=13)
        enemy->Position.x=500-enemy->Position.x;
}

void Level5::Move_ID_9_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=2.7)
        enemy->Position=sf::Vector2f(200*time, 250);
}

void Level5::Move_ID_9_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=13) {
        Level5::Move_ID_9_1(enemy);
        enemy->Position.x=500-enemy->Position.x;
    }
}

void Level5::Move_ID_10_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<5.2) {
        enemy->Position.x=100*time;
        enemy->Position.y=80+25*time;
    }
}

void Level5::Move_ID_10_2 (Enemy* enemy) {
    Level5::Move_ID_10_1(enemy);
    if (Engine.PastTime-enemy->BaseTime<5.2)
        enemy->Position.x=500-enemy->Position.x;
}

void Level5::Move_ID_11 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<0.8) {
        enemy->Position.x=220+30*time/0.8;
        enemy->Position.y=300*time-100*time*time;
    }
    else if (time<16) {
        enemy->Position.x=250;
        enemy->Position.y=176;
    }
    else if (time<18) {
        time-=16;
        enemy->Position.x=250+120*time*time;
        enemy->Position.y=176-60*time*time;
    }
}

void Level5::Move_ID_12_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<3) {
        enemy->Position.x=200*time;
        enemy->Position.y=110-25*time;
    }
}

void Level5::Move_ID_12_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<3) {
        enemy->Position.x=500-200*time;
        enemy->Position.y=110-25*time;
    }
}

void Level5::Move_ID_13_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<2.5) {
        enemy->Position.x=250*time;
    }
}

void Level5::Move_ID_13_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<2.5) {
        enemy->Position.x=500-250*time;
    }
}

void Level5::Move_ID_14_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<1) {
        enemy->Position.x=40+40*time;
        enemy->Position.y=200*time-100*time*time;
    }
    else if (time>8 && time<12) {
        time-=8;
        enemy->Position.x=80+60*time;
        enemy->Position.y=100-20*time*time;
    }
}

void Level5::Move_ID_14_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<1) {
        enemy->Position.x=460-40*time;
        enemy->Position.y=200*time-100*time*time;
    }
    else if (time>8 && time<12) {
        time-=8;
        enemy->Position.x=420-60*time;
        enemy->Position.y=100-20*time*time;
    }
}

void Level5::Move_ID_15_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=0.5) {
        enemy->Position.x=90+50*time;
        enemy->Position.y=400*time-400*time*time;
    }
    else if (time>=10 && time<12) {
        time-=10;
        enemy->Position.x=115+30*time;
        enemy->Position.y=100-30*time*time;
    }
}

void Level5::Move_ID_15_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=0.5) {
        enemy->Position.x=410-50*time;
        enemy->Position.y=400*time-400*time*time;
    }
    else if (time>=10 && time<12) {
        time-=10;
        enemy->Position.x=385-30*time*time;
        enemy->Position.y=100-30*time*time;
    }
}

void Level5::Move_ID_16_1 (Enemy* enemy) {
    if (Engine.PastTime-enemy->BaseTime<6)
        enemy->Position.x+=120*Engine.FrameTime;
}

void Level5::Move_ID_16_2 (Enemy* enemy) {
    if (Engine.PastTime-enemy->BaseTime<6)
        enemy->Position.x-=120*Engine.FrameTime;
}

void Level5::Move_ID_17 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=1.5) {
        enemy->Position.x=400-100*time;
        enemy->Position.y=350*time-100*time*time-200;
    }
    else if (time>=23 && time<27) {
        time-=23;
        enemy->Position.x=250-70*time;
        enemy->Position.y=300-20*time*time-200;
    }
}

void Level5::Move_ID_18_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=1.25) {
        enemy->Position.x=200*time;
        enemy->Position.y=150;
    }
    else if (time<=2.25) {
        time-=1.25;
        enemy->Position.x=250+cos(PI*3/2+PI*time)*50;
        enemy->Position.y=100-sin(PI*3/2+PI*time)*50;
    }
    else if (time<3.5) {
        time-=2.25;
        enemy->Position.x=250-200*time;
        enemy->Position.y=50;
    }
}

void Level5::Move_ID_18_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=1.25) {
        enemy->Position.x=500-200*time;
        enemy->Position.y=150;
    }
    else if (time<=2.25) {
        time-=1.25;
        enemy->Position.x=250+cos(PI*3/2-PI*time)*50;
        enemy->Position.y=100-sin(PI*3/2-PI*time)*50;
    }
    else if (time<3.5) {
        time-=2.25;
        enemy->Position.x=250+200*time;
        enemy->Position.y=50;
    }
}

///BOSS

void Level5::BossMove_ID_1(Boss* LevelBoss) {
    float time=LevelBoss->Data.size()>0 ? Engine.PastTime-LevelBoss->Data[0] : 0;
    time=fmod(time, 4);
    if (time<=1) {
        time=time>0.5?0.5:time; //Cap to 0.5;
        LevelBoss->Position.x=250+500*time-400*time*time;
        LevelBoss->Position.y=150+60*time;
    }
    else if (time<=2) {
        time=(--time>0.5?0.5:time);
        LevelBoss->Position.x=400-500*time+400*time*time;
        LevelBoss->Position.y=180+60*time;
    }
    else if (time<=3) {
        time=((time-=2)>0.5?0.5:time);
        LevelBoss->Position.x=250-500*time+400*time*time;
        LevelBoss->Position.y=210-60*time;
    }
    else {
        time=((time-=3)>0.5?0.5:time);
        LevelBoss->Position.x=100+500*time-400*time*time;
        LevelBoss->Position.y=180-60*time;
    }
}

void Level5::BossMove_ID_2 (Boss* LevelBoss) {
    float time=LevelBoss->Data.size()>1?Engine.PastTime-LevelBoss->Data[0]:0;
    float &x=LevelBoss->Position.x, &y=LevelBoss->Position.y;
    if (time<=0.6) {}
    else if (time<=2.5) {
        float Angle=-atan2f(120-y,250-x);
        if (x<250) {x+=150*cos(Angle)*Engine.FrameTime; if(x>250)x=250;}
        if (x>250) {x+=150*cos(Angle)*Engine.FrameTime; if(x<250)x=250;}
        if (y>120) {y-=150*sin(Angle)*Engine.FrameTime; if(y<120)y=120;}
    }
    else {
        time=fmod(time-2.5f, 3.9f);
        if (time<=0.7f) {
            LevelBoss->Position.x=250+180*time-30/2*time*time;
            LevelBoss->Position.y=120+50*time;
        }
        else if (time<=1.3f) {
            LevelBoss->Position=sf::Vector2<float>(369.875,155);
        }
        else if (time<=2.f) {
            time-=1.3f;
            LevelBoss->Position.x=369.875f-500*time+225*time*time;
        }
        else if (time<=2.6f) {
            LevelBoss->Position=sf::Vector2<float>(130.125f, 155);
        }
        else if (time<=3.3f) {
            time-=2.6f;
            LevelBoss->Position.x=130.125f+180*time-30/2*time*time;
            LevelBoss->Position.y=155-50*time;
        }
        else {
            LevelBoss->Data[0]+=3.9f;
            Level5::BossMove_ID_2(LevelBoss);
        }
    }
}

void Level5::BossMove_ID_3 (Boss* LevelBoss) {
    float &x=LevelBoss->Position.x, &y=LevelBoss->Position.y;
    float Angle=-atan2f(300-y,250-x);
    if (x<250) {
        x+=140*cos(Angle)*Engine.FrameTime;
        if (x>250) x=250;
    }
    else if (x>250) {
        x+=140*cos(Angle)*Engine.FrameTime;
    }
    if (y<300) {
        y+=140*-sin(Angle)*Engine.FrameTime;
    }
}

void Level5::BossMove_ID_4 (Boss* LevelBoss) {
    float &x=LevelBoss->Position.x, &y=LevelBoss->Position.y;
    float Angle=-atan2f(180-y,250-x);
    if (x<250) {
        x+=140*cos(Angle)*Engine.FrameTime;
        if (x>250) x=250;
    }
    else if (x>250) {
        x+=140*cos(Angle)*Engine.FrameTime;
    }
    if (y>180) {
        y+=140*-sin(Angle)*Engine.FrameTime;
    }
}

void Level5::BossMove_ID_5 (Boss* LevelBoss) {
    if (LevelBoss->Position.y>100) {
        LevelBoss->Position.y-=80*Engine.FrameTime;
        if (LevelBoss->Position.y<100)
            LevelBoss->Position.y=100;
    }
}

void Level5::BossMove_ID_6 (Boss* LevelBoss) {
    float time=LevelBoss->Data.size()==1?Engine.PastTime-LevelBoss->Data[0]:0;
    LevelBoss->Position.x=250+200*-sin(time*0.5);
    LevelBoss->Position.y=100;
}

void Level5::BossMove_ID_7 (Boss* LevelBoss) {
    float Angle=-atan2f(140-LevelBoss->Position.y, 250-LevelBoss->Position.x);
    float &x=LevelBoss->Position.x, &y=LevelBoss->Position.y;
    if (x!=250) {
        enum {WAS_LEFT, WAS_RIGHT} prev=x<250?WAS_LEFT:WAS_RIGHT;
        x+=cos(Angle)*150*Engine.FrameTime;
        if ((x>250 && prev==WAS_LEFT) || (x<250 && prev==WAS_RIGHT))
            x=250;
    }
    if (y!=140) {
        enum {WAS_UP, WAS_DOWN} prev=y<140?WAS_UP:WAS_DOWN;
        y-=sin(Angle)*150*Engine.FrameTime;
        if ((y>140 && prev==WAS_UP) || (y<140 && prev==WAS_DOWN))
            y=140;
    }
}

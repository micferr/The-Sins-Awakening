#include "Level4.h"

void Level4::Move_ID_1_1(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<5) {
        if (time<1.5) {
            enemy->Position.x=0+200*time;
            enemy->Position.y=200-100*time+40*time*time;
        }
        else {
            enemy->Position.x=300;
            enemy->Position.y=140;
            if (time>2) {
                time-=2;
                enemy->Position.x=300+70*time;
                enemy->Position.y=140+60*time*time;
            }
        }
    }
}

void Level4::Move_ID_1_2(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<5) {
        if (time<1.5) {
            enemy->Position.x=500-200*time;
            enemy->Position.y=200-100*time+40*time*time;
        }
        else {
            enemy->Position.x=200;
            enemy->Position.y=140;
            if (time>2) {
                time-=2;
                enemy->Position.x-=70*time;
                enemy->Position.y+=60*time*time;
            }
        }
    }
}

void Level4::Move_ID_2_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<2) {
        enemy->Position.x=100;
        enemy->Position.y=240*time;
    }
    else if (time<=2.5) {
        enemy->Position.x=150+cos(PI+time*PI)*50;
        enemy->Position.y=480-sin(PI+time*PI)*50;
    }
    else if (time<12) {
        time-=2.5;
        enemy->Position.x=150+110*time;
        enemy->Position.y=530-90*time*time;
    }
}

void Level4::Move_ID_2_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<2) {
        enemy->Position.x=400;
        enemy->Position.y=240*time;
    }
    else if (time<=2.5) {
        enemy->Position.x=350+cos(-time*PI)*50;
        enemy->Position.y=480-sin(PI+time*PI)*50;
    }
    else if (time<12) {
        time-=2.5;
        enemy->Position.x=350-110*time;
        enemy->Position.y=530-90*time*time;
    }
}

void Level4::Move_ID_3_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=5.2) {
        enemy->Position.x=40+20*time*time;
        enemy->Position.y=600-125*time;
    }
}

void Level4::Move_ID_3_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=5.2) {
        enemy->Position.x=460-20*time*time;
        enemy->Position.y=600-125*time;
    }
}

void Level4::Move_ID_4_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    enemy->Position.x=200*time;
    enemy->Position.y=160-sin(time/2*PI)*50; //PI in 2 secs
}

void Level4::Move_ID_4_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    enemy->Position.x=500-200*time;
    enemy->Position.y=160+sin(time/2*PI)*50;
}

void Level4::Move_ID_5_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=7.7) {
        enemy->Position.x=200+20*time*time;
        enemy->Position.y=80*time;
    }
}

void Level4::Move_ID_5_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=7.7) {
        enemy->Position.x=300-20*time*time;
        enemy->Position.y=80*time;
    }
}

void Level4::Move_ID_6_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<1.5) {
        enemy->Position.x=40;
        enemy->Position.y=600-200*time;
    }
    else if (time<7.5) {
        time-=1.5;
        float Angle=PI-(PI/3)*time;
        enemy->Position.x=250+cos(Angle)*210;
        enemy->Position.y=300-sin(Angle)*210;
    }
    else {
        time-=7.5;
        enemy->Position.x=40;
        enemy->Position.y=300-200*time;
    }
}

void Level4::Move_ID_6_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<1.5) {
        enemy->Position.x=460;
        enemy->Position.y=600-200*time;
    }
    else if (time<7.5) {
        time-=1.5;
        float Angle=(PI/3)*time;
        enemy->Position.x=250+cos(Angle)*210;
        enemy->Position.y=300-sin(Angle)*210;
    }
    else {
        time-=7.5;
        enemy->Position.x=460;
        enemy->Position.y=300-200*time;
    }
}

void Level4::Move_ID_7_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    enemy->Position.x=130;
    if (time<=2) {
        enemy->Position.y=-30+145*time;
        if (enemy->Position.y>130)
            enemy->Position.y=130;
    }
    else
        enemy->Position.y=130-145*(time-2);
}

void Level4::Move_ID_7_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    enemy->Position.x=370;
    if (time<=2) {
        enemy->Position.y=-30+145*time;
        if (enemy->Position.y>130)
            enemy->Position.y=130;
    }
    else
        enemy->Position.y=130-145*(time-2);
}

void Level4::Move_ID_8 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<35) {
        enemy->Position.x=250;
        enemy->Position.y=-60+90*time;
        if (enemy->Position.y>210)
            enemy->Position.y=210;
    }
    else {
        enemy->Position.y=210-(time-35)*70;
    }
}

void Level4::Move_ID_9_1_START (Enemy* enemy) {
    for (unsigned int i=0; i<Engine.Enemies.size(); ++i) {
        if (Engine.Enemies.at(i)->Move==&Level4::Move_ID_8) /* If the midboss is still alive */ {
            enemy->Move=&Level4::Move_ID_9_NOTHING;
            return;
        }
    }
    enemy->Move=&Level4::Move_ID_9_1_GO;
}

void Level4::Move_ID_9_2_START (Enemy* enemy) {
    for (unsigned int i=0; i<Engine.Enemies.size(); ++i) {
        if (Engine.Enemies.at(i)->Move==&Level4::Move_ID_8) {
            enemy->Move=&Level4::Move_ID_9_NOTHING;
            return;
        }
    }
    enemy->Move=&Level4::Move_ID_9_2_GO;
}

void Level4::Move_ID_9_1_GO (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<3) {
        enemy->Position.x=180*time;
        enemy->Position.y=170-20*time*time;
    }
}

void Level4::Move_ID_9_2_GO (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<3) {
        enemy->Position.x=500-180*time;
        enemy->Position.y=170-20*time*time;
    }
}

void Level4::Move_ID_9_NOTHING (Enemy* enemy) {
    enemy->Position.x=enemy->Position.y=10000;
}

void Level4::Move_ID_10_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    enemy->Position.x=170*time;
    enemy->Position.y=130-20*time;
}

void Level4::Move_ID_10_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    enemy->Position.x=500-170*time;
    enemy->Position.y=130-20*time;
}

void Level4::Move_ID_11_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=1.25) {
        enemy->Position.x=200*time;
        enemy->Position.y=100+80*time;
    }
    else if (time<8) {
        enemy->Position.x=250;
        enemy->Position.y=200;
    }
    else {
        time-=8;
        enemy->Position.x=250+10*time*time;
        enemy->Position.y=200+20*time*time;
    }
}

void Level4::Move_ID_11_2 (Enemy* enemy) {
    Level4::Move_ID_11_1(enemy);
    enemy->Position.x=500-enemy->Position.x; //Specular
}

///Boss

void Level4::BossMove_ID_1 (Boss* LevelBoss) {
    LevelBoss->Position.y-=40*Engine.FrameTime;
    if (LevelBoss->Position.y<90)
        LevelBoss->Position.y=90;
}

void Level4::BossMove_ID_2 (Boss* LevelBoss) {
    if (LevelBoss->Data.size()==4) /* We have to set the data */ {
        Level4::BossShoot_ID_2_SETDATA(LevelBoss, Engine.PastTime);
    }
    float time=Engine.PastTime-LevelBoss->Data[0];
    LevelBoss->Position=sf::Vector2<float>(250+sin(time*0.8)*160, 120-cos(time*0.8)*30); //Cos and sin voluntarily inverted
}

void Level4::BossMove_ID_3 (Boss* LevelBoss) {
    if (LevelBoss->Position!=sf::Vector2<float>(250,130)) {
        float Angle=-atan2f(130-LevelBoss->Position.y, 250-LevelBoss->Position.x);
        signed short hor=LevelBoss->Position.x<250 ? -1 : (LevelBoss->Position.x>250 ? 1 : 0),
                     ver=LevelBoss->Position.y<130 ? -1 : (LevelBoss->Position.y>130 ? 1 : 0); //LoL
        if (hor!=0) {
            LevelBoss->Position.x+=cos(Angle)*90*Engine.FrameTime;
            if ((hor==-1 && LevelBoss->Position.x>250) || (hor==1 && LevelBoss->Position.x<250)) LevelBoss->Position.x=250;
        }
        if (ver!=0) {
            LevelBoss->Position.y-=sin(Angle)*90*Engine.FrameTime;
            if ((ver==-1 && LevelBoss->Position.y>130) || (ver==-1 && LevelBoss->Position.y<130)) LevelBoss->Position.y=130;
        }
    }
}

void Level4::BossMove_ID_4 (Boss* LevelBoss) {
    LevelBoss->Position.y+=60*Engine.FrameTime;
    if (LevelBoss->Position.y>300)
        LevelBoss->Position.y=300;
    float PlayerToBossAngle=-atan2f(LevelBoss->Position.y-Engine.Player->Position.y, LevelBoss->Position.x-Engine.Player->Position.x);
    LevelBoss->Data[1]=((LevelBoss->LifeBars.back()->MaxHealth-LevelBoss->LifeBars.back()->Health)/LevelBoss->LifeBars.back()->MaxHealth);
    float movspeed=LevelBoss->Data[1]*50;
    Engine.Player->Position.x+=movspeed*cos(PlayerToBossAngle)*Engine.FrameTime;
    Engine.Player->Position.y-=movspeed*sin(PlayerToBossAngle)*Engine.FrameTime;
    LevelBoss->LifeBars.back()->ShootTable.at(1)->first.second=4-3*LevelBoss->Data[1];
}

void Level4::BossMove_ID_5 (Boss* LevelBoss) {
    LevelBoss->Position.y-=90*Engine.FrameTime;
    if (LevelBoss->Position.y<100)
        LevelBoss->Position.y=100;
}

void Level4::BossMove_ID_6_PREPARE (Boss* LevelBoss) {
    if (LevelBoss->Data.size()==3)
        Level4::BossShoot_ID_6_1(LevelBoss, Engine.PastTime);
    LevelBoss->Position.y-=100*Engine.FrameTime;
    LevelBoss->LifeBars.back()->Health=590-((Engine.PastTime-LevelBoss->Data[1])*10);
    if (LevelBoss->Position.y<-150) {
        LevelBoss->Position.y=1150;
        LevelBoss->LifeBars.back()->Move=&Level4::BossMove_ID_6_GO;
    }
}

void Level4::BossMove_ID_6_GO (Boss* LevelBoss) {
    LevelBoss->LifeBars.back()->Health=590-((Engine.PastTime-LevelBoss->Data[1])*10);
    LevelBoss->Data[0]=(LevelBoss->LifeBars.back()->MaxHealth-LevelBoss->LifeBars.back()->Health)/LevelBoss->LifeBars.back()->MaxHealth; //Fire rate
    LevelBoss->LifeBars.back()->ShootTable.back()->first.second=0.4-0.25*LevelBoss->Data[0];
    float speed=400+(LevelBoss->LifeBars.back()->MaxHealth-LevelBoss->LifeBars.back()->Health)/LevelBoss->LifeBars.back()->MaxHealth*400;
    LevelBoss->Position.y+=speed*Engine.FrameTime;
    if (LevelBoss->Position.y>1200) {
        LevelBoss->Position.x=Engine.Player->Position.x;
        LevelBoss->Position.y=-150+LevelBoss->Position.y-1200;
    }
}

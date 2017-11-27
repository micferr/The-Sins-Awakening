#include "Level2.h"

void Level2::Move_ID_1_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time>0 && time<4) {
        double to_cos_and_sin=(90-(60*time))*PI/180;
        sf::Vector2<double> rad(cos(to_cos_and_sin), sin(to_cos_and_sin));
        enemy->Position.y=150+30*rad.y;
        enemy->Position.x=-40+500*rad.x;
    }
}

void Level2::Move_ID_1_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time>0 && time<4) {
        double to_cos_and_sin=(90-(60*time))*PI/180;
        sf::Vector2<double> rad(cos(to_cos_and_sin), sin(to_cos_and_sin));
        enemy->Position.y=150+30*rad.y;
        enemy->Position.x=515-500*rad.x;
    }
}

void Level2::Move_ID_2_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time>0 && time<=1.5) {
        //S-zero + V-zero*t + 1/2*a*t^2
        double y=-50+(240*time)+(-60*time*time);
        if (y>80)
            y=80;
        enemy->Position.y=y;
    }
    else if (time>=17 && time<23) {
        enemy->Position.y-=40*Engine.FrameTime;
    }
}

void Level2::Move_ID_2_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time>=0 && time<=1.5) {
        //S-zero + V-zero*t + 1/2*a*t^2
        double y=-50+(240*time)+(-90*time*time); //1/2*a --> a/2 --> -80/2 --> -40
        //With time=1.5: -30+240*1.5+a*t^2/2 --> 127.50
        if (y>127.5)
            y=127.5;
        enemy->Position.y=y;
    }
    else if (time>=17 && time<23) {
        enemy->Position.y-=40*Engine.FrameTime;
    }
}

void Level2::Move_ID_3_1 (Enemy* enemy) {
    //if previous enemies are still there, these enemies will never enter
    for (short i=0; i<16; ++i)
        if (Engine.Enemies.at(i)->Move==&Level2::Move_ID_2_1 || Engine.Enemies.at(i)->Move==&Level2::Move_ID_2_2) {
            enemy->Move=&Level2::Move_ID_3_NULL;
            return;
        }
    //else they will
    enemy->Move=&Level2::Move_ID_3_2;
}

void Level2::Move_ID_3_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=7)
        enemy->Position.y=-10+124*time;
}

void Level2::Move_ID_3_NULL (Enemy* enemy) {
    //Nothing
}

void Level2::Move_ID_4_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<6) {
        double Angle=-time*40*PI/180; //Radians
        enemy->Position=sf::Vector2<float>(180+cos(Angle)*190, -20-sin(Angle)*190);
    }
}

void Level2::Move_ID_4_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<6) {
        double Angle=(180+(time*40))*PI/180;
        enemy->Position=sf::Vector2<float>(320+cos(Angle)*190, -20-sin(Angle)*190);
    }
}

void Level2::Move_ID_5_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<4) {
        double Angle=(135-time*40)*PI/180;
        enemy->Position=sf::Vector2<float>(250+cos(Angle)*500, 600-sin(Angle)*500);
    }
}

void Level2::Move_ID_5_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<4) {
        double Angle=(45+time*40)*PI/180;
        enemy->Position=sf::Vector2<float>(250+cos(Angle)*500, 600-sin(Angle)*500);
    }
}

void Level2::Move_ID_6_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<6) {
        if (time>1 && time<1.8)
            time=1;
        else if (time>=1.8 && time<3)
            time-=0.8;
        else if (time>=3 && time<3.8)
            time=2.2;
        else if (time>=3.8)
            time-=1.6;
        enemy->Position=sf::Vector2<float>(-25-cos(2.7)*200*time, 40+sin(2.7)*200*time);
    }
}

void Level2::Move_ID_6_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<6) {
        if (time>1 && time<1.8)
            time=1;
        else if (time>=1.8 && time<3)
            time-=0.8;
        else if (time>=3 && time<3.8)
            time=2.2;
        else if (time>=3.8)
            time-=1.6;
        enemy->Position=sf::Vector2<float>(525+cos(2.7)*200*time, 40+sin(2.7)*200*time); //passing 2.8 to funcs as radians, directly, lightly going down
    }
}

void Level2::Move_ID_7_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<5) {
        enemy->Position.x+=120*Engine.FrameTime;
    }
}

void Level2::Move_ID_7_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<5) {
        enemy->Position.x-=120*Engine.FrameTime;
    }
}

void Level2::Move_ID_8 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=3) {
        enemy->Position.y=-60+60*time;
    }
    else if (time<=21) {
        enemy->Position.y=120;
    }
    else if (time<=34) {
        time-=21;
        enemy->Position=sf::Vector2<float>(250+cos(0.3)*100*time, 120-10*time);
    }
}

void Level2::Move_ID_9_1 (Enemy* enemy) {
    for (unsigned i=0; i<Engine.Enemies.size(); ++i)
        if (Engine.Enemies.at(i)->Move==&Level2::Move_ID_8) {
            enemy->Move=&Level2::Move_ID_9_NULL;
            return;
        }

    enemy->Move=&Level2::Move_ID_9_1_PLUS;
}

void Level2::Move_ID_9_1_PLUS (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<4) {
        enemy->Position.x+=Engine.FrameTime*324;
        enemy->Position.y+=Engine.FrameTime*25;
    }
}

void Level2::Move_ID_9_2 (Enemy* enemy) {
    for (unsigned i=0; i<Engine.Enemies.size(); ++i)
        if (Engine.Enemies.at(i)->Move==&Level2::Move_ID_8) {
            enemy->Move=&Level2::Move_ID_9_NULL;
            return;
        }

    enemy->Move=&Level2::Move_ID_9_2_PLUS;
}

void Level2::Move_ID_9_2_PLUS (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<4) {
        enemy->Position.x-=Engine.FrameTime*324;
        enemy->Position.y+=Engine.FrameTime*25;
    }
}

void Level2::Move_ID_9_NULL (Enemy* enemy) {
    //Nothing
}

void Level2::Move_ID_10_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=1) {
        enemy->Position.x=-50+300*time;
        enemy->Position.y=210-30*time;
    }
    else if (time<=20) {
        enemy->Position.x=250;
        enemy->Position.y=180;
    }
    else if (time<=25) {
        time-=20;
        enemy->Position.x=250+300*time;
        enemy->Position.y=180-30*time;
    }
}

void Level2::Move_ID_10_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=1) {
        enemy->Position.x=550-300*time;
        enemy->Position.y=210-30*time;
    }
    else if (time<=20) {
        enemy->Position.x=250;
        enemy->Position.y=180;
    }
    else if (time<=25) {
        time-=20;
        enemy->Position.x=250-300*time;
        enemy->Position.y=180-30*time;
    }
}

void Level2::Move_ID_11 (Enemy* enemy) {
    enemy->Position.y+=80*Engine.FrameTime;
}

///Boss

void Level2::BossMove_ID_1 (Boss* LevelBoss) {
    LevelBoss->Position.y+=100*Engine.FrameTime;
    if (LevelBoss->Position.y>300)
        LevelBoss->Position.y=300;
}

void Level2::BossMove_ID_2 (Boss* LevelBoss) {
    LevelBoss->Position.y-=120*Engine.FrameTime;
    if (LevelBoss->Position.y<100)
        LevelBoss->Position.y=100;
}

void Level2::BossMove_ID_3 (Boss* LevelBoss) {
    Level2::BossMove_ID_2(LevelBoss);
}

void Level2::BossMove_ID_4 (Boss* LevelBoss) {
    LevelBoss->Position.y+=80*Engine.FrameTime;
    if (LevelBoss->Position.y>180)
        LevelBoss->Position.y=180;
}

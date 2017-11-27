#include "Level3.h"

void Level3::Move_ID_1_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<10)
        enemy->Position.y=-20+110*time;
}

void Level3::Move_ID_1_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<10)
        enemy->Position.y=620-110*time;
}

void Level3::Move_ID_2_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<10)
        enemy->Position=sf::Vector2f(-20+cos(-0.14)*130*time,
                                     170-sin(-0.14)*130*time);
}

void Level3::Move_ID_2_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<10)
        enemy->Position=sf::Vector2f(520-cos(-0.14)*130*time,
                                     170-sin(-0.14)*130*time);
}

void Level3::Move_ID_3_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<10)
        enemy->Position=sf::Vector2f(enemy->Position.x, -20+80*time);
}

void Level3::Move_ID_3_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<10)
        enemy->Position.y=620-80*time;
}

void Level3::Move_ID_3_3 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<10)
        enemy->Position.x=-20+70*time;
}

void Level3::Move_ID_3_4 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<10)
        enemy->Position.x=520-70*time;
}

void Level3::Move_ID_4 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=1)
        enemy->Position=sf::Vector2f(-20+275*time, -40+240*time);
    else if (time<=13)
        enemy->Position=sf::Vector2f(250,200);
    else if (time<17) {
        enemy->Position=sf::Vector2f(250+(time-13)*275, 200-(time-13)*240);
    }
}

void Level3::Move_ID_5_START (Enemy* enemy) {
    bool has_to_run=true;
    for (unsigned i=0; i<Engine.Enemies.size(); ++i)
        if (Engine.Enemies.at(i)->Move==&Level3::Move_ID_4)
            has_to_run=false;

    if (has_to_run)
        enemy->Move=&Level3::Move_ID_5;
    else
        enemy->Move=&Level3::Move_ID_5_NULL;
}

void Level3::Move_ID_5_NULL (Enemy* enemy) {
    enemy=enemy;
}

void Level3::Move_ID_5_GO (Enemy* enemy) {
    enemy->Move=&Level3::Move_ID_5;
}

void Level3::Move_ID_5 (Enemy* enemy) {
    enemy->Position.y+=180*Engine.FrameTime;
}

void Level3::Move_ID_6_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    enemy->Position.x=-30+95*time;
    enemy->Position.y=180-sin(0.2)*time;
}

void Level3::Move_ID_6_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    enemy->Position.x=530-95*time;
    enemy->Position.y=180-sin(0.2)*time;
}

void Level3::Move_ID_7 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<2) {
        enemy->Position.x=70+90*time;
        enemy->Position.y=-40+120*time;
    }
    else if (time<26) {
        enemy->Position.x=250;
        enemy->Position.y=200;
    }
    else if (time<33) {
        time-=26;
        enemy->Position.x=250+60*time;
    }
}

void Level3::Move_ID_8_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    enemy->Position.x=-30+170*time;
    enemy->Position.y=25+15*time;
}

void Level3::Move_ID_8_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    enemy->Position.x=530-170*time;
    enemy->Position.y=25+15*time;
}

void Level3::Move_ID_9_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    enemy->Position.x=20+cos(PI+time*2)*140+time*100;
    enemy->Position.y=+60*time;
}

void Level3::Move_ID_9_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    enemy->Position.x=480+cos(time*2)*140-time*100;
    enemy->Position.y=+60*time;
}

void Level3::Move_ID_10_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    float angle=PI+PI/2*time;
    if (time<4) {
        enemy->Position.x=25+cos(angle)*130;
        enemy->Position.y=300-sin(angle)*170;
    }
}

void Level3::Move_ID_10_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    float angle=-PI/2*time;
    if (time<4) {
        enemy->Position.x=475+cos(angle)*170;
        enemy->Position.y=300-sin(angle)*170;
    }
}

void Level3::Move_ID_11_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<2) {
        enemy->Position.x=-30+140*time;
        enemy->Position.y=140+20*time;
    }
    else if (time<7) {
        enemy->Position.x=250;
        enemy->Position.y=180;
    }
    else {
        time-=7;
        enemy->Position.x=250+140*time;
        enemy->Position.y=160-60*time*time;
    }
}

void Level3::Move_ID_11_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<2) {
        enemy->Position.x=530-140*time;
        enemy->Position.y=140+20*time;
    }
    else if (time<7) {
        enemy->Position.x=250;
        enemy->Position.y=180;
    }
    else {
        time-=7;
        enemy->Position.x=250-140*time;
        enemy->Position.y=160-60*time*time;
    }
}

///Boss

/* Triangle movement:
 * 0<=time<=3: <250,150>
 * 3<time<=4: move from <250,150> to <100,190>
 * 4<time<=7: <100,190>
 * 7<time<=9: move from<100,190> to <400,190> //nearly unnoticeable speed change
 * 9<time<=12: <400,190>
 * 12<time: move from <400,190> to <250,150>
 */
void Level3::BossMove_ID_1 (Boss* LevelBoss) {
    LevelBoss->Data[0]+=Engine.FrameTime;
    float time=LevelBoss->Data[0];
    while (time>13)
        time-=13;
    if (time<=3) {
        LevelBoss->Position.x=250;
        LevelBoss->Position.y=150;
    }
    else if (time<=4) {
        time-=3;
        LevelBoss->Position.x=250-150*time;
        LevelBoss->Position.y=150+40*time;
    }
    else if (time<=7) {
        LevelBoss->Position.x=100;
        LevelBoss->Position.y=190;
    }
    else if (time<=9) {
        time-=7;
        LevelBoss->Position.x=100+150*time;
        LevelBoss->Position.y=190;
    }
    else if (time<=12) {
        LevelBoss->Position.x=400;
        LevelBoss->Position.y=190;
    }
    else {
        time-=12;
        LevelBoss->Position.x=400-150*time;
        LevelBoss->Position.y=190-40*time;
    }
}

void Level3::BossMove_ID_2 (Boss* LevelBoss) {
    float Angle=-atan2f(300-LevelBoss->Position.y, 250-LevelBoss->Position.x);
    //x
    if (LevelBoss->Position.x<250) {
        LevelBoss->Position.x+=cos(Angle)*100*Engine.FrameTime;
        if (LevelBoss->Position.x>250)
            LevelBoss->Position.x=250;
    }
    else if (LevelBoss->Position.x>250) {
        LevelBoss->Position.x+=cos(Angle)*100*Engine.FrameTime;
        if (LevelBoss->Position.x<250)
            LevelBoss->Position.x=250;
    }
    //y
    if (LevelBoss->Position.y<300) {
        LevelBoss->Position.y-=sin(Angle)*100*Engine.FrameTime;
        if (LevelBoss->Position.y>300)
            LevelBoss->Position.y=300;
    }
    //No need to handle y>300, it will never happen.
}

void Level3::BossMove_ID_3 (Boss* LevelBoss) {
    //Don't move (250,300)
}

void Level3::BossMove_ID_4 (Boss* LevelBoss) {
    LevelBoss->Position.y-=80*Engine.FrameTime;
    if (LevelBoss->Position.y<110)
        LevelBoss->Position.y=110;
}

void Level3::BossMove_ID_5 (Boss* LevelBoss) {
    //Don't move (250, 110)
    if (LevelBoss->LifeBars.back()->Health<=400 && LevelBoss->LifeBars.back()->ShootTable.at(5)->first.first>90000)
        LevelBoss->LifeBars.back()->ShootTable.at(5)->first.first=0;
    else if (LevelBoss->LifeBars.back()->Health<=800 && LevelBoss->LifeBars.back()->ShootTable.at(4)->first.first>90000)
        LevelBoss->LifeBars.back()->ShootTable.at(4)->first.first=0;
    else if (LevelBoss->LifeBars.back()->Health<=1200 && LevelBoss->LifeBars.back()->ShootTable.at(3)->first.first>90000)
        LevelBoss->LifeBars.back()->ShootTable.at(3)->first.first=0;
}

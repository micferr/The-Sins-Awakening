#include "Level1.h"

void Level1::Move_ID_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime; //Simpler
    //Start moving
    if (time>0) {
        enemy->Position.y=200+sin(30)*time*15;
        enemy->Position.x=time*150;
    }
    else
        enemy->Position=sf::Vector2<float>(0,0);
}

void Level1::Move_ID_2(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time>0) {
        enemy->Position.y=200+sin(30)*time*15;
        enemy->Position.x=500-time*150;
    }
    else
        enemy->Position=sf::Vector2<float>(500,200);
}

void Level1::Move_ID_3(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    enemy->Position.x=25;
    if (time>0) {
        if (enemy->Position.y >= 650)
            enemy->Position.y = 650;
        else
            enemy->Position.y=time*50;
    }
    else
        enemy->Position.y=0;
}

void Level1::Move_ID_4(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    enemy->Position.x=475;
    if (time>0) {
        if (enemy->Position.y >= 650)
            enemy->Position.y = 650;
        else
            enemy->Position.y=time*50+25;
    }
    else
        enemy->Position.y=0;
}

void Level1::Move_ID_5(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time>=0 && time<2) enemy->Position.y=-50+100*time;
    else if (time>=2 && time<7.5) enemy->Position.y=150;
    else if (time>=7.5 && time<12) enemy->Position.y=150-((time-7.5)*100);
    else enemy->Position.y=-100;
}

void Level1::Move_ID_6(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time>=0 && time<5)
        enemy->Position.y+=Engine.FrameTime*66;
    else if (time>20 && time<24) {
        enemy->Position.x=250+cos((180-100*(time-20))*PI/180)*30*pow((time-20),2);
        enemy->Position.y=300+sin((180-100*(time-20))*PI/180)*40*(time-20);
    }
}

void Level1::Move_ID_7_1(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time >= 0 && time <= 5) {
        float angle=0;
        if (time>1)
            angle+=pow(time,2)*10;
        enemy->Position.x+=cos(angle*PI/180)*240*Engine.FrameTime;
        enemy->Position.y-=sin(angle*PI/180)*240*Engine.FrameTime;
    }
}

void Level1::Move_ID_7_2(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time >= 0 && time <= 5) {
        float angle=0;
        if (time>1)
            angle+=pow(time,2)*10;
        enemy->Position.x-=cos(angle*PI/180)*240*Engine.FrameTime;
        enemy->Position.y-=sin(angle*PI/180)*240*Engine.FrameTime;
    }
}

void Level1::Move_ID_8(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time>=0 && time<=30) {
        enemy->Position.x+=cos(time*PI)*120*Engine.FrameTime;
        enemy->Position.y=time*50;
    }
}

void Level1::Move_ID_9_1 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time >= 0 && time <= 4) {
        enemy->Position.x=cos((-135+time*25)*PI/180)*380+250;
        enemy->Position.y=-sin((-135+time*25)*PI/180)*380-240;
    }
}

void Level1::Move_ID_9_2 (Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time >= 0 && time <= 4) {
        enemy->Position.x=cos((-45-time*25)*PI/180)*380+250;
        enemy->Position.y=-sin((-45-time*25)*PI/180)*380-240;
    }
}

void Level1::BossMove_ID_1 (Boss* boss) {}

void Level1::BossMove_ID_2 (Boss* boss) {
    if (boss->Position.y!=70) {
        float newY=boss->Position.y-100*Engine.FrameTime;
        if (newY<70) newY=70;
        boss->Position.y=newY;
    }
    else if (boss->LifeBars.back()->ShootTable.back()->first.first>9000) { //Good to all the three shoots
        for (short i=0; i<3; ++i)
            boss->LifeBars.back()->ShootTable.at(i)->first.first=1;
    }
}

void Level1::BossMove_ID_3 (Boss* boss) {
    if (boss->Position.y!=300.f) {
        float newY=boss->Position.y+120*Engine.FrameTime;
        if (newY>300.00f)
            newY=300.00f;
        boss->Position.y=newY;
    }
    else {
        if (boss->LifeBars.back()->ShootTable.back()->first.first>9000)
            boss->LifeBars.back()->ShootTable.back()->first.first=1;
        if (boss->Bullets.size()>0)
            boss->LifeBars.back()->ShootTable.back()->first.first=99999;
    }
}

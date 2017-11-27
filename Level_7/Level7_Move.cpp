#include "Level7.h"

///ENEMIES

void Level7::Move_ID_1_1(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<1.5) {
        enemy->Position.x=-50+450*time;
        enemy->Position.y=150-60*time;
    }
}

void Level7::Move_ID_1_2(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<1.5) {
        enemy->Position.x=550-450*time;
        enemy->Position.y=150-60*time;
    }
}

void Level7::Move_ID_3(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<=1.0f) {
        enemy->Position.x=210+time*40;
        enemy->Position.y=-30+110*time;
    }
    else if (time<=6.5) {
        enemy->Position={250,80};
    }
    else if (time<=12) {
        time-=6.5;
        enemy->Position.x=250+15*time*time;
        enemy->Position.y=80-20*time*time;
    }
}

void Level7::Move_ID_5(Enemy* enemy) {
    float time=Engine.PastTime-enemy->BaseTime;
    if (time<1.5f) {
        enemy->Position.x=325-50*time;
        enemy->Position.y=-60+160*time;
    }
    else if (time<36) {
        enemy->Position={250,180};
    }
    else if (time<42) {
        time-=36;
        enemy->Position.x=250-20*time*time;
        enemy->Position.y=180-25*time*time;
    }
}

///BOSS

void Level7::BossMove_ID_1(Boss* boss) {}

void Level7::BossMove_ID_2(Boss* boss) {
    float time=boss->Data.size()==4 ? Engine.PastTime-boss->Data[0] : 0;
    if (time<=0.8)
        boss->Position.y=150+250*time-78.125*time*time;
    else
        boss->Position.y=300;
}

void Level7::BossMove_ID_3(Boss* boss) {}

void Level7::BossMove_ID_4(Boss* boss) {
    float time=boss->Data.size()==1?Engine.PastTime-boss->Data[0]:0;
    if (time<1.2) return;

    float Angle=-atan2f(120-boss->Position.y, 250-boss->Position.x);
    float Movement=120*Engine.FrameTime;
    boss->Position.x+=Movement*cos(Angle);
    boss->Position.y-=Movement*sin(Angle);
}

void Level7::BossMove_ID_5(Boss* boss) {
    if (boss->Data.size()==1)
        return;

    if (boss->Position.x<250) {
        boss->Position.x+=160*cos(boss->Data[0])*Engine.FrameTime;
        boss->Position.y-=160*sin(boss->Data[0])*Engine.FrameTime;
        if (boss->Position.x>250)
            boss->Position={250,120};
    }
    if (boss->Position.x>250) {
        boss->Position.x+=160*cos(boss->Data[0])*Engine.FrameTime;
        boss->Position.y-=160*sin(boss->Data[0])*Engine.FrameTime;
        if (boss->Position.x<250)
            boss->Position={250,120};
    }
}

void Level7::BossMove_ID_6(Boss* boss) {
    if (boss->Position.y>120) {
        boss->Position.y-=160*Engine.FrameTime;
        if (boss->Position.y<120)
            boss->Position.y=120;
    }
}

/*void Level7::BossMove_ID_7(Boss* boss) {
    boss->Position.y=min(boss->Position.y+50*Engine.FrameTime, 200.0);

    LifeBar* bar=boss->LifeBars.back();
    float DamagePercentage=(bar->MaxHealth-bar->Health)/bar->MaxHealth;
    float& f=bar->ShootTable[2]->first.second;
    if (DamagePercentage<0.2f) f=1.5f;
    else if (DamagePercentage<0.4f) f=1.2f;
    else if (DamagePercentage<0.6f) f=0.7f;
    else if (DamagePercentage<0.8f) f=0.4f;
    else f=0.2f;
}*/

void Level7::BossMove_ID_7(Boss* boss) {
    if (boss->Data.size()!=7)
        return;

    boss->Position.y=min<float>(boss->Position.y+40*Engine.FrameTime, 150.f);

    LifeBar* bar=boss->LifeBars.back();
    float HealthPercentage=bar->Health/bar->MaxHealth;
    for (unsigned i=0; i<4; ++i) {
        if (HealthPercentage<=0.8f-0.2*i && static_cast<bool>(boss->Data[3+i])==false) {
            ++boss->Data[3+i];
            boss->LifeBars.back()->ShootTable[4+i]->first.first=2.f;
        }
    }
}

void Level7::BossMove_ID_8(Boss* boss) {
    boss->Position.y=max<double>(boss->Position.y-180*Engine.FrameTime, -150);

    if (boss->Data.size()!=12)
        return;
    boss->LifeBars.back()->Health=1800-10*(Engine.PastTime-boss->Data[0]);
    float HealthPercentage=(boss->LifeBars.back()->Health/boss->LifeBars.back()->MaxHealth)*100;
    for (unsigned i=0; i<5; ++i) {
        if (HealthPercentage<100*(6.9-float(i*1.4))/7.f && boss->Data[1+i]<0) {
            boss->Data[1+i]=1;
            boss->LifeBars.back()->ShootTable[3+i*2]->first.first=6.f;
            for (unsigned j=4; j<=14-2*(5-i); j+=2)
                boss->LifeBars.back()->ShootTable[j]->first.first=9.f;
        }
    }
}

void Level7::BossMove_ID_9(Boss* boss) {
    boss->Position.x=250;
    boss->Position.y=min<float>(120.f, boss->Position.y+120.f*Engine.FrameTime);

    if (boss->Data.size()!=4)
        return;

    boss->Data[0]=boss->LifeBars.back()->Health/boss->LifeBars.back()->MaxHealth*100;
}

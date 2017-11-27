#include "Level4.h"

void Level4::CreateBarOne(void) {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=750;
    for (unsigned short i=0; i<30; ++i)
        bar->Loot.push_back(POWER_ITEM);
    bar->Name="13 - Dangerous Dance";
    bar->BonusScore=400000;
    bar->Move=&Level4::BossMove_ID_1;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=0;
    bar->ShootTable.back()->first.second=99999;
    bar->ShootTable.back()->second=&Level4::BossShoot_ID_1_SETDATA;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=1.5;
    bar->ShootTable.back()->first.second=1.2;
    bar->ShootTable.back()->second=&Level4::BossShoot_ID_1_1;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=0;
    bar->ShootTable.back()->first.second=0.07;
    bar->ShootTable.back()->second=&Level4::BossShoot_ID_1_2;
}

void Level4::CreateBarTwo(void) {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=1150; //1150
    for (unsigned short i=0; i<15; ++i)
        bar->Loot.push_back(SCORE_ITEM);
    for (unsigned short i=0; i<10; ++i)
        bar->Loot.push_back(POWER_ITEM);
    for (unsigned short i=0; i<15; ++i)
        bar->Loot.push_back(SCORE_ITEM);
    bar->Name="14 - Hottest Meteor Shower";
    bar->BonusScore=400000;
    bar->Move=&Level4::BossMove_ID_2;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=0;
    bar->ShootTable.back()->first.second=99999;
    bar->ShootTable.back()->second=&Level4::BossShoot_ID_2_SETDATA;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=1.5;
    bar->ShootTable.back()->first.second=0.14;
    bar->ShootTable.back()->second=&Level4::BossShoot_ID_2_1;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=2;
    bar->ShootTable.back()->first.second=0.05;
    bar->ShootTable.back()->second=&Level4::BossShoot_ID_2_2;
}

void Level4::CreateBarThree (void) {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=1000;
    for (unsigned short i=0; i<30; ++i)
        bar->Loot.push_back(POWER_ITEM);
    bar->Name="Attack Pattern n° 15";
    bar->BonusScore=400000;
    bar->Move=&Level4::BossMove_ID_3;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=0;
    bar->ShootTable.back()->first.second=90000;
    bar->ShootTable.back()->second=&Level4::BossShoot_ID_3_SETDATA;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=1.5;
    bar->ShootTable.back()->first.second=0.04;
    bar->ShootTable.back()->second=&Level4::BossShoot_ID_3_1;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=3;
    bar->ShootTable.back()->first.second=0.7;
    bar->ShootTable.back()->second=&Level4::BossShoot_ID_3_2;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=0;
    bar->ShootTable.back()->first.second=0.05;
    bar->ShootTable.back()->second=&Level4::BossShoot_ID_3_3;
}

void Level4::CreateBarFour (void) {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=1500; //1500
    for (unsigned short i=0; i<10; ++i)
        bar->Loot.push_back(POWER_ITEM);
    for (unsigned short i=0; i<30; ++i)
        bar->Loot.push_back(SCORE_ITEM);
    for (unsigned short i=0; i<10; ++i)
        bar->Loot.push_back(POWER_ITEM);
    bar->Name="Attack Pattern n° 16";
    bar->BonusScore=400000;
    bar->Move=&Level4::BossMove_ID_4;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=0;
    bar->ShootTable.back()->first.second=99000;
    bar->ShootTable.back()->second=Level4::BossShoot_ID_4_SETDATA;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=3;
    bar->ShootTable.back()->first.second=4;
    bar->ShootTable.back()->second=&Level4::BossShoot_ID_4_1;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=0;
    bar->ShootTable.back()->first.second=0.05;
    bar->ShootTable.back()->second=&Level4::BossShoot_ID_4_2;
}

void Level4::CreateBarFive () {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=1250;
    for (unsigned short i=0; i<30; ++i)
        bar->Loot.push_back(POWER_ITEM);
    bar->Name="Attack Pattern n° 17";
    bar->BonusScore=400000;
    bar->Move=&Level4::BossMove_ID_5;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=2.5;
    bar->ShootTable.back()->first.second=90000;
    bar->ShootTable.back()->second=&Level4::BossShoot_ID_5_1;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=4.5;
    bar->ShootTable.back()->first.second=0.5;
    bar->ShootTable.back()->second=&Level4::BossShoot_ID_5_2;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=5;
    bar->ShootTable.back()->first.second=1.2;
    bar->ShootTable.back()->second=&Level4::BossShoot_ID_5_3;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=0;
    bar->ShootTable.back()->first.second=0.05;
    bar->ShootTable.back()->second=&Level4::BossShoot_ID_5_4;
}

void Level4::CreateBarSix() {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=590; //590
    for (unsigned short i=0; i<40; ++i)
        bar->Loot.push_back(SCORE_ITEM);
    bar->Name="18 - Burning Passion";
    bar->BonusScore=400000;
    bar->Move=&Level4::BossMove_ID_6_PREPARE;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=3;
    bar->ShootTable.back()->first.second=0.3;
    bar->ShootTable.back()->second=&Level4::BossShoot_ID_6_2;
}

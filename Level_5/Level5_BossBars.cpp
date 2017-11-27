#include "Level5.h"

void Level5::CreateBarOne(void) {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=600; //600
    for (unsigned short i=0; i<10; ++i) bar->Loot.push_back(POWER_ITEM);
    for (unsigned short i=0; i<10; ++i) bar->Loot.push_back(SCORE_ITEM);
    for (unsigned short i=0; i<10; ++i) bar->Loot.push_back(POWER_ITEM);
    bar->Name="Attack Pattern n° 19";
    bar->BonusScore=500000;
    bar->Move=&Level5::BossMove_ID_1;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=0;
    bar->ShootTable.back()->first.second=99999;
    bar->ShootTable.back()->second=&Level5::BossShoot_ID_1_SETDATA;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=0.75;
    bar->ShootTable.back()->first.second=2;
    bar->ShootTable.back()->second=&Level5::BossShoot_ID_1_1;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=0.5;
    bar->ShootTable.back()->first.second=1;
    bar->ShootTable.back()->second=&Level5::BossShoot_ID_1_2;
}

void Level5::CreateBarTwo(void) {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=900; //900
    for (unsigned int i=0; i<5; ++i) bar->Loot.push_back(POWER_ITEM);
    for (unsigned int i=0; i<20; ++i) bar->Loot.push_back(SCORE_ITEM);
    for (unsigned int i=0; i<5; ++i) bar->Loot.push_back(POWER_ITEM);
    bar->Name="Attack Pattern n° 20";
    bar->BonusScore=500000;
    bar->Move=&Level5::BossMove_ID_2;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=0;
    bar->ShootTable.back()->first.second=99999;
    bar->ShootTable.back()->second=&Level5::BossShoot_ID_2_SETDATA;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=2.4;
    bar->ShootTable.back()->first.second=3.9;
    bar->ShootTable.back()->second=&Level5::BossShoot_ID_2_1;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=3.6;
    bar->ShootTable.back()->first.second=1.3;
    bar->ShootTable.back()->second=&Level5::BossShoot_ID_2_2;
}

void Level5::CreateBarThree(void) {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=800; //800
    for (unsigned i=0; i<2; ++i) {
        for (unsigned j=0; j<5; ++j) bar->Loot.push_back(POWER_ITEM);
        for (unsigned j=0; j<5; ++j) bar->Loot.push_back(SCORE_ITEM);
    }
    bar->Name="Attack Pattern n° 21";
    bar->BonusScore=500000;
    bar->Move=&Level5::BossMove_ID_3;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=0;
    bar->ShootTable.back()->first.second=99999;
    bar->ShootTable.back()->second=&Level5::BossShoot_ID_3_SETDATA;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=1.8;
    bar->ShootTable.back()->first.second=5;
    bar->ShootTable.back()->second=&Level5::BossShoot_ID_3_1;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=2.8;
    bar->ShootTable.back()->first.second=0.08;
    bar->ShootTable.back()->second=&Level5::BossShoot_ID_3_2;
}

void Level5::CreateBarFour(void) {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=850;
    for (unsigned i=0; i<10; ++i) {
        bar->Loot.push_back(POWER_ITEM);
        bar->Loot.push_back(SCORE_ITEM);
    }
    bar->Name="Attack Pattern n° 22";
    bar->BonusScore=500000;
    bar->Move=&Level5::BossMove_ID_4;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=0;
    bar->ShootTable.back()->first.second=99999;
    bar->ShootTable.back()->second=&Level5::BossShoot_ID_4_SETDATA;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=3;
    bar->ShootTable.back()->first.second=0.121;
    bar->ShootTable.back()->second=&Level5::BossShoot_ID_4_1;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=5;
    bar->ShootTable.back()->first.second=0.4;
    bar->ShootTable.back()->second=&Level5::BossShoot_ID_4_2;
}

void Level5::CreateBarFive() {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=1250;
    for (unsigned i=0; i<20; ++i) bar->Loot.push_back(POWER_ITEM);
    bar->Name="Attack Pattern n° 23";
    bar->BonusScore=500000;
    bar->Move=&Level5::BossMove_ID_5;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=1;
    bar->ShootTable.back()->first.second=99999;
    bar->ShootTable.back()->second=&Level5::BossShoot_ID_5_1;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=1.5;
    bar->ShootTable.back()->first.second=0.04;
    bar->ShootTable.back()->second=&Level5::BossShoot_ID_5_2;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=3;
    bar->ShootTable.back()->first.second=0.5;
    bar->ShootTable.back()->second=&Level5::BossShoot_ID_5_3;
}

void Level5::CreateBarSix() {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=850;
    for (unsigned i=0; i<20; ++i) bar->Loot.push_back(SCORE_ITEM);
    bar->Name="Attack Pattern n° 24";
    bar->BonusScore=500000;
    bar->Move=&Level5::BossMove_ID_6;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=0;
    bar->ShootTable.back()->first.second=99999;
    bar->ShootTable.back()->second=&Level5::BossShoot_ID_6_SETDATA;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=1;
    bar->ShootTable.back()->first.second=0.2;
    bar->ShootTable.back()->second=&Level5::BossShoot_ID_6_1;
}

void Level5::CreateBarSeven() {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=1400;
    for (unsigned i=0; i<5; ++i) bar->Loot.push_back(POWER_ITEM);
    for (unsigned i=0; i<12; ++i) bar->Loot.push_back(SCORE_ITEM);
    for (unsigned i=0; i<5; ++i) bar->Loot.push_back(POWER_ITEM);
    bar->Name="Attack Pattern n° 25";
    bar->BonusScore=500000;
    bar->Move=&Level5::BossMove_ID_7;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=0;
    bar->ShootTable.back()->first.second=99999;
    bar->ShootTable.back()->second=&Level5::BossShoot_ID_7_SETDATA;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=1.4;
    bar->ShootTable.back()->first.second=1.4;
    bar->ShootTable.back()->second=&Level5::BossShoot_ID_7_1_MAIN;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=2.8;
    bar->ShootTable.back()->first.second=1.4;
    bar->ShootTable.back()->second=&Level5::BossShoot_ID_7_2;
}

#include "Level6.h"

void Level6::CreateBarOne(void) {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Name="Attack Pattern n° 26";
    bar->BonusScore=600000;
    bar->Health=bar->MaxHealth=900;
    bar->Move=&Level6::BossMove_ID_1;
    for (unsigned i=0; i<10; ++i) {
        bar->Loot.push_back(POWER_ITEM);
        bar->Loot.push_back(SCORE_ITEM);
    }
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=0;
    bar->ShootTable.back()->first.second=99999;
    bar->ShootTable.back()->second=&Level6::BossShoot_ID_1_SETDATA;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=1.3;
    bar->ShootTable.back()->first.second=0.04;
    bar->ShootTable.back()->second=&Level6::BossShoot_ID_1;
}

void Level6::CreateBarTwo(void) {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Name="Attack Pattern n° 27";
    bar->BonusScore=600000;
    bar->Health=bar->MaxHealth=1000;
    bar->Move=&Level6::BossMove_ID_3;
    for (unsigned i=0; i<3; ++i) bar->Loot.push_back(POWER_ITEM);
    for (unsigned i=0; i<15; ++i) bar->Loot.push_back(SCORE_ITEM);
    for (unsigned i=0; i<3; ++i) bar->Loot.push_back(POWER_ITEM);
    bar->ShootTable.push_back(new TableElement({1,0.2}, &Level6::BossShoot_ID_2_1));
    bar->ShootTable.push_back(new TableElement({1.8,5}, &Level6::BossShoot_ID_2_2));
}

void Level6::CreateBarThree(void) {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Name="Attack Pattern n° 28";
    bar->BonusScore=600000;
    bar->Health=bar->MaxHealth=800;
    bar->Move=&Level6::BossMove_ID_3;
    for (unsigned i=0; i<22; ++i) bar->Loot.push_back(SCORE_ITEM);
    bar->ShootTable.push_back(new TableElement({0,99999}, &Level6::BossShoot_ID_3_SETDATA));
    bar->ShootTable.push_back(new TableElement({1.5,0.4}, &Level6::BossShoot_ID_3));
}

void Level6::CreateBarFour(void) {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Name="Attack Pattern n° 29";
    bar->BonusScore=600000;
    bar->Health=bar->MaxHealth=1200;
    bar->Move=&Level6::BossMove_ID_4;
    for (unsigned i=0; i<5; ++i) bar->Loot.push_back(POWER_ITEM);
    for (unsigned i=0; i<12; ++i) bar->Loot.push_back(SCORE_ITEM);
    for (unsigned i=0; i<5; ++i) bar->Loot.push_back(POWER_ITEM);
    bar->ShootTable.push_back(new TableElement({0,99999}, &Level6::BossShoot_ID_4_SETDATA));
    bar->ShootTable.push_back(new TableElement({1.2, 0.9}, &Level6::BossShoot_ID_4_1));
    bar->ShootTable.push_back(new TableElement({1.3, 1.3}, &Level6::BossShoot_ID_4_2));
    bar->ShootTable.push_back(new TableElement({3.0, 0.6}, &Level6::BossShoot_ID_4_3));
}

void Level6::CreateBarFive(void) {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Name="Attack Pattern n° 30";
    bar->BonusScore=600000;
    bar->Health=bar->MaxHealth=850;
    bar->Move=&Level6::BossMove_ID_5;
    for (unsigned i=0; i<25; ++i) bar->Loot.push_back(POWER_ITEM);
    bar->ShootTable.push_back(new TableElement({0,99999}, &Level6::BossShoot_ID_5_SETDATA));
    bar->ShootTable.push_back(new TableElement({0.6, 0.03}, &Level6::BossShoot_ID_5));
}

void Level6::CreateBarSix(void) {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Name="Attack Pattern n° 31";
    bar->BonusScore=600000;
    bar->Health=bar->MaxHealth=1300;
    bar->Move=&Level6::BossMove_ID_6;
    for (unsigned i=0; i<5; ++i) bar->Loot.push_back(POWER_ITEM);
    for (unsigned i=0; i<15; ++i) bar->Loot.push_back(SCORE_ITEM);
    for (unsigned i=0; i<5; ++i) bar->Loot.push_back(POWER_ITEM);
    bar->ShootTable.push_back(new TableElement({0,99999}, &Level6::BossShoot_ID_6_SETDATA));
    bar->ShootTable.push_back(new TableElement({1,1.2}, &Level6::BossShoot_ID_6_1));
}

void Level6::CreateBarSeven(void) {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Name="Attack Pattern n° 32";
    bar->BonusScore=600000;
    bar->Health=bar->MaxHealth=1200;
    bar->Move=&Level6::BossMove_ID_7;
    for (unsigned i=0; i<30; ++i) bar->Loot.push_back(POWER_ITEM);
    bar->ShootTable.push_back(new TableElement({0,99999}, &Level6::BossShoot_ID_7_SETDATA));
    bar->ShootTable.push_back(new TableElement({1.2,0.07}, &Level6::BossShoot_ID_7_1));
}

void Level6::CreateBarEight(void) {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Name="Attack Pattern n° 33";
    bar->BonusScore=600000;
    bar->Health=bar->MaxHealth=1800;
    bar->Move=&Level6::BossMove_ID_8;
    for (unsigned i=0; i<40; ++i) bar->Loot.push_back(SCORE_ITEM);
    bar->ShootTable.push_back(new TableElement({0,99999}, &Level6::BossShoot_ID_8_SETDATA));
    bar->ShootTable.push_back(new TableElement({1.2,2.4}, &Level6::BossShoot_ID_8_1));
    bar->ShootTable.push_back(new TableElement({4.0,4.2}, &Level6::BossShoot_ID_8_2));
}

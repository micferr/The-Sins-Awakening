#include "Level2.h"

void Level2::CreateBarOne() {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=600;
    for (short i=0; i<5; ++i)
        bar->Loot.push_back(POWER_ITEM);
    for (short i=0; i<5; ++i) {
        bar->Loot.push_back(SCORE_ITEM);
        bar->Loot.push_back(POWER_ITEM);
        bar->Loot.push_back(SCORE_ITEM);
    }
    for (short i=0; i<5; ++i)
        bar->Loot.push_back(POWER_ITEM);
    bar->Name="4 - Promising Starter";
    bar->BonusScore=200000;
    bar->Move=&Level2::BossMove_ID_1;
    bar->ShootTable.push_back(new std::pair<std::pair<float, float>, void(*)(Boss*, float)>);
    bar->ShootTable.back()->first.first=3;
    bar->ShootTable.back()->first.second=0.75;
    bar->ShootTable.back()->second=&Level2::BossShoot_ID_1;
}

void Level2::CreateBarTwo() {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=800;
    for (short i=0; i<5; i++)
        bar->Loot.push_back(POWER_ITEM);
    for (short i=0; i<10; i++)
        bar->Loot.push_back(SCORE_ITEM);
    for (short i=0; i<5; i++)
        bar->Loot.push_back(POWER_ITEM);
    bar->Name="5 - Great Banquet";
    bar->BonusScore=200000;
    bar->Move=&Level2::BossMove_ID_2;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=2;
    bar->ShootTable.back()->first.second=0.1;
    bar->ShootTable.back()->second=&Level2::BossShoot_ID_2_1;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=4;
    bar->ShootTable.back()->first.second=2.5;
    bar->ShootTable.back()->second=&Level2::BossShoot_ID_2_2;
    //
    Engine.LevelBoss->Data.clear();
    Engine.LevelBoss->Data.push_back(0.f); //Angle - increments by 0.08 each shot
}

void Level2::CreateBarThree() {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=600;
    for (short i=0; i<5; ++i)
        bar->Loot.push_back(SCORE_ITEM);
    for (short i=0; i<15; ++i)
        bar->Loot.push_back(POWER_ITEM);
    for (short i=0; i<5; ++i)
        bar->Loot.push_back(SCORE_ITEM);
    bar->Name="6 - Unsatiable Appetite";
    bar->BonusScore=200000;
    bar->Move=&Level2::BossMove_ID_3;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=1.5;
    bar->ShootTable.back()->first.second=1;
    bar->ShootTable.back()->second=&Level2::BossShoot_ID_3;
}

void Level2::CreateBarFour() {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=1400;
    for (short i=0; i<5; ++i)
        bar->Loot.push_back(POWER_ITEM);
    for (short i=0; i<15; ++i)
        bar->Loot.push_back(SCORE_ITEM);
    for (short i=0; i<5; ++i)
        bar->Loot.push_back(POWER_ITEM);
    bar->Name="7 - Hungry Cannibal"; //Man-eater
    bar->BonusScore=200000;
    bar->Move=&Level2::BossMove_ID_4;
    bar->ShootTable.push_back(new TableElement); //Shooter balls
    bar->ShootTable.back()->first.first=2;
    bar->ShootTable.back()->first.second=0.4;
    bar->ShootTable.back()->second=&Level2::BossShoot_ID_4;
    //
    Engine.LevelBoss->Data.clear();
    Engine.LevelBoss->Data.push_back(0.f);
}

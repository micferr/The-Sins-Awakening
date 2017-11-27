#include "Level1.h"

void Level1::CreateBarOne() {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=300;
    for (short i=0; i<4; i++) {
        bar->Loot.push_back(SCORE_ITEM);
        bar->Loot.push_back(POWER_ITEM);
    }
    bar->Loot.push_back(SCORE_ITEM);
    bar->Name="1 - Lazy Shooting";
    bar->BonusScore=100000;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.at(0)->first.first=2.6;
    bar->ShootTable.at(0)->first.second=2.6;
    bar->ShootTable.at(0)->second=&Level1::BossShoot_ID_1_1;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.at(1)->first.first=3.9;
    bar->ShootTable.at(1)->first.second=2.6;
    bar->ShootTable.at(1)->second=&Level1::BossShoot_ID_1_2;
    bar->Move=&Level1::BossMove_ID_1;
}

void Level1::CreateBarTwo() {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=800;
    for (int i=0; i<8; i++) {
        bar->Loot.push_back(SCORE_ITEM);
        bar->Loot.push_back(POWER_ITEM);
    }
    bar->Name="2 - Flood of Worries";
    bar->BonusScore=100000;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.at(0)->first.first=3;
    bar->ShootTable.at(0)->first.second=0.05;
    bar->ShootTable.at(0)->second=&Level1::BossShoot_ID_2_1; //Side-columns bullets
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.at(1)->first.first=3;
    bar->ShootTable.at(1)->first.second=1.0;
    bar->ShootTable.at(1)->second=&Level1::BossShoot_ID_2_2;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.at(2)->first.first=3.5;
    bar->ShootTable.at(2)->first.second=1.0;
    bar->ShootTable.at(2)->second=&Level1::BossShoot_ID_2_3;
    bar->Move=&Level1::BossMove_ID_2;
}

void Level1::CreateBarThree() {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=1100;
    for (int i=0; i<10; i++) {
        bar->Loot.push_back(SCORE_ITEM);
        bar->Loot.push_back(POWER_ITEM);
        bar->Loot.push_back(SCORE_ITEM);
    }
    bar->Name="3 - Slow Vortex";
    bar->BonusScore=100000;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=99999;
    bar->ShootTable.back()->first.second=99999;
    bar->ShootTable.back()->second=&Level1::BossShoot_ID_3;
    bar->Move=&Level1::BossMove_ID_3;
}

#include "Level3.h"

void Level3::CreateBarOne(void) {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=650;
    for (short i=0; i<10; ++i)
        bar->Loot.push_back(POWER_ITEM);
    for (short i=0; i<5; ++i)
        bar->Loot.push_back(SCORE_ITEM);
    for (short i=0; i<10; ++i)
        bar->Loot.push_back(POWER_ITEM);
    bar->Name="8 - Economic Gravitation Center";
    bar->BonusScore=300000;
    bar->Move=&Level3::BossMove_ID_1;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=2;
    bar->ShootTable.back()->first.second=0.5;
    bar->ShootTable.back()->second=&Level3::BossShoot_ID_1;
    Engine.LevelBoss->Data.clear();
    Engine.LevelBoss->Data.push_back(0.f); //time, updated with Move_1
}

void Level3::CreateBarTwo(void) {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=700;
    for (short i=0; i<5; ++i)
        bar->Loot.push_back(POWER_ITEM);
    for (short i=0; i<10; ++i)
        bar->Loot.push_back(SCORE_ITEM);
    for (short i=0; i<5; ++i)
        bar->Loot.push_back(POWER_ITEM);
    bar->Name="9 - Capitalistic Spiral";
    bar->BonusScore=300000;
    bar->Move=&Level3::BossMove_ID_2;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=2;
    bar->ShootTable.back()->first.second=0.12;
    bar->ShootTable.back()->second=&Level3::BossShoot_ID_2_1;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=2;
    bar->ShootTable.back()->first.second=2;
    bar->ShootTable.back()->second=&Level3::BossShoot_ID_2_2;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=0;
    bar->ShootTable.back()->first.second=99999;
    bar->ShootTable.back()->second=&Level3::BossShoot_ID_2_SET;
    /* Data:
     * 0: Color for double x
     * 1: 0 or 1: Red to black or vice-versa
     * 2: Angle for double x
     * 3: Angle for coin bullets
     */
}

void Level3::CreateBarThree(void) {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=700;
    for (short i=0; i<15; ++i)
        bar->Loot.push_back(POWER_ITEM);
    bar->Name="10 - Killing Loaner";
    bar->BonusScore=300000;
    bar->Move=&Level3::BossMove_ID_3;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=2;
    bar->ShootTable.back()->first.second=2;
    bar->ShootTable.back()->second=&Level3::BossShoot_ID_3_1;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=2;
    bar->ShootTable.back()->first.second=1;
    bar->ShootTable.back()->second=&Level3::BossShoot_ID_3_2;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=0;
    bar->ShootTable.back()->first.second=99999;
    bar->ShootTable.back()->second=&Level3::BossShoot_ID_3_SET;
    /* Data:
     * 0: _1 angle
     */
}

void Level3::CreateBarFour(void) {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=1200;
    for (short i=0; i<5; ++i)
        bar->Loot.push_back(POWER_ITEM);
    for (short i=0; i<5; ++i)
        bar->Loot.push_back(SCORE_ITEM);
    for (short i=0; i<5; ++i)
        bar->Loot.push_back(POWER_ITEM);
    bar->Name="11 - Walls of El Dorado";
    bar->BonusScore=300000;
    bar->Move=&Level3::BossMove_ID_4;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=2;
    bar->ShootTable.back()->first.second=6;
    bar->ShootTable.back()->second=&Level3::BossShoot_ID_4_1;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=5;
    bar->ShootTable.back()->first.second=6;
    bar->ShootTable.back()->second=&Level3::BossShoot_ID_4_2;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=3;
    bar->ShootTable.back()->first.second=0.8;
    bar->ShootTable.back()->second=&Level3::BossShoot_ID_4_3;
}

void Level3::CreateBarFive(void) {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Health=bar->MaxHealth=1400;
    for (short i=0; i<2; ++i)
        bar->Loot.push_back(POWER_ITEM);
    for (short i=0; i<12; ++i)
        bar->Loot.push_back(SCORE_ITEM);
    for (short i=0; i<2; ++i)
        bar->Loot.push_back(POWER_ITEM);
    bar->Name="12 - Nightmare of Kinkaku-ji";
    bar->BonusScore=300000;
    bar->Move=&Level3::BossMove_ID_5;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=2;
    bar->ShootTable.back()->first.second=2;
    bar->ShootTable.back()->second=&Level3::BossShoot_ID_5_1;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=3;
    bar->ShootTable.back()->first.second=2;
    bar->ShootTable.back()->second=&Level3::BossShoot_ID_5_2;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=2.5;
    bar->ShootTable.back()->first.second=0.06666666666666666666666666666666666666;
    bar->ShootTable.back()->second=&Level3::BossShoot_ID_5_3_1;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=999999;
    bar->ShootTable.back()->first.second=0.06666666666666666666666666666666666666;
    bar->ShootTable.back()->second=&Level3::BossShoot_ID_5_3_2;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=999999;
    bar->ShootTable.back()->first.second=0.09999999999999999999999999999999999999;
    bar->ShootTable.back()->second=&Level3::BossShoot_ID_5_3_3;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=999999;
    bar->ShootTable.back()->first.second=0.099999999999999999999999999999999999999;
    bar->ShootTable.back()->second=&Level3::BossShoot_ID_5_3_4;
    bar->ShootTable.push_back(new TableElement);
    bar->ShootTable.back()->first.first=0;
    bar->ShootTable.back()->first.second=999999;
    bar->ShootTable.back()->second=&Level3::BossShoot_ID_5_SET;
    /* Data:
     * 0-3: Angles for _5_3_x
     */
}

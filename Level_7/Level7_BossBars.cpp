#include "Level7.h"

void Level7::CreateBarOne() {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Name="34 - Introduction for the Greatest Battle";
    bar->BonusScore=700000;
    bar->Health=bar->MaxHealth=1100;
    bar->Move=&Level7::BossMove_ID_1;
    for (unsigned i=0; i<40; ++i) bar->Loot.push_back(SCORE_ITEM);
    bar->ShootTable.push_back(new TableElement({0,99999}, &Level7::BossShoot_ID_1_SETDATA));
    bar->ShootTable.push_back(new TableElement({1.5,0.025}, &Level7::BossShoot_ID_1_2));
}

void Level7::CreateBarTwo() {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Name="35 - Haughty Feasting";
    bar->BonusScore=700000;
    bar->Health=bar->MaxHealth=1000;
    bar->Move=&Level7::BossMove_ID_2;
    for (unsigned i=0; i<30; ++i) bar->Loot.push_back(POWER_ITEM);
    bar->ShootTable.push_back(new TableElement({0,99999}, &Level7::BossShoot_ID_2_SETDATA));
    bar->ShootTable.push_back(new TableElement({2, 0.025f}, &Level7::BossShoot_ID_2_1));
}

void Level7::CreateBarThree() {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Name="36 - Fearful Power of Mens' Evil Deeds";
    bar->BonusScore=700000;
    bar->Health=bar->MaxHealth=1200;
    bar->Move=&Level7::BossMove_ID_3;
    for (unsigned i=0; i<33; ++i) bar->Loot.push_back(SCORE_ITEM);
    bar->ShootTable.push_back(new TableElement({0,99999}, &Level7::BossShoot_ID_3_SETDATA));
    bar->ShootTable.push_back(new TableElement({0.6f, 99999}, &Level7::BossShoot_ID_3_1));
    bar->ShootTable.push_back(new TableElement({1.f, 0.01f}, &Level7::BossShoot_ID_3_2));
    bar->ShootTable.push_back(new TableElement({5.f, 0.1f}, &Level7::BossShoot_ID_3_3));
}

void Level7::CreateBarFour() {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Name="37 - Light of the Shiniest Star";
    bar->BonusScore=700000;
    bar->Health=bar->MaxHealth=900;
    bar->Move=&Level7::BossMove_ID_4;
    for (unsigned i=0; i<5; ++i) bar->Loot.push_back(POWER_ITEM);
    for (unsigned i=0; i<30; ++i) bar->Loot.push_back(SCORE_ITEM);
    for (unsigned i=0; i<5; ++i) bar->Loot.push_back(POWER_ITEM);
    bar->ShootTable.push_back(new TableElement({0,99999}, &Level7::BossShoot_ID_4_SETDATA));
    bar->ShootTable.push_back(new TableElement({2.f,2.5f}, &Level7::BossShoot_ID_4_1));
    bar->ShootTable.push_back(new TableElement({2.f,0.15f}, &Level7::BossShoot_ID_4_2));
}

void Level7::CreateBarFive() {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Name="38 - Lion Chasing in the Dark Wood";
    bar->BonusScore=700000;
    bar->Health=bar->MaxHealth=1000;
    bar->Move=&Level7::BossMove_ID_5;
    for (unsigned i=0; i<10; ++i) bar->Loot.push_back(POWER_ITEM);
    for (unsigned i=0; i<35; ++i) bar->Loot.push_back(SCORE_ITEM);
    for (unsigned i=0; i<10; ++i) bar->Loot.push_back(POWER_ITEM);
    bar->ShootTable.push_back(new TableElement({0.f,99999.f}, &Level7::BossShoot_ID_5_SETDATA));
    bar->ShootTable.push_back(new TableElement({3.f,99999.f}, &Level7::BossShoot_ID_5_1));
    bar->ShootTable.push_back(new TableElement({4.f,1.2f}, &Level7::BossShoot_ID_5_2));
    //bar->ShootTable.push_back(new TableElement({3.5f, 0.7f}, &Level7::BossShoot_ID_5_3));
}

void Level7::CreateBarSix() {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Name="39 - Total Annihilation Ray";
    bar->BonusScore=700000;
    bar->Health=bar->MaxHealth=950;
    bar->Move=&Level7::BossMove_ID_6;
    for (unsigned i=0; i<45; ++i) bar->Loot.push_back(SCORE_ITEM);
    bar->ShootTable.push_back(new TableElement({0.f, 99999.f}, &Level7::BossShoot_ID_6_SETDATA));
    bar->ShootTable.push_back(new TableElement({0.8f, 10.f}, &Level7::BossShoot_ID_6_1));
    bar->ShootTable.push_back(new TableElement({1.8f, 10.f}, &Level7::BossShoot_ID_6_2));
    bar->ShootTable.push_back(new TableElement({3.8f, 0.55f}, &Level7::BossShoot_ID_6_3));
}

/*void Level7::CreateBarSeven() {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Name="Attack Pattern n° 40";
    bar->BonusScore=700000;
    bar->Health=bar->MaxHealth=1300;
    bar->Move=&Level7::BossMove_ID_7;
    for (unsigned i=0; i<25; ++i) bar->Loot.push_back(POWER_ITEM);
    for (unsigned i=0; i<25; ++i) bar->Loot.push_back(SCORE_ITEM);
    bar->ShootTable.push_back(new TableElement({0.f,99999.f}, &Level7::BossShoot_ID_7_SETDATA));
    bar->ShootTable.push_back(new TableElement({1.8f,4.f}, &Level7::BossShoot_ID_7_1));
    bar->ShootTable.push_back(new TableElement({3.f,1.5f}, &Level7::BossShoot_ID_7_2));
}*/

void Level7::CreateBarSeven() {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Name="40 - Eastern Devil Magic";
    bar->BonusScore=1000000;
    bar->Health=bar->MaxHealth=2000;
    bar->Move=&Level7::BossMove_ID_7;
    for (unsigned i=0; i<25; ++i) bar->Loot.push_back(POWER_ITEM);
    for (unsigned i=0; i<25; ++i) bar->Loot.push_back(SCORE_ITEM);
    bar->ShootTable.push_back(new TableElement({0.f,999999.f}, &Level7::BossShoot_ID_7_SETDATA));
    bar->ShootTable.push_back(new TableElement({2.f,999999.f}, &Level7::BossShoot_ID_7_1)); //4 balls, origin of _2
    bar->ShootTable.push_back(new TableElement({3.f, 0.05f}, &Level7::BossShoot_ID_7_2)); //
    bar->ShootTable.push_back(new TableElement({3.5f, 0.25f}, &Level7::BossShoot_ID_7_3)); //Random falling balls
    bar->ShootTable.push_back(new TableElement({999999.f,2.f}, &Level7::BossShoot_ID_7_4)); //Three aimed
    bar->ShootTable.push_back(new TableElement({999999.f,4.f}, &Level7::BossShoot_ID_7_5)); //Upwards arc stream
    bar->ShootTable.push_back(new TableElement({999999.f,0.05f}, &Level7::BossShoot_ID_7_6)); //Downward arc stream
    bar->ShootTable.push_back(new TableElement({999999.f,0.3f}, &Level7::BossShoot_ID_7_7)); //Circles of reds*/
}

void Level7::CreateBarEight() {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Name="41 - Hell's Punishment";
    bar->BonusScore=1500000;
    bar->Health=bar->MaxHealth=1800;
    bar->Move=&Level7::BossMove_ID_8;
    for (unsigned i=0; i<50; ++i) bar->Loot.push_back(POWER_ITEM);
    for (unsigned i=0; i<50; ++i) bar->Loot.push_back(SCORE_ITEM);
    bar->ShootTable.push_back(new TableElement({0.f, 1e15}, &Level7::BossShoot_ID_8_SETDATA));
    bar->ShootTable.push_back(new TableElement({2.f, 1e15}, &Level7::BossShoot_ID_8_BOSS1));
    bar->ShootTable.push_back(new TableElement({3.5f, 1e15}, &Level7::BossShoot_ID_8_1));
    bar->ShootTable.push_back(new TableElement({1e15, 1e15}, &Level7::BossShoot_ID_8_BOSS2));
    bar->ShootTable.push_back(new TableElement({1e15, 1.5f}, &Level7::BossShoot_ID_8_2));
    bar->ShootTable.push_back(new TableElement({1e15, 1e15}, &Level7::BossShoot_ID_8_BOSS3));
    bar->ShootTable.push_back(new TableElement({1e15, 1.5f}, &Level7::BossShoot_ID_8_3));
    bar->ShootTable.push_back(new TableElement({1e15, 1e15}, &Level7::BossShoot_ID_8_BOSS4));
    bar->ShootTable.push_back(new TableElement({1e15, 1.2f}, &Level7::BossShoot_ID_8_4));
    bar->ShootTable.push_back(new TableElement({1e15, 1e15}, &Level7::BossShoot_ID_8_BOSS5));
    bar->ShootTable.push_back(new TableElement({1e15, 2.f}, &Level7::BossShoot_ID_8_5));
    bar->ShootTable.push_back(new TableElement({1e15, 1e15}, &Level7::BossShoot_ID_8_BOSS6));
    bar->ShootTable.push_back(new TableElement({1e15, 0.9f}, &Level7::BossShoot_ID_8_6));
    bar->ShootTable.push_back(new TableElement({1e15, 1e15}, &Level7::BossShoot_ID_8_BOSS7));
    bar->ShootTable.push_back(new TableElement({1e15, 0.7f}, &Level7::BossShoot_ID_8_7));
}

void Level7::CreateBarNine() {
    Engine.LevelBoss->LifeBars.push_back(new LifeBar);
    LifeBar* bar=Engine.LevelBoss->LifeBars.back();
    bar->Name="42 - The Seven Deadly Sins";
    bar->BonusScore=1666000;
    bar->Health=bar->MaxHealth=1600;
    bar->Move=&Level7::BossMove_ID_9;
    for (unsigned i=0; i<100; ++i) bar->Loot.push_back(SCORE_ITEM);
    bar->ShootTable.push_back(new TableElement({0.f, 1e15}, &Level7::BossShoot_ID_9_SETDATA));
    bar->ShootTable.push_back(new TableElement({3.f, 1.f}, &Level7::BossShoot_ID_9_1));
    //bar->ShootTable.push_back(new TableElement({4.f, 0.07f}, &Level7::BossShoot_ID_9_2));
    bar->ShootTable.push_back(new TableElement({4.f, 0.3f}, &Level7::BossShoot_ID_9_2));
    bar->ShootTable.push_back(new TableElement({4.f, 0.9f}, &Level7::BossShoot_ID_9_3));
    bar->ShootTable.push_back(new TableElement({4.f, 1.2f}, &Level7::BossShoot_ID_9_4));
}

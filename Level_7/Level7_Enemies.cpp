#include "Level7.h"

void Level7::CreateEnemies() {
    Enemy* enemy=nullptr;

    ///1 - Openers - Fast rings
    for (unsigned i=0; i<20; ++i) {
        for (unsigned j=0; j<2; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=5;
            enemy->BaseTime=3+0.2*i;
            for (unsigned k=0; k<5; ++k)
                enemy->Loot.push_back(POWER_ITEM);
            enemy->Move=j==0?&Level7::Move_ID_1_1:&Level7::Move_ID_1_2;
            enemy->ShootTable.push_back(new EnemyShoot(0.3, Shoot_ID_1));
        }
    }

    ///2 - Two-sided Streaming
    for (unsigned i=0; i<50; ++i) {
        for (unsigned j=0; j<2; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=3;
            enemy->BaseTime=12+0.2*i;
            for (unsigned k=0; k<2; ++k)
                enemy->Loot.push_back(SCORE_ITEM);
            enemy->Move=j==0?&Level7::Move_ID_1_1:&Level7::Move_ID_1_2;
            for (unsigned k=0; k<10; ++k)
                enemy->ShootTable.push_back(new EnemyShoot(0.15+0.05*k, Shoot_ID_2));
        }
    }

    ///3 -
    for (unsigned i=0; i<1; ++i) {
        Engine.Enemies.push_back(new Enemy_1);
        enemy=Engine.Enemies.back();
        enemy->Life=50;
        enemy->BaseTime=10;
        for (unsigned j=0; j<5; ++j)
            enemy->Loot.push_back(POWER_ITEM);
        enemy->Loot.push_back(BOMB_ITEM);
        for (unsigned j=0; j<5; ++j)
            enemy->Loot.push_back(POWER_ITEM);
        enemy->Move=Level7::Move_ID_3;
        for (unsigned j=0; j<20; ++j)
            enemy->ShootTable.push_back(new EnemyShoot(1.2+j*0.25, Shoot_ID_3));
    }

    ///4 -
    for (unsigned i=0; i<36; ++i) {
        for (unsigned j=0; j<2; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=4;
            enemy->BaseTime=28+i+j*0.5;
            for (unsigned k=0; k<5; ++k)
                enemy->Loot.push_back(SCORE_ITEM);
            enemy->Move=j==0?Level7::Move_ID_1_1:Level7::Move_ID_1_2;
            enemy->ShootTable.push_back(new EnemyShoot(0.3, Shoot_ID_4));
        }
    }

    ///5 - Midboss
    for (unsigned i=0; i<1; ++i) {
        Engine.Enemies.push_back(new Enemy_2);
        enemy=Engine.Enemies.back();
        enemy->Life=1200;
        enemy->BaseTime=25;
        for (unsigned k=0; k<10; ++k)
            enemy->Loot.push_back(POWER_ITEM);
        for (unsigned k=0; k<10; ++k)
            enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(LIFE_ITEM);
        for (unsigned k=0; k<10; ++k)
            enemy->Loot.push_back(SCORE_ITEM);
        for (unsigned k=0; k<10; ++k)
            enemy->Loot.push_back(POWER_ITEM);
        enemy->Move=Level7::Move_ID_5;
        for (unsigned k=0; k<30*5; ++k)
            enemy->ShootTable.push_back(new EnemyShoot(2.5+k*0.2, Shoot_ID_5));
    }
}

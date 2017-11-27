#include "Level4.h"

void Level4::CreateEnemies() {
    Enemy* enemy=nullptr;
    ///1 - Openers - 0-23
    for (unsigned short i=0; i<2; ++i) {
        for (unsigned short j=0; j<12; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=6;
            enemy->BaseTime=3+j*0.5;
            enemy->Loot.push_back(1-i);
            enemy->Loot.push_back(0+i);
            if (i==0)
                enemy->Move=&Level4::Move_ID_1_1;
            else
                enemy->Move=&Level4::Move_ID_1_2;
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=1.5;
            enemy->ShootTable.back()->second=&Level4::Shoot_ID_1;
        }
    }

    ///2 - Lateral, U-like path - 24-55
    for (unsigned short i=0; i<2; ++i) {
        for (unsigned short j=0; j<16; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=7;
            enemy->BaseTime=12+j*0.4;
            enemy->Loot.push_back((i+j)%2);
            enemy->Loot.push_back(1-enemy->Loot[0]);
            if (i==0)
                enemy->Move=&Level4::Move_ID_2_1;
            else
                enemy->Move=&Level4::Move_ID_2_2;
            for (unsigned short k=0; k<8; ++k) {
                enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
                enemy->ShootTable.back()->first=2.5+k*0.05;
                enemy->ShootTable.back()->second=&Level4::Shoot_ID_2;
            }
        }
    }

    ///3 - Ascending lateral - 56-87
    for (unsigned short i=0; i<2; ++i) {
        for (unsigned short j=0; j<16; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=8;
            enemy->BaseTime=21+j*0.8;
            enemy->Loot.push_back(j%2);
            if (i==0)
                enemy->Move=&Level4::Move_ID_3_1;
            else
                enemy->Move=&Level4::Move_ID_3_2;
            for (unsigned short k=0; k<3; ++k) {
                enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
                enemy->ShootTable.back()->first=2+k*0.6;
                enemy->ShootTable.back()->second=&Level4::Shoot_ID_3;
            }
        }
    }

    ///4 - Spiral (simplification of Mamizou) - 88-93
    for (unsigned short i=0; i<2; ++i) {
        for (unsigned short j=0; j<3; ++j) {
            Engine.Enemies.push_back(new Enemy_1);
            enemy=Engine.Enemies.back();
            enemy->Life=20;
            enemy->BaseTime=35+j*6+i*3;
            enemy->Loot.push_back(POWER_ITEM);
            enemy->Loot.push_back(SCORE_ITEM);
            enemy->Loot.push_back(POWER_ITEM);
            enemy->Loot.push_back(SCORE_ITEM);
            enemy->Loot.push_back(POWER_ITEM);
            if (i==0)
                enemy->Move=&Level4::Move_ID_4_1;
            else
                enemy->Move=&Level4::Move_ID_4_2;
            for (unsigned short k=0; k<20; ++k) {
                enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
                enemy->ShootTable.back()->first=0.5+k*0.1;
                if (i==0)
                    enemy->ShootTable.back()->second=&Level4::Shoot_ID_4_1;
                else
                    enemy->ShootTable.back()->second=&Level4::Shoot_ID_4_2;
            }
        }
    }

    ///5 - Bomb droppers - 94-107
    for (unsigned short i=0; i<7; ++i) {
        for (unsigned short j=0; j<2; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=15;
            enemy->BaseTime=36+i*2;
            enemy->Loot.push_back(POWER_ITEM);
            if (j==0)
                enemy->Move=&Level4::Move_ID_5_1;
            else
                enemy->Move=&Level4::Move_ID_5_2;
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=1;
            enemy->ShootTable.back()->second=&Level4::Shoot_ID_5;
        }
    }

    ///6 - Four queues making a circle - 108-127
    for (unsigned short i=0; i<10; ++i) {
        for (unsigned short j=0; j<2; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=5;
            enemy->BaseTime=53+i*0.6;
            enemy->Loot.push_back(i%2);
            if (j==0) enemy->Move=&Level4::Move_ID_6_1;
            else enemy->Move=&Level4::Move_ID_6_2;
            for (unsigned short k=0; k<8; ++k) {
                enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
                enemy->ShootTable.back()->first=1.5*(k+0.5);
                enemy->ShootTable.back()->second=&Level4::Shoot_ID_6;
            }
        }
    }

    ///7 - Three circles of bullets - 128-133
    for (unsigned short i=0; i<3; ++i) {
        for (unsigned short j=0; j<2; ++j) {
            Engine.Enemies.push_back(new Enemy_1);
            enemy=Engine.Enemies.back();
            enemy->Life=34;
            enemy->BaseTime=64+i*6+j*3;
            enemy->Loot.push_back(SCORE_ITEM);
            enemy->Loot.push_back(SCORE_ITEM);
            enemy->Loot.push_back(POWER_ITEM);
            enemy->Loot.push_back(POWER_ITEM);
            enemy->Loot.push_back(SCORE_ITEM);
            enemy->Loot.push_back(SCORE_ITEM);
            if (j==0) enemy->Move=&Level4::Move_ID_7_1;
            else enemy->Move=&Level4::Move_ID_7_2;
            for (unsigned short k=0; k<3; ++k) {
                enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
                enemy->ShootTable.back()->first=1.3+0.3*k;
                enemy->ShootTable.back()->second=&Level4::Shoot_ID_7;
            }
            ///Data storing - deleted by last shooting
            for (unsigned short k=0; k<2; ++k) {
                //0: how many times already shoot?
                //1: angle
                enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
                enemy->ShootTable.back()->first=0;
            }
        }
    }

    ///8 - Midboss - 134-134
    for (unsigned short i=0; i<1; ++i) {
        Engine.Enemies.push_back(new Enemy_2);
        enemy=Engine.Enemies.back();
        enemy->Life=1100;
        enemy->BaseTime=81;
        for (unsigned short j=0; j<4; ++j) enemy->Loot.push_back(SCORE_ITEM);
        for (unsigned short j=0; j<3; ++j) enemy->Loot.push_back(POWER_ITEM);
        for (unsigned short j=0; j<1; ++j) enemy->Loot.push_back(LIFE_ITEM);
        for (unsigned short j=0; j<3; ++j) enemy->Loot.push_back(POWER_ITEM);
        for (unsigned short j=0; j<4; ++j) enemy->Loot.push_back(SCORE_ITEM);
        enemy->Move=&Level4::Move_ID_8;
        for (unsigned short j=0; j<30; ++j) {
            for (unsigned short k=0; k<10; ++k) {
                enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
                enemy->ShootTable.back()->first=3.5+k*0.1+j;
                enemy->ShootTable.back()->second=&Level4::Shoot_ID_8_1;
            }
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=4.5+j;
            enemy->ShootTable.back()->second=&Level4::Shoot_ID_8_2;
        }
        //Clockwise angle:
        enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
        enemy->ShootTable.back()->first=-PI/2;
    }

    ///9 - When midboss dies - 135-246
    for (unsigned short i=0; i<8; ++i) { //How many times everything?
        for (unsigned short j=0; j<2; ++j) { //Two rows, left and right
            for (unsigned short k=0; k<7; ++k) {
                Engine.Enemies.push_back(new Enemy_0);
                enemy=Engine.Enemies.back();
                enemy->Life=3;
                enemy->BaseTime=91+i*5+j*2.5+k*0.2;
                enemy->Loot.push_back(j%2);
                if (i<5) {
                    if (j==0) enemy->Move=&Level4::Move_ID_9_1_START;
                    else enemy->Move=&Level4::Move_ID_9_2_START;
                }
                else {
                    if (j==0) enemy->Move=&Level4::Move_ID_9_1_GO;
                    else enemy->Move=&Level4::Move_ID_9_2_GO;
                }
                enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
                enemy->ShootTable.back()->first=0.6;
                enemy->ShootTable.back()->second=&Level4::Shoot_ID_9;
            }
        }
    }

    ///10 - Fairy Wars midboss, third spell - 247-252
    for (unsigned short i=0; i<3; ++i) {
        for (unsigned short j=0; j<2; ++j) {
            Engine.Enemies.push_back(new Enemy_1);
            enemy=Engine.Enemies.back();
            enemy->Life=20;
            enemy->BaseTime=131.5+i*4;
            if ((i==1 && j==0) || (i%2==0 && j==1)) enemy->BaseTime+=1.6;
            enemy->Loot.push_back((i)%2);
            enemy->Loot.push_back((i+1)%2);
            enemy->Loot.push_back((i+1)%2);
            enemy->Loot.push_back((i)%2);
            if (j==0) enemy->Move=&Level4::Move_ID_10_1;
            else enemy->Move=&Level4::Move_ID_10_2;
            for (unsigned short k=0; k<60; ++k) {
                enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
                enemy->ShootTable.back()->first=0.6+k*0.025;
                if (j==0) enemy->ShootTable.back()->second=&Level4::Shoot_ID_10_1;
                else enemy->ShootTable.back()->second=&Level4::Shoot_ID_10_2;
            }
            //Player->Position.x and y, to get angle as if player wouldn't move after first shoot
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=10000;
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=10000;
        }
    }

    ///11 - Chasing circles - 253-255
    for (unsigned short j=0; j<2; ++j) {
        Engine.Enemies.push_back(new Enemy_1);
        enemy=Engine.Enemies.back();
        enemy->Life=180;
        enemy->BaseTime=145+j*10;
        for (unsigned short k=0; k<3; ++k) enemy->Loot.push_back(POWER_ITEM);
        for (unsigned short k=0; k<3; ++k) enemy->Loot.push_back(SCORE_ITEM);
        if (j==0)
            enemy->Move=&Level4::Move_ID_11_1;
        else
            enemy->Move=&Level4::Move_ID_11_2;
        for (unsigned short k=0; k<5; ++k) {
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=2+1.3*k;
            enemy->ShootTable.back()->second=&Level4::Shoot_ID_11_1;
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=2.2+1.3*k;
            enemy->ShootTable.back()->second=&Level4::Shoot_ID_11_2;
        }
    }
}

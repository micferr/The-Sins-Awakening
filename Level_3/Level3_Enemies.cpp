#include "Level3.h"

void Level3::CreateEnemies() {
    Enemy* enemy=nullptr;
    ///1 - Openers - Wall
    for (short i=0; i<2; ++i) {
        for (short j=0; j<7; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=6;
            enemy->BaseTime=3+i*6;
            if (i==0)
                enemy->Move=&Level3::Move_ID_1_1;
            else
                enemy->Move=&Level3::Move_ID_1_2;
            if (j%4<2) { //0 or 1
                enemy->Loot.push_back(POWER_ITEM);
                enemy->Loot.push_back(SCORE_ITEM);
            }
            else { //2 or 3
                enemy->Loot.push_back(SCORE_ITEM);
                enemy->Loot.push_back(POWER_ITEM);
            }
            for (short k=0; k<7; ++k) {
                enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
                enemy->ShootTable.back()->first=(k+1)*0.5+0.3;
                enemy->ShootTable.back()->second=&Level3::Shoot_ID_1;
            }
            enemy->Position.x=100+50*j;
        }
    }
    ///2 - Spiral
    for (short i=0; i<2; ++i) {
        for (unsigned j=0; j<2; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=14;
            enemy->BaseTime=13.5+(i*2+j)*2;
            enemy->Loot.push_back(POWER_ITEM);
            enemy->Loot.push_back(SCORE_ITEM);
            enemy->Loot.push_back(SCORE_ITEM);
            enemy->Loot.push_back(POWER_ITEM);
            if (j==0)
                enemy->Move=&Level3::Move_ID_2_1;
            else
                enemy->Move=&Level3::Move_ID_2_2;
            for (short k=0; k<40; ++k) {
                enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
                enemy->ShootTable.back()->first=0.8+k*0.025;
                enemy->ShootTable.back()->second=&Level3::Shoot_ID_2;
            }
        }
    }
    ///3 - Crossing (up to down)
    for (short i=0; i<6; ++i) {
        for (short j=0; j<2; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=7;
            enemy->BaseTime=23;
            enemy->Loot.push_back(j); //0 || 1
            enemy->Loot.push_back(1-j); //1 || 0
            if (j==0)
                enemy->Move=&Level3::Move_ID_3_1;
            else
                enemy->Move=&Level3::Move_ID_3_2;
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=1;
            enemy->ShootTable.back()->second=&Level3::Shoot_ID_3;
            enemy->Position.x=25+(450/12*(i*2+j))+(450/24);
        }
    }
    ///Crossing (left to right)
    for (short i=0; i<7; ++i) {
        for (short j=0; j<2; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=7;
            enemy->BaseTime=29.5;
            enemy->Loot.push_back(j);
            enemy->Loot.push_back(1-j);
            if (j==0)
                enemy->Move=&Level3::Move_ID_3_3;
            else
                enemy->Move=&Level3::Move_ID_3_4;
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=1;
            enemy->ShootTable.back()->second=&Level3::Shoot_ID_3;
            enemy->Position.y=25+(550/14*(i*2+j))+(550/28);
        }
    }
    ///4 - Bullet barrier
    for (short i=0; i<1; ++i) {
        Engine.Enemies.push_back(new Enemy_1);
        enemy=Engine.Enemies.back();
        enemy->Life=90;
        enemy->BaseTime=36;
        for (short j=0; j<5; ++j)
            enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(BOMB_ITEM);
        for (short j=0; j<5; ++j)
            enemy->Loot.push_back(SCORE_ITEM);
        enemy->Move=&Level3::Move_ID_4;
        for (short j=0; j<8; ++j) {
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=1.5+j*1.5;
            enemy->ShootTable.back()->second=&Level3::Shoot_ID_4;
        }
    }
    ///5 - Meteors
    for (short i=0; i<12; ++i) {
        Engine.Enemies.push_back(new Enemy_0);
        enemy=Engine.Enemies.back();
        enemy->Life=5;
        enemy->BaseTime=38+i;
        enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(SCORE_ITEM);
        enemy->Move=&Level3::Move_ID_5_START;
        for (short j=0; j<5; ++j) {
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=1+0.4*j;
            enemy->ShootTable.back()->second=&Level3::Shoot_ID_5;
        }
        enemy->Position.y=-30;
        enemy->Position.x=Randomizer.GetRandom(30.f,465.f);
    }
    for (short i=0; i<8; ++i) {
        Engine.Enemies.push_back(new Enemy_0);
        enemy=Engine.Enemies.back();
        enemy->Life=5;
        enemy->BaseTime=50+i;
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(SCORE_ITEM);
        enemy->Move=&Level3::Move_ID_5_GO;
        for (short j=0; j<5; ++j) {
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=1+0.4*j;
            enemy->ShootTable.back()->second=&Level3::Shoot_ID_5;
        }
        enemy->Position.y=-30;
        enemy->Position.x=Randomizer.GetRandom(30.f, 465.f);
    }
    ///6 - Rotating (goes horizontally and shoots spirals (6))
    for (short i=0; i<5; ++i) {
        Engine.Enemies.push_back(new Enemy_0);
        enemy=Engine.Enemies.back();
        enemy->Life=50;
        enemy->BaseTime=59+6*i;
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(POWER_ITEM);
        if (i%2==0)
            enemy->Move=&Level3::Move_ID_6_1;
        else
            enemy->Move=&Level3::Move_ID_6_2;
        for (short j=0; j<80; ++j) {
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=1+0.05*j;
            if (i%2==0)
                enemy->ShootTable.back()->second=&Level3::Shoot_ID_6_1;
            else
                enemy->ShootTable.back()->second=&Level3::Shoot_ID_6_2;
        }
    }
    ///7 - Crossing Spirals
    for (short i=0; i<1; ++i) {
        Engine.Enemies.push_back(new Enemy_1);
        enemy=Engine.Enemies.back();
        enemy->Life=400;
        enemy->BaseTime=88;
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Loot.push_back(BOMB_ITEM);
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Move=&Level3::Move_ID_7;
        for (unsigned int j=0; j<460; ++j) {
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=3+j*0.05;
            enemy->ShootTable.back()->second=&Level3::Shoot_ID_7;
        }
    }
    ///8 - Small arcs
    for (short i=0; i<8; ++i) {
        for (short j=0; j<2; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=13;
            enemy->BaseTime=90+i*4+j*2;
            enemy->Loot.push_back(POWER_ITEM);
            enemy->Loot.push_back(POWER_ITEM);
            if (j==0)
                enemy->Move=&Level3::Move_ID_8_1;
            else
                enemy->Move=&Level3::Move_ID_8_2;
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=0.5;
            enemy->ShootTable.back()->second=&Level3::Shoot_ID_8;
        }
    }
    ///9 - 2 Score trains
    for (short i=0; i<14; ++i) {
        for (short j=0; j<2; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=9;
            enemy->BaseTime=121+i*0.5;
            enemy->Loot.push_back(SCORE_ITEM);
            enemy->Loot.push_back(SCORE_ITEM);
            if (j==0)
                enemy->Move=&Level3::Move_ID_9_1;
            else
                enemy->Move=&Level3::Move_ID_9_2;
            for (short k=0; k<2; ++k) {
                enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
                enemy->ShootTable.back()->first=0.7+2*k;
                enemy->ShootTable.back()->second=&Level3::Shoot_ID_9;
            }
        }
    }
    ///10 - Round cage (???, naming's sooo difficult...)
    for (short i=0; i<13; ++i) {
        for (short j=0; j<2; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=6;
            enemy->BaseTime=130+i*0.5+j*0.25;
            enemy->Loot.push_back(POWER_ITEM);
            enemy->Loot.push_back(SCORE_ITEM);
            if (j==0)
                enemy->Move=&Level3::Move_ID_10_1;
            else
                enemy->Move=&Level3::Move_ID_10_2;
            for (short k=0; k<6; ++k) {
                enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
                enemy->ShootTable.back()->first=1+0.5*k;
                if (k%2==0)
                    enemy->ShootTable.back()->second=&Level3::Shoot_ID_10_1;
                else
                    enemy->ShootTable.back()->second=&Level3::Shoot_ID_10_2;
            }
        }
    }
    ///11 - Circles of bullets
    for (short i=0; i<2; ++i) {
        Engine.Enemies.push_back(new Enemy_1);
        enemy=Engine.Enemies.back();
        enemy->Life=95;
        enemy->BaseTime=139+i*10;
        enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Loot.push_back(SCORE_ITEM);
        if (i%2==0)
            enemy->Move=&Level3::Move_ID_11_1;
        else
            enemy->Move=&Level3::Move_ID_11_2;
        for (short j=0; j<2; ++j) {
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=3+j*4;
            enemy->ShootTable.back()->second=&Level3::Shoot_ID_11;
        }
    }
}

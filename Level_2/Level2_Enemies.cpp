#include "Level2.h"

void Level2::CreateEnemies(void) {
    Enemy* enemy=nullptr;
    ///Openers - Hell raven style
    for (short i=0; i<12; ++i) {
        Engine.Enemies.push_back(new Enemy_0);
        enemy=Engine.Enemies.back();
        enemy->Life=5;
        enemy->BaseTime=3+i;
        if (i%2==0)
            enemy->Move=&Level2::Move_ID_1_1;
        else
            enemy->Move=&Level2::Move_ID_1_2;
        enemy->Loot.push_back(0);
        enemy->Loot.push_back(1);
        enemy->Loot.push_back(0);
        for (short j=0; j<40; j++) {
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.at(j)->first=j*0.075+i*0.01; //j*x: shots in 3 secs of time - i*x: always different bullets' positions
            enemy->ShootTable.at(j)->second=&Level2::Shoot_ID_1;
        }
    }
    ///Multispeed arc'd bullets
    for (short i=0; i<4; ++i) {
        Engine.Enemies.push_back(new Enemy_1);
        enemy=Engine.Enemies.back();
        enemy->Life=30;
        for (short j=0; j<5; j++)
            enemy->Loot.push_back(POWER_ITEM);
        if (i==0 || i==3) {
            enemy->Move=&Level2::Move_ID_2_1;
            enemy->BaseTime=17;
        }
        else {
            enemy->Move=&Level2::Move_ID_2_2;
            enemy->BaseTime=22;
        }
        for (short j=0; j<3; j++) {
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.at(j)->first=2.5+5*j;
            enemy->ShootTable.at(j)->second=&Level2::Shoot_ID_2;
        }

        enemy->Position.x=25+56.25*((i*2)+1);
        enemy->Position.y=-30;
    }
    ///Double column
    for (short i=0; i<20; ++i) { ///Filler
        Engine.Enemies.push_back(new Enemy_0);
        enemy=Engine.Enemies.back();
        enemy->Life=13;
        enemy->BaseTime=26+i*0.6;
        for (short j=0; j<3; ++j)
            enemy->Loot.push_back(SCORE_ITEM);
        enemy->Move=&Level2::Move_ID_3_1;
        for (short j=0; j<5; ++j) {
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=1+j*0.6;
            enemy->ShootTable.back()->second=&Level2::Shoot_ID_3;
        }
        if (i%2==0)
            enemy->Position.x=100;
        else
            enemy->Position.x=400;
        enemy->Position.y=-30;
    }
    for (short i=0; i<20; ++i) { ///regular
        Engine.Enemies.push_back(new Enemy_0);
        enemy=Engine.Enemies.back();
        enemy->Life=13;
        enemy->BaseTime=38+i*0.6;
        if (i%4<2)
            enemy->Loot.push_back(POWER_ITEM);
        else
            enemy->Loot.push_back(SCORE_ITEM);
        enemy->Move=&Level2::Move_ID_3_2;
        for (short j=0; j<5; ++j) {
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=1+j*0.6;
            enemy->ShootTable.back()->second=&Level2::Shoot_ID_3;
        }
        if (i%2==0)
            enemy->Position.x=100;
        else
            enemy->Position.x=400;
        enemy->Position.y=-30;
    }
    ///Area and direct - Area
    for (short i=0; i<10; i++) {
        Engine.Enemies.push_back(new Enemy_0);
        enemy=Engine.Enemies.back();
        enemy->Life=10;
        enemy->BaseTime=52+i*1.3;
        enemy->Loot.push_back(1-i%2);
        enemy->Loot.push_back(0+i%2);
        enemy->Loot.push_back(1-i%2);
        if (i%2==0)
            enemy->Move=&Level2::Move_ID_4_1;
        else
            enemy->Move=&Level2::Move_ID_4_2;
        for (short i=0; i<2; i++) {
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=0.5+i*1.3;
            enemy->ShootTable.back()->second=&Level2::Shoot_ID_4;
        }
    }
    ///Area and direct - Direct
    for (short i=0; i<3; i++) {
        for (short j=0; j<5; j++) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=5;
            enemy->BaseTime=52+i*5+j*0.8;
            enemy->Loot.push_back(POWER_ITEM);
            if (i%2==0)
                enemy->Move=&Level2::Move_ID_5_1;
            else
                enemy->Move=&Level2::Move_ID_5_2;
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=0.7;
            enemy->ShootTable.back()->second=&Level2::Shoot_ID_5;
        }
    }
    ///Circles of crossing bullets
    for (short i=0; i<5; ++i) {
        for (short j=0; j<2; ++j) {
            Engine.Enemies.push_back(new Enemy_1);
            enemy=Engine.Enemies.back();
            enemy->Life=13;
            enemy->BaseTime=66.5+j+i*2;
            for (short k=0; k<4; ++k)
                enemy->Loot.push_back(POWER_ITEM);
            if (j==0)
                enemy->Move=&Level2::Move_ID_6_1;
            else
                enemy->Move=&Level2::Move_ID_6_2;
            for (short k=0; k<2; k++) {
                enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
                enemy->ShootTable.back()->first=1.3+k*2;
                enemy->ShootTable.back()->second=&Level2::Shoot_ID_6;
            }
        }
    }
    ///Crossing support
    for (short i=0; i<5; ++i) {
        Engine.Enemies.push_back(new Enemy_0);
        enemy=Engine.Enemies.back();
        enemy->Life=9;
        enemy->BaseTime=67.5+i*2;
        enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Loot.push_back(SCORE_ITEM);
        if (i%2==0)
            enemy->Move=&Level2::Move_ID_7_1;
        else
            enemy->Move=&Level2::Move_ID_7_2;
        enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
        enemy->ShootTable.at(0)->first=1.4;
        enemy->ShootTable.at(0)->second=&Level2::Shoot_ID_7;
        enemy->Position=sf::Vector2<float>(250+260*pow(-1,i+1), 135+5*i*pow(-1,i+1)); //Right or left
    }
    ///Strong
    for (short i=0; i<1; ++i) {
        Engine.Enemies.push_back(new Enemy_2);
        enemy=Engine.Enemies.back();
        enemy->Life=700;
        enemy->BaseTime=84;
        enemy->Loot.push_back(LIFE_ITEM);
        enemy->Move=&Level2::Move_ID_8;
        for (short j=0; j<120; ++j) {
                enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
                enemy->ShootTable.back()->first=3.5+j*0.15;
                enemy->ShootTable.back()->second=&Level2::Shoot_ID_8;
        }
        enemy->Position.x=250;
    }
    ///Circles of bullets
    for (short i=0; i</*22*/16; ++i) {
        Engine.Enemies.push_back(new Enemy_0);
        enemy=Engine.Enemies.back();
        enemy->Life=6;
        enemy->BaseTime=84+i*2;
        //Loot
        if (i<=10) {
            //PSPSPSPSPSP
            for (short j=0; j<5; ++j) {
                enemy->Loot.push_back(POWER_ITEM);
                enemy->Loot.push_back(SCORE_ITEM);
            }
            enemy->Loot.push_back(POWER_ITEM);
        }
        else {
            enemy->Loot.push_back(POWER_ITEM);
            enemy->Loot.push_back(POWER_ITEM);
            enemy->Loot.push_back(SCORE_ITEM);
            enemy->Loot.push_back(SCORE_ITEM);
            enemy->Loot.push_back(POWER_ITEM);
            enemy->Loot.push_back(POWER_ITEM);
        }
        //Move
        if (i<=10) {
            if (i%2==0)
                enemy->Move=&Level2::Move_ID_9_1;
            else
                enemy->Move=&Level2::Move_ID_9_2;
        }
        else {
            if (i%2==0)
                enemy->Move=&Level2::Move_ID_9_1_PLUS;
            else
                enemy->Move=&Level2::Move_ID_9_2_PLUS;
        }
        //Shoot
        for (short j=0; j<2; ++j) {
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=0.5+1*j;
            enemy->ShootTable.back()->second=&Level2::Shoot_ID_9;
        }
        //Position
        enemy->Position.y=60+int(i/2)*20;
        if (i%2==0)
            enemy->Position.x=-20;
        else
            enemy->Position.x=540;
    }
    ///Circles falling
    for (short i=0; i</*2*/1; ++i) {
        Engine.Enemies.push_back(new Enemy_1);
        enemy=Engine.Enemies.back();
        enemy->Life=250;
        enemy->BaseTime=/*127*/115+i*20;
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(SCORE_ITEM);
        if (i%2==0)
            enemy->Move=&Level2::Move_ID_10_1;
        else
            enemy->Move=&Level2::Move_ID_10_2;
        for (unsigned j=0; j<157; ++j) {
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=1.5+j*double(float(18)/float(157)); //16 seconds / 157 shoots
            if (i%2==0)
                enemy->ShootTable.back()->second=&Level2::Shoot_ID_10_1;
            else
                enemy->ShootTable.back()->second=&Level2::Shoot_ID_10_2;
        }
    }
    ///11 - "Koishi"'s helpers
    for (unsigned short i=0; i</*8*/4; ++i) {
        for (unsigned short j=0; j<2; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=8;
            enemy->BaseTime=/*129*/117+i*5;
            enemy->Loot.push_back(SCORE_ITEM);
            enemy->Loot.push_back(SCORE_ITEM);
            enemy->Loot.push_back(SCORE_ITEM);
            enemy->Move=&Level2::Move_ID_11;
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=3;
            enemy->ShootTable.back()->second=&Level2::Shoot_ID_11;
            enemy->Position.x=250+20*(i+1)*pow(-1,j+1);
            enemy->Position.y=-20;
        }
    }
}

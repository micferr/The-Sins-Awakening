#include "Level5.h"

void Level5::CreateEnemies (void) {
    Enemy* enemy=nullptr;

    ///1 - Openers
    for (unsigned short i=0; i<2; ++i) {
        Engine.Enemies.push_back(new Enemy_1);
        enemy=Engine.Enemies.back();
        enemy->Life=29;
        enemy->BaseTime=3+i*3;
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Loot.push_back(SCORE_ITEM);
        if (i==0)
            enemy->Move=&Level5::Move_ID_1_1;
        else
            enemy->Move=&Level5::Move_ID_1_2;
        for (unsigned short j=0; j<10; ++j) {
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=2+j*0.15;
            enemy->ShootTable.back()->second=&Level5::Shoot_ID_1;
        }
    }

    ///2 - Waves
    for (unsigned short i=0; i<4; ++i) {
        for (unsigned short j=0; j<12; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=3;
            enemy->BaseTime=10+i*4+j*0.3;
            enemy->Loot.push_back(j%2);
            if (i%2==0)
                enemy->Move=&Level5::Move_ID_2_1;
            else
                enemy->Move=&Level5::Move_ID_2_2;
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=1.1;
            enemy->ShootTable.back()->second=&Level5::Shoot_ID_2;
        }
    }

    ///3 - Night sakura of dead spirits great fairies
    for (unsigned short i=0; i<2; ++i) {
        Engine.Enemies.push_back(new Enemy_1);
        enemy=Engine.Enemies.back();
        enemy->Life=30;
        enemy->BaseTime=10+8*i;
        enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Loot.push_back(SCORE_ITEM);
        enemy->Move=&Level5::Move_ID_3;
        for (unsigned short j=0; j<2; ++j) {
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=1.3+0.9*j;
            enemy->ShootTable.back()->second=j==0 ? &Level5::Shoot_ID_3_1 : &Level5::Shoot_ID_3_2;
        }
    }

    ///4 - Three arcs
    for (unsigned short i=0; i<4; ++i) {
        Engine.Enemies.push_back(new Enemy_1);
        enemy=Engine.Enemies.back();
        enemy->Life=21;
        enemy->BaseTime=26+i*5;
        for (unsigned int j=0; j<3; ++j)
            enemy->Loot.push_back(POWER_ITEM);
        enemy->Move=&Level5::Move_ID_4;
        for (unsigned j=0; j<5; ++j) {
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            enemy->ShootTable.back()->first=1+j*0.75;
            enemy->ShootTable.back()->second=&Level5::Shoot_ID_4;
        }
        enemy->Position.x=100+300*i; //100 or 400
    }

    ///5 - Common stream
    for (unsigned short i=0; i<2; ++i) {
        for (unsigned short j=0; j<15; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=3;
            enemy->BaseTime=27+i*4+j*0.2;
            enemy->Loot.push_back(SCORE_ITEM);
            enemy->Move=(i==0 ? &Move_ID_5_1 : &Move_ID_5_2);
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>(1.2,&Level5::Shoot_ID_5));
        }
    }

    ///6 - Scrolling vertical
    for (unsigned short i=0; i<2; ++i) {
        for (unsigned short j=0; j<2; ++j) {
            Engine.Enemies.push_back(new Enemy_1);
            enemy=Engine.Enemies.back();
            enemy->Life=31;
            enemy->BaseTime=35+i*8+j*4;
            enemy->Loot.push_back(SCORE_ITEM);
            enemy->Loot.push_back(POWER_ITEM);
            enemy->Loot.push_back(POWER_ITEM);
            enemy->Loot.push_back(SCORE_ITEM);
            enemy->Move=j%2==0 ? Move_ID_6_2 : Move_ID_6_1;
            for (unsigned short k=0; k<4; ++k)
                for (unsigned short m=0; m<10; ++m)
                    enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>(0.2+m*0.045+k*0.9, &Level5::Shoot_ID_6));
        }
    }

    ///7 - 6's helpers
    for (unsigned short i=0; i<12; ++i) {
        for (unsigned short j=0; j<2; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=4;
            enemy->BaseTime=39+i+j*0.5;
            enemy->Loot.push_back(j);
            enemy->Loot.push_back((j+1)%2);
            enemy->Move=j%2==0 ? Move_ID_7_1 : Move_ID_7_2;
            for (unsigned short k=0; k<3; ++k)
                enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>(0.3+2.7*k, &Level5::Shoot_ID_7));
        }
    }

    ///8 - Circular
    for (unsigned short i=0; i<2; ++i) {
        Engine.Enemies.push_back(new Enemy_1);
        enemy=Engine.Enemies.back();
        enemy->Life=80;
        enemy->BaseTime=53+i*12;
        for (unsigned short j=0; j<3; ++j)
            enemy->Loot.push_back(SCORE_ITEM);
        if (i==0)
            for (unsigned short j=0; j<3; ++j)
                enemy->Loot.push_back(POWER_ITEM);
        else
            enemy->Loot.push_back(BOMB_ITEM);
        for (unsigned short j=0; j<3; ++j)
            enemy->Loot.push_back(SCORE_ITEM);
        enemy->Move=i==0 ? Move_ID_8_1 : Move_ID_8_2;
        for (unsigned short j=0; j<30; ++j)
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>(1.35+j*0.30, &Shoot_ID_8));
    }

    ///9 - 8's shield
    for (unsigned short i=0; i<2; ++i) {
        for (unsigned short j=0; j<30; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=5;
            enemy->BaseTime=53+i*12+j*0.3;
            enemy->Loot.push_back(SCORE_ITEM);
            enemy->Move=i==0 ? Move_ID_9_1 : Move_ID_9_2;
            enemy->ShootTable.push_back(new std::pair<float,void(*)(Enemy*)>(1, &Shoot_ID_9));
        }
    }

    ///10 - Two circles
    for (unsigned short i=0; i<8; ++i) {
        Engine.Enemies.push_back(new Enemy_0);
        enemy=Engine.Enemies.back();
        enemy->Life=13;
        enemy->BaseTime=73+i*2;
        enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Loot.push_back(SCORE_ITEM);
        enemy->Move=i%2==0 ? Move_ID_10_1 : Move_ID_10_2;
        for (unsigned short k=0; k<2; ++k)
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>(0.7+1.8*k, &Shoot_ID_10));
    }

    ///11 - Player mover
    for (unsigned short i=0; i<1; ++i) {
        Engine.Enemies.push_back(new Enemy_1);
        enemy=Engine.Enemies.back();
        enemy->Life=150;
        enemy->BaseTime=92;
        for (unsigned short j=0; j<3; ++j)
            enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(BOMB_ITEM);
        for (unsigned short j=0; j<3; ++j)
            enemy->Loot.push_back(SCORE_ITEM);
        enemy->Move=&Level5::Move_ID_11;
        for (unsigned short j=0; j<10; ++j)
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>(1+j*1.5, &Level5::Shoot_ID_11));
    }

    ///12 - Spirals
    for (unsigned short i=0; i<5; ++i) {
        Engine.Enemies.push_back(new Enemy_1);
        enemy=Engine.Enemies.back();
        enemy->Life=12;
        enemy->BaseTime=92+i*3;
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Move=i%2==0 ? Level5::Move_ID_12_1 :Level5::Move_ID_12_2;
        for (unsigned short j=0; j<30; ++j)
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>(0.1+0.1*j, &Level5::Shoot_ID_12));
    }

    ///13 - Small groups
    for (unsigned short i=0; i<11; ++i) {
        for (unsigned short j=0; j<5; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=3;
            enemy->BaseTime=107+i+j*0.2;
            enemy->Loot.push_back(SCORE_ITEM);
            enemy->Move=i%2==0 ? Level5::Move_ID_13_1 : Level5::Move_ID_13_2;
            enemy->Position.y=60+i*5;
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>(0.2, &Level5::Shoot_ID_13));
        }
    }

    ///14 - Bullet rings - two sides
    for (unsigned short i=0; i<4; ++i) {
        Engine.Enemies.push_back(new Enemy_1);
        enemy=Engine.Enemies.back();
        enemy->Life=38;
        enemy->BaseTime=120+floor(i/2)*8;
        for (unsigned short j=0; j<5; ++j)
            enemy->Loot.push_back(POWER_ITEM);
        enemy->Move=i%2==0 ? Level5::Move_ID_14_1 : Level5::Move_ID_14_2;
        for (unsigned short j=0; j<35; ++j)
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>(1+j*0.2, &Level5::Shoot_ID_14));
    }

    ///15 - Spirals
    for (unsigned short i=0; i<2; ++i) {
        Engine.Enemies.push_back(new Enemy_1);
        enemy=Engine.Enemies.back();
        enemy->Life=60;
        enemy->BaseTime=136+i*10;
        enemy->Loot.push_back(POWER_ITEM);
        for (unsigned short j=0; j<4; ++j) enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Move=i==0 ? Level5::Move_ID_15_2 : Level5::Move_ID_15_1;
        for (unsigned short j=0; j<84; ++j)
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>(0.6+0.1*j, &Level5::Shoot_ID_15));
    }

    ///16 - Spirals' helpers
    for (unsigned short i=0; i<2; ++i) {
        for (unsigned short j=0; j<6; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=18;
            enemy->BaseTime=136+i*10;
            enemy->Loot.push_back(SCORE_ITEM);
            enemy->Loot.push_back(POWER_ITEM);
            enemy->Loot.push_back(SCORE_ITEM);
            enemy->Move=i==0?Level5::Move_ID_16_1:Level5::Move_ID_16_2;
            float Angle=PI/6+PI/3*j;
            enemy->Position.x=(i==0?-60:560)+cos(Angle)*70;
            enemy->Position.y=110-sin(Angle)*70;
            for (unsigned short k=0; k<4; ++k)
                enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>(1.5+0.8*k, &Level5::Shoot_ID_16));
        }
    }

    ///17 - PlayerBomb dropper
    for (unsigned short i=0; i<1; ++i) {
        Engine.Enemies.push_back(new Enemy_1);
        enemy=Engine.Enemies.back();
        enemy->Life=300;
        enemy->BaseTime=154;
        for (unsigned short j=0; j<3; ++j) enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Loot.push_back(BOMB_ITEM);
        enemy->Loot.push_back(POWER_ITEM);
        for (unsigned short j=0; j<3; ++j) enemy->Loot.push_back(SCORE_ITEM);
        enemy->Move=&Level5::Move_ID_17;
        for (unsigned short j=0; j<14; ++j)
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>(1.5+j, &Level5::Shoot_ID_17));
    }

    ///18 - Three in random direction
    for (unsigned short i=0; i<2; ++i) {
        for (unsigned short j=0; j<20; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=5;
            enemy->BaseTime=154+j;
            enemy->Loot.push_back(i%2);
            enemy->Move=i==0?&Level5::Move_ID_18_1:&Level5::Move_ID_18_2;
            for (unsigned short k=0; k<5; ++k)
                enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>(0.5+k*0.3, &Level5::Shoot_ID_18));
        }
    }
}

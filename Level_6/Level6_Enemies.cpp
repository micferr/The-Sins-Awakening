#include "Level6.h"

void Level6::CreateEnemies(void) {
    Enemy* enemy=nullptr;

    ///1 - Two openers
    for (unsigned i=0; i<4; ++i) {
        Engine.Enemies.push_back(new Enemy_1);
        enemy=Engine.Enemies.back();
        enemy->Life=45;
        enemy->BaseTime=3+(i>=2?11:0);
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Move=i%2==0?&Level6::Move_ID_1_1:Level6::Move_ID_1_2;
        for (unsigned j=0; j<10; ++j)
            enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>(1+j*0.5, &Level6::Shoot_ID_1));
    }

    ///2 - DNA-like falling
    for (unsigned i=0; i<28; ++i) {
        for (unsigned j=0; j<2; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=5;
            enemy->BaseTime=i<14?9+i*0.3:20+(i-14)*0.3;
            enemy->Loot.push_back((i+j)%2);
            if (i<14) enemy->Move=(j==0?Move_ID_2_1:Move_ID_2_2);
            else enemy->Move=(j==0?Move_ID_2_3:Move_ID_2_4);
            for (unsigned k=0; k<3; ++k)
                enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>(0.9+k*0.6, &Level6::Shoot_ID_2));
        }
    }

    ///3 - Streaming
    for (unsigned i=0; i<4; ++i) {
        for (unsigned j=0; j<20; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=8;
            enemy->BaseTime=28+i*8+j*0.35;
            for (unsigned k=0; k<2; ++k) enemy->Loot.push_back(j%2);
            enemy->Move=i%2==0?Move_ID_3_1:Move_ID_3_2;
            for (unsigned k=0; k<5; ++k) enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>(0.6+k*0.2,Shoot_ID_3));
        }
    }

    ///4 - Explosive bullets
    for (unsigned i=0; i<8; ++i) {
        Engine.Enemies.push_back(new Enemy_1);
        enemy=Engine.Enemies.back();
        enemy->Life=20;
        enemy->BaseTime=60+i*2;
        enemy->Loot.push_back(POWER_ITEM);
        for (unsigned k=0; k<4; ++k) enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Move=i%2==1?Move_ID_4_1:Move_ID_4_2;
        for (unsigned k=0; k<9; ++k) enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>(0.5+k*0.5,Shoot_ID_4));
    }

    ///5 - Falling
    for (unsigned i=0; i<5; ++i) {
        for (unsigned j=0; j<2; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=9;
            enemy->BaseTime=76+i*1.5+j*0.75;
            enemy->Loot.push_back(SCORE_ITEM);
            enemy->Move=j==0?Move_ID_5_1:Move_ID_5_2;
            for (unsigned k=0; k<4; ++k)
                enemy->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>(k*0.5,Shoot_ID_5));
        }
    }

    ///6 - Flamethrower
    for (unsigned i=0; i<2; ++i) {
        Engine.Enemies.push_back(new Enemy_1);
        enemy=Engine.Enemies.back();
        enemy->Life=140;
        enemy->BaseTime=85+i*13.5;
        if (i==0) {
            for (unsigned j=0; j<5; ++j) enemy->Loot.push_back(POWER_ITEM);
            for (unsigned j=0; j<5; ++j) enemy->Loot.push_back(SCORE_ITEM);
            for (unsigned j=0; j<5; ++j) enemy->Loot.push_back(POWER_ITEM);
        }
        else
            enemy->Loot.push_back(BOMB_ITEM);
        enemy->Move=Move_ID_6;
        for (unsigned k=0; k<24; ++k) {
            for (unsigned m=0; m<2; ++m) enemy->ShootTable.push_back(new EnemyShoot(1.2+k*0.48+m*0.24, Shoot_ID_6_1));
            enemy->ShootTable.push_back(new EnemyShoot(1.2+k*0.48, Shoot_ID_6_2));
        }
    }

    ///7 - Falling (two lines, same time)
    for (unsigned i=0; i<12; ++i) {
        for (unsigned j=0; j<2; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=7;
            enemy->BaseTime=111+i*0.5;
            enemy->Loot.push_back(i%2);
            enemy->Loot.push_back(i%2);
            enemy->Move=j==0?Move_ID_7_1:Move_ID_7_2;
            for (unsigned k=0; k<6; ++k)
                enemy->ShootTable.push_back(new EnemyShoot(0.9+0.2*k, Shoot_ID_7));
        }
    }

    ///8 - MidBoss
    for (unsigned i=0; i<1; ++i) {
        Engine.Enemies.push_back(new Enemy_2);
        enemy=Engine.Enemies.back();
        enemy->Life=600;
        enemy->BaseTime=121;
        for (unsigned j=0; j<10; ++j) enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(LIFE_ITEM);
        for (unsigned j=0; j<10; ++j) enemy->Loot.push_back(SCORE_ITEM);
        enemy->Move=Move_ID_8;
        for (unsigned j=0; j<15; ++j) {
            for (unsigned k=0; k<20; ++k) enemy->ShootTable.push_back(new EnemyShoot(1.5+j*2+k*0.05, Shoot_ID_8_1));
            for (unsigned k=0; k<20; ++k) enemy->ShootTable.push_back(new EnemyShoot(1.5+1+j*2+k*0.05, Shoot_ID_8_2));
        }
    }

    ///9 - Midboss time fillers
    for (unsigned i=0; i<25; ++i) {
        for (unsigned j=0; j<2; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=8;
            enemy->BaseTime=141+i;
            if (i<15) {
                for (unsigned k=0; k<6; ++k) enemy->Loot.push_back(SCORE_ITEM);
                enemy->Move=j==0?Move_ID_9_WAIT_1:Move_ID_9_WAIT_2;
            }
            else {
                for (unsigned k=0; k<2; ++k) enemy->Loot.push_back(SCORE_ITEM);
                enemy->Move=j==0?Move_ID_9_1:Move_ID_9_2;
            }
            enemy->ShootTable.push_back(new EnemyShoot(0.4,Shoot_ID_9));
        }
    }

    ///10 - Streaming 12-way growing bullets
    for (unsigned i=0; i<2; ++i) {
        for (unsigned j=0; j<2; ++j) {
            for (unsigned k=0; k<12; ++k) {
                Engine.Enemies.push_back(new Enemy_0);
                enemy=Engine.Enemies.back();
                enemy->Life=5;
                enemy->BaseTime=169+i*3+j*1.5+k*0.11;
                enemy->Loot.push_back(k%2);
                enemy->Move=j==0?Move_ID_10_2:Move_ID_10_1;
                enemy->ShootTable.push_back(new EnemyShoot(1-0.07*k,Shoot_ID_10));
            }
        }
    }

    ///11 - Screencrossing
    for (unsigned i=0; i<20; ++i) {
        Engine.Enemies.push_back(new Enemy_0);
        enemy=Engine.Enemies.back();
        enemy->Life=10;
        enemy->BaseTime=176+i*0.5;
        enemy->Loot.push_back(i%2);
        enemy->Loot.push_back(i%2);
        enemy->Move=i%2==0?Move_ID_11_1_FIRSTPHASE:Move_ID_11_2_FIRSTPHASE;
        for (unsigned j=0; j<3; ++j)
            enemy->ShootTable.push_back(new EnemyShoot(0.6*j, Shoot_ID_11));
    }

    ///12_1 - Flames
    for (unsigned i=0; i<1; ++i) {
        Engine.Enemies.push_back(new Enemy_1);
        enemy=Engine.Enemies.back();
        enemy->Life=110;
        enemy->BaseTime=188;
        enemy->Loot.push_back(POWER_ITEM);
        for (unsigned j=0; j<5; ++j) enemy->Loot.push_back(SCORE_ITEM);
        enemy->Loot.push_back(POWER_ITEM);
        enemy->Move=Move_ID_12_1;
        for (unsigned j=0; j<40; ++j)
            enemy->ShootTable.push_back(new EnemyShoot(1.2+0.25*j, Shoot_ID_12));
    }

    ///13_1 - 12's helper shield
    for (unsigned i=0; i<22; ++i) {
        for (unsigned j=0; j<2; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=3;
            enemy->BaseTime=189+i*0.5+j*0.25;
            switch (i%3) {
                case 0: enemy->Loot.push_back(POWER_ITEM); break;
                case 1: enemy->Loot.push_back(SCORE_ITEM); break;
                case 2: break;
            }
            enemy->Move=j==0?Move_ID_13_1_1:Move_ID_13_1_2;
            for (unsigned k=0; k<3; ++k)
                enemy->ShootTable.push_back(new EnemyShoot(0.4+k*0.3, Shoot_ID_13_1));
        }
    }

    ///12_2
    for (unsigned i=0; i<2; ++i) {
        Engine.Enemies.push_back(new Enemy_1);
        enemy=Engine.Enemies.back();
        enemy->Life=100;
        enemy->BaseTime=201;
        for (unsigned j=0; j<2; ++j) enemy->Loot.push_back(POWER_ITEM);
        for (unsigned j=0; j<6; ++j) enemy->Loot.push_back(SCORE_ITEM);
        for (unsigned j=0; j<2; ++j) enemy->Loot.push_back(POWER_ITEM);
        enemy->Move=i==0?Move_ID_12_2_1:Move_ID_12_2_2;
        for (unsigned j=0; j<58; ++j)
            enemy->ShootTable.push_back(new EnemyShoot(1.2+0.25*j, Shoot_ID_12));
    }

    ///13_2
    for (unsigned i=0; i<27; ++i) {
        for (unsigned j=0; j<4; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=3;
            enemy->BaseTime=202+i*0.5+(j%2)*0.25;
            enemy->Loot.push_back(POWER_ITEM);
            switch(j) {
                case 0: enemy->Move=Move_ID_13_2_1_1; break;
                case 1: enemy->Move=Move_ID_13_2_1_2; break;
                case 2: enemy->Move=Move_ID_13_2_2_1; break;
                case 3: enemy->Move=Move_ID_13_2_2_2; break;
            }
            for (unsigned k=0; k<4; ++k)
                enemy->ShootTable.push_back(new EnemyShoot(0.4+k*0.25, Shoot_ID_13_2));
        }
    }

    ///12_3
    for (unsigned i=0; i<3; ++i) {
        Engine.Enemies.push_back(new Enemy_1);
        enemy=Engine.Enemies.back();
        enemy->Life=90;
        enemy->BaseTime=220;
        if (i!=1)
            for (unsigned j=0; j<8; ++j)
                enemy->Loot.push_back(SCORE_ITEM);
        else
            enemy->Loot.push_back(BOMB_ITEM);
        switch (i) {
            case 0: enemy->Move=Move_ID_12_3_1; break;
            case 1: enemy->Move=Move_ID_12_3_2; break;
            case 2: enemy->Move=Move_ID_12_3_3; break;
        }
        for (unsigned j=0; j<70; ++j)
            enemy->ShootTable.push_back(new EnemyShoot(1.2+0.25*j, Shoot_ID_12));
    }

    ///13_3
    for (unsigned i=0; i<33; ++i) {
        for (unsigned j=0; j<4; ++j) {
            Engine.Enemies.push_back(new Enemy_0);
            enemy=Engine.Enemies.back();
            enemy->Life=3;
            enemy->BaseTime=221+i*0.5+(j<2)*0.25;
            enemy->Loot.push_back(SCORE_ITEM);
            switch (j) {
                case 0: enemy->Move=Move_ID_13_3_1_1; break;
                case 1: enemy->Move=Move_ID_13_3_1_2; break;
                case 2: enemy->Move=Move_ID_13_3_2_1; break;
                case 3: enemy->Move=Move_ID_13_3_2_2; break;
            }
            for (unsigned k=0; k<4; ++k)
                enemy->ShootTable.push_back(new EnemyShoot(0.3+0.15*k, Shoot_ID_13_3));
        }
    }
}

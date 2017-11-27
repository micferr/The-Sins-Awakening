#include "Level1.h"

void Level1::CreateEnemies() {
    ///Type 1 - Openers 1
    for (int i=0; i<12; i++) { //First Type Enemies
        Engine.Enemies.push_back(new Enemy_0);
        Engine.Enemies.back()->Life=4;
        Engine.Enemies.back()->BaseTime=2+i*0.3;
        Engine.Enemies.back()->Move=&Level1::Move_ID_1;
        Engine.Enemies.back()->Loot.push_back(i%2);
        //Bullets
        Engine.Enemies.back()->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
        Engine.Enemies.back()->ShootTable.at(0)->first=0.8;
        Engine.Enemies.back()->ShootTable.at(0)->second=&Level1::Shoot_ID_1;
    }

    ///Type 2 - Openers 2
    for (int i=0; i<12; i++) {
        Engine.Enemies.push_back(new Enemy_0);
        Engine.Enemies.back()->Life=4;
        Engine.Enemies.back()->BaseTime=2+i*0.3;
        Engine.Enemies.back()->Move=&Level1::Move_ID_2;
        Engine.Enemies.back()->Loot.push_back(i%2);
        //Bullets
        Engine.Enemies.back()->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
        Engine.Enemies.back()->ShootTable.at(0)->first=0.8;
        Engine.Enemies.back()->ShootTable.at(0)->second=&Level1::Shoot_ID_2;
    }

    ///Type 3 - Web 1
    for (int i=0; i<20; i++) {
        Engine.Enemies.push_back(new Enemy_0);
        Engine.Enemies.back()->Life=6;
        Engine.Enemies.back()->BaseTime=5.50+i;
        Engine.Enemies.back()->Move=&Level1::Move_ID_3;
        Engine.Enemies.back()->Loot.push_back(0);
        //Bullets
        for (int j=0; j<12; j++) {
            Engine.Enemies.back()->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            Engine.Enemies.back()->ShootTable.at(j)->second=&Level1::Shoot_ID_3;
            Engine.Enemies.back()->ShootTable.at(j)->first=j;
        }
    }

    ///Type 4 - Web 2
    for (int i=0; i<20; i++) {
        Engine.Enemies.push_back(new Enemy_0);
        Engine.Enemies.back()->Life=6;
        Engine.Enemies.back()->BaseTime=6.00+i;
        Engine.Enemies.back()->Move=&Level1::Move_ID_4;
        Engine.Enemies.back()->Loot.push_back(1);
        //Bullets
        for (int j=0; j<12; j++) {
            Engine.Enemies.back()->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            Engine.Enemies.back()->ShootTable.at(j)->second=&Level1::Shoot_ID_4;
            Engine.Enemies.back()->ShootTable.at(j)->first=j;
        }
    }

    ///Type 5 - Lines of bullets
    for (int i=0; i<8; i++) {
        Engine.Enemies.push_back(new Enemy_1);
        Engine.Enemies.back()->Life=40;
        if (i<2) Engine.Enemies.back()->BaseTime=33;
        else {
            if (i<4) Engine.Enemies.back()->BaseTime=37.5;
            else {
                if (i<6) Engine.Enemies.back()->BaseTime=42;
                else Engine.Enemies.back()->BaseTime=46.5;
            }
        }
        Engine.Enemies.back()->Move=&Level1::Move_ID_5;
        Engine.Enemies.back()->Loot.push_back(i%2); //0 or 1
        Engine.Enemies.back()->Loot.push_back(i%2==0); //1 or 0
        Engine.Enemies.back()->PrevPosition.y=Engine.Enemies.back()->Position.y=-15;
        switch (i) {
            case 0: Engine.Enemies.back()->Position.x=222; break;
            case 1: Engine.Enemies.back()->Position.x=278; break;
            case 2: Engine.Enemies.back()->Position.x=166; break;
            case 3: Engine.Enemies.back()->Position.x=334; break;
            case 4: Engine.Enemies.back()->Position.x=110; break;
            case 5: Engine.Enemies.back()->Position.x=390; break;
            case 6: Engine.Enemies.back()->Position.x=54; break;
            case 7: Engine.Enemies.back()->Position.x=446; break;
            default: break;
        }
        //Bullets
        for (int j=0; j<5; j++) {
            for (int k=0; k<20; k++) {
                Engine.Enemies.back()->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
                Engine.Enemies.back()->ShootTable.at(j*20+k)->second=&Level1::Shoot_ID_5;
                Engine.Enemies.back()->ShootTable.at(j*20+k)->first=j+2+k*0.03;
            }
        }
    }

    ///Type 6 - Tank
    {
        Engine.Enemies.push_back(new Enemy_1);
        Engine.Enemies.back()->Life=250;
        Engine.Enemies.back()->BaseTime=54;
        Engine.Enemies.back()->Move=&Level1::Move_ID_6;
        Engine.Enemies.back()->PrevPosition.y=Engine.Enemies.back()->Position.y=-30;
        Engine.Enemies.back()->PrevPosition.x=Engine.Enemies.back()->Position.x=250;
        //Loot
        for (short i=0; i<3; i++)
            Engine.Enemies.back()->Loot.push_back(1);
        Engine.Enemies.back()->Loot.push_back(2);
        for (short i=0; i<3; i++)
            Engine.Enemies.back()->Loot.push_back(1);
        //Bullets
        for (short i=0; i<60; i++) {
            Engine.Enemies.back()->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            Engine.Enemies.back()->ShootTable.at(i)->first=5+(0.25*i);
            Engine.Enemies.back()->ShootTable.at(i)->second=&Level1::Shoot_ID_6;
        }
    }

    ///Type 7 - Tank helpers
    {
        //Filling up  a vector with the y-position, which will be extracted randomly. Each element will be extracted once
        std::vector<int> Pos_y;
        for (int i=0; i<20; i++)
            Pos_y.push_back(100+i*5);
        for (int i=0; i<20; i++) {
            Engine.Enemies.push_back(new Enemy_0);
            Engine.Enemies.back()->Life=4;
            Engine.Enemies.back()->BaseTime=55+i;
            int random=Randomizer.GetRandom(0,19-i);
            Engine.Enemies.back()->PrevPosition.y=Engine.Enemies.back()->Position.y=Pos_y.at(random); //Extract a random element from the vector
            Pos_y.erase(Pos_y.begin()+random);
            if (i%2 == 0) {
                Engine.Enemies.back()->Move=&Level1::Move_ID_7_1;
                Engine.Enemies.back()->PrevPosition.x=Engine.Enemies.back()->Position.x=-25;
            }
            else {
                Engine.Enemies.back()->Move=&Level1::Move_ID_7_2;
                Engine.Enemies.back()->PrevPosition.x=Engine.Enemies.back()->Position.x=500;
            }
            //Loot
            Engine.Enemies.back()->Loot.push_back(Randomizer.GetRandom((int)0,(int)1));
            //Bullets
            Engine.Enemies.back()->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            Engine.Enemies.back()->ShootTable.at(0)->first=0.7;
            Engine.Enemies.back()->ShootTable.at(0)->second=&Level1::Shoot_ID_7;
        }
    }

    ///Type 8 - Harmonic movement
    for (int i=0; i<36; i++) {
        Engine.Enemies.push_back(new Enemy_0);
        Engine.Enemies.back()->Life=8;
        Engine.Enemies.back()->BaseTime=74+i*0.75;
        Engine.Enemies.back()->Position=sf::Vector2<float>(65+((i%2)*370),-25);
        Engine.Enemies.back()->Move=&Level1::Move_ID_8;
        Engine.Enemies.back()->Loot.push_back(i%2);
        for (int j=0; j<4; j++) {
            Engine.Enemies.back()->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            Engine.Enemies.back()->ShootTable.at(j)->first=2*(j+1)+(j%2);
            Engine.Enemies.back()->ShootTable.at(j)->second=&Level1::Shoot_ID_8;
        }
    }

    ///Type 9 - Seiga Kaku
    // 4 onde, da destra e da sinistra alternativamente.
    for (int i=0; i<20; i++) {
        Engine.Enemies.push_back(new Enemy_0);
        Engine.Enemies.back()->Life=4;
        Engine.Enemies.back()->BaseTime=108+0.4*i;
        Engine.Enemies.back()->Position=sf::Vector2<float>(-25,-25);
        Engine.Enemies.back()->Move=&Level1::Move_ID_9_1;
        Engine.Enemies.back()->Loot.push_back(1-(i%3==0));
        for (int j=0; j<30; j++) {
            Engine.Enemies.back()->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            Engine.Enemies.back()->ShootTable.at(j)->first=0.5+(j*0.1);
            Engine.Enemies.back()->ShootTable.at(j)->second=&Level1::Shoot_ID_9;
        }
    }
    for (int i=0; i<20; i++) {
        Engine.Enemies.push_back(new Enemy_0);
        Engine.Enemies.back()->Life=4;
        Engine.Enemies.back()->BaseTime=120+0.4*i;
        Engine.Enemies.back()->Position=sf::Vector2<float>(-25,-25);
        Engine.Enemies.back()->Move=&Level1::Move_ID_9_2;
        Engine.Enemies.back()->Loot.push_back(1-(i%3==0));
        for (int j=0; j<30; j++) {
            Engine.Enemies.back()->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            Engine.Enemies.back()->ShootTable.at(j)->first=0.5+(j*0.1);
            Engine.Enemies.back()->ShootTable.at(j)->second=&Level1::Shoot_ID_9;
        }
    }
    /*for (int i=0; i<20; i++) {
        Engine.Enemies.push_back(new Enemy_0);
        Engine.Enemies.back()->Life=4;
        Engine.Enemies.back()->BaseTime=132+0.4*i;
        Engine.Enemies.back()->Position=sf::Vector2<float>(-25,-25);
        Engine.Enemies.back()->Move=&Level1::Move_ID_9_1;
        Engine.Enemies.back()->Loot.push_back(1-(i%3==0));
        for (int j=0; j<30; j++) {
            Engine.Enemies.back()->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            Engine.Enemies.back()->ShootTable.at(j)->first=0.5+(j*0.1);
            Engine.Enemies.back()->ShootTable.at(j)->second=&Level1::Shoot_ID_9;
        }
    }
    for (int i=0; i<20; i++) {
        Engine.Enemies.push_back(new Enemy_0);
        Engine.Enemies.back()->Life=9;
        Engine.Enemies.back()->BaseTime=144+0.4*i;
        Engine.Enemies.back()->Position=sf::Vector2<float>(-25,-25);
        Engine.Enemies.back()->Move=&Level1::Move_ID_9_2;
        Engine.Enemies.back()->Loot.push_back(1-(i%3==0));
        for (int j=0; j<30; j++) {
            Engine.Enemies.back()->ShootTable.push_back(new std::pair<float, void(*)(Enemy*)>);
            Engine.Enemies.back()->ShootTable.at(j)->first=0.5+(j*0.1);
            Engine.Enemies.back()->ShootTable.at(j)->second=&Level1::Shoot_ID_9;
        }
    }*/
}

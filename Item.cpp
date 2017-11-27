#include "Item.h"
#include "Global.h"

Item::Item() : AutoCollected(false) {}

ItemPool::ItemPool(GameEngine* EnginePointer) : pEngine(EnginePointer) {}

ItemPool::~ItemPool() {
    Clear();
}

void ItemPool::BindEngine(GameEngine* EnginePointer) {
    pEngine=EnginePointer;
}

void ItemPool::Clear() {
    for (size_t i=0; i<ItemVector.size(); i++)
        delete ItemVector.at(i);
    ItemVector.clear();
}

void ItemPool::GenerateFallingItems(Enemy* enemy) {
    for (unsigned int i=0; i<enemy->Loot.size(); i++) {
        ItemVector.push_back(new Item);
        ItemVector.back()->ID=(ItemID)enemy->Loot[i];
        ItemVector.back()->Sprite.setTexture(pEngine->ItemImages.at(static_cast<unsigned>(ItemVector.back()->ID)));
        ItemVector.back()->Sprite.setPosition(enemy->Position);
        ItemVector.back()->Sprite.setOrigin(9.5,9.5);
        ItemVector.back()->Angle=double(45+((90/double(enemy->Loot.size()+1)*double(i+1))))*PI/180;
        ItemVector.back()->BaseTime=Engine.PastTime;
        ItemVector.back()->BasePosition=enemy->Position;
    }
}

void ItemPool::GenerateFallingItems(Boss* boss) {
    for (unsigned int i=0; i<boss->LifeBars.back()->Loot.size(); i++) {
        ItemVector.push_back(new Item);
        ItemVector.back()->ID=(ItemID)boss->LifeBars.back()->Loot[i];
        ItemVector.back()->Sprite.setTexture(Engine.ItemImages.at(static_cast<unsigned>(ItemVector.back()->ID)));
        ItemVector.back()->Sprite.setOrigin(9.5,9.5);
        ItemVector.back()->Sprite.setPosition(boss->Position);
        ItemVector.back()->Angle=double(45+((90/(double(boss->LifeBars.back()->Loot.size()+1)))*double(i+1)))*PI/180;
        ItemVector.back()->BaseTime=Engine.PastTime;
        ItemVector.back()->BasePosition=sf::Vector2<float>(boss->Position);
    }
}

void ItemPool::MoveItems() {
    //Move falling items and eventually deletes them
    MyPlayer* Player=pEngine->Player;
    float PastTime=pEngine->PastTime;
    std::uint64_t &Score=pEngine->Score;
    for (unsigned int i=0; i<ItemVector.size();) {
        if (!ItemVector.at(i)->AutoCollected) {
            if (PastTime-ItemVector.at(i)->BaseTime<=1)
                ItemVector.at(i)->Sprite.setPosition(ItemVector.at(i)->BasePosition.x + cos(ItemVector.at(i)->Angle)*120*(PastTime-ItemVector.at(i)->BaseTime) + cos(ItemVector.at(i)->Angle)*1/2*(-120*pow(PastTime-ItemVector.at(i)->BaseTime, 2)),
                                                     ItemVector.at(i)->BasePosition.y - sin(ItemVector.at(i)->Angle)*150*(PastTime-ItemVector.at(i)->BaseTime) - sin(ItemVector.at(i)->Angle)*1/2*(-150*pow(PastTime-ItemVector.at(i)->BaseTime, 2)));
            else
                ItemVector.at(i)->Sprite.setPosition(ItemVector.at(i)->BasePosition.x + cos(ItemVector.at(i)->Angle)*120 + cos(ItemVector.at(i)->Angle)*(-60),
                                                     ItemVector.at(i)->BasePosition.y - sin(ItemVector.at(i)->Angle)*150 - sin(ItemVector.at(i)->Angle)*(-75) + 30*(PastTime-ItemVector.at(i)->BaseTime-1) + 40*pow(PastTime-ItemVector.at(i)->BaseTime-1, 2));
        }
        else {
            float Movement=450*Engine.FrameTime;
            float Angle=-atan2f(Engine.Player->Position.y-ItemVector.at(i)->Sprite.getPosition().y, Engine.Player->Position.x-ItemVector.at(i)->Sprite.getPosition().x);
            ItemVector.at(i)->Sprite.move(cos(Angle)*Movement, -sin(Angle)*Movement);
        }

        //If the Item is no longer catchable
        if (ItemVector.at(i)->Sprite.getPosition().x < 15 || ItemVector.at(i)->Sprite.getPosition().x > 485 ||  ItemVector.at(i)->Sprite.getPosition().y > 585) {
            delete ItemVector.at(i);
            ItemVector.erase(ItemVector.begin()+i);
        }
        //If the player caught the Item
        else if (pow(ItemVector.at(i)->Sprite.getPosition().x-Player->Position.x , 2) + pow(ItemVector.at(i)->Sprite.getPosition().y-Player->Position.y , 2) <= pow(Player->SelectedShotType.HitboxRadius+40 , 2)) {
            Play(ITEMCOLLECTED);
            switch (ItemVector.at(i)->ID) {
                case ItemID::POWER_ITEM:
                    Player->PauseGauge=Player->PauseGauge>0.5?1:Player->PauseGauge+0.5;
                    if (Player->Power < 1000) {
                        Player->Power=min(Player->Power+(ItemVector.at(i)->AutoCollected?10:5),1000u);
                        break;
                    }
                case ItemID::SCORE_ITEM:
                    Engine.Score += (ItemVector.at(i)->AutoCollected ? 15000 : (Player->Charge*10.0) *(Engine.Player->ChargeTime>0?5:1));
                    Engine.Score -= Engine.Score%10;
                    break;
                case ItemID::BOMB_ITEM:
                    if (Player->Bombs < 7)
                        ++Player->Bombs;
                    else
                        Score+=25000;
                    break;
                case ItemID::LIFE_ITEM:
                    GainLife();
                    break;
                default:
                    break;
            }
            delete ItemVector.at(i);
            ItemVector.erase(ItemVector.begin()+i);
        }
        //Else
        else {
            ++i;
        }
    }
}

void ItemPool::AutoCollect() {
    for (size_t i=0; i<ItemVector.size(); ++i)
        ItemVector[i]->AutoCollected=true;
}

void ItemPool::GainLife() {
    Play(LIFEGAINED);
    if (pEngine->Player->Lives < 8) {
        ++pEngine->Player->Lives;
    }
    else if (pEngine->Player->Bombs < 7)
        ++pEngine->Player->Bombs;
    else
        pEngine->Score+=50000;
}

void ItemPool::DrawItems() {
    for (unsigned int i=0; i<ItemVector.size(); i++) {
        MainWindow.draw(ItemVector.at(i)->Sprite);
    }
}

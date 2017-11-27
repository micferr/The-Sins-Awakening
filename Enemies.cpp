#include "Enemies.h"
#include "Global.h"

void Foe::SetImage(sf::Texture &texture) {
    unsigned width=texture.getSize().x, height=texture.getSize().y;
    for (int i=0; i<4; i++) {
        Sprite[i].setTexture(texture);
        Sprite[i].setTextureRect(sf::IntRect(width/4*i, 0, width/4, height));
        Sprite[i].setOrigin(Sprite[i].getLocalBounds().width/2, Sprite[i].getLocalBounds().height/2);
    }
}

Enemy::Enemy() {
    PrevPosition=Position=sf::Vector2<float>(-100,-100);
    for (short i=0; i<4; ++i)
        Sprite[i].setPosition(-100,-100);
}

void Enemy::Draw() {
    float f=fmodf(Engine.PastTime-BaseTime,0.4f);
    short w=f>=0.2f?1:0;
    if (Position.x == PrevPosition.x)
        MainWindow.draw(Sprite[w]);
    else if (Position.x < PrevPosition.x)
        MainWindow.draw(Sprite[2]);
    else
        MainWindow.draw(Sprite[3]);
}

Enemy_0::Enemy_0() {
    SetImage(Engine.EnemyImages[0]);
    for (auto i=0; i<4; ++i) Sprite[i].setColor(sf::Color(192,64,64));
    Radius=ENEMY_0_RADIUS;
}

Enemy_1::Enemy_1() {
    SetImage(Engine.EnemyImages[1]);
    Radius=ENEMY_1_RADIUS;
}

Enemy_2::Enemy_2() {
    SetImage(Engine.EnemyImages[2]);
    Radius=ENEMY_2_RADIUS;

    AuraSprite.setTexture(Engine.BossAuraImage);
    AuraSprite.setOrigin(Engine.BossAuraImage.getSize().x/2,Engine.BossAuraImage.getSize().y/2);
    AuraSprite.setColor(sf::Color(64,64,64));
}

void Enemy_2::Draw() {
    AuraSprite.setPosition(Position);
    MainWindow.draw(AuraSprite);
    Enemy::Draw();
}

Boss::Boss() {
    Position=sf::Vector2<float>(-1000,-1000);
    Radius=25;
    Bullets.reserve(2000);
    AuraSprite.setTexture(Engine.BossAuraImage);
    AuraSprite.setOrigin(Engine.BossAuraImage.getSize().x/2, Engine.BossAuraImage.getSize().y/2);
    AuraSprite.setPosition(Position);
}

Boss::~Boss() {
    for (unsigned i=0; i<LifeBars.size(); ++i) {
        for (unsigned j=0; j<LifeBars[i]->ShootTable.size(); ++j)
            delete LifeBars[i]->ShootTable[j];
        delete LifeBars[i];
    }
    for (unsigned i=0; i<Bullets.size(); ++i)
        delete Bullets[i];
}

void Boss::Draw() {
    AuraSprite.setPosition(Position);
    MainWindow.draw(AuraSprite);

    float f=fmodf(Engine.PastTime,0.4f);
    short w=f>=0.2f?1:0;
    if (Position.x == PrevPosition.x)
        MainWindow.draw(Sprite[w]);
    else if (Position.x < PrevPosition.x)
        MainWindow.draw(Sprite[2]);
    else
        MainWindow.draw(Sprite[3]);
}

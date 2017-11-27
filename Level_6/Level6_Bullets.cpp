#include "Level6.h"

void Level6::BulletMove_ID_1(Bullet* bullet) {
    float Speed=Engine.PastTime-bullet->BaseTime<=0.5?200:100;
    float Movement=Speed*Engine.FrameTime;
    bullet->Travel(cos(bullet->Angle)*Movement, -sin(bullet->Angle)*Movement);
}

void Level6::BulletMove_ID_2(Bullet* bullet) {
    float Movement=260*Engine.FrameTime;
    bullet->Travel(cos(bullet->Angle)*Movement, -sin(bullet->Angle)*Movement);
}

void Level6::BulletMove_ID_3(Bullet* bullet) {
    float Movement=280*Engine.FrameTime;
    bullet->Travel(cos(bullet->Angle)*Movement, -sin(bullet->Angle)*Movement);
}

void Level6::BulletMove_ID_4(Bullet* bullet) {
    float Movement=300*Engine.FrameTime;
    bullet->Travel(cos(bullet->Angle)*Movement, -sin(bullet->Angle)*Movement);
}

void Level6::BulletMove_ID_5(Bullet* bullet) {
    float Movement=100*Engine.FrameTime;
    bullet->Travel(cos(bullet->Angle)*Movement, -sin(bullet->Angle)*Movement);
}

void Level6::BulletMove_ID_6_1(Bullet* bullet) {
    float Movement=230*Engine.FrameTime;
    bullet->Travel(cos(bullet->Angle)*Movement, -sin(bullet->Angle)*Movement);
}

void Level6::BulletMove_ID_6_2(Bullet* bullet) {
    float Movement=(Engine.PastTime-bullet->BaseTime<1?200:60)*Engine.FrameTime;
    bullet->Travel(cos(bullet->Angle)*Movement,-sin(bullet->Angle)*Movement);
}

void Level6::BulletMove_ID_7(Bullet* bullet) {
    bullet->Travel(70*Engine.FrameTime);
}

void Level6::BulletMove_ID_8_1(Bullet* bullet) {
    float Movement=(Engine.PastTime-bullet->BaseTime)*140;
    bullet->SetPosition(250+cos(bullet->Angle)*Movement, 200-sin(bullet->Angle)*Movement);
}

void Level6::BulletMove_ID_8_3(Bullet* bullet) {
    bullet->Travel(80*Engine.FrameTime);
}

void Level6::BulletMove_ID_9(Bullet* bullet) {
    bullet->Travel(170*Engine.FrameTime);
}

void Level6::BulletMove_ID_10(Bullet* bullet) {
    bullet->TravelAtSpeed(310);
    bullet->SetRadius(9+40*(Engine.PastTime-bullet->BaseTime));
}

void Level6::BulletMove_ID_11(Bullet* bullet) {
    bullet->TravelAtSpeed(240);
}

void Level6::BulletMove_ID_12_FIRSTPHASE(Bullet* bullet) {
    if (Engine.PastTime-bullet->BaseTime>=1.5) {
        bullet->SetAngle(-atan2f(Engine.Player->Position.y-bullet->Sprite.getPosition().y, Engine.Player->Position.x-bullet->Sprite.getPosition().x));
        bullet->SetMoveFunc(BulletMove_ID_12_SECONDPHASE);
        bullet->Move(bullet);
    }
    else {
        bullet->TravelAtSpeed(120);
    }
}

void Level6::BulletMove_ID_12_SECONDPHASE(Bullet* bullet) {
    bullet->TravelAtSpeed(210);
}

void Level6::BulletMove_ID_13(Bullet* bullet) {
    bullet->TravelAtSpeed(140);
}

/// - BOSS

void Level6::BossBulletMove_ID_1(SuperBullet* sbullet) {
    float Movement=270*(Engine.PastTime-sbullet->BaseTime);
    sbullet->SetPosition(250+Movement*cos(sbullet->Angle), 150+Movement*-sin(sbullet->Angle));
}

bool Level6::DeleteBullet_ID_6_1(SuperBullet* sbullet) {
    float BaseAngle=Randomizer.GetRandom(0.f,1.f);
    if (Engine.PastTime-sbullet->BaseTime>=1.3) {
        for (unsigned i=0; i<9; ++i) {
            Engine.LevelBoss->Bullets.push_back(new SpeedBullet(Randomizer.GetRandom(25.f,50.f)));
            SuperBullet* newbullet=Engine.LevelBoss->Bullets.back();
            newbullet->SetImage(BULLET_1_RED);
            newbullet->SetRadius(9);
            newbullet->SetPosition(sbullet->Sprite.getPosition());
            newbullet->SetAngle(BaseAngle+2*PI/9*i);
            newbullet->SetDeleteFunc(Level6::DeleteBullet_ID_6_EXPLOSION);
            newbullet->SetBaseTime(Engine.PastTime);
        }
        /*Engine.ExplosionSprites.push_back(new sf::Sprite);
        sf::Sprite* expl=Engine.ExplosionSprites.back();
        expl->setTexture(Engine.ExplosionImages[1]);
        expl->setOrigin(26,26);
        expl->setPosition(sbullet->Sprite.getPosition());
        expl->setScale(2,2);*/
        Engine.VisualEffects.AddEffect(new EffectExplosion(sbullet->Sprite.getPosition().x, sbullet->Sprite.getPosition().y, 50, 0.4));
        return true;
    }
    else return false;
}

bool Level6::DeleteBullet_ID_6_EXPLOSION(SuperBullet* sbullet) {
    float x=sbullet->Sprite.getPosition().x, y=sbullet->Sprite.getPosition().y;
    return Engine.PastTime-sbullet->BaseTime>=5.f && (x<15 || x>485 || y<15 || y>585);
}

void Level6::BossBulletMove_ID_8_2(SuperBullet* sbullet) {
    float time=Engine.PastTime-sbullet->BaseTime;
    float Movement=120*time-50*time*time;
    sbullet->SetPosition(Engine.LevelBoss->Position.x + Movement*cos(sbullet->Angle),
                         Engine.LevelBoss->Position.y + Movement*-sin(sbullet->Angle));
}

bool Level6::DeleteBullet_ID_8_2(SuperBullet* sbullet) {
    if (Engine.PastTime-sbullet->BaseTime>=1) {
        for (unsigned i=0; i<44; ++i) {
            Engine.LevelBoss->Bullets.push_back(new SpeedBullet(80));
            SpeedBullet* ssbullet=dynamic_cast<SpeedBullet*>(Engine.LevelBoss->Bullets.back());
            ssbullet->SetImage(BULLET_2_RED);
            ssbullet->SetRadius(7);
            ssbullet->SetPosition(sbullet->Sprite.getPosition());
            ssbullet->SetAngle(2*PI/36*i);
        }
        return true;
    }
    else return false;
}

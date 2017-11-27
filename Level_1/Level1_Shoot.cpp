#include "Level1.h"

//Bullet creation

void Level1::Shoot_ID_1(Enemy* enemy) {
    Engine.EnemyBullets.push_back(new Bullet(250));
    Bullet* bullet=Engine.EnemyBullets.back();
    bullet->SetImage(BULLET_1_RED);
    bullet->SetRadius(10);
    bullet->SetPosition(120, 206);
    bullet->SetAngle(-atan2f(Engine.Player->Position.y-206 , Engine.Player->Position.x-120));
}

void Level1::Shoot_ID_2(Enemy* enemy) {
    Engine.EnemyBullets.push_back(new Bullet(250));
    Bullet* bullet=Engine.EnemyBullets.back();
    bullet->SetImage(BULLET_1_RED);
    bullet->SetRadius(10);
    bullet->SetPosition(380, 206);
    bullet->SetAngle(-atan2f(Engine.Player->Position.y-206 , Engine.Player->Position.x-380));
}

void Level1::Shoot_ID_3(Enemy *enemy) {
    Engine.EnemyBullets.push_back(new Bullet(175));
    Bullet* bullet=Engine.EnemyBullets.back();
    bullet->SetImage(BULLET_1_BLUE);
    bullet->SetPosition(25,int(Engine.PastTime-enemy->BaseTime)*50);
    bullet->SetRadius(13);
    bullet->SetAngle(-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x));
}

void Level1::Shoot_ID_4(Enemy* enemy) {
    Engine.EnemyBullets.push_back(new Bullet(175));
    Bullet* bullet=Engine.EnemyBullets.back();
    bullet->SetImage(BULLET_1_BLUE);
    bullet->SetPosition(475,int(Engine.PastTime-enemy->BaseTime)*50+25);
    bullet->SetRadius(13);
    bullet->SetAngle(-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x));
}

void Level1::Shoot_ID_5(Enemy* enemy) {
    Engine.EnemyBullets.push_back(new Bullet(250));
    Bullet* bullet=Engine.EnemyBullets.back();
    bullet->SetImage(BULLET_2_GREY);
    bullet->SetPosition(enemy->Position);
    bullet->SetAngle(-atan2f(Engine.Player->Position.y-150, Engine.Player->Position.x-enemy->Position.x));
    bullet->SetRadius(15);
}

void Level1::Shoot_ID_6(Enemy* enemy) {
    float angle=-7*PI/180*(Engine.PastTime-enemy->BaseTime)*32; //Auff... //WAT, indeed //So much testing
    for (int i=0; i<5; i++) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullet=Engine.EnemyBullets.back();
        bullet->SetImage(BULLET_1_GREEN);
        bullet->SetPosition(enemy->Position);
        bullet->SetAngle(angle+PI/2.5*i);
        bullet->SetRadius(8);
        bullet->SetMoveFunc(Level1::BulletMove_ID_6);
        bullet->SetBaseTime(Engine.PastTime);
    }
}

void Level1::Shoot_ID_7(Enemy* enemy) {
    float Angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x);
    for (int i=0; i<3; i++) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullet=Engine.EnemyBullets.back();
        bullet->SetImage(BULLET_1_RED);
        bullet->SetPosition(enemy->Position);
        bullet->SetAngle(Angle+(-6+6*i)*PI/180);
        bullet->SetRadius(20);
        bullet->SetMoveFunc(Level1::BulletMove_ID_7);
        bullet->SetBaseTime(Engine.PastTime);
    }
}

void Level1::Shoot_ID_8 (Enemy* enemy) {
    float angle=-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x);
    for (short i=0; i<3; i++) {
        Engine.EnemyBullets.push_back(new Bullet);
        Bullet* bullet=Engine.EnemyBullets.back();
        bullet->SetImage(BULLET_1_YELLOW);
        bullet->SetPosition(enemy->Position);
        if (i==0) {
            bullet->SetAngle(angle);
            bullet->SetRadius(15);
        }
        else {
            bullet->SetAngle(angle-PI/8+PI/12*i);
            bullet->SetRadius(10);
        }
        bullet->SetMoveFunc(Level1::BulletMove_ID_8);
        bullet->SetBaseTime(Engine.PastTime);
    }
}

void Level1::Shoot_ID_9 (Enemy* enemy) {
    Engine.EnemyBullets.push_back(new Bullet(400));
    Bullet* bullptr=Engine.EnemyBullets.back();
    bullptr->SetImage(BULLET_2_RED);
    bullptr->SetPosition(enemy->Position);
    bullptr->SetAngle(-atan2f(Engine.Player->Position.y-enemy->Position.y, Engine.Player->Position.x-enemy->Position.x));
    bullptr->SetRadius(9);
}

void Level1::BossShoot_ID_1_1 (Boss* boss, float basetime) {
    Engine.LevelBoss->Bullets.push_back(new SuperBullet(150));
    SuperBullet* bullptr=Engine.LevelBoss->Bullets.back();
    bullptr->SetImage(BULLET_1_RED_WIDE);
    bullptr->SetPosition(boss->Position);
    bullptr->SetAngle(-atan2f(Engine.Player->Position.y-boss->Position.y, Engine.Player->Position.x-boss->Position.x));
    bullptr->SetRadius(130);
    bullptr->Sprite.setScale(132/25.f/6.f,132/25.f/6.f);
}

void Level1::BossShoot_ID_1_2 (Boss* boss, float basetime) {
    BossShoot_ID_1_1(boss, basetime);
}

void Level1::BossShoot_ID_2_1 (Boss* boss, float basetime) {
    int x[2]={90,410};
    for (unsigned short i=0; i<2; i++) {
        Engine.LevelBoss->Bullets.push_back(new SuperBullet);
        SuperBullet* bullptr=Engine.LevelBoss->Bullets.back();
        bullptr->SetImage(BULLET_3_WIDE);
        bullptr->SetImageColor(128,204,204);
        bullptr->SetPosition(x[i], -120);
        bullptr->SetRadius(65);
        bullptr->Sprite.setScale(67.f/25.f/6,67.f/25.f/6);
        bullptr->SetBaseTime(basetime);
        bullptr->SetMoveFunc(Level1::BossBulletMove_ID_2);
        bullptr->SetDeleteFunc(Level1::DeleteBullet_ID_2);
    }
}

void Level1::BossShoot_ID_2_2 (Boss* boss, float basetime) {
    Engine.LevelBoss->Bullets.push_back(new SuperBullet);
    SuperBullet* bullptr=Engine.LevelBoss->Bullets.back();
    bullptr->SetImage(BULLET_3_WIDE);
    bullptr->SetImageColor(128,204,204);
    bullptr->SetPosition(160,-120);
    bullptr->SetRadius(115);
    bullptr->Sprite.setScale(120.f/25.f/6.f,120.f/25.f/6.f);
    bullptr->SetBaseTime(basetime);
    bullptr->SetMoveFunc(Level1::BossBulletMove_ID_2);
    bullptr->SetDeleteFunc(Level1::DeleteBullet_ID_2);
}

void Level1::BossShoot_ID_2_3 (Boss* boss, float basetime) {
    Engine.LevelBoss->Bullets.push_back(new SuperBullet);
    SuperBullet* bullptr=Engine.LevelBoss->Bullets.back();
    bullptr->SetImage(BULLET_3_WIDE);
    bullptr->SetImageColor(128,204,204);
    bullptr->SetPosition(340,-120);
    bullptr->SetRadius(115);
    bullptr->Sprite.setScale(120.f/25.f/6.f,120.f/25.f/6.f);
    bullptr->SetBaseTime(basetime);
    bullptr->SetMoveFunc(Level1::BossBulletMove_ID_2);
    bullptr->SetDeleteFunc(Level1::DeleteBullet_ID_2);
}

void Level1::BossShoot_ID_3 (Boss* boss, float basetime) {
    Engine.LevelBoss->Bullets.push_back(new SuperBullet);
    SuperBullet* bullptr=Engine.LevelBoss->Bullets.back();
    bullptr->SetImage(BULLET_1_BLUE_WIDE);
    bullptr->SetImageColor(255,255,255,128);
    bullptr->SetRadius(72);
    bullptr->SetPosition(boss->Position.x, 300);
    bullptr->Deletable=false;
    bullptr->SetMoveFunc(Level1::BossBulletMove_ID_3_3);
    for (unsigned short i=0; i<6; i++) {
        Engine.LevelBoss->Bullets.push_back(new SuperBullet);
        SuperBullet* bullptr=Engine.LevelBoss->Bullets.back();
        bullptr->SetImage(BULLET_1_BLUE_WIDE);
        bullptr->SetPosition(boss->Position.x, 300);
        bullptr->SetAngle(i*PI/3);
        bullptr->SetRadius(72);
        bullptr->Deletable=false;
        bullptr->SetBaseTime(basetime);
        bullptr->SetMoveFunc(Level1::BossBulletMove_ID_3_1);
    }
    for (unsigned int i=0; i<6; i++) {
        Engine.LevelBoss->Bullets.push_back(new SuperBullet);
        SuperBullet* bullptr=Engine.LevelBoss->Bullets.back();
        bullptr->SetImage(BULLET_1_BLUE_WIDE);
        bullptr->SetPosition(boss->Position);
        bullptr->SetAngle(PI/3*i);
        bullptr->SetRadius(72);
        bullptr->Deletable=false;
        bullptr->SetBaseTime(basetime);
        bullptr->SetMoveFunc(Level1::BossBulletMove_ID_3_2);
    }
    for (auto i : Engine.LevelBoss->Bullets)
        i->Sprite.setScale(72/25.f/6.f,72/25.f/6.f);
}

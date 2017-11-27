#ifndef LEVEL4_H
#define LEVEL4_H

#include "..\GameEngine.h"
#include "..\Global.h"

namespace Level4 {
    void CreateEnemies ();

    void Move_ID_1_1 (Enemy* enemy);
    void Move_ID_1_2 (Enemy* enemy);
    void Move_ID_2_1 (Enemy* enemy);
    void Move_ID_2_2 (Enemy* enemy);
    void Move_ID_3_1 (Enemy* enemy);
    void Move_ID_3_2 (Enemy* enemy);
    void Move_ID_4_1 (Enemy* enemy);
    void Move_ID_4_2 (Enemy* enemy);
    void Move_ID_5_1 (Enemy* enemy);
    void Move_ID_5_2 (Enemy* enemy);
    void Move_ID_6_1 (Enemy* enemy);
    void Move_ID_6_2 (Enemy* enemy);
    void Move_ID_7_1 (Enemy* enemy);
    void Move_ID_7_2 (Enemy* enemy);
    void Move_ID_8 (Enemy* enemy);
    void Move_ID_9_1_START (Enemy* enemy);
    void Move_ID_9_2_START (Enemy* enemy);
    void Move_ID_9_1_GO (Enemy* enemy);
    void Move_ID_9_2_GO (Enemy* enemy);
    void Move_ID_9_NOTHING (Enemy* enemy);
    void Move_ID_10_1 (Enemy* enemy);
    void Move_ID_10_2 (Enemy* enemy);
    void Move_ID_11_1 (Enemy* enemy);
    void Move_ID_11_2 (Enemy* enemy);

    void Shoot_ID_1 (Enemy* enemy);
    void Shoot_ID_2 (Enemy* enemy);
    void Shoot_ID_3 (Enemy* enemy);
    void Shoot_ID_4_1 (Enemy* enemy);
    void Shoot_ID_4_2 (Enemy* enemy);
    void Shoot_ID_5 (Enemy* enemy); //This is what the enemy shoots (see BulletMove_ID_5_BOMB)
    void Shoot_ID_6 (Enemy* enemy);
    void Shoot_ID_7 (Enemy* enemy);
    void Shoot_ID_8_1 (Enemy* enemy);
    void Shoot_ID_8_2 (Enemy* enemy);
    void Shoot_ID_9 (Enemy* enemy);
    void Shoot_ID_10_1 (Enemy* enemy);
    void Shoot_ID_10_2 (Enemy* enemy);
    void Shoot_ID_11_1 (Enemy* enemy);
    void Shoot_ID_11_2 (Enemy* enemy);

    void BulletMove_ID_1_1 (Bullet* bullet);
    void BulletMove_ID_1_2 (Bullet* bullet);
    void BulletMove_ID_2 (Bullet* bullet);
    void BulletMove_ID_3_1 (Bullet* bullet);
    void BulletMove_ID_3_2 (Bullet* bullet);
    void BulletMove_ID_4 (Bullet* bullet);
    void BulletMove_ID_5_BOMB (Bullet* bullet);
        void BulletMove_ID_5_START_EXPLOSION (Bullet* bullet);
    void BulletMove_ID_5_EXPLOSION (Bullet* bullet);
    void BulletMove_ID_6 (Bullet* bullet);
    void BulletMove_ID_7 (Bullet* bullet);
    void BulletMove_ID_8_1 (Bullet* bullet);
    void BulletMove_ID_8_2 (Bullet* bullet);
    void BulletMove_ID_9 (Bullet* bullet);
    void BulletMove_ID_10 (Bullet* bullet);
    void BulletMove_ID_11_1_START (Bullet* bullet);
    void BulletMove_ID_11_1_GOSTRAIGHT (Bullet* bullet);
    void BulletMove_ID_11_2 (Bullet* bullet);

    void CreateBarOne ();
    void BossMove_ID_1 (Boss* LevelBoss);
    void BossShoot_ID_1_SETDATA (Boss* LevelBoss, float basetime);
    void BossShoot_ID_1_1 (Boss* LevelBoss, float basetime);
    void BossShoot_ID_1_2 (Boss* LevelBoss, float basetime); //Close-range
    void BossBulletMove_ID_1_1_CLOCKWISE (SuperBullet* sbullet);
    void BossBulletMove_ID_1_1_ANTICLOCKWISE (SuperBullet* sbullet);
    void BossBulletMove_ID_1_2 (SuperBullet* sbullet);
    bool DeleteBullet_ID_1_1 (SuperBullet* sbullet);
    bool DeleteBullet_ID_1_2 (SuperBullet* sbullet);
    //
    void CreateBarTwo ();
    void BossMove_ID_2 (Boss* LevelBoss);
    void BossShoot_ID_2_SETDATA (Boss* LevelBoss, float basetime); //[0] = angle for Shoot2
    void BossShoot_ID_2_1 (Boss* LevelBoss, float basetime);
    void BossShoot_ID_2_2 (Boss* LevelBoss, float basetime); //Close-range attack (No delete)
    void BossBulletMove_ID_2_1_FIRSTPART_1 (SuperBullet* sbullet);
    void BossBulletMove_ID_2_1_FIRSTPART_2 (SuperBullet* sbullet);
    void BossBulletMove_ID_2_1_SECONDPART_1 (SuperBullet* sbullet);
    void BossBulletMove_ID_2_1_SECONDPART_2 (SuperBullet* sbullet);
    void BossBulletMove_ID_2_2 (SuperBullet* sbullet);
    bool DeleteBullet_ID_2_1_FIRSTPART (SuperBullet* sbullet);
    bool DeleteBullet_ID_2_1_SECONDPART (SuperBullet* sbullet);
    bool DeleteBullet_ID_2_2 (SuperBullet* sbullet);
    //
    void CreateBarThree ();
    void BossMove_ID_3 (Boss* LevelBoss);
    void BossShoot_ID_3_SETDATA (Boss* LevelBoss, float basetime); //[0] - Angle of Shoot_1 //[1] - Missile to left(-1) or right(+1)?
    void BossShoot_ID_3_1 (Boss* LevelBoss, float basetime); //Main pattern
    void BossShoot_ID_3_2 (Boss* LevelBoss, float basetime); //Missile - SpeedBullet
    void BossShoot_ID_3_3 (Boss* LevelBoss, float basetime); //Close-range
    void BossBulletMove_ID_3_1 (SuperBullet* sbullet);
    void BossBulletMove_ID_3_2_FIRSTPART (SuperBullet* sbullet);
    void BossBulletMove_ID_3_2_SECONDPART (SuperBullet* sbullet);
    bool DeleteBullet_ID_3_1 (SuperBullet* sbullet);
    bool DeleteBullet_ID_3_2 (SuperBullet* sbullet);
    //
    void CreateBarFour ();
    void BossMove_ID_4 (Boss* LevelBoss);
    void BossShoot_ID_4_SETDATA (Boss* LevelBoss, float basetime);
    void BossShoot_ID_4_1 (Boss* LevelBoss, float basetime);
    void BossShoot_ID_4_2 (Boss* LevelBoss, float basetime); //Close-range
    void BossBulletMove_ID_4_1 (SuperBullet* sbullet);
    bool DeleteBullet_ID_4_1 (SuperBullet* sbullet);
    //
    void CreateBarFive ();
    void BossMove_ID_5 (Boss* LevelBoss);
    void BossShoot_ID_5_1 (Boss* LevelBoss, float basetime); //Two balls
    void BossShoot_ID_5_2 (Boss* LevelBoss, float basetime); //Regular shoot
    void BossShoot_ID_5_3 (Boss* LevelBoss, float basetime); //Shoot by two balls
    void BossShoot_ID_5_4 (Boss* LevelBoss, float basetime); //Usual close-range
    void BossBulletMove_ID_5_1 (SuperBullet* sbullet);
    void BossBulletMove_ID_5_2_1 (SuperBullet* sbullet);
    void BossBulletMove_ID_5_2_2 (SuperBullet* sbullet);
    void BossBulletMove_ID_5_3 (SuperBullet* sbullet);
    bool DeleteBullet_ID_5_1 (SuperBullet* sbullet);
    bool DeleteBullet_ID_5_2 (SuperBullet* sbullet);
    bool DeleteBullet_ID_5_3 (SuperBullet* sbullet);
    //
    void CreateBarSix ();
    void BossMove_ID_6_PREPARE (Boss* LevelBoss);
    void BossMove_ID_6_GO (Boss* LevelBoss);
    void BossShoot_ID_6_1 (Boss* LevelBoss, float basetime); //Huge flame
    void BossShoot_ID_6_2 (Boss* LevelBoss, float basetime); //Little flames
    void BossBulletMove_ID_6_1 (SuperBullet* sbullet);
    void BossBulletMove_ID_6_2 (SuperBullet* sbullet);
    bool DeleteBullet_ID_6_1 (SuperBullet* sbullet);
    bool DeleteBullet_ID_6_2 (SuperBullet* sbullet);
}

#define CREATE_LEVEL_FOUR() \
    imagebuffer=Reader.getFile("Boss4.png"); \
    imagesize=Reader.getEntryFileSize("Boss4.png"); \
    LevelBoss->Texture.loadFromMemory(imagebuffer, imagesize); \
    LevelBoss->SetImage(LevelBoss->Texture); \
    delete[] imagebuffer; \
    \
    imagebuffer=Reader.getFile("Level4Background.png"); \
    imagesize=Reader.getEntryFileSize("Level4Background.png"); \
    LevelBackgroundImage[0].loadFromMemory(imagebuffer, imagesize); \
    delete[] imagebuffer; \
    \
    imagebuffer=Reader.getFile("Level4BossBackground.png"); \
    imagesize=Reader.getEntryFileSize("Level4BossBackground.png"); \
    LevelBackgroundImage[1].loadFromMemory(imagebuffer,imagesize); \
    delete[] imagebuffer; \
    \
    imagebuffer=Reader.getFile("CharPortrait4blur.png"); \
    imagesize=Reader.getEntryFileSize("CharPortrait4blur.png"); \
    BossPortraitImage.loadFromMemory(imagebuffer, imagesize); \
    delete[] imagebuffer; \
    \
    Level4::CreateEnemies(); \
    \
    LevelTime=168; \
    CurrentLevel=LEVEL_FOUR; \
    LevelMusicID=LEVEL4_THEME; \
    BossMusicID=BOSS4_THEME; \
    LevelBoss->AuraSprite.setColor(sf::Color(255,192,203)); \
    \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("He he, I'll admit my defeat. Go on Hero, let's see\nhow far your values will bring you!", RIGHT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("I would have never thought there could be a man\nwho could defeat me.", RIGHT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("Wow, Hero, congratulations!", RIGHT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("But you lost anyway, he he. I have to go now.\nBye bye!", LEFT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("You speak so, insolent girl, but my power extends\nover all humans, not just men.", RIGHT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("You see? I was right! If hundreds of men failed,\nthen it was a girl's duty to beat you!", LEFT_TALKING)); \
    \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Well then, let's fight! We'll be betting on human\ndignity!", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Sure, I will show you the true strenght of\nhumans!", LEFT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Are you sure you want to fight me?", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("So you're saying you could resist me? Stop for a\nmoment and think about it.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("You're wrong! People are not that simple-minded!\nEveryone has his own personality, hopes, beliefs...", LEFT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("No matter how hard they try, there's no way\nthey may put their primordial instincts away.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("It doesn't matter what they say, in the end\nhumans are just animals.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("It was. Men are so weak-willed, they couldn't\nstand a chance against my powers.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("What are you talking about? This is the king's\ncastle!", LEFT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Welcome to my humble abode, Hero! Please,\nenjoy your stay!", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Fine then, if you want to fight that much, I won't\ndeny you an end in this splendid castle!", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Because I'm not a man, maybe?", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Many men have fallen fighting against me, why\nwould you not?", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("I'm sorry, but there is no chance that a girl like\nyou could defeat someone as powerful as I am.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("A Sin?! This means I'll have to defeat you!", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Feelings, emotions, and, in particular, desires.\nControlling these means controlling humans.\nAnd that is my true nature.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Let me introduce myself properly. I am Lust, one\nof the Seven Deadly Sins, with power over the\nhuman nature.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Don't worry, it is because this castle has just got\nmine. It was property of the king, but I defeated\nhim.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Your? Sorry, but... who are you? I've been\nhere a couple of times, but I don't really\nremember having met you.", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Hello, little girl, and welcome to my home.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Hello there!", LEFT_TALKING)); \
    \
    Level4::CreateBarSix(); \
    Level4::CreateBarFive(); \
    Level4::CreateBarFour(); \
    Level4::CreateBarThree(); \
    Level4::CreateBarTwo(); \
    Level4::CreateBarOne();

#endif // LEVEL4_H

#ifndef LEVEL5_H
#define LEVEL5_H

#include "..\GameEngine.h"
#include "..\Global.h"

namespace Level5 {
    void CreateEnemies();

    void Move_ID_1_1 (Enemy* enemy);
    void Move_ID_1_2 (Enemy* enemy);
    void Move_ID_2_1 (Enemy* enemy);
    void Move_ID_2_2 (Enemy* enemy);
    void Move_ID_3 (Enemy* enemy);
    void Move_ID_4 (Enemy* enemy);
    void Move_ID_5_1 (Enemy* enemy);
    void Move_ID_5_2 (Enemy* enemy);
    void Move_ID_6_1 (Enemy* enemy);
    void Move_ID_6_2 (Enemy* enemy);
    void Move_ID_7_1 (Enemy* enemy);
    void Move_ID_7_2 (Enemy* enemy);
    void Move_ID_8_1 (Enemy* enemy);
    void Move_ID_8_2 (Enemy* enemy);
    void Move_ID_9_1 (Enemy* enemy);
    void Move_ID_9_2 (Enemy* enemy);
    void Move_ID_10_1 (Enemy* enemy);
    void Move_ID_10_2 (Enemy* enemy);
    void Move_ID_11 (Enemy* enemy);
    void Move_ID_12_1 (Enemy* enemy);
    void Move_ID_12_2 (Enemy* enemy);
    void Move_ID_13_1 (Enemy* enemy);
    void Move_ID_13_2 (Enemy* enemy);
    void Move_ID_14_1 (Enemy* enemy);
    void Move_ID_14_2 (Enemy* enemy);
    void Move_ID_15_1 (Enemy* enemy);
    void Move_ID_15_2 (Enemy* enemy);
    void Move_ID_16_1 (Enemy* enemy);
    void Move_ID_16_2 (Enemy* enemy);
    void Move_ID_17 (Enemy* enemy);
    void Move_ID_18_1 (Enemy* enemy);
    void Move_ID_18_2 (Enemy* enemy);

    void Shoot_ID_1 (Enemy* enemy);
    void Shoot_ID_2 (Enemy* enemy);
    void Shoot_ID_3_1 (Enemy* enemy);
    void Shoot_ID_3_2 (Enemy* enemy);
    void Shoot_ID_4 (Enemy* enemy);
    void Shoot_ID_5 (Enemy* enemy);
    void Shoot_ID_6 (Enemy* enemy);
    void Shoot_ID_7 (Enemy* enemy);
    void Shoot_ID_8 (Enemy* enemy);
    void Shoot_ID_9 (Enemy* enemy);
    void Shoot_ID_10 (Enemy* enemy);
    void Shoot_ID_11 (Enemy* enemy);
    void Shoot_ID_12 (Enemy* enemy);
    void Shoot_ID_13 (Enemy* enemy);
    void Shoot_ID_14 (Enemy* enemy);
    void Shoot_ID_15 (Enemy* enemy);
    void Shoot_ID_16 (Enemy* enemy);
    void Shoot_ID_17 (Enemy* enemy);
    void Shoot_ID_18 (Enemy* enemy);

    void BulletMove_ID_1 (Bullet* bullet);
    void BulletMove_ID_2_1 (Bullet* bullet);
    void BulletMove_ID_2_2 (Bullet* bullet);
    void BulletMove_ID_3_1 (Bullet* bullet);
    void BulletMove_ID_3_2 (Bullet* bullet);
    void BulletMove_ID_3_3 (Bullet* bullet);
    void BulletMove_ID_4 (Bullet* bullet);
    void BulletMove_ID_5 (Bullet* bullet);
    void BulletMove_ID_6 (Bullet* bullet);
    void BulletMove_ID_7 (Bullet* bullet);
    void BulletMove_ID_8 (Bullet* bullet);
    void BulletMove_ID_9 (Bullet* bullet);
    void BulletMove_ID_10_1 (Bullet* bullet);
    void BulletMove_ID_10_2 (Bullet* bullet);
    void BulletMove_ID_11 (Bullet* bullet);
    void BulletMove_ID_12 (Bullet* bullet);
    void BulletMove_ID_13 (Bullet* bullet);
    void BulletMove_ID_14 (Bullet* bullet);
    void BulletMove_ID_15 (Bullet* bullet);
    void BulletMove_ID_16 (Bullet* bullet);
    void BulletMove_ID_17 (Bullet* bullet);
    void BulletMove_ID_18 (Bullet* bullet);

    void CreateBarOne();
    void BossMove_ID_1(Boss* LevelBoss);
    void BossShoot_ID_1_SETDATA(Boss* LevelBoss, float basetime);
    void BossShoot_ID_1_1(Boss* LeveBoss, float basetime);
    void BossShoot_ID_1_2(Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_1_1(SuperBullet* sbullet);
    void BossBulletMove_ID_1_2(SuperBullet* sbullet);
    void BossBulletMove_ID_1_3(SuperBullet* sbullet);
    bool DeleteBullet_ID_1_2(SuperBullet* sbullet);
    //
    void CreateBarTwo();
    void BossMove_ID_2(Boss* LevelBoss);
    void BossShoot_ID_2_SETDATA(Boss* LevelBoss, float basetime);
    void BossShoot_ID_2_1(Boss* LevelBoss, float basetime);
    void BossShoot_ID_2_2(Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_2_1_1(SuperBullet* sbullet);
    void BossBulletMove_ID_2_1_2(SuperBullet* sbullet);
    void BossBulletMove_ID_2_2(SuperBullet* sbullet);
    //
    void CreateBarThree();
    void BossMove_ID_3(Boss* LevelBoss);
    void BossShoot_ID_3_SETDATA(Boss* LevelBoss, float basetime);
    void BossShoot_ID_3_1(Boss* LevelBoss, float basetime);
    void BossShoot_ID_3_2(Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_3_1_START(SuperBullet* sbullet);
    void BossBulletMove_ID_3_1_GO(SuperBullet* sbullet);
    void BossBulletMove_ID_3_2(SuperBullet* sbullet);
    bool DeleteBullet_ID_3_1(SuperBullet* sbullet);
    //
    void CreateBarFour();
    void BossMove_ID_4(Boss* LevelBoss);
    void BossShoot_ID_4_SETDATA(Boss* LevelBoss, float basetime);
    void BossShoot_ID_4_1(Boss* LevelBoss, float basetime);
    void BossShoot_ID_4_2(Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_4_1_1(SuperBullet* sbullet);
    void BossBulletMove_ID_4_1_2(SuperBullet* sbullet);
    void BossBulletMove_ID_4_2(SuperBullet* sbullet);
    bool DeleteBullet_ID_4_1(SuperBullet* sbullet);
    //
    void CreateBarFive();
    void BossMove_ID_5(Boss* LevelBoss);
    void BossShoot_ID_5_1(Boss* LevelBoss, float basetime);
    void BossShoot_ID_5_2(Boss* LevelBoss, float basetime);
    void BossShoot_ID_5_3(Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_5_1_1(SuperBullet* sbullet);
    void BossBulletMove_ID_5_1_2(SuperBullet* sbullet);
    void BossBulletMove_ID_5_2(SuperBullet* sbullet);
    void BossBulletMove_ID_5_3(SuperBullet* sbullet);
    //
    void CreateBarSix();
    void BossMove_ID_6(Boss* LevelBoss);
    void BossShoot_ID_6_SETDATA(Boss* LevelBoss, float basetime);
    void BossShoot_ID_6_1(Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_6_1(SuperBullet* sbullet);
    void BossBulletMove_ID_6_2(SuperBullet* sbullet);
    bool DeleteBullet_ID_6_1(SuperBullet* sbullet);
    //
    void CreateBarSeven();
    void BossMove_ID_7(Boss* LevelBoss);
    void BossShoot_ID_7_SETDATA(Boss* LevelBoss, float basetime);
    void BossShoot_ID_7_1_MAIN(Boss* LevelBoss, float basetime);
    void BossShoot_ID_7_1_1(Boss* LevelBoss, float basetime);
    void BossShoot_ID_7_1_2(Boss* LevelBoss, float basetime);
    void BossShoot_ID_7_1_3(Boss* LevelBoss, float basetime);
    void BossShoot_ID_7_2(Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_7_1_1(SuperBullet* sbullet);
    void BossBulletMove_ID_7_1_2(SuperBullet* sbullet);
    void BossBulletMove_ID_7_1_3(SuperBullet* sbullet);
    void BossBulletMove_ID_7_2(SuperBullet* sbullet);
    bool DeleteBullet_ID_7_1(SuperBullet* sbullet);
}

#define CREATE_LEVEL_FIVE() \
    imagebuffer=Reader.getFile("Boss5.png"); \
    imagesize=Reader.getEntryFileSize("Boss5.png"); \
    LevelBoss->Texture.loadFromMemory(imagebuffer, imagesize); \
    LevelBoss->SetImage(LevelBoss->Texture); \
    delete[] imagebuffer; \
    \
    imagebuffer=Reader.getFile("Level5Background.png"); \
    imagesize=Reader.getEntryFileSize("Level5Background.png"); \
    LevelBackgroundImage[0].loadFromMemory(imagebuffer, imagesize); \
    delete[] imagebuffer; \
    \
    imagebuffer=Reader.getFile("Level5BossBackground.png"); \
    imagesize=Reader.getEntryFileSize("Level5BossBackground.png"); \
    LevelBackgroundImage[1].loadFromMemory(imagebuffer,imagesize); \
    delete[] imagebuffer; \
    \
    imagebuffer=Reader.getFile("CharPortrait5blur.png"); \
    imagesize=Reader.getEntryFileSize("CharPortrait5blur.png"); \
    BossPortraitImage.loadFromMemory(imagebuffer, imagesize); \
    delete[] imagebuffer; \
    \
    Level5::CreateEnemies(); \
    \
    LevelTime=180; \
    CurrentLevel=LEVEL_FIVE; \
    LevelMusicID=LEVEL5_THEME; \
    BossMusicID=BOSS5_THEME; \
    LevelBoss->AuraSprite.setColor(sf::Color(0,128,0)); \
    \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("Now go, Hero, your strongest opponents are\nwaiting for you.", RIGHT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("Will you see the peace and happiness you\nbelieve in? I really don't know.", RIGHT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("So you've won. Does it mean you're right?", RIGHT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("Anyway, just two Sins left. I have to go, bye!", LEFT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("Come on, you're doing it again...", LEFT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("Hahaha! You really think so? Even if you defeat\nus underlings, you still have no chance when it\ncomes to our leader!", RIGHT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("You see? I was right, you Sins are all talk.", LEFT_TALKING)); \
    \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("But, for the same reason, I hate you. Come,\nHero, fight me and feel the power of my hatred!", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("I told you. Happiness does not exist. Please,\nknow I admire you for believing in it, for you still\nhave this hope.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("But they won't feel joy and happiness either!", LEFT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("That's why I said I have saved them. They won't\nfeel neither sadness, nor hatred, ever again.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("In the end, happiness is just a made-up illusion,\nas it means making other people sad.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("...or, in the second case, they start hating each\nother's personal success.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("People either live a flat life, stupidly happy in\ntheir mediocrity...", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("People dream of an ideal place where everyone\ncan live happily, but that isn't possible. There are\nonly two possible scenarios.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Calm down. What I mean is, have you ever seen\nsomeone so happy that you got sad?", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("What do you mean? Stop with this foolish talk!", LEFT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Think about it, Hero, isn't it sad? In the end,\nhappiness doesn't exist.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("I saved them from the pain of living in this world.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Envy, right? What have you done?", LEFT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("It was me. Hello, Hero!", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("This place... What has happened here?", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Seriously, I've been listening to these threats\nover and over, if you're any different, just show\nme, okay?", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Oh please, why do you always say you're going\nto beat me when it is you to be defeated?\nThat's not even funny anymore.", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("\"Beat me\"? Do you really think you can fight\nagainst my desctructive powers? If so, foolish\ngirl, I'll mercilessly crush you down!", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("I don't quite get it, but if you're one of the Sins,\nI guess I'll have to beat you!", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("My magic power can do far more than this, and\nif you dare oppose me, you'll be the next to fall.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Yes. I am Envy, and my true nature is to ruin\neverything.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("I-Is this your doing? A girl like you did all this?\nYou know, that's not good at all!", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Do you like it? This is my masterpiece, look at it!\nDevastation truly is the highest art!", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Hey, you over there! What's up with this mess?", LEFT_TALKING)); \
    \
    Level5::CreateBarSeven(); \
    Level5::CreateBarSix(); \
    Level5::CreateBarFive(); \
    Level5::CreateBarFour(); \
    Level5::CreateBarThree(); \
    Level5::CreateBarTwo(); \
    Level5::CreateBarOne();

#endif // LEVEL5_H

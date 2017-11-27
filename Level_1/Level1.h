#ifndef LEVEL1_H
#define LEVEL1_H

#include "..\GameEngine.h"
#include "..\Global.h"

//namespace for enemies' movements and shootings
namespace Level1 {
    void Move_ID_1 (Enemy* enemy);
    void Move_ID_2 (Enemy* enemy);
    void Move_ID_3 (Enemy* enemy);
    void Move_ID_4 (Enemy* enemy);
    void Move_ID_5 (Enemy* enemy);
    void Move_ID_6 (Enemy* enemy);
    void Move_ID_7_1 (Enemy* enemy);
    void Move_ID_7_2 (Enemy* enemy);
    void Move_ID_8 (Enemy* enemy);
    void Move_ID_9_1 (Enemy* enemy);
    void Move_ID_9_2 (Enemy* enemy);
    void BossMove_ID_1 (Boss* boss);
    void BossMove_ID_2 (Boss* boss);
    void BossMove_ID_3 (Boss* boss);

    void Shoot_ID_1 (Enemy* enemy);
    void Shoot_ID_2 (Enemy* enemy);
    void Shoot_ID_3 (Enemy* enemy);
    void Shoot_ID_4 (Enemy* enemy);
    void Shoot_ID_5 (Enemy* enemy);
    void Shoot_ID_6 (Enemy* enemy);
    void Shoot_ID_7 (Enemy* enemy);
    void Shoot_ID_8 (Enemy* enemy);
    void Shoot_ID_9 (Enemy* enemy);
    void BossShoot_ID_1_1 (Boss* boss, float basetime);
    void BossShoot_ID_1_2 (Boss* boss, float basetime);
    void BossShoot_ID_2_1 (Boss* boss, float basetime);
    void BossShoot_ID_2_2 (Boss* boss, float basetime);
    void BossShoot_ID_2_3 (Boss* boss, float basetime);
    void BossShoot_ID_3 (Boss* boss, float basetime);

    void BulletMove_ID_6 (Bullet* bullet);
    void BulletMove_ID_7 (Bullet* bullet);
    void BulletMove_ID_8 (Bullet* bullet);
    void BulletMove_ID_9 (Bullet* bullet);
    void BossBulletMove_ID_1 (SuperBullet* sbullet);
    void BossBulletMove_ID_2 (SuperBullet* sbullet);
    void BossBulletMove_ID_3_1 (SuperBullet* sbullet);
    void BossBulletMove_ID_3_2 (SuperBullet* sbullet);
    void BossBulletMove_ID_3_3 (SuperBullet* sbullet);

    bool DeleteBullet_ID_1 (SuperBullet* sbullet);
    bool DeleteBullet_ID_2 (SuperBullet* sbullet);
    bool DeleteBullet_ID_3 (SuperBullet* sbullet);

    void CreateEnemies();
    void CreateBarOne();
    void CreateBarTwo();
    void CreateBarThree();
};

#define CREATE_LEVEL_ONE() \
    imagebuffer=Reader.getFile("Boss1.png"); \
    imagesize=Reader.getEntryFileSize("Boss1.png"); \
    LevelBoss->Texture.loadFromMemory(imagebuffer,imagesize); \
    LevelBoss->SetImage(LevelBoss->Texture); \
    delete[] imagebuffer; \
    \
    imagebuffer=Reader.getFile("Level1Background.png"); \
    imagesize=Reader.getEntryFileSize("Level1Background.png"); \
    LevelBackgroundImage[0].loadFromMemory(imagebuffer,imagesize); \
    delete[] imagebuffer; \
    \
    imagebuffer=Reader.getFile("Level1BossBackground.png"); \
    imagesize=Reader.getEntryFileSize("Level1BossBackground.png"); \
    LevelBackgroundImage[1].loadFromMemory(imagebuffer,imagesize); \
    delete[] imagebuffer; \
    \
    imagebuffer=Reader.getFile("CharPortrait1blur.png"); \
    imagesize=Reader.getEntryFileSize("CharPortrait1blur.png"); \
    BossPortraitImage.loadFromMemory(imagebuffer,imagesize); \
    delete[] imagebuffer; \
    \
    Level1::CreateEnemies(); \
    \
    LevelTime=/*156*/132; \
    CurrentLevel=LEVEL_ONE; \
    LevelMusicID=LEVEL1_THEME; \
    BossMusicID=BOSS1_THEME; \
    LevelBoss->AuraSprite.setColor(sf::Color(0,127,255)); \
    \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("F-Farewell.", RIGHT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("That's enough. Farewell.", LEFT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("There is... a cave, further in the forest.\nGluttony's there. I don't know anything else.", RIGHT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("Don't make me waste time. Where have they\ngone?", LEFT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("I-I don't know.", RIGHT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("So, where are the others?", LEFT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("This girl... is dangerous...", RIGHT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("So I was right! To think I was just bluffing...\nHaha, you sure are stupid! I'm leaving, goodbye!", LEFT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("H-How do you...", RIGHT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("Now, where are you fellows? Perhaps... in the\ncave further in the forest?", LEFT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("Wasn't I right? This was fast!", LEFT_TALKING)); \
    \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("A bit of effort to gain an eternity of\nnothingness... It really sounds like a good idea!\nHuman, prepare to die!", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("I owe our leader at least this much... Yes, it's\ndecided! If I kill you, I'll be able to live like this\nforever!", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("But, those guns... So you're the one supposed to\ndefeat us!", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("There are plenty of plants here, so I don't even\nhave to bother finding food. This life really suits\nme well!", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("It would be a lot of work... yeah, really a lot.\nThat's why I decided to leave them and spend\nmy days in this forest.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Our leader told us we had to take over humans,\nbut I don't feel like doing it.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("What are you planning to do here?", LEFT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Yeah, right. I'm Sloth.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Hey you! You're one of the Sins, right?", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Wait a moment, now you're going too far! I'm\nfine living like this and, if you won't let me,\nprepare to die!", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("This way, you won't have to worry about\nanything any more. This sounds like a really good\nidea, right?", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Oh, don't worry, I'll slain you in the blink of an\neye, aren't you happy?", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Isn't it obvious? Where should I, Sloth, spend my\ndays other than here, where I can worry about\nnothing?", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("What are you doing here in this forest?", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("I finally found you, I spent ages looking for you!", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Hey, you're one of them!", LEFT_TALKING)); \
    \
    Level1::CreateBarThree(); \
    Level1::CreateBarTwo(); \
    Level1::CreateBarOne();

#endif

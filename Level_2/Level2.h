#ifndef LEVEL2_H
#define LEVEL2_H

#include "..\GameEngine.h"
#include "..\Global.h"

namespace Level2 {
    void CreateEnemies();

    void Move_ID_1_1 (Enemy* enemy);
    void Move_ID_1_2 (Enemy* enemy);
    void Move_ID_2_1 (Enemy* enemy);
    void Move_ID_2_2 (Enemy* enemy);
    void Move_ID_3_1 (Enemy* enemy);
    void Move_ID_3_2 (Enemy* enemy);
    void Move_ID_3_NULL (Enemy* enemy);
    void Move_ID_4_1 (Enemy* enemy);
    void Move_ID_4_2 (Enemy* enemy);
    void Move_ID_5_1 (Enemy* enemy);
    void Move_ID_5_2 (Enemy* enemy);
    void Move_ID_6_1 (Enemy* enemy);
    void Move_ID_6_2 (Enemy* enemy);
    void Move_ID_7_1 (Enemy* enemy);
    void Move_ID_7_2 (Enemy* enemy);
    void Move_ID_8 (Enemy* enemy);
    void Move_ID_9_1 (Enemy* enemy);
    void Move_ID_9_1_PLUS (Enemy* enemy);
    void Move_ID_9_2 (Enemy* enemy);
    void Move_ID_9_2_PLUS (Enemy* enemy);
    void Move_ID_9_NULL (Enemy* enemy);
    void Move_ID_10_1 (Enemy* enemy);
    void Move_ID_10_2 (Enemy* enemy);
    void Move_ID_11 (Enemy* enemy);

    void Shoot_ID_1 (Enemy* enemy);
    void Shoot_ID_2 (Enemy* enemy);
    void Shoot_ID_3 (Enemy* enemy);
    void Shoot_ID_4 (Enemy* enemy);
    void Shoot_ID_5 (Enemy* enemy);
    void Shoot_ID_6 (Enemy* enemy);
    void Shoot_ID_7 (Enemy* enemy);
    void Shoot_ID_8 (Enemy* enemy);
    void Shoot_ID_9 (Enemy* enemy);
    void Shoot_ID_10_1 (Enemy* enemy);
    void Shoot_ID_10_2 (Enemy* enemy);
    void Shoot_ID_11 (Enemy* enemy);

    void BulletMove_ID_1 (Bullet* bullet);
    void BulletMove_ID_2_1 (Bullet* bullet);
    void BulletMove_ID_2_2 (Bullet* bullet);
    void BulletMove_ID_2_3 (Bullet* bullet);
    void BulletMove_ID_2_4 (Bullet* bullet);
    void BulletMove_ID_2_5 (Bullet* bullet);
    void BulletMove_ID_2_6 (Bullet* bullet);
    void BulletMove_ID_2_7 (Bullet* bullet);
    void BulletMove_ID_2_8 (Bullet* bullet);
    void BulletMove_ID_3 (Bullet* bullet);
    void BulletMove_ID_4_1 (Bullet* bullet);
    void BulletMove_ID_4_2 (Bullet* bullet);
    void BulletMove_ID_5 (Bullet* bullet);
    void BulletMove_ID_6 (Bullet* bullet);
    void BulletMove_ID_7_1 (Bullet* bullet);
    void BulletMove_ID_7_2 (Bullet* bullet);
    void BulletMove_ID_7_3 (Bullet* bullet);
    void BulletMove_ID_8 (Bullet* bullet);
    void BulletMove_ID_9 (Bullet* bullet);
    void BulletMove_ID_10_1 (Bullet* bullet);
    void BulletMove_ID_10_2 (Bullet* bullet);
    void BulletMove_ID_11 (Bullet* bullet);

    void CreateBarOne();
    void BossMove_ID_1(Boss* LevelBoss);
    void BossShoot_ID_1(Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_1 (SuperBullet* sbullet);
    bool DeleteBullet_ID_1 (SuperBullet* sbullet);
    //
    void CreateBarTwo ();
    void BossMove_ID_2 (Boss* LevelBoss);
    void BossShoot_ID_2_1 (Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_2_1 (SuperBullet* sbullet);
    bool DeleteBullet_ID_2_1 (SuperBullet* sbullet);
    void BossShoot_ID_2_2 (Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_2_2 (SuperBullet* sbullet);
    bool DeleteBullet_ID_2_2 (SuperBullet* sbullet);
    //
    void CreateBarThree ();
    void BossMove_ID_3 (Boss* LevelBoss);
    void BossShoot_ID_3 (Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_3_1 (SuperBullet* sbullet);
    void BossBulletMove_ID_3_2 (SuperBullet* sbullet);
    bool DeleteBullet_ID_3 (SuperBullet* sbullet);

    void CreateBarFour ();
    void BossMove_ID_4 (Boss* LevelBoss);
    void BossShoot_ID_4 (Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_4_1 (SuperBullet* sbullet);
    void BossBulletMove_ID_4_2 (SuperBullet* sbullet);
    bool DeleteBullet_ID_4 (SuperBullet* sbullet);
}

#define CREATE_LEVEL_TWO() \
    imagebuffer=Reader.getFile("Boss2.png"); \
    imagesize=Reader.getEntryFileSize("Boss2.png"); \
    LevelBoss->Texture.loadFromMemory(imagebuffer, imagesize); \
    LevelBoss->SetImage(LevelBoss->Texture); \
    delete[] imagebuffer; \
    \
    imagebuffer=Reader.getFile("Level2Background.png"); \
    imagesize=Reader.getEntryFileSize("Level2Background.png"); \
    LevelBackgroundImage[0].loadFromMemory(imagebuffer, imagesize); \
    delete[] imagebuffer; \
    \
    imagebuffer=Reader.getFile("Level2BossBackground.png"); \
    imagesize=Reader.getEntryFileSize("Level2BossBackground.png"); \
    LevelBackgroundImage[1].loadFromMemory(imagebuffer, imagesize); \
    delete[] imagebuffer; \
    \
    imagebuffer=Reader.getFile("CharPortrait2blur.png"); \
    imagesize=Reader.getEntryFileSize("CharPortrait2blur.png"); \
    BossPortraitImage.loadFromMemory(imagebuffer, imagesize); \
    delete[] imagebuffer; \
    \
    Level2::CreateEnemies(); \
    \
    LevelTime=/*171*/142; \
    CurrentLevel=LEVEL_TWO; \
    LevelMusicID=LEVEL2_THEME; \
    BossMusicID=BOSS2_THEME; \
    LevelBoss->AuraSprite.setColor(sf::Color(255,128,0)); \
    \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("Got it. Farewell.", LEFT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("Each one of them has a role... You'll find them\nsomewhere around the town.", RIGHT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("Now, tell me, where have they gone?", LEFT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("\"Thank you\", eh? What a strange girl...", RIGHT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("I'll go to the town square then, it's always very\ncrowded. Thank you, and goodbye!", LEFT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("Yeah, right... Look for places with lot of people...", RIGHT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("So, where are the others? If they're doing their\nduty, they should be somewhere around the\ntown, right?", LEFT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("Y-You're disgusting!", LEFT_TALKING)); \
    \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Human, bring those sweet memories back!\nPlease, fill me with your delightful savour!", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Too much time has passed since last time I've\ndevoured a man, I've nearly forgotten how good\nyou taste.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("But! There's one food I won't find here, and it is\nhumans!", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("The forest is big, and full of delicious fruits, and\nwild animals too! This is my heaven on hearth!", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("If I taught people the joys of eating, they would\nbe stealing food away from me, right? That's\nwhy I live here, far from people!", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("You're right! What I want is just to eat, and eat,\nand eat again!", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Have you given up on taking over humanity as\nwell?", LEFT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("I've already managed to give him a proper\npunishment.", LEFT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("I'll make sure to punish him well as soon as he\ncomes back!", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("\"He\"? Are you talking about Sloth? So he\ntalked... That traitor!", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Looks like he was right.", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("But I'm hungry, little girl! Come here, and\nprepare to be devoured!", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("N-No, thank you, I think I'll pass...", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Yes! Delicious-looking girl, will you be my next\nmeal?", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("I love eating, I would eat anything, anywhere, at\nany time! I would eat even you!", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Friendship? When did I mention that? I have no\nfriends, exception made for food.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("You guys have a weird idea of friendship...", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Sloth used to find me it. He was so weak...\nImposing my will on him was pretty easy!", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("You're Gluttony, right? What are doing here,\naren't you supposed to be outside looking for\nfood?", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Don't underestimate me. I've already taken out\nyour friend.", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Oh, so the humans sent this little girl against us?", RIGHT_TALKING)); \
    \
    Level2::CreateBarFour(); \
    Level2::CreateBarThree(); \
    Level2::CreateBarTwo(); \
    Level2::CreateBarOne();

#endif

#ifndef LEVEL3_H
#define LEVEL3_H

#include "..\GameEngine.h"
#include "..\Global.h"

namespace Level3 {
    void CreateEnemies();

    void Move_ID_1_1 (Enemy* enemy);
    void Move_ID_1_2 (Enemy* enemy);
    void Move_ID_2_1 (Enemy* enemy);
    void Move_ID_2_2 (Enemy* enemy);
    void Move_ID_3_1 (Enemy* enemy);
    void Move_ID_3_2 (Enemy* enemy);
    void Move_ID_3_3 (Enemy* enemy);
    void Move_ID_3_4 (Enemy* enemy);
    void Move_ID_4 (Enemy* enemy);
    void Move_ID_5_START (Enemy* enemy); //Placeholder if you defeat #4
    void Move_ID_5_NULL (Enemy* enemy); //You don't need the placeholders
    void Move_ID_5_GO (Enemy* enemy); //Non-placeholder
    void Move_ID_5 (Enemy* enemy);
    void Move_ID_6_1 (Enemy* enemy);
    void Move_ID_6_2 (Enemy* enemy);
    void Move_ID_7 (Enemy* enemy);
    void Move_ID_8_1 (Enemy* enemy);
    void Move_ID_8_2 (Enemy* enemy);
    void Move_ID_9_1 (Enemy* enemy);
    void Move_ID_9_2 (Enemy* enemy);
    void Move_ID_10_1 (Enemy* enemy);
    void Move_ID_10_2 (Enemy* enemy);
    void Move_ID_11_1 (Enemy* enemy);
    void Move_ID_11_2 (Enemy* enemy);

    void Shoot_ID_1 (Enemy* enemy);
    void Shoot_ID_2 (Enemy* enemy);
    void Shoot_ID_3 (Enemy* enemy);
    void Shoot_ID_4 (Enemy* enemy);
    void Shoot_ID_5 (Enemy* enemy);
    void Shoot_ID_6_1 (Enemy* enemy);
    void Shoot_ID_6_2 (Enemy* enemy);
    void Shoot_ID_7 (Enemy* enemy);
    void Shoot_ID_8 (Enemy* enemy);
    void Shoot_ID_9 (Enemy* enemy);
    void Shoot_ID_10_1 (Enemy* enemy);
    void Shoot_ID_10_2 (Enemy* enemy);
    void Shoot_ID_11 (Enemy* enemy);

    void BulletMove_ID_1_1 (Bullet* bullet);
    void BulletMove_ID_1_2 (Bullet* bullet);
    void BulletMove_ID_1_3 (Bullet* bullet);
    void BulletMove_ID_2 (Bullet* bullet);
    void BulletMove_ID_3 (Bullet* bullet);
    void BulletMove_ID_4 (Bullet* bullet);
    void BulletMove_ID_5 (Bullet* bullet);
    void BulletMove_ID_6 (Bullet* bullet);
    void BulletMove_ID_7 (Bullet* bullet);
    void BulletMove_ID_8 (Bullet* bullet);
    void BulletMove_ID_9_1 (Bullet* bullet);
    void BulletMove_ID_10 (Bullet* bullet);
    void BulletMove_ID_11_1 (Bullet* bullet);
    void BulletMove_ID_11_2 (Bullet* bullet);
    void BulletMove_ID_11_3_PREPARE (Bullet* bullet);
    void BulletMove_ID_11_3 (Bullet* bullet);

    void CreateBarOne();
    void BossMove_ID_1 (Boss* LevelBoss);
    void BossShoot_ID_1 (Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_1 (SuperBullet* sbullet);
    bool DeleteBullet_ID_1 (SuperBullet* sbullet);
    //
    void CreateBarTwo();
    void BossMove_ID_2 (Boss* LevelBoss);
    void BossShoot_ID_2_1 (Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_2_1 (SuperBullet* sbullet);
    bool DeleteBullet_ID_2_1 (SuperBullet* sbullet);
    void BossShoot_ID_2_2 (Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_2_2 (SuperBullet* sbullet);
    bool DeleteBullet_ID_2_2 (SuperBullet* sbullet);
    void BossShoot_ID_2_SET (Boss* LevelBoss, float basetime); //Data-setter
    //
    void CreateBarThree();
    void BossMove_ID_3 (Boss* LevelBoss);
    void BossShoot_ID_3_1 (Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_3_1 (SuperBullet* sbullet);
    bool DeleteBullet_ID_3_1 (SuperBullet* sbullet);
    void BossShoot_ID_3_2 (Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_3_2 (SuperBullet* sbullet);
    bool DeleteBullet_ID_3_2 (SuperBullet* sbullet);
    void BossShoot_ID_3_SET (Boss* LevelBoss, float basetime);
    //
    void CreateBarFour();
    void BossMove_ID_4 (Boss* LevelBoss);
    void BossShoot_ID_4_1 (Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_4_1 (SuperBullet* sbullet);
    bool DeleteBullet_ID_4_1 (SuperBullet* sbullet);
    void BossShoot_ID_4_2 (Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_4_2 (SuperBullet* sbullet);
    bool DeleteBullet_ID_4_2 (SuperBullet* sbullet);
    void BossShoot_ID_4_3 (Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_4_3 (SuperBullet* sbullet);
    bool DeleteBullet_ID_4_3 (SuperBullet* sbullet);
    //
    ///!!! Everything here is a speedbullet
    void CreateBarFive();
    void BossMove_ID_5 (Boss* LevelBoss);
    void BossShoot_ID_5_1 (Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_5_1_1 (SuperBullet* sbullet);
    void BossBulletMove_ID_5_1_2 (SuperBullet* sbullet);
    bool DeleteBullet_ID_5_1 (SuperBullet* sbullet);
    void BossShoot_ID_5_2 (Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_5_2_1 (SuperBullet* sbullet);
    void BossBulletMove_ID_5_2_2 (SuperBullet* sbullet);
    bool DeleteBullet_ID_5_2 (SuperBullet* sbullet);
    void BossShoot_ID_5_3_1 (Boss* LevelBoss, float basetime); //Green bullets
    void BossShoot_ID_5_3_2 (Boss* LevelBoss, float basetime); //Light blue bullets
    void BossShoot_ID_5_3_3 (Boss* LevelBoss, float basetime); //Blue bullets
    void BossShoot_ID_5_3_4 (Boss* LevelBoss, float basetime); //Purple bullets
    void BossBulletMove_ID_5_3_1 (SuperBullet* sbullet);
    void BossBulletMove_ID_5_3_2 (SuperBullet* sbullet);
    bool DeleteBullet_ID_5_3 (SuperBullet* sbullet);
    void BossShoot_ID_5_SET (Boss* LevelBoss, float basetime);
}

#define CREATE_LEVEL_THREE() \
    imagebuffer=Reader.getFile("Boss3.png"); \
    imagesize=Reader.getEntryFileSize("Boss3.png"); \
    LevelBoss->Texture.loadFromMemory(imagebuffer, imagesize); \
    LevelBoss->SetImage(LevelBoss->Texture); \
    delete[] imagebuffer; \
    \
    imagebuffer=Reader.getFile("Level3Background.png"); \
    imagesize=Reader.getEntryFileSize("Level3Background.png"); \
    LevelBackgroundImage[0].loadFromMemory(imagebuffer,imagesize); \
    delete[] imagebuffer; \
    \
    imagebuffer=Reader.getFile("Level3BossBackground.png"); \
    imagesize=Reader.getEntryFileSize("Level3BossBackground.png"); \
    LevelBackgroundImage[1].loadFromMemory(imagebuffer,imagesize); \
    delete[] imagebuffer; \
    \
    imagebuffer=Reader.getFile("CharPortrait3blur.png"); \
    imagesize=Reader.getEntryFileSize("CharPortrait3blur.png"); \
    BossPortraitImage.loadFromMemory(imagebuffer, imagesize); \
    delete[] imagebuffer; \
    \
    Level3::CreateEnemies(); \
    \
    LevelTime=162; \
    CurrentLevel=LEVEL_THREE; \
    LevelMusicID=LEVEL3_THEME; \
    BossMusicID=BOSS3_THEME; \
    LevelBoss->AuraSprite.setColor(sf::Color(255,215,0)); \
    \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("Farewell.", LEFT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("So that's how it is... Bye, hero.", RIGHT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("That's why I can't afford a defeat.", LEFT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("It's not like that. I will defeat you, because I have\na world I want to protect, a world which wanted\nme as his hope.", LEFT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("Humans are weak-willed beings. Sooner or later,\nyou will fall.", RIGHT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("But there are many challenges waiting for you.", RIGHT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("I'll have to admit, desiring wealths is not among\nyour faults...", RIGHT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("As far as needed, of course. I'm afraid I have to\ngo now, bye bye!", LEFT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("But I wonder... How far will you be able to get?", RIGHT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("Yes, maybe you're really an exceptional girl.\nThat's why I couldn't defeat you.", RIGHT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("He he, looks like I'm not your ordinary girl. You\nweren't even all that strong, you know?", LEFT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("Losing to a girl like you... How is it possible?", RIGHT_TALKING)); \
    \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Hero, fight and let me see how much hope is\nworth!", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("I'm really interested in knowing yours.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Yes, not only everything, but also everyone has\na price.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("If you throw everything away to get power,\ndoesn't that mean you're selling your own life?", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("\"Everything has a price\", they think, without\nnoticing how they are \"spending\" their moral\nvalues for money.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("There are people who end up loving money itself,\nbut the majority sees it as a way to rule society.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("But it's not like they actually need it. They just\nwant it to become more and more powerful.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("I'm letting people know the joys of money. They\ncome here asking for some, and I satisfy their\ndesire.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("And, here I was, thinking how my goal would\nhave been obvius for someone like you...", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Tsk, don't treat me like those traitors.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Have you given up too, like Sloth and Gluttony?", LEFT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Stop acting dumb and tell me, what's your plan?", LEFT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("\"This\", as you call it, is just me doing my job.\nIs there anything wrong with it?", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("What... What is this?", LEFT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Hello, hero! So you have finally come.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Prepare, little girl, for I will teach you the great\npower of money!", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Is that what you really think? I will show you how\nwrong you are.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Thank you, but I don't want that kind of friends.\nThey will just act as friends, without heartfelt\nfriendship.", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Even other people will like you more, you will\nhave much more friends than you have now!", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Think about it! You will be able to buy everything\nyou want!", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("I don't mind giving you plenty of it, either.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("That said, I won't mind getting some, he he.", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("\"Happy\"? Money can make life better, but it\ndoesn't give happiness by itself.", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Of course, as much as you want! Are you happy?", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("I want some money, too. Will you give me?", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("I am just doing my job. I give everyone all the\nmoney they need. I indeed help people.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Hello, old man! What a nice place! What are you\ndoing here?", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Hello, little girl!", RIGHT_TALKING)); \
    \
    Level3::CreateBarFive(); \
    Level3::CreateBarFour(); \
    Level3::CreateBarThree(); \
    Level3::CreateBarTwo(); \
    Level3::CreateBarOne(); \

#endif

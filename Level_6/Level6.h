#ifndef LEVEL6_H
#define LEVEL6_H

#include "..\GameEngine.h"
#include "..\Global.h"

namespace Level6 {
    void CreateEnemies();

    void Move_ID_1_1(Enemy* enemy);
    void Move_ID_1_2(Enemy* enemy);
    void Move_ID_2_1(Enemy* enemy);
    void Move_ID_2_2(Enemy* enemy);
    void Move_ID_2_3(Enemy* enemy);
    void Move_ID_2_4(Enemy* enemy);
    void Move_ID_3_1(Enemy* enemy);
    void Move_ID_3_2(Enemy* enemy);
    void Move_ID_4_1(Enemy* enemy);
    void Move_ID_4_2(Enemy* enemy);
    void Move_ID_5_1(Enemy* enemy);
    void Move_ID_5_2(Enemy* enemy);
    void Move_ID_6(Enemy* enemy);
    void Move_ID_7_1(Enemy* enemy);
    void Move_ID_7_2(Enemy* enemy);
    void Move_ID_8(Enemy* enemy);
    void Move_ID_9_WAIT_1(Enemy* enemy);
    void Move_ID_9_WAIT_2(Enemy* enemy);
    void Move_ID_9_DONTGO(Enemy* enemy);
    void Move_ID_9_1(Enemy* enemy);
    void Move_ID_9_2(Enemy* enemy);
    void Move_ID_10_1(Enemy* enemy);
    void Move_ID_10_2(Enemy* enemy);
    void Move_ID_11_1_FIRSTPHASE(Enemy* enemy);
    void Move_ID_11_2_FIRSTPHASE(Enemy* enemy);
    void Move_ID_11_1_SECONDPHASE(Enemy* enemy);
    void Move_ID_11_2_SECONDPHASE(Enemy* enemy);
    void Move_ID_12_1(Enemy* enemy);
    void Move_ID_12_2_1(Enemy* enemy);
    void Move_ID_12_2_2(Enemy* enemy);
    void Move_ID_12_3_1(Enemy* enemy);
    void Move_ID_12_3_2(Enemy* enemy);
    void Move_ID_12_3_3(Enemy* enemy);
    void Move_ID_13_1_1(Enemy* enemy);
    void Move_ID_13_1_2(Enemy* enemy);
    void Move_ID_13_2_1_1(Enemy* enemy);
    void Move_ID_13_2_1_2(Enemy* enemy);
    void Move_ID_13_2_2_1(Enemy* enemy);
    void Move_ID_13_2_2_2(Enemy* enemy);
    void Move_ID_13_3_1_1(Enemy* enemy);
    void Move_ID_13_3_1_2(Enemy* enemy);
    void Move_ID_13_3_2_1(Enemy* enemy);
    void Move_ID_13_3_2_2(Enemy* enemy);

    void Shoot_ID_1(Enemy* enemy);
    void Shoot_ID_2(Enemy* enemy);
    void Shoot_ID_3(Enemy* enemy);
    void Shoot_ID_4(Enemy* enemy);
    void Shoot_ID_5(Enemy* enemy);
    void Shoot_ID_6_1(Enemy* enemy);
    void Shoot_ID_6_2(Enemy* enemy);
    void Shoot_ID_7(Enemy* enemy);
    void Shoot_ID_8_1(Enemy* enemy);
    void Shoot_ID_8_2(Enemy* enemy);
    void Shoot_ID_8_3(Enemy* enemy);
    void Shoot_ID_9(Enemy* enemy);
    void Shoot_ID_10(Enemy* enemy);
    void Shoot_ID_11(Enemy* enemy);
    void Shoot_ID_12(Enemy* enemy);
    void Shoot_ID_13_1(Enemy* enemy);
    void Shoot_ID_13_2(Enemy* enemy);
    void Shoot_ID_13_3(Enemy* enemy);

    void BulletMove_ID_1(Bullet* bullet);
    void BulletMove_ID_2(Bullet* bullet);
    void BulletMove_ID_3(Bullet* bullet);
    void BulletMove_ID_4(Bullet* bullet);
    void BulletMove_ID_5(Bullet* bullet);
    void BulletMove_ID_6_1(Bullet* bullet);
    void BulletMove_ID_6_2(Bullet* bullet);
    void BulletMove_ID_7(Bullet* bullet);
    void BulletMove_ID_8_1(Bullet* bullet);
    void BulletMove_ID_8_3(Bullet* bullet);
    void BulletMove_ID_9(Bullet* bullet);
    void BulletMove_ID_10(Bullet* bullet);
    void BulletMove_ID_11(Bullet* bullet);
    void BulletMove_ID_12_FIRSTPHASE(Bullet* bullet);
    void BulletMove_ID_12_SECONDPHASE(Bullet* bullet);
    void BulletMove_ID_13(Bullet* bullet);

    void CreateBarOne();
    void BossMove_ID_1(Boss* LevelBoss);
    void BossShoot_ID_1_SETDATA(Boss* LevelBoss, float basetime);
    void BossShoot_ID_1(Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_1(SuperBullet* sbullet);
    //
    void CreateBarTwo();
    void BossMove_ID_2(Boss* LevelBoss);
    void BossShoot_ID_2_1(Boss* LevelBoss, float basetime);
    void BossShoot_ID_2_2(Boss* LevelBoss, float basetime);
    //
    void CreateBarThree();
    void BossMove_ID_3(Boss* LevelBoss);
    void BossShoot_ID_3_SETDATA(Boss* LevelBoss, float basetime);
    void BossShoot_ID_3(Boss* LevelBoss, float basetime);
    //
    void CreateBarFour();
    void BossMove_ID_4(Boss* LevelBoss);
    void BossShoot_ID_4_SETDATA(Boss* LevelBoss, float basetime);
    void BossShoot_ID_4_1(Boss* LevelBoss, float basetime);
    void BossShoot_ID_4_2(Boss* LevelBoss, float basetime);
    void BossShoot_ID_4_3(Boss* LevelBoss, float basetime);
    //
    void CreateBarFive();
    void BossMove_ID_5(Boss* LevelBoss);
    void BossShoot_ID_5_SETDATA(Boss* LevelBoss, float basetime);
    void BossShoot_ID_5(Boss* LevelBoss, float basetime);
    //
    void CreateBarSix();
    void BossMove_ID_6(Boss* LevelBoss);
    void BossShoot_ID_6_SETDATA(Boss* LevelBoss, float basetime);
    void BossShoot_ID_6_1(Boss* LevelBoss, float basetime);
    bool DeleteBullet_ID_6_1(SuperBullet* sbullet);
    bool DeleteBullet_ID_6_EXPLOSION(SuperBullet* sbullet);
    //
    void CreateBarSeven();
    void BossMove_ID_7(Boss* LevelBoss);
    void BossShoot_ID_7_SETDATA(Boss* LevelBoss, float basetime);
    void BossShoot_ID_7_1(Boss* LevelBoss, float basetime);
    //
    void CreateBarEight();
    void BossMove_ID_8(Boss* LevelBoss);
    void BossShoot_ID_8_SETDATA(Boss* LevelBoss, float basetime);
    void BossShoot_ID_8_1(Boss* LevelBoss, float basetime);
    void BossShoot_ID_8_2(Boss* LevelBoss, float basetime);
    void BossBulletMove_ID_8_2(SuperBullet* sbullet);
    bool DeleteBullet_ID_8_2(SuperBullet* sbullet);
}

#define CREATE_LEVEL_SIX() \
    imagebuffer=Reader.getFile("Boss6.png"); \
    imagesize=Reader.getEntryFileSize("Boss6.png"); \
    LevelBoss->Texture.loadFromMemory(imagebuffer, imagesize); \
    LevelBoss->SetImage(LevelBoss->Texture); \
    delete[] imagebuffer; \
    \
    imagebuffer=Reader.getFile("Level6Background.png"); \
    imagesize=Reader.getEntryFileSize("Level6Background.png"); \
    LevelBackgroundImage[0].loadFromMemory(imagebuffer, imagesize); \
    delete[] imagebuffer; \
    \
    imagebuffer=Reader.getFile("Level6BossBackground.png"); \
    imagesize=Reader.getEntryFileSize("Level6BossBackground.png"); \
    LevelBackgroundImage[1].loadFromMemory(imagebuffer,imagesize); \
    delete[] imagebuffer; \
    \
    imagebuffer=Reader.getFile("CharPortrait6blur.png"); \
    imagesize=Reader.getEntryFileSize("CharPortrait6blur.png"); \
    BossPortraitImage.loadFromMemory(imagebuffer, imagesize); \
    delete[] imagebuffer; \
    \
    Level6::CreateEnemies(); \
    \
    LevelTime=241; \
    CurrentLevel=LEVEL_SIX; \
    LevelMusicID=LEVEL6_THEME; \
    BossMusicID=BOSS6_THEME; \
    LevelBoss->AuraSprite.setColor(sf::Color(64,0,0)); \
    \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("The time for the greatest desperation has finally\ncome.", RIGHT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("Is this the power of hope? I don't know, but I\nhave nothing to fear.", RIGHT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("I haven't been able to protect you.", RIGHT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("Master... Please, forgive me.", RIGHT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("A power a hundred times greater than this\nsword's... The time for the final battle has\nfinally come.", RIGHT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("Go on, Heroine. I'm looking forward to having\nserious fun, when my master will finally crush\nyour hopes, once and for all.", RIGHT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("But I wasn't strong enough.", RIGHT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("But you fought well! You surely were better\nthan the others!", LEFT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("I haven't been able to use your power.", RIGHT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("Master... Please, forgive me.", RIGHT_TALKING)); \
    \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("So be it. If you've chosen to fight, prepare, for\nyour end is coming.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("I can't give up now. I'll fight!", LEFT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("You don't need to know that. Now choose: will\nyou run away, or will you fight me?", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Crushing the Pandora's Box? Just what is going\non...", LEFT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("I'll wait until the Box gets crushed, and in the\nmeantime I won't let anyone enter the temple.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("That's why I am here. I have to guard my\nmaster. As long as the two of us resist, nothing\nelse matters.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("While our leader was even stronger than me,\nhaving to both fight humans and defend the\nPandora's Box was too much.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Last time, I alone was able to decimate the\nhuman army. But... I committed a big mistake.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("I am Wrath, the so-called One-Man Army\nhumans had learnt to fear.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("If you had participated in the first war against\nus, you wouldn't speak to me like that.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("And you'll be the next. Tell me, why are you\nhere?", LEFT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("And at last you have come, Hero. This means\nyou have defeated all the others.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Here, at the temple... What are they planning to\ndo?", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("So be it. If you've chosen to fight, prepare to be\nslayed by my merciless sword of despair.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Of course I do!", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Heroine, do you really want to fight me?", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("And thanks to this sword, my master will be\nassisting me.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("I was defeated, too, but now I've learnt the\nlesson. I will fight you with all of my strength.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("They underestimated the power of humans.\nThey got defeated, and thanks to you they did\nso twice.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("And, I have every intention of using it. My\ncomrades made a big mistake.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("This sword has been given to me by my master,\nand it's the strongest weapon ever forged.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Yes, yes, I'm used to this by now. But, do you\nreally need to use such a big sword against\nsomeone like me?", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("I am Wrath, the so-called One-Man Army\nhumans had learnt to fear.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("As you wish. I'll exterminate you immediately.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Oh, right, there's still another one before the\nleader. Come on, let's end this quickly.", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Not so fast, Heroine. I won't let anyone enter.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("So the mastermind was hiding here after all...\nGuess it's time to beat him!", LEFT_TALKING)); \
    \
    Level6::CreateBarEight(); \
    Level6::CreateBarSeven(); \
    Level6::CreateBarSix(); \
    Level6::CreateBarFive(); \
    Level6::CreateBarFour(); \
    Level6::CreateBarThree(); \
    Level6::CreateBarTwo(); \
    Level6::CreateBarOne();

#endif // LEVEL6_H

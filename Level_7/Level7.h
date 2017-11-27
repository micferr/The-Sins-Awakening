#ifndef LEVEL7_H
#define LEVEL7_H

#include "..\GameEngine.h"
#include "..\Global.h"

namespace Level7 {
    void CreateEnemies();

    void Move_ID_1_1(Enemy* enemy);
    void Move_ID_1_2(Enemy* enemy);
    //void Move_ID_2_1(Enemy* enemy); //=1_1
    //void Move_ID_2_2(Enemy* enemy); //=1_2
    void Move_ID_3(Enemy* enemy);
    void Move_ID_3(Enemy* enemy);
    //void Move_ID_4_1(Enemy* enemy); //=1_1
    //void Move_ID_4_2(Enemy* enemy); //=1_2
    void Move_ID_5(Enemy* enemy);

    void Shoot_ID_1(Enemy* enemy);
    void Shoot_ID_2(Enemy* enemy);
    void Shoot_ID_3(Enemy* enemy);
    void Shoot_ID_4(Enemy* enemy);
    void Shoot_ID_5(Enemy* enemy);

    void CreateBarOne();
    void BossMove_ID_1(Boss* boss);
    void BossShoot_ID_1_SETDATA(Boss* boss, float basetime);
    void BossShoot_ID_1_1(Boss* boss, float basetime);
    void BossShoot_ID_1_2(Boss* boss, float basetime);
    void BossBulletMove_ID_1_1(SuperBullet* sbullet);
    void BossBulletMove_ID_1_2_1(SuperBullet* sbullet);
    void BossBulletMove_ID_1_2_2(SuperBullet* sbullet);
    bool DeleteBullet_ID_1_2(SuperBullet* sbullet);
    //
    void CreateBarTwo();
    void BossMove_ID_2(Boss* boss);
    void BossShoot_ID_2_SETDATA(Boss* boss, float basetime);
    void BossShoot_ID_2_1(Boss* boss, float basetime);
    void BossBulletMove_ID_2_1_1(SuperBullet* sbullet);
    void BossBulletMove_ID_2_1_2(SuperBullet* sbullet);
    bool DeleteBullet_ID_2_1(SuperBullet* sbullet);
    //
    void CreateBarThree();
    void BossMove_ID_3(Boss* boss);
    void BossShoot_ID_3_SETDATA(Boss* boss, float basetime);
    void BossShoot_ID_3_1(Boss* boss, float basetime);
    void BossShoot_ID_3_2(Boss* boss, float basetime);
    void BossShoot_ID_3_3(Boss* boss, float basetime);
    void BossBulletMove_ID_3_1(SuperBullet* sbullet);
    bool DeleteBullet_ID_3_2(SuperBullet* sbullet);
    //
    void CreateBarFour();
    void BossMove_ID_4(Boss* boss);
    void BossShoot_ID_4_SETDATA(Boss* boss, float basetime);
    void BossShoot_ID_4_1(Boss* boss, float basetime);
    void BossShoot_ID_4_2(Boss* boss, float basetime);
    void BossBulletMove_ID_4_1_1(SuperBullet* sbullet);
    void BossBulletMove_ID_4_1_2(SuperBullet* sbullet);
    void BossBulletMove_ID_4_2(SuperBullet* sbullet);
    bool DeleteBullet_ID_4_1(SuperBullet* sbullet);
    bool DeleteBullet_ID_4_2(SuperBullet* sbullet);
    //
    void CreateBarFive();
    void BossMove_ID_5(Boss* boss);
    void BossShoot_ID_5_SETDATA(Boss* boss, float basetime);
    void BossShoot_ID_5_1(Boss* boss, float basetime);
    void BossShoot_ID_5_2(Boss* boss, float basetime);
    void BossShoot_ID_5_3(Boss* boss, float basetime);
    void BossBulletMove_ID_5_1(SuperBullet* sbullet);
    void BossBulletMove_ID_5_2_1(SuperBullet* sbullet);
    void BossBulletMove_ID_5_2_2(SuperBullet* sbullet);
    bool DeleteBullet_ID_5_2(SuperBullet* sbullet);
    //
    void CreateBarSix();
    void BossMove_ID_6(Boss* boss);
    void BossShoot_ID_6_SETDATA(Boss* boss, float basetime);
    void BossShoot_ID_6_1(Boss* boss, float basetime);
    void BossShoot_ID_6_2(Boss* boss, float basetime);
    void BossShoot_ID_6_3(Boss* boss, float basetime);
    void BossBulletMove_ID_6_2(SuperBullet* sbullet);
    void BossBulletMove_ID_6_3(SuperBullet* sbullet);
    bool DeleteBullet_ID_6_3(SuperBullet* sbullet);
    //
    /*void CreateBarSeven();
    void BossMove_ID_7(Boss* boss);
    void BossShoot_ID_7_SETDATA(Boss* boss, float basetime);
    void BossShoot_ID_7_1(Boss* boss, float basetime);
    void BossShoot_ID_7_2(Boss* boss, float basetime);
    void BossBulletMove_ID_7_1(SuperBullet* sbullet);
    bool DeleteBullet_ID_7_1(SuperBullet* sbullet);*/
    //
    void CreateBarSeven();
    void BossMove_ID_7(Boss* boss);
    void BossShoot_ID_7_SETDATA(Boss* boss, float basetime);
    void BossShoot_ID_7_1(Boss* boss, float basetime);
    void BossShoot_ID_7_2(Boss* boss, float basetime);
    void BossShoot_ID_7_3(Boss* boss, float basetime);
    void BossShoot_ID_7_4(Boss* boss, float basetime);
    void BossShoot_ID_7_5(Boss* boss, float basetime);
    void BossShoot_ID_7_6(Boss* boss, float basetime);
    void BossShoot_ID_7_7(Boss* boss, float basetime);
    void BossBulletMove_ID_7_1(SuperBullet* sbullet);
    void BossBulletMove_ID_7_2(SuperBullet* sbullet);
    void BossBulletMove_ID_7_4(SuperBullet* sbullet);
    void BossBulletMove_ID_7_5(SuperBullet* sbullet);
    //
    void CreateBarEight();
    void BossMove_ID_8(Boss* boss);
    void BossShoot_ID_8_SETDATA(Boss* boss, float basetime);
    void BossShoot_ID_8_BOSS1(Boss* boss, float basetime); //Sloth
    void BossShoot_ID_8_1(Boss* boss, float basetime);
    void BossShoot_ID_8_BOSS2(Boss* boss, float basetime); //Gluttony
    void BossShoot_ID_8_2(Boss* boss, float basetime);
    void BossShoot_ID_8_BOSS3(Boss* boss, float basetime); //Greed
    void BossShoot_ID_8_3(Boss* boss, float basetime);
    void BossShoot_ID_8_BOSS4(Boss* boss, float basetime); //Lust
    void BossShoot_ID_8_4(Boss* boss, float basetime);
    void BossShoot_ID_8_BOSS5(Boss* boss, float basetime); //Envy
    void BossShoot_ID_8_5(Boss* boss, float basetime);
    void BossShoot_ID_8_BOSS6(Boss* boss, float basetime); //Wrath
    void BossShoot_ID_8_6(Boss* boss, float basetime);
    void BossShoot_ID_8_BOSS7(Boss* boss, float basetime); //Pride
    void BossShoot_ID_8_7(Boss* boss, float basetime);
    void BossBulletMove_ID_8_1(SuperBullet* sbullet);
    void BossBulletMove_ID_8_7(SuperBullet* sbullet);
    //
    void CreateBarNine();
    void BossMove_ID_9(Boss* boss);
    void BossShoot_ID_9_SETDATA(Boss* boss, float basetime);
    void BossShoot_ID_9_1(Boss* boss, float basetime);
    void BossShoot_ID_9_2(Boss* boss, float basetime);
    void BossShoot_ID_9_3(Boss* boss, float basetime);
    void BossShoot_ID_9_4(Boss* boss, float basetime);
    void BossBulletMove_ID_9_3(SuperBullet* sbullet);
    void BossBulletMove_ID_9_4(SuperBullet* sbullet);
    bool DeleteBullet_ID_9_3(SuperBullet* sbullet);
    bool DeleteBullet_ID_9_4(SuperBullet* sbullet);

    class OriginBullet : public SuperBullet {
        public:
        sf::Vector2<float> OriginPosition;

        void SetOrigin(float x, float y);
        void SetOrigin(const sf::Vector2<float>& origin);
        sf::Vector2<float> GetOrigin();
    };
}

#define CREATE_LEVEL_SEVEN() \
    imagebuffer=Reader.getFile("Boss7.png"); \
    imagesize=Reader.getEntryFileSize("Boss7.png"); \
    LevelBoss->Texture.loadFromMemory(imagebuffer, imagesize); \
    LevelBoss->SetImage(LevelBoss->Texture); \
    delete[] imagebuffer; \
    \
    imagebuffer=Reader.getFile("Level7Background.png"); \
    imagesize=Reader.getEntryFileSize("Level7Background.png"); \
    LevelBackgroundImage[0].loadFromMemory(imagebuffer, imagesize); \
    delete[] imagebuffer; \
    \
    imagebuffer=Reader.getFile("Level7BossBackground.png"); \
    imagesize=Reader.getEntryFileSize("Level7BossBackground.png"); \
    LevelBackgroundImage[1].loadFromMemory(imagebuffer,imagesize); \
    delete[] imagebuffer; \
    \
    imagebuffer=Reader.getFile("CharPortrait7blur.png"); \
    imagesize=Reader.getEntryFileSize("CharPortrait7blur.png"); \
    BossPortraitImage.loadFromMemory(imagebuffer, imagesize); \
    delete[] imagebuffer; \
    \
    Level7::CreateEnemies(); \
    \
    LevelTime=70; \
    CurrentLevel=LEVEL_SEVEN; \
    LevelMusicID=LEVEL7_THEME; \
    BossMusicID=BOSS7_THEME; \
    LevelBoss->AuraSprite.setColor(sf::Color(255,255,255)); \
    \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("Yeah, I will keep that in mind. Farewell.", LEFT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("If evil does not disappear from people's hearts,\nexpect us back.", RIGHT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("But remember! All of this happened just\nbecause of the human nature.", RIGHT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("Your world is safe. Be happy with your\ncompanions, you deserve it.", RIGHT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("Our power has been consumed. We will soon\nvanish back into the Box.", RIGHT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("What will happen now?", LEFT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("It is. Congratulations, hero, for you have\ncompleted you mission.", RIGHT_TALKING)); \
    EndDialogueList[0].push_back(std::pair<std::string, Speaker>("Is it all over, now?", LEFT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("Irriverent until the end, eh... \"Goodbye\", then.", RIGHT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("I'll be waiting for it, then. Goodbye!", LEFT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("And then, our revenge will be terrible. Wait for\nus.", RIGHT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("No matter what, sooner or later we will be back.", RIGHT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("Very well, Alba. Our defeat is not absolute.", RIGHT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("It's Alba!", LEFT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("Heroine, what is your name?", RIGHT_TALKING)); \
    EndDialogueList[1].push_back(std::pair<std::string, Speaker>("And everything happens all over again.", RIGHT_TALKING)); \
    \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Hero, will you be able to save mankind? Will you\nfulfill your role until the very end?", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Now, humanity's last hope! This world's destiny\nhas been put in your hands!", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("But now you are here. In the end, I will have to\nfight.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("That's why Wrath was protecting me. I needed\nmore time in order to destroy the Box.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("This ancient, magic-reinforced jewel gave them\nthe power to fight us.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Humans are weak, they could never stand a\nchance aganst me. But, the Pandora's Box...", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("Looks like you're totally worth your name. So,\nwhat are you doing here?", LEFT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("You are right, it is Pride, the greatest Sin, that\nyou are talking to.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("\"Their?\", you say? How disrespectful of you.\nDon't be afraid to name us.", RIGHT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("You must be their leader, right?", LEFT_TALKING)); \
    BeginDialogueList[0].push_back(std::pair<std::string, Speaker>("I salute thee, human.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("We lost once, but by defeating this girl we Sins\nwill get our revenge! We will save our honor!\nWe will save our Pride!", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Youthful spirit, full of bursting magic!\nMighty wizard, is this the power of your\nbloodline?", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Wow! Well then, I will be no less! Let's fight!", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Nobody else had the necessary power. We lost\njust because of him.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Has he never told you? As the most expert in\nthe arts of magic, he was the one who, in the\nend, finally sealed us.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Wait, wait, wait! You know my grandpa?", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("The preparations for the ritual are nearing\ncompletion. Soon I'll be able to destroy the\nPandora's Box.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("You're already feeling it, right? As expected\nfrom the grandaughter of such a powerful\nmagician.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Thanks, but... This place, feels a bit strange,\ndoesn't it?", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("It's hard to believe a girl like you got this far,\ncongratulations.", RIGHT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("Whoa, an angel! So cool!", LEFT_TALKING)); \
    BeginDialogueList[1].push_back(std::pair<std::string, Speaker>("I salute thee, human.", RIGHT_TALKING)); \
    \
    Level7::CreateBarNine(); \
    Level7::CreateBarEight(); \
    Level7::CreateBarSeven(); \
    Level7::CreateBarSix(); \
    Level7::CreateBarFive(); \
    Level7::CreateBarFour(); \
    Level7::CreateBarThree(); \
    Level7::CreateBarTwo(); \
    Level7::CreateBarOne();

#endif // LEVEL7_H

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Defines.h"
#include "EffectList.h"
#include "Bullet.h"
#include "Player.h"
#include "Item.h"
#include "Enemies.h"
#include "Audio.h"
#include "ScoreRewards.h"
#include "Background.h"
#include "EffectList.h"
#include "Explosion.h"

struct ResourceFileReader;
struct DataStruct;
class ScrollingBackground;

enum GameMode {
  STORY_MODE,
  PRACTICE_MODE,
  FINAL_MODE,
  EXTRA_MODE
};

enum Level {
    LEVEL_ONE=1,
    LEVEL_TWO=2,
    LEVEL_THREE=3,
    LEVEL_FOUR=4,
    LEVEL_FIVE=5,
    LEVEL_SIX=6,
    LEVEL_SEVEN=7,
    LEVEL_EXTRA=8
};

enum PreHandlerState {
    GOTO_EXIT = -1,
    GOTO_MAINMENU = 0,
    GOTO_NEXTFRAME = 1,
    GOTO_CONTINUE = 2
};

enum Speaker {
    LEFT_TALKING = 0,
    RIGHT_TALKING = 1,
    NONE_TALKING = -1
};

struct GameEngine {
    GameMode Mode; //Story, Practice, Extra
    sf::Clock Timer; //To handle time
    double PastTime; //Total time passed since last reset (level start - boss speaking - boss battle - boss defeated)
    double FrameTime;
    AudioHandler *AudioHandle;
    ScoreRewards ScoreRewarder;

    //Level stuff
    double LevelTime; //How much time before boss appears?
    std::uint64_t Score, MaxScore;
    long Graze;
    bool InGame;
    Level CurrentLevel;
    MyPlayer *Player;
    Boss *LevelBoss;
    std::vector<Enemy*> Enemies;
    std::vector<Bullet*> PlayerBullets;
    std::vector<Bullet*> EnemyBullets;
    ItemPool Items;
    std::vector<std::pair<std::string, Speaker>> BeginDialogueList[2];
    std::vector<std::pair<std::string, Speaker>> EndDialogueList[2];
    MusicID LevelMusicID, BossMusicID;

    //Key flags
    bool UpPressed, DownPressed, LeftPressed, RightPressed;
    bool ZPressed, XPressed, CPressed, ShiftPressed;
    bool LAltPressed, F4Pressed, CrossPressed;

    //Visuals
    sf::Text MaxScoreString, MaxScoreValueString, ScoreString, ScoreValueString;
    sf::Text LivesString, BombsString, PowerString, PowerValueString, ChargeString, ChargeValueString, GrazeString, GrazeValueString;
    sf::RectangleShape PauseGaugeBackground, PauseGaugeFill;
    std::vector<sf::Texture> ExplosionImages;
    std::vector<sf::Texture> EnemyImages;
    std::vector<sf::Texture> BulletImages;
    std::vector<sf::Texture> ItemImages;
    sf::Texture LivesImage;
    sf::Texture BombsImage;
    sf::Texture LevelBackgroundImage[2];
    sf::Sprite LevelBackgroundSprite; ScrollingBackground_Compatibility Background;
    sf::Sprite LevelBossBackgroundSprite;
    sf::Texture OutsideBackgroundImage[2];
    sf::Sprite OutsideBackgroundSprite;
    sf::Sprite LivesSprites[7];
    sf::Sprite BombsSprites[8];
    sf::Texture PlayerPortraitImage[2], BossPortraitImage;
    sf::Sprite PlayerPortraitSprite, BossPortraitSprite;
    sf::Texture BossAuraImage;
    sf::Texture MsgBoxImage;
    sf::Sprite MsgBoxSprite;
    sf::Texture StarImage, ArrowImage;
    EffectList VisualEffects;

    //Member functions
    GameEngine();
    ~GameEngine();
    void CreateMode(GameMode mode); //How many lives-bombs-ecc.?
    void CreateLevel(Level level); //Loads level-specific resources
    int LevelStart();
    void DestroyLevel(); //Free enemies, bullets, etc
    int ExitMenu(); //Pause the game
    void ScreenShot(); //Takes a screenshot
    int HandleEvents(); //Handle events, updates data, if 0, goes to the main menu, if -1 exits
    void Display(); //Render the graphics
    int SaveScreen(); //Enter name, save score

    PreHandlerState PreHandler(std::vector<std::pair<std::string, Speaker> > &Dlist); //You can't bomb, charge and do stuff like that while talking to the boss (empties events' poll)
    void PostDisplayer(std::vector<std::pair<std::string, Speaker> > &Dlist); //Renders characters' portraits and dialogue box during dialogues

    //For Support
    void DeleteBullet(Bullet *bullet, int owner);
    void DestroyEnemy(unsigned pos);
};

#endif

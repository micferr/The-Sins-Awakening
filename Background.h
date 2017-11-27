#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>

struct GameEngine;

class Background {
    public:
    Background();
    virtual ~Background();

    virtual void Load()=0;
    virtual void Display()=0;
};

class ScrollingBackground : public Background {
    GameEngine* EnginePointer;
    sf::RenderWindow *WindowPointer;
    enum {LEVEL, BOSS} Section;

    float LevelTime, BossTime;
    sf::VertexArray LevelVertexArray, BossVertexArray;
    sf::RenderStates LevelRenderStates, BossRenderStates;

    public:

    ScrollingBackground();
    virtual ~ScrollingBackground();

    void Load();
    void BindTextures(const sf::Texture& leveltexture, const sf::Texture& bosstexture);
    void BindEngine(const GameEngine& engine);
    void BindWindow(const sf::RenderWindow& window);
    void SetLevelSection();
    void SetBossSection();
    void Display();
};

class ScrollingBackground_Compatibility : Background {
    sf::Texture BigTexture;
    GameEngine* EnginePointer;
    sf::RenderWindow *WindowPointer;
    enum {LEVEL, BOSS} Section;

    float LevelTime, BossTime;
    sf::VertexArray LevelVertexArray, BossVertexArray;
    sf::RenderStates LevelRenderStates, BossRenderStates;
    public:

    ScrollingBackground_Compatibility();
    virtual ~ScrollingBackground_Compatibility();

    void Load();
    void LoadFromTextures(const sf::Texture& leveltexture, const sf::Texture& bosstexture);
    void BindTextures(const sf::Texture& leveltexture, const sf::Texture& bosstexture);
    void BindEngine(const GameEngine& engine);
    void BindWindow(const sf::RenderWindow& window);
    void SetLevelSection();
    void SetBossSection();
    void Display();
};

#endif // BACKGROUND_H

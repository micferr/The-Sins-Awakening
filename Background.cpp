#include "Background.h"
#include "GameEngine.h"

#include <cmath>
#include <gl/gl.h>

Background::Background() {}

Background::~Background() {}

///ScrollingBackground

ScrollingBackground::ScrollingBackground() : LevelTime(0.f), BossTime(0.f), LevelVertexArray(sf::Quads, 48), BossVertexArray(sf::Quads, 4) {
    for (unsigned i=0; i<12; ++i) {
        LevelVertexArray[i*4].position=sf::Vector2f(25,/*-525*/25+i*110); LevelVertexArray[i*4].texCoords=sf::Vector2f(0,0);
        LevelVertexArray[i*4+1].position=sf::Vector2f(475,/*-525*/25+i*110); LevelVertexArray[i*4+1].texCoords=sf::Vector2f(450,0);
        LevelVertexArray[i*4+2].position=sf::Vector2f(475,/*-525*/25+110+i*110); LevelVertexArray[i*4+2].texCoords=sf::Vector2f(450,110);
        LevelVertexArray[i*4+3].position=sf::Vector2f(25,/*-525*/25+110+i*110); LevelVertexArray[i*4+3].texCoords=sf::Vector2f(0,110);
    }
    {
        BossVertexArray[0].position=sf::Vector2f(25, 25); BossVertexArray[0].texCoords=sf::Vector2f(0,0);
        BossVertexArray[1].position=sf::Vector2f(475, 25); BossVertexArray[1].texCoords=sf::Vector2f(450,0);
        BossVertexArray[2].position=sf::Vector2f(475, 575); BossVertexArray[2].texCoords=sf::Vector2f(450,550);
        BossVertexArray[3].position=sf::Vector2f(25, 575); BossVertexArray[3].texCoords=sf::Vector2f(0,550);
    }
}

ScrollingBackground::~ScrollingBackground() {}

void ScrollingBackground::Load() {}

void ScrollingBackground::BindTextures(const sf::Texture& LevelTexture, const sf::Texture& BossTexture) {
    LevelRenderStates.texture=&LevelTexture;
    BossRenderStates.texture=&BossTexture;
}

void ScrollingBackground::BindEngine(const GameEngine& engine) {
    EnginePointer=const_cast<GameEngine*>(&engine);
}

void ScrollingBackground::BindWindow(const sf::RenderWindow& window) {
    WindowPointer=const_cast<sf::RenderWindow*>(&window);
}

void ScrollingBackground::SetLevelSection() {
    Section=ScrollingBackground::LEVEL;
}

void ScrollingBackground::SetBossSection() {
    Section=ScrollingBackground::BOSS;
    BossTime=-550.f-(110.f-LevelTime);
    while (BossTime<-85.f-550.f)
        BossTime+=110.f;
}

void ScrollingBackground::Display() {
    LevelTime+=EnginePointer->FrameTime*160.f;
    while (LevelTime>0)
        LevelTime-=550.f;
    sf::Transform leveltranslation;
    leveltranslation.translate(0,ceil(LevelTime));
    LevelRenderStates.transform=leveltranslation;
    WindowPointer->draw(LevelVertexArray, LevelRenderStates);

    if (Section==BOSS) {
        BossTime=static_cast<float>(std::min(BossTime+EnginePointer->FrameTime*160.f, 0.0));
        sf::Transform bosstranslation;
        bosstranslation.translate(0,ceil(BossTime));
        BossRenderStates.transform=bosstranslation;
        WindowPointer->draw(BossVertexArray, BossRenderStates);
    }
}

/// ScrollingBackground_Compatibility

ScrollingBackground_Compatibility::ScrollingBackground_Compatibility() : LevelTime(0.f), BossTime(0.f), LevelVertexArray(sf::Quads, 4), BossVertexArray(sf::Quads, 4) {
    LevelVertexArray[0].position=sf::Vector2f(25.f,-85.f); LevelVertexArray[0].texCoords=sf::Vector2f(0.f,0.f);
    LevelVertexArray[1].position=sf::Vector2f(475.f,-85.f); LevelVertexArray[1].texCoords=sf::Vector2f(450.f,0.f);
    LevelVertexArray[2].position=sf::Vector2f(475.f,575.f); LevelVertexArray[2].texCoords=sf::Vector2f(450.f,660.f);
    LevelVertexArray[3].position=sf::Vector2f(25.f,575.f); LevelVertexArray[3].texCoords=sf::Vector2f(0.f,660.f);

    BossVertexArray[0].position=sf::Vector2f(25, 25); BossVertexArray[0].texCoords=sf::Vector2f(0,0);
    BossVertexArray[1].position=sf::Vector2f(475, 25); BossVertexArray[1].texCoords=sf::Vector2f(450,0);
    BossVertexArray[2].position=sf::Vector2f(475, 575); BossVertexArray[2].texCoords=sf::Vector2f(450,550);
    BossVertexArray[3].position=sf::Vector2f(25, 575); BossVertexArray[3].texCoords=sf::Vector2f(0,550);
}

ScrollingBackground_Compatibility::~ScrollingBackground_Compatibility() {}

void ScrollingBackground_Compatibility::Load() {}

void ScrollingBackground_Compatibility::LoadFromTextures(const sf::Texture& leveltexture, const sf::Texture& bosstexture) {
    BindTextures(leveltexture, bosstexture);
}

void ScrollingBackground_Compatibility::BindTextures(const sf::Texture& leveltexture, const sf::Texture& bosstexture) {
    if (leveltexture.getSize().x==0 || leveltexture.getSize().y==0)
        return;

    sf::Image LevelTexture_ToImage=leveltexture.copyToImage(), BigImage;
    BigImage.create(450, 660);
    for (unsigned y=0; y<110; ++y) { //Suffering
        for (unsigned x=0; x<450; ++x) {
            for (unsigned i=0; i<6; ++i) {
                BigImage.setPixel(x, y+i*110, LevelTexture_ToImage.getPixel(x, y));
            }
        }
    }
    BigTexture.loadFromImage(BigImage);
    LevelRenderStates.texture=&BigTexture;
    BossRenderStates.texture=&bosstexture;
}

void ScrollingBackground_Compatibility::BindEngine(const GameEngine& engine) {
    EnginePointer=const_cast<GameEngine*>(&engine);
}

void ScrollingBackground_Compatibility::BindWindow(const sf::RenderWindow& window) {
    WindowPointer=const_cast<sf::RenderWindow*>(&window);
}

void ScrollingBackground_Compatibility::SetLevelSection() {
    Section=ScrollingBackground_Compatibility::LEVEL;
}

void ScrollingBackground_Compatibility::SetBossSection() {
    Section=ScrollingBackground_Compatibility::BOSS;
    BossTime=-550.f-(110.f-LevelTime);
    while (BossTime<-85.f-550.f)
        BossTime+=110.f;
}

void ScrollingBackground_Compatibility::Display() {
    LevelTime+=EnginePointer->FrameTime*160.f;
    while (LevelTime>=110.f)
        LevelTime-=110.f;
    sf::Transform leveltranslation;
    leveltranslation.translate(0,ceil(LevelTime));
    LevelRenderStates.transform=leveltranslation;
    WindowPointer->draw(LevelVertexArray, LevelRenderStates);

    if (Section==BOSS) {
        BossTime=static_cast<float>(std::min(BossTime+EnginePointer->FrameTime*160.f, 0.0));
        sf::Transform bosstranslation;
        bosstranslation.translate(0,ceil(BossTime));
        BossRenderStates.transform=bosstranslation;
        WindowPointer->draw(BossVertexArray, BossRenderStates);
    }
}

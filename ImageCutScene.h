#ifndef IMAGECUTSCENE_H
#define IMAGECUTSCENE_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <initializer_list>
#include <memory>

#include "Global.h"

class SceneSubTitle {
    protected:
        std::vector<sf::Text> Subs;

    public:
        SceneSubTitle()=default;
        SceneSubTitle(std::initializer_list<std::string> subs);
        virtual ~SceneSubTitle();

        void AddSub(const std::string& sub);

        size_t GetNumOfSubs();
        std::string GetSub(size_t index); //return "" on error
};

class SceneImage {
        std::shared_ptr<sf::Texture> Data;
    protected:
        sf::Sprite Background;

    public:
        SceneImage();
        SceneImage(const std::string& filename);
        virtual ~SceneImage();

        void LoadImage(const std::string& filename);

        const sf::Sprite& GetBackground();
};

/*class SceneImage {
        std::string ImageFile;

    public:
        SceneImage(const std::string& filename);
};*/

class Scene : public SceneSubTitle, public SceneImage {
        size_t CurrentSub;
    public:
        Scene();
        Scene(const std::string& imagefile, std::initializer_list<std::string> subs);
        virtual ~Scene();

        bool NextSub(); //true on success, false when no more subs
        void Draw();
        void Display();
};

class CutScene {
        std::vector<Scene> Scenes;
        size_t CurrentScene;

        size_t GetNumOfScenes();

        int DisplayNextScene();
        //void SkipCutScene();
    public:
        CutScene();
        CutScene(std::initializer_list<Scene> scenes);

        int Show();
};

#endif // IMAGECUTSCENE_H

#include "ImageCutScene.h"

#include <functional>

/// - Class SceneSubTitle

SceneSubTitle::SceneSubTitle(std::initializer_list<std::string> subs) {
    for (auto sub : subs)
        AddSub(sub);
}

SceneSubTitle::~SceneSubTitle() {}

void SceneSubTitle::AddSub(const std::string& sub) {
    constexpr unsigned txt_size=25;
    Subs.push_back(sf::Text(sub, Font[TUFFY], txt_size));
    sf::Text& sub_str=Subs.back();
    int i=0;
    for (char c : sub) if(c=='\n') ++i; //++i for each newline
    sub_str.setPosition(400-(sub_str.getLocalBounds().width/2),
                        520-i*txt_size);
    sub_str.setColor(sf::Color(0,0,0,255));
}

size_t SceneSubTitle::GetNumOfSubs() {
    return Subs.size();
}

std::string SceneSubTitle::GetSub(size_t index) {
    if (index>=GetNumOfSubs()) return "";
    else return Subs[index].getString();
}

/// - Class SceneImage

SceneImage::SceneImage() : Data(nullptr) {}

SceneImage::SceneImage(const std::string& filename) : Data(nullptr) {
    LoadImage(filename);
}

SceneImage::~SceneImage() {}

void SceneImage::LoadImage(const std::string& filename) {
    char* imagedata=Reader.getFile(filename);
    size_t imagesize=Reader.getEntryFileSize(filename);
    Data=std::shared_ptr<sf::Texture>(new sf::Texture);
    Data->loadFromMemory(imagedata, imagesize);
    Background.setTexture(*Data);
    Background.setPosition(0,0);
    delete[] imagedata;
}

const sf::Sprite& SceneImage::GetBackground() {
    return Background;
}

/// - Class Scene

Scene::Scene() : CurrentSub(0) {}

Scene::Scene(const std::string& imagefile, std::initializer_list<std::string> subs) :   SceneSubTitle(subs),
                                                                                        SceneImage(imagefile),
                                                                                        CurrentSub(0)
{}

Scene::~Scene() {}

bool Scene::NextSub() {
    if (CurrentSub+1<GetNumOfSubs()) {
        ++CurrentSub;
        return true;
    }
    else
        return false;
}

void Scene::Draw() {
    //MainWindow.clear();
    MainWindow.draw(GetBackground());
    MainWindow.draw(Subs[CurrentSub]);
}

void Scene::Display() {
    MainWindow.display();
}

/// - Class CutScene

size_t CutScene::GetNumOfScenes() {
    return Scenes.size();
}

int CutScene::DisplayNextScene() {
    Scene* scene=&Scenes[CurrentScene];
    ++CurrentScene;
    float QuitTime=0.4+0.6*(CurrentScene<GetNumOfScenes());

    sf::RectangleShape FadingBlack;
    FadingBlack.setSize(sf::Vector2f(802.f,602.f));
    FadingBlack.setPosition(-1.f,-1.f);
    FadingBlack.setFillColor(sf::Color(0,0,0,0));
    sf::Clock Timer;
    Timer.restart();
    float timer;
    bool switched=false;
    while ((timer=Timer.getElapsedTime().asSeconds())<=QuitTime) {
        while (MainWindow.pollEvent(Event))
            if (Event.type==sf::Event::Closed)
                return -1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LAlt) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F4))
            return -1;
        FadingBlack.setFillColor(sf::Color(0,0,0,timer<=0.6 ? 255*(min(timer,0.4f)/0.4f) : 255.f-((timer-0.6f)*255.f/0.4f)));

        if (timer>0.4 && !switched) {
            scene=&Scenes[CurrentScene];
            switched=true;
        }

        scene->Draw();
        MainWindow.draw(FadingBlack);
        MainWindow.display();
    }
    return 0;
}

CutScene::CutScene() : CurrentScene(0)
{}

CutScene::CutScene(std::initializer_list<Scene> scenes) : Scenes(scenes), CurrentScene(0)
{}

int CutScene::Show() {
    StopMusic();
    if (Scenes.size()==0) return 0;
    {
        sf::Clock begin_clock;
        sf::RectangleShape R;
        R.setSize(sf::Vector2f(800.f,600.f));
        R.setPosition(0,0);
        R.setFillColor(sf::Color(0,0,0,255));
        while (begin_clock.getElapsedTime().asSeconds()<0.4) {
            R.setFillColor(sf::Color(0,0,0,255-255*(begin_clock.getElapsedTime().asSeconds()/0.4)));
            while (MainWindow.pollEvent(Event))
                if (Event.type==sf::Event::Closed)
                    return -1;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LAlt) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F4))
                return -1;
            Scenes[0].Draw();
            MainWindow.draw(R);
            MainWindow.display();
            sf::sleep(sf::milliseconds(17));
        }
    }
    while (MainWindow.pollEvent(Event)); //Empties event list
    for (auto i : Scenes) {
        bool Loop=true;
        while (Loop) {
            while (MainWindow.pollEvent(Event)) {
                switch(Event.type) {
                    case sf::Event::KeyPressed:
                        switch (Event.key.code) {
                            case sf::Keyboard::Z:
                                Loop=Scenes[CurrentScene].NextSub();
                                break;
                            case sf::Keyboard::LControl:
                                return 0; //Skips CutScene;
                                break;
                            default:
                                break;
                        }
                        break;
                    case sf::Event::Closed:
                        return -1;
                    default:
                        break;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LAlt) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F4))
                return -1;
            Scenes[CurrentScene].Draw();
            Scenes[CurrentScene].Display();
            sf::sleep(sf::milliseconds(20));
        }
        if (DisplayNextScene()==-1)
            return -1;
    }
    while (MainWindow.pollEvent(Event));
    return 0;
}

#ifndef GAME_HPP
#define	GAME_HPP

#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Scene.hpp"
#include "facade/Window.hpp"
#include "facade/Time.hpp"
#include "facade/Clock.hpp"
#include "facade/Texture.hpp"
#include "GameObject.hpp"
#include "facade/Sound.hpp"
#include "facade/Music.hpp"

namespace gme{ 

//class Camera;
    
class Game {
public:
    Game(sf::Vector2f windowSize, std::string name) ;
    Game(const Game& orig);
    virtual ~Game();
    static void setCurrentScene(Scene *s);
    static void setCurrentScene(std::string n);
    void run();
    virtual void setup() = 0;
    static Scene *getCurrentScene();
    static void addScene(Scene *s);
    static Window *getWindow();
    static Time deltaTime;
    static Time unfixedDeltaTime;
    static float ticPercent;
    static void newTexture(const std::string &path, const std::string &name);
    static Texture *getTexture(const std::string &name);
    static void newSound(const std::string &path, const std::string &name);
    static void newMusic(const std::string &path, const std::string &name);
    static Sound *getSound(const std::string &name);
    static Music *getMusic(const std::string &name);
    
    Clock deltaClock;
    static Clock updateClock;
    static bool debugColliders;
    static GameObject *mainCamera;
    static int addTag(const std::string &s);
    static std::unordered_map<std::string, unsigned int> *getTags();
private:  
    static std::unordered_map<std::string, unsigned int> tagmap;
    static char tagCount;
    static std::vector<Scene*> scenes;
    static std::vector<Texture> textures;
    static std::vector<Sound> sounds;
    static std::vector<Music*> musics;
    static Scene *currentScene;
    //sfml class
    static Window *window;
};

}

#endif	/* GAME_HPP */


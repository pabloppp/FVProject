#ifndef GAME_HPP
#define	GAME_HPP

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Scene.hpp"
#include "facade/Window.hpp"
#include "facade/Time.hpp"
#include "facade/Clock.hpp"
#include "facade/Texture.hpp"
#include "GameObject.hpp"

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
    static void newTexture(const std::string &path, const std::string &name);
    static Texture *getTexture(const std::string &name);
    Clock deltaClock;
    static bool debugColliders;
    static GameObject *mainCamera;
private:   
    static std::vector<Scene*> scenes;
    static std::vector<Texture> textures;
    static Scene *currentScene;
    //sfml class
    static Window *window;
};

}

#endif	/* GAME_HPP */


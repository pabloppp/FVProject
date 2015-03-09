#ifndef SCENE_HPP
#define	SCENE_HPP

#include <vector>

#include "GameObject.hpp"
#include "facade/Clock.hpp"
#include "CollisionGrid.hpp"
#include <Box2D/Box2D.h>

namespace gme{

class Game;
    
class Scene {
public:
    Scene(std::string n = "scene");
    Scene(const Scene& orig);
    virtual ~Scene();
    void addGameObject(GameObject *g);
    void destroyGameObject(GameObject *g);
    void instantiate(GameObject *g);
    std::vector<GameObject*> *getGameObjects();
    virtual void setup() = 0;
    void superSetup();
    void update();
    std::string getName();
    b2World *boxWorld;
    
private:
    std::vector<GameObject*> gameObjects;
    std::string name;
    sf::View mainView;
    Clock updateClock;
    float lastTime;
    int testCount;
    float test1;
    float test2;    
};

}

#endif	/* SCENE_HPP */


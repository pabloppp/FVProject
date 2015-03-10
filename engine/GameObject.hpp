/* 
 * File:   GameObject.hpp
 * Author: pablopernias
 *
 * Created on 12 de febrero de 2015, 1:28
 */

#ifndef GAMEOBJECT_HPP
#define	GAMEOBJECT_HPP

#include <string>
#include <vector>

#include "Component.hpp"
#include "components/Transform.hpp"
#include "components/Renderer.hpp"
#include "components/Collider.hpp"
#include "components/RigidBody.hpp"

namespace gme{
    
class Scene;    
    
class GameObject {
public:
    GameObject(std::string n = "gameObject");
    GameObject(const GameObject& orig);
    virtual ~GameObject();
    void update();
    void earlyUpdate();
    void fixedUpdate();
    void drawGui();
    virtual void setup(){};
    void componentSetup();
    void addTag(std::string t);
    bool hasTag(const std::string &t);
    std::unordered_map<std::string, std::string> *getTags();
    static std::vector<GameObject*> findWithTag(std::string s);
    static std::vector<GameObject*> find(std::string s);
    static void sendMessage(std::string s, float f);
    static void broadcastMessage(std::string s, float f);
    void addComponent(Component* c);
    //template <class T> Component *getComponent();
    void setActive(bool b);
    bool isActive();
    std::string getName();
    void setParent(GameObject *g);
    GameObject *getParent();
    void addChild(GameObject *g);
    void removeChild(GameObject *g);
    std::vector<GameObject*> getChildren();
    RigidBody *getRigidBody();
    Transform *getTransform();
    Collider *getCollider();
    Renderer *getRenderer();
    void onCollision(Collider *col);
    template <class T> 
    inline Component *getComponent(){
        for(int i=0;i<components.size();i++){
            if( dynamic_cast<T>(components.at(i)) ) return components.at(i);
        }
        return NULL;
    }

private:
    GameObject* parent;
    std::vector<GameObject*> children;
    std::vector<Component*> components;
    std::vector<std::string> tags;
    std::unordered_map<std::string, std::string> tagmap;
    std::string name;
    bool active;
    Transform *transform;
    Renderer *renderer;
    Collider *collider;
    RigidBody *rigidBody;
};

}

#endif	/* GAMEOBJECT_HPP */


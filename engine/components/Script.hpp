#ifndef SCRIPT_HPP
#define	SCRIPT_HPP

#include "../Component.hpp"
#include "Transform.hpp"
#include "Renderer.hpp"
#include "Collider.hpp"
#include "RigidBody.hpp"

namespace gme{
    
class Script : public Component{
public:
    virtual void onGui(){};
    virtual void onMessage(std::string m, float v){};
    virtual void onCollision(Collider *c){};
    virtual void fixedUpdate(){};
    Transform *getTransform();
    Renderer *getRenderer();
    Collider *getCollider();
    RigidBody *getRigidBody();
    void destroyGameObject(GameObject * g);
    void instantiate(GameObject * g);
    void sendMessage(std::string s, float f);
    void sendMessageUpward(std::string s, float f);
    void broadcastMessage(std::string s, float f);
private:

};

}

#endif	/* SCRIPT_HPP */


#ifndef RIGIDBODY_HPP
#define	RIGIDBODY_HPP

#include "../Component.hpp"
#include "../facade/Vector2.hpp"
#include "Collider.hpp"

namespace gme{
    
class RigidBody : public Component{
public:
    RigidBody();
    virtual ~RigidBody();
    void update();
    void updatep();
    void setup();

    void push(Vector2 vector);
    void push(Vector2 direction, float force);
    void pushImmediate(Vector2 direction, float force);
    void rotate(float force);
    void rotateImmediate(float force);
    void setGravity(bool g);
    void gravityMultiplier(float f);
    bool hasGravity();
    void onCollision(Collider *c);
    void isKinematic();
    void isDynamic();
    void isStatic();
    void setFixedRot(bool b);
    void setFriction(float f);
    float getFriction();
    void setWeight(float f);
    float getWeight();
    void setElasticity(float f);
    float getElasticity();
    void setSpeed(float x, float y);
    void setSpeed(Vector2 direction, float force);
    Vector2 getSpeed();
    float getAngularSpeed();
    void setAngularSpeed(float f);
    b2BodyDef b2def;
    b2Body* b2body;
    b2FixtureDef fixtureDef;
private:
    float friction;
    float elasticity;
    float weight;
    bool fixedRotation;
};

}

#endif	/* RIGIDBODY_HPP */


#include "player.hpp"
#include "PlayerMovement.hpp"
#include "LifeManager.hpp"

void player::setup() {
    
    std::cout << "player setup" << std::endl;
    
    addTag("player");
    
    getRenderer()->setTexture("playerTexture");
    getRenderer()->setSize(gme::Vector2(32,32));
    getRenderer()->setCenter(gme::Vector2(0.5, 0.7));
    getTransform()->scale = gme::Vector2(3,3);
    
    gme::RigidBody *rigidbody = new gme::RigidBody;
    rigidbody->setWeight(10);
    rigidbody->isDynamic();
    rigidbody->gravityMultiplier(5);
    rigidbody->setFixedRot(true);
    addComponent(rigidbody);
    
    gme::BoxCollider *collider = new gme::BoxCollider;
    collider->setSize(10*3,19*3);
    collider->addFilterTag("player");
    addComponent(collider);
    
    PlayerMovement *playerMovement = new PlayerMovement;
    if(overrideKeys){
        playerMovement->upKey = upKey;
        playerMovement->downKey = downKey;
        playerMovement->leftKey = leftKey;
        playerMovement->rightKey = rightKey;
        playerMovement->jumpKey = jumpKey;
        playerMovement->weaponKey = weaponKey;
        playerMovement->actionKey = actionKey;
    }
    
    LifeManager *stats = new LifeManager();
    
    addComponent(playerMovement);
    addComponent(stats);
}



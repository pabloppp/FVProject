#include "player.hpp"
#include "PlayerMovement.hpp"
#include "LifeManager.hpp"
#include "weapon.hpp"
#include "pistolaBehavior.hpp"
#include "moveToTop.hpp"

void player::setup() {
    
    std::cout << "player setup" << std::endl;
    
    addTag("player");
    
    getRenderer()->setTexture("playerTexture");
    getRenderer()->setSize(gme::Vector2(32,32));
    getRenderer()->setPivot(gme::Vector2(0.5, 1));
    //getRenderer()->setCenter(gme::Vector2(0.5, 0.7));
    getTransform()->scale = gme::Vector2(3,3);
    
    gme::RigidBody *rigidbody = new gme::RigidBody;
    rigidbody->setWeight(10);
    rigidbody->isDynamic();
    rigidbody->gravityMultiplier(5);
    rigidbody->setFixedRot(true);
    rigidbody->setElasticity(0);
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
        playerMovement->changeWeapon = changeWeapon;
    }
    
    LifeManager *stats = new LifeManager();
    stats->maxHp = 10;
    stats->maxLives = 1;
    
    addComponent(playerMovement);
    addComponent(stats);
    
    moveToTop *mtt = new moveToTop();
    mtt->setOrder(-2);
    addComponent(mtt);
}



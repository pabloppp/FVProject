#include "enemyBullet.hpp"

void enemyBullet::setup() {
    getRenderer()->setTexture("enemy_bullet");
    getRenderer()->setSize( gme::Vector2(16,16) );
    getRenderer()->setFrame(gme::Vector2(0, 0));
    getRenderer()->setPivot(gme::Vector2(0.5, 0.5));
    
    getTransform()->setScale(gme::Vector2(3,3));
}

void enemyBullet::update() {

}

void enemyBullet::onCollision(gme::Collider* c) {
    if(c->gameObject()->hasTag("player")){
        c->gameObject()->sendMessage("damage", 25);
    }
}



enemyBullet::~enemyBullet() {
}


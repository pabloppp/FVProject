#include "IABoss.hpp"
#include "emptyGameObject.hpp"
#include "tile.hpp"
#include "sprayParticleScript.hpp"
#include "defaultParticle.hpp"

void IABoss::setup() {
    findPlayer();
    std::cout << getTransform()->getPosition().x << std::endl;
    getTransform()->resize(gme::Vector2(-1,1));
}

void IABoss::findPlayer() {
    player = gme::GameObject::find("p1").at(0);
   if(gme::GameObject::find("p2").size() > 0){
        player2 = gme::GameObject::find("p2").at(0);
   }
   else{
        player2 = NULL;
   }
}


void IABoss::update() {
    /*if(stateManager->isPaused()){
        getRigidBody()->setSpeed(0, 0);
        getRigidBody()->setActive(false);
        return;
    }
    else getRigidBody()->setActive(true);*/
    
    if(player){
       gme::Vector2 playerpos = player->getTransform()->getPosition();
        gme::Vector2 enemypos = getTransform()->getPosition();
        
        if(enemypos.x > playerpos.x-16*3 && enemypos.x < playerpos.x+16*3
                && enemypos.y > playerpos.y-16*3 && enemypos.y < playerpos.y+16*3){
            player->sendMessage("damage", damage);
        }
        
        if(player2 != NULL){
            gme::Vector2 playerpos2 = player2->getTransform()->getPosition();
            
            if(enemypos.x > playerpos2.x-16*3 && enemypos.x < playerpos2.x+16*3
                    && enemypos.y > playerpos2.y-16*3 && enemypos.y < playerpos2.y+16*3){
                player2->sendMessage("damage", damage);
            }
        }
        
        deltatime = gme::Game::deltaTime.asSeconds();
        float dist = speed;
        walkFPS = 30;
        gme::Vector2 inipos = gme::Vector2(16,enemypos.y);
        gme::Vector2 finpos = gme::Vector2(1584-16,enemypos.y);
               
        if( ((gme::Vector2::distance(finpos, enemypos) < 800 && right) || (gme::Vector2::distance(inipos, enemypos) < 800 && !right))){
            dist *= 4;
            walkFPS *= 2;
        }
        
        if(side && clk.currentTime().asSeconds() < 3){
            dist =0;
        }
        
        vectorDirector(playerpos, enemypos);
         if(grounded && getRigidBody()->getSpeed().y >= 0) getRigidBody()->setSpeed(dir, dist);
    }
    
    animate();
    
    grounded = false;
    
}

void IABoss::vectorDirector(gme::Vector2 player, gme::Vector2 enemy) {
    
    std::cout << "enemy: " << enemy.y << std::endl;
    std::cout << "player: " << player.y << std::endl;
    
    if(enemy.x < 16 && !right){
        dir.x = -dir.x;        
        clk.restart();
        right = true;
        side = true;
        getTransform()->resize(gme::Vector2(-1,1));
    }
    
    if(enemy.x > 1510 && right){
        dir.x = -dir.x;        
        clk.restart();
        right = false;
        side = true;
        getTransform()->resize(gme::Vector2(-1,1));
    }
    
    
    
}


void IABoss::onCollision(gme::Collider* c) {
    gme::Vector2 relativePosition = getCollider()->getRelativePosition(c);
    if(c->gameObject()->hasTag("floor")){
        if(relativePosition.y == -1){ //si golpea el suelo
            grounded = true;
        }
    }
    
}

void IABoss::onMessage(std::string m, float v) {

    if(m.compare("kill")==0 && !dead){
        std::cout << "muerte" << std::endl;
        dead = true;
        //explode(20, 50, 50, 250);
    }
    
    if(m.compare("damage")==0 && !dead){
        //explode(3,10, 50, 150);
        std::cout << "damage " << std::endl;
    }
}




void IABoss::animate() {
if(animClock.currentTime().asSeconds() > 1.0f/walkFPS){
            animClock.restart();
            walkFrameCount++;
            if(walkFrameCount > 3) walkFrameCount = 0;
            getRenderer()->setFrame("boss_"+std::to_string(walkFrameCount));
        }
}

IABoss::~IABoss() {

}

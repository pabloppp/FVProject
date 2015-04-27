#include "IABoss.hpp"
#include "emptyGameObject.hpp"
#include "tile.hpp"
#include "sprayParticleScript.hpp"
#include "defaultParticle.hpp"
#include "LifeManager.hpp"
void IABoss::setup() {
    findPlayer();
    std::cout << getTransform()->getPosition().x << std::endl;
    getTransform()->resize(gme::Vector2(-1,1));
     lm = (LifeManager*)gameObject()->getComponent<LifeManager*>();
     
     
    std::vector<gme::GameObject*> *objects = gme::Game::getCurrentScene()->getGameObjects();
    
    for(int i=0;i<objects->size();i++){
        if(objects->at(i) == gameObject()){
            objects->erase(objects->begin()+i);
            objects->push_back(gameObject());
            break;
        }
    } 
   
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
               
        /*if( ((gme::Vector2::distance(finpos, enemypos) < 800 && right) || (gme::Vector2::distance(inipos, enemypos) < 800 && !right))){
            dist *= 4;
            walkFPS *= 2;
        }*/
        //std::cout << "distancia: " << gme::Vector2::distance(playerpos, enemypos) << std::endl;
         if( ((playerpos.x > enemypos.x && right) || (playerpos.x < enemypos.x && !right))
                && gme::Vector2::distance(playerpos, enemypos) < 400  && !sprint && (abs(int(enemypos.y)-int(playerpos.y))<150)){
             std::cout <<"enemy Y" << enemypos.y << std::endl;
             std::cout <<"player Y" << playerpos.y << std::endl;
             sprint =true;
             clkS.restart();
        }
        
        if(sprint && clkS.currentTime().asSeconds() > 1){
            dist *= 4;
            walkFPS *= 2;
            if(lm->getHp() < (lm->getMaxHp()/5)){
                dist*=2;
            }
        }
        if(sprint && clkS.currentTime().asSeconds() < 1){
            dist *= 0;
        }
        
        
        
        if(side && clk.currentTime().asSeconds() < 5){
            dist =0;
        }
        if(side && clk.currentTime().asSeconds() > 15){
            side =false;
            sprint = false;
            
        }
        
        vectorDirector(playerpos, enemypos);
         if(grounded && getRigidBody()->getSpeed().y >= 0){
             getRigidBody()->setSpeed(dir, dist);
            // std::cout << sprint <<std::endl;
         }
    }
    
    animate();
    grounded = false;
    
}

void IABoss::vectorDirector(gme::Vector2 player, gme::Vector2 enemy) {
    
    //std::cout << "enemy: " << enemy.y << std::endl;
    //std::cout << "player: " << player.y << std::endl;
    
    if(enemy.x < 16 && !right){
        dir.x = -dir.x;        
        clk.restart();
        right = true;
        side = true;
        sprint = false;
        getTransform()->resize(gme::Vector2(-1,1));
    }
    
    if(enemy.x > 1510 && right){
        dir.x = -dir.x;        
        clk.restart();
        right = false;
        side = true;
        sprint =false;
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
    
    if(c->gameObject()->hasTag("bullet") && !sprint){
        gme::Vector2 playerpos = player->getTransform()->getPosition();
        gme::Vector2 enemypos = getTransform()->getPosition();    
        if((playerpos.x < enemypos.x && right) || (playerpos.x > enemypos.x && !right) ){
             std::cout <<"dado con una bala  por la espalda" << std::endl;
             dir.x = -dir.x;   
             right = !right;
              getTransform()->resize(gme::Vector2(-1,1));
        }
        
    }
    
}

void IABoss::onMessage(std::string m, float v) {

    if(m.compare("kill")==0 && !dead){
        std::cout << "muerte" << std::endl;
        dead = true;
        explode(20, 50, 50, 250);
    }
    
    if(m.compare("damage")==0 && !dead){
        explode(3,10, 50, 150);
        std::cout << "damage " << std::endl;
    }
}

void IABoss::explode(int min, int max, float forcemin, float forcemax) {
int cantidad = (rand() % (max-min)) + min;
    
    gme::Vector2 pos = getTransform()->getPositionRelative();
    for(int i=0;i<cantidad;i++){
        float dirX = ( (rand() % 200) - 100 ) / 100.f;
        float dirY = ( (rand() % 200) - 100 ) / 100.f;
        int force = (rand() % (int)(forcemax-forcemin)) + forcemin;
        defaultParticle *particle = new defaultParticle("blood"); 
        particle->startingPosition = pos;
        instantiate(particle);
        particle->getTransform()->setPosition(pos);
        
        ((sprayParticleScript*)(particle->getComponent<sprayParticleScript*>()))->sticky = true;
        
        particle->getRenderer()->setColor(255,0,0);
        particle->getRigidBody()->pushImmediate(gme::Vector2(dirX, dirY), force);
                
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

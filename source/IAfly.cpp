/* 
 * File:   IAfly.cpp
 * Author: albertomartinezmartinez
 * 
 * Created on 12 de mayo de 2015, 18:59
 */

#include "IAfly.hpp"
#include "Animator.hpp"
#include "defaultParticle.hpp"
#include "sprayParticleScript.hpp"
#include "tile.hpp"

void IAfly::setup() {
    findPlayer();
    std::vector<gme::GameObject*> *objects = gme::Game::getCurrentScene()->getGameObjects();
    
    for(int i=0;i<objects->size();i++){
        if(objects->at(i) == gameObject()){
            objects->erase(objects->begin()+i);
            objects->push_back(gameObject());
            break;
        }
    }
    
     std::vector<gme::GameObject*> gm = gme::GameObject::find("manager");
    if(gm.size() > 0){
        GlobalStateManager *gsm = (GlobalStateManager*)(gm.at(0)->getComponent<GlobalStateManager*>());
        if(gsm != NULL){
            stateManager = gsm;
        }
    }
    gme::Vector2 pos1 = gme::Vector2(100,50);
    gme::Vector2 pos2 = gme::Vector2(200,50);
    gme::Vector2 pos3 = gme::Vector2(800,50);
    posiciones.push_back(pos1);
    posiciones.push_back(pos2);
    posiciones.push_back(pos3);
}

void IAfly::update() {
    if(stateManager->isPaused()){
        getRigidBody()->setSpeed(0, 0);
        getRigidBody()->setActive(false);
        return;
    }
    else getRigidBody()->setActive(true);
    
    if(player){
       gme::Vector2 playerpos = player->getTransform()->getPosition();
        gme::Vector2 enemypos = getTransform()->getPosition();
        
        if(enemypos.x > playerpos.x-16*3 && enemypos.x < playerpos.x+16*3
                && enemypos.y > playerpos.y-16*3 && enemypos.y < playerpos.y+16*3){
            player->sendMessage("damage", damage);
            if(!back) moveToInit();
        }
        
        if(player2 != NULL){
            gme::Vector2 playerpos2 = player2->getTransform()->getPosition();
            
            if(enemypos.x > playerpos2.x-16*3 && enemypos.x < playerpos2.x+16*3
                    && enemypos.y > playerpos2.y-16*3 && enemypos.y < playerpos2.y+16*3){
                player2->sendMessage("damage", damage);
               if(!back) moveToInit();
            }
        }
        
       float dist = speed;
       
       float distance = gme::Vector2::distance(playerpos, enemypos);
      
       
       if(distance < 300 && !back){
           dist *= 2;
           if(!sprint) sprint=true;
       }
        
      if( gme::Vector2::distance(init,enemypos) < 10 && back && !wait){
          
          clkG.restart();
          wait = true;
      }
      
       if(stop && !grounded && back && wait){
           dist=0;
           stop = true;
       }
       
      if(wait && clkG.currentTime().asSeconds() > 1) {
          back = false;
          wait = false;
      }
       
       
        if(!back) vectorDirector(playerpos,enemypos);
        if(back) vectorDirector(init,enemypos);
       
       /*if(enemy_boss) std::cout << "El enemigo e sun jefazo" << std::endl;
       else std::cout << "El enemigo es nomalucho" << std::endl;
       */
        getRigidBody()->setSpeed(dir, dist);
    }
        grounded = false;
        
}

void IAfly::vectorDirector(gme::Vector2 player,gme::Vector2 enemy) {
    if(enemy.x < 16*3 && !right){
        dir.x = 1;
        right = true;
        change = true;
        return;
    }
    if(enemy.x > 1526-16*3 && right){
        dir.x = -1;
        right = false;
        change = true;
        return;
    }
    
    float h = player.y -5;
    float H = player.y +5;
    float w = player.x -5;
    float W = player.x +5;
    //std::cout << player.y << " p/e " << enemy.y << std::endl;
    
    
    //if(enemy.x > player.x - 5 && enemy.x < player.x +5) stop = true;;
    
    if(enemy.x > w && enemy.x < W) dir.x=0;
    
    if(player.x < enemy.x && right){
        dir.x = -1;
        right = false;
    }
    
    if(player.x > enemy.x && !right){
        dir.x = 1;
        right = true;
    }
    
    if(enemy.y > h && enemy.y < H) dir.y=0;
    if(player.y > enemy.y && down){
        dir.y = 1;
        down = false;
    }
    if(player.y < enemy.y && !down){
        dir.y = -1;
        down = true;
    }
    if(grounded){
        float difference = std::abs(enemy.y-player.y);
        if(gdir.x != 0){
            dir.y = 1;
            down = false;
            if(player.y < enemy.y && !down && difference > 25){
                dir.y = -1;
                down = true;
            }
        }
        
        if(gdir.y != 0){
            if(difference > 50){
                std::cout << difference << " dif " << std::endl;
            }
        }
        
    }
    
}


void IAfly::findPlayer() {
     player = gme::GameObject::find("p1").at(0);
   if(gme::GameObject::find("p2").size() > 0){
        player2 = gme::GameObject::find("p2").at(0);
   }
   else{
        player2 = NULL;
   }
}

void IAfly::moveToInit() {
        std::cout << "volver a la position de inicio" << std::endl;
        pos = rand()%3;
        init = posiciones.at(pos);
        std::cout << init.x << " " << init.y << std::endl;
        back = true;
        sprint = false;
    
}


void IAfly::onCollision(gme::Collider* c) {
    gme::Vector2 rP = getCollider()->getRelativePosition(c);
    if(c->gameObject()->hasTag("floor")){
        //if(sprint) moveToInit();
        grounded = true;
        gdir = rP;
    }
    if(c->gameObject()->hasTag("corner")){
           cornered = ((tile*)(c->gameObject()))->side;
    }
    
}

void IAfly::animate() {

}

void IAfly::onMessage(std::string m, float v) {
    if(m.compare("kill")==0 && !dead){
        std::cout << "muerte" << std::endl;
        dead = true;
        explode(20, 50, 50, 250);
    }
    
    if(m.compare("damage")==0 && !dead){
        explode(3,10, 50, 150);
    }
}


void IAfly::explode(int min, int max, float forcemin, float forcemax) {
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

void IAfly::onGui() {
    gme::Vector2 enemyPos = getTransform()->getPosition();
    gme::Vector2 enemyPosWindow = enemyPos.worldToScreen();
    if(enemyPosWindow.x < -32*3){
        gme::GUI::globalRotation = 90;
        float posy = enemyPosWindow.y;
        if(posy < 16*3 ) posy = 16*3;
        else if(posy > 576-16*3) posy = 576-16*3;
        gme::GUI::drawTexture(
            gme::Vector2(16*3+8*3, posy),
            gme::Vector2(16*3, 16*3),
            gme::GUI::TextureName("indicator_enemy"),
            gme::GUI::Origin::Center,
            gme::GUI::ScaleToFit
        );
    }
    else if(enemyPosWindow.x > 1024+32*3){
        gme::GUI::globalRotation = -90;
        float posy = enemyPosWindow.y;
        if(posy < 16*3 ) posy = 16*3;
        else if(posy > 576-16*3) posy = 576-16*3;
        gme::GUI::drawTexture(
            gme::Vector2(1024-8*3, posy),
            gme::Vector2(16*3, 16*3),
            gme::GUI::TextureName("indicator_enemy"),
            gme::GUI::Origin::Center,
            gme::GUI::ScaleToFit
        );
    }
    else if(enemyPosWindow.y > 576){
        gme::GUI::globalRotation = 0;
        float posx = enemyPosWindow.x;
        if(posx < 16*3 ) posx = 16*3;
        else if(posx > 1024-16*3) posx = 576-16*3;
        gme::GUI::drawTexture(
            gme::Vector2(posx, 576-8*3),
            gme::Vector2(16*3, 16*3),
            gme::GUI::TextureName("indicator_enemy"),
            gme::GUI::Origin::Center,
            gme::GUI::ScaleToFit
        );
    }
    gme::GUI::globalRotation = 0;
}

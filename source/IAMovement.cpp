/* 
 * File:   IAMovement.cpp
 * Author: albertomartinezmartinez
 * 
 * Created on 14 de abril de 2015, 18:18
 */

#include "IAMovement.hpp"
#include "emptyGameObject.hpp"
#include "tile.hpp"

void IAMovement::findPlayer() {
   player = gme::GameObject::find("p1").at(0);
}

void IAMovement::setup() {
    right = true;
    timepas=3;
    check = 0;
    jumping = false;
    dead = false;
    destroyed = false;
    
    /*std::vector<gme::GameObject*> *objects = gme::Game::getCurrentScene()->getGameObjects();
    for(int i=0;i<objects->size();i++){
        if(objects->at(i) == gameObject()){
            objects->erase(objects->begin()+i);
            objects->push_back(gameObject());
            break;
        }
    }*/
    
    spawn = getTransform()->getPosition();
    
    trigger = new emptyGameObject("coltrigger");
    trigger->addComponent(new gme::RigidBody());
    trigger->getRigidBody()->isStatic();
    trigger->getRenderer()->setSize(gme::Vector2(32,32));
    trigger->getRenderer()->setPivot(gme::Vector2(0.5,1));
    gme::BoxCollider *bc = new gme::BoxCollider();
    bc->isTrigger(true);
    trigger->addComponent(bc);
    trigger->addTag("enemy");
    gameObject()->addChild(trigger);
    instantiate(trigger);
    trigger->getTransform()->setPosition(gme::Vector2(0,0));
    
    findPlayer();
    
}

void IAMovement::update() { 
     
    trigger->getTransform()->position = gme::Vector2(0,0);
    
    if(player){
        gme::Vector2 playerpos = player->getTransform()->getPosition();
        gme::Vector2 enemypos = getTransform()->getPosition();
        
        if(enemypos.x < -16*3 || enemypos.x > 1584-16*3){
            if(random()%3 == 1){
                getTransform()->setPosition(spawn);
                enemypos = spawn;
                getRenderer()->setColor(255,150,150);
            }
            else{
                dead = true;
            }
        }
        
        deltatime = gme::Game::deltaTime.asSeconds();
        float dist = 7;
        walkFPS = 30;
               
        if( ((playerpos.x > enemypos.x && right) || (playerpos.x < enemypos.x && !right))
                && gme::Vector2::distance(playerpos, enemypos) < 200 ){
            dist *= 2;
            walkFPS *= 2;
        }
        
        vectorDirector(playerpos, enemypos);
        
        
       
        
        //getTransform()->translate(dir,dist*deltatime);
        
        if(grounded && getRigidBody()->getSpeed().y >= 0) getRigidBody()->setSpeed(dir, dist);
        
        jump(playerpos,enemypos);
        
    }
    
    animate();
    
    grounded = false;
    
    
    cornered = 0;
    
    //if(dead) gameObject()->sendMessage("damage", 999999);
    
}

void IAMovement::jump(gme::Vector2 player, gme::Vector2 enemy) {
    //getRigidBody()->pushImmediate(dir,40000*deltatime);
    
    /*if(player.y < enemy.y && !jumping && elapsetime == 0){
        std::cout << "jugador por encima" << std::endl;
        elapsetime = clkJ.currentTime().asSeconds();
    }*/
    
    
    if(clkJ.currentTime().asSeconds() > 5 && player.y < enemy.y && getRigidBody()){
        clkJ.restart();
        grounded = false;
        std::cout << "jumping: " << 40000*deltatime << std::endl;
        getRigidBody()->pushImmediate(gme::Vector2(0,-1), 20000*deltatime);
    }
    
    if(cornered != 0 && !acted){
        acted = true;
        
        if(right){ //ENEMIGO MIRANDO A LA DERECHA
            if(cornered == 2){
                if(player.x > enemy.x){
                    if(player.y <= enemy.y){
                        //SALTAR
                        clkJ.restart();
                        grounded = false;
                        std::cout << "jumping: " << 40000*deltatime << std::endl;
                        getRigidBody()->pushImmediate(gme::Vector2(0,-1), 25000*deltatime);
                    }
                    else{
                        //NO HACER NADA
                    }
                }
                else{
                    if(player.y <= enemy.y){
                        //MEDIA VUELTa
                        dir.x = -dir.x;        
                        clk.restart();
                        right = !right;
                        getTransform()->resize(gme::Vector2(-1,1));
                    }
                    else{
                        //NO HACER NADA
                    }
                }
            }
            else{
                if(player.y <= enemy.y){
                    //SALTAR
                    clkJ.restart();
                    grounded = false;
                    std::cout << "jumping: " << 40000*deltatime << std::endl;
                    getRigidBody()->pushImmediate(gme::Vector2(0,-1), 20000*deltatime);
                }
                //NO HACER NADA
            }
            
        }
        else{ //ENEMIGO MIRANDO A LA IZQUIERDA
            if(cornered == 2){
                if(player.y <= enemy.y){
                    //SALTAR
                    clkJ.restart();
                    grounded = false;
                    std::cout << "jumping: " << 40000*deltatime << std::endl;
                    getRigidBody()->pushImmediate(gme::Vector2(0,-1), 25000*deltatime);
                }
                else{
                    //NO HACER NADA
                }
            }
            else{
                if(player.x < enemy.x){
                    if(player.y <= enemy.y){
                        //SALTAR
                        clkJ.restart();
                        grounded = false;
                        std::cout << "jumping: " << 40000*deltatime << std::endl;
                        getRigidBody()->pushImmediate(gme::Vector2(0,-1), 20000*deltatime);
                    }
                    else{
                        //NO HACER NADA
                    }
                }
                else{
                    if(player.y <= enemy.y){
                        //MEDIA VUELTa
                        dir.x = -dir.x;        
                        clk.restart();
                        right = !right;
                        getTransform()->resize(gme::Vector2(-1,1));
                    }
                    else{
                        //NO HACER NADA
                    }
                }
            }
        }   
        
    }
    else if(cornered == 0 && acted){
        acted = false;
    }
    
      
}

void IAMovement::animate() {
    if(animClock.currentTime().asSeconds() > 1.0f/walkFPS){
            animClock.restart();
            walkFrameCount++;
            if(walkFrameCount >= 14) walkFrameCount = 0;
            getRenderer()->setFrame(std::to_string(walkFrameCount+1));
        }
}



void IAMovement::vectorDirector(gme::Vector2 player, gme::Vector2 enemy) {
   
    
    /*if(enemy.x < 16 && !right){
        dir.x = -dir.x;        
        clk.restart();
        right = true;
        getTransform()->resize(gme::Vector2(-1,1));
    }
    
    if(enemy.x > 1584-16 && right){
        dir.x = -dir.x;        
        clk.restart();
        right = false;
        getTransform()->resize(gme::Vector2(-1,1));
    }*/
    
    if(player.x == enemy.x) clk.restart();
    
    if(player.y >= enemy.y){
        if(player.x < enemy.x && clk.currentTime().asSeconds()>timepas && right){
            dir.x = -dir.x;
            clk.restart();
            right= false;
            getTransform()->resize(gme::Vector2(-1,1));
        }

        if(player.x > enemy.x && clk.currentTime().asSeconds()>timepas && !right){
            dir.x = -dir.x;
            /*Falta cambiar la direccion del sprite*/

            clk.restart();
            right= true;
            getTransform()->resize(gme::Vector2(-1,1));
        }
    }
    
        
}



IAMovement::~IAMovement() {
}

void IAMovement::onCollision(gme::Collider* c) {
    gme::Vector2 relativePosition = getCollider()->getRelativePosition(c);
    if(gameObject()->hasTag("enemy") && c->gameObject()->hasTag("floor")){       
        if(relativePosition.y == -1){ //si golpea el suelo
            grounded = true;
        }
    }
    
    if(c->gameObject()->hasTag("player")){
        c->gameObject()->sendMessage("damage", 5);
    }
    
    if(c->gameObject()->hasTag("corner")){  
        cornered = ((tile*)(c->gameObject()))->side;
    }
}

void IAMovement::onMessage(std::string m, float v) {

    if(m.compare("kill")==0 && !dead){
        std::cout << "muerte" << std::endl;
        dead = true;
    }
}



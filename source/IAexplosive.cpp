

#include "IAexplosive.hpp"
#include "tile.hpp"
#include "sprayParticleScript.hpp"
#include "defaultParticle.hpp"

void IAexplosive::setup() {
findPlayer();
    std::vector<gme::GameObject*> *objects = gme::Game::getCurrentScene()->getGameObjects();
    
    for(int i=0;i<objects->size();i++){
        if(objects->at(i) == gameObject()){
            objects->erase(objects->begin()+i);
            objects->push_back(gameObject());
            break;
        }
    }
    
    
    spawn = getTransform()->getPosition();
   
    
     std::vector<gme::GameObject*> gm = gme::GameObject::find("manager");
    if(gm.size() > 0){
        GlobalStateManager *gsm = (GlobalStateManager*)(gm.at(0)->getComponent<GlobalStateManager*>());
        if(gsm != NULL){
            stateManager = gsm;
        }
    }
}

void IAexplosive::update() {
if(stateManager->isPaused()){
        getRigidBody()->setSpeed(0, 0);
        getRigidBody()->setActive(false);
        return;
    }
    else getRigidBody()->setActive(true);
    
    if(player){
        
       gme::Vector2 playerpos = player->getTransform()->getPosition();
        gme::Vector2 enemypos = getTransform()->getPosition();
        float distance = gme::Vector2::distance(playerpos,enemypos);
        
        
        
        if(enemypos.x < -16*3 || enemypos.x > 1584-16*3){
            if(random()%3 == 1){
                getTransform()->setPosition(spawn);
                enemypos = spawn;
                
                fixPos = true;
                
                //getRenderer()->setColor(getRenderer()->getColorR(),getRenderer()->getColorG()-100,getRenderer()->getColorB()-100);
            }
        }
        
         deltatime = gme::Game::deltaTime.asSeconds();
        float dist = speed;
        
        
        
        if(distance <= 500) {
            if(!wait && !sprint){
                wait =true;
                sprint =true;
                boomb = true;
                clkW.restart();
                clkB.restart();
            }
        }
        
        
        if(wait && clkW.currentTime().asSeconds() > 1) wait =false;
        if(wait) dist *=0;
        if(!wait && sprint) dist +=3;
        
        
        
        if(boomb && clkB.currentTime().asSeconds() > 3){
            if(distance <=  5) player->sendMessage("explote",50);
            else if(distance <= 10) player->sendMessage("explote",25);
            else if(distance <= 20) player->sendMessage("explote",15);
            else player->sendMessage("explote",0);
            if(player2 != NULL){
                gme::Vector2 playerpos2 = player->getTransform()->getPosition();
                float distance2 = gme::Vector2::distance(playerpos2,enemypos);
                if(distance2 <=  5) player2->sendMessage("explote",50);
                else if(distance2 <= 10) player2->sendMessage("explote",25);
                else if(distance2 <= 20) player2->sendMessage("explote",15);
                else player2->sendMessage("explote",0);
            }
            boomb = false;
            std::cout << "debe expltar el enemigo" << std::endl;
            explode(20, 50, 50, 250);
        }
        
        vectorDirector(playerpos, enemypos);
        if(grounded && getRigidBody()->getSpeed().y >= 0) getRigidBody()->setSpeed(dir, dist);
        
        jump(playerpos,enemypos);
       
         
    }
    grounded = false;
}


void IAexplosive::vectorDirector(gme::Vector2 player, gme::Vector2 enemy) {
   
    
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


void IAexplosive::jump(gme::Vector2 player, gme::Vector2 enemy) {
    //getRigidBody()->pushImmediate(dir,40000*deltatime);
    
    /*if(player.y < enemy.y && !jumping && elapsetime == 0){
        std::cout << "jugador por encima" << std::endl;
        elapsetime = clkJ.currentTime().asSeconds();
    }*/
    
    
    if(clkJ.currentTime().asSeconds() > 5 && player.y < enemy.y && getRigidBody()){
        clkJ.restart();
        grounded = false;
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


void IAexplosive::findPlayer() {
     player = gme::GameObject::find("p1").at(0);
   if(gme::GameObject::find("p2").size() > 0){
        player2 = gme::GameObject::find("p2").at(0);
   }
   else{
        player2 = NULL;
   }
}

void IAexplosive::onCollision(gme::Collider* c) {
    gme::Vector2 relativePosition = getCollider()->getRelativePosition(c);
    if(gameObject()->hasTag("enemy") && c->gameObject()->hasTag("floor")){       
        if(relativePosition.y == -1){ //si golpea el suelo
            grounded = true;
        }
    }
    
    if(c->gameObject()->hasTag("corner")){  
        cornered = ((tile*)(c->gameObject()))->side;
    }
    
    if(c->gameObject()->hasTag("bullet")){
        //explode(3,10);
    }
}

void IAexplosive::onMessage(std::string m, float v) {
    if(m.compare("kill")==0 && !dead){
        std::cout << "muerte" << std::endl;
        dead = true;
        explode(20, 50, 50, 250);
    }
    
    if(m.compare("damage")==0 && !dead){
        explode(3,10, 50, 150);
    }
    
    if(m.compare("explote") == 0){
        std::cout << "boooom" << std::endl;
    }
}


void  IAexplosive::explode(int min, int max, float forcemin, float forcemax) {
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
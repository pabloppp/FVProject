
#include "IAMovement.hpp"
#include "emptyGameObject.hpp"
#include "tile.hpp"
#include "sprayParticleScript.hpp"
#include "defaultParticle.hpp"
#include "mainGame.hpp"

void IAMovement::findPlayer() {
   int rnd = int(rand() % 100);
   if(!mainGame::coop || rnd < 50){
        player = gme::GameObject::find("p1").at(0);
        if(gme::GameObject::find("p2").size() > 0){
             player2 = gme::GameObject::find("p2").at(0);
        }
        else{
             player2 = NULL;
        }
   }
   else{
        player = gme::GameObject::find("p2").at(0);
        if(gme::GameObject::find("p1").size() > 0){
             player2 = gme::GameObject::find("p1").at(0);
        }
        else{
             player2 = NULL;
        }
   }
}

void IAMovement::setup() {
    right = true;
    timepas=3;
    check = 0;
    jumping = false;
    dead = false;
    destroyed = false;
    
    fixPos = true;
    
    spawn = getTransform()->getPosition();
    
    findPlayer();
    
    std::vector<gme::GameObject*> gm = gme::GameObject::find("manager");
    if(gm.size() > 0){
        GlobalStateManager *gsm = (GlobalStateManager*)(gm.at(0)->getComponent<GlobalStateManager*>());
        if(gsm != NULL){
            stateManager = gsm;
        }
    }
    
   danyoEnemigo_sound = new gme::SoundPlayer();
   danyoEnemigo_sound->setSound("danyo2");
   danyoEnemigo_sound->setVolume(30.0);
   
   explosionEnemigo_sound = new gme::SoundPlayer();
   explosionEnemigo_sound->setSound("explosionEnemigo");
   
          
}

void IAMovement::update() { 
     
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
        }
        
        if(player2 != NULL){
            gme::Vector2 playerpos2 = player2->getTransform()->getPosition();
            
            if(enemypos.x > playerpos2.x-16*3 && enemypos.x < playerpos2.x+16*3
                    && enemypos.y > playerpos2.y-16*3 && enemypos.y < playerpos2.y+16*3){
                player2->sendMessage("damage", damage);
            }
        }
        
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
        walkFPS = 30;
               
        if( ((playerpos.x > enemypos.x && right) || (playerpos.x < enemypos.x && !right))
                && gme::Vector2::distance(playerpos, enemypos) < 200 ){
            dist *= 2;
            walkFPS *= 2;
            sendMessage("detected", 0);
        }
        
        vectorDirector(playerpos, enemypos);
        
        
        if(grounded && getRigidBody()->getSpeed().y >= 0) getRigidBody()->setSpeed(dir, dist);
        
        jump(playerpos,enemypos);
        
    }
    
    animate();
    
    grounded = false;
    cornered = 0;
    
}

void IAMovement::jump(gme::Vector2 player, gme::Vector2 enemy) {
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
    
    if(c->gameObject()->hasTag("corner")){  
        cornered = ((tile*)(c->gameObject()))->side;
    }
    
    if(c->gameObject()->hasTag("bullet")){
        //explode(3,10);
    }
}

void IAMovement::onMessage(std::string m, float v) {
    if(m.compare("kill")==0 && !dead){
        if(mainGame::sound)explosionEnemigo_sound->play();
        std::cout << "muerte" << std::endl;
        
        mainGame::kills += 1;
        mainGame::saveProfile();
        
        if(lasthitby == 1){
            if(player->getName().compare("p1") == 0){
                player->sendMessage("givePoints", 150);
            }
            else if(player2 != NULL ){
                player2->sendMessage("givePoints", 150);
            }
        }
        else if(lasthitby == 2){
            if(player->getName().compare("p2") == 0) player->sendMessage("givePoints", 150);
            else if(player2 != NULL ){
                player2->sendMessage("givePoints", 150);
            }
        }       
        dead = true;
        explode(20, 50, 50, 250);
    }    
    if(m.compare("damage")==0 && !dead){
        
        if(clksound.currentTime().asSeconds() > 0.9){
            if(mainGame::sound)danyoEnemigo_sound->play();
            clksound.restart();
        }
        explode(3,10, 50, 150);
    }
    if(m.compare("iam")==0){
        lasthitby = v;
        std::cout << "esp: " << v << std::endl;
    }
}

void IAMovement::explode(int min, int max, float forcemin, float forcemax) {
    if(mainGame::particles == 0) return;
    else if(mainGame::particles == 1){
        max /= 4.0;
        min /= 4.0;
    } 
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

void IAMovement::onGui() {
    
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





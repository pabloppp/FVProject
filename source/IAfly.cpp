/* 
 * File:   IAfly.cpp
 * Author: albertomartinezmartinez
 * 
 * Created on 15 de mayo de 2015, 14:58
 */

#include "IAfly.hpp"
#include "defaultParticle.hpp"
#include "sprayParticleScript.hpp"
#include "mainGame.hpp"

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
     
    // posiciones iniciales
     
     positions.push_back(gme::Vector2(100,50));
     positions.push_back(gme::Vector2(800,50));
     positions.push_back(gme::Vector2(1200,50));
     
     wavePositions.push_back(gme::Vector2(200,50));
     wavePositions.push_back(gme::Vector2(1300,50));
     
     
     fly_sound = new gme::SoundPlayer();
     fly_sound->setSound("flySound");
     
     danyoEnemigo_sound = new gme::SoundPlayer();
    danyoEnemigo_sound->setSound("danyo2");
    danyoEnemigo_sound->setVolume(30.0);
   
    explosionEnemigo_sound = new gme::SoundPlayer();
    explosionEnemigo_sound->setSound("explosionEnemigo");

    
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
            sprint = false;
            if(!enemy_boss)moveToInit();
        }
        
        if(player2 != NULL){
            gme::Vector2 playerpos2 = player2->getTransform()->getPosition();
            
            if(enemypos.x > playerpos2.x-16*3 && enemypos.x < playerpos2.x+16*3
                    && enemypos.y > playerpos2.y-16*3 && enemypos.y < playerpos2.y+16*3){
                player2->sendMessage("damage", damage);
                sprint = false;
                if(!enemy_boss)moveToInit();
            }
        }
        
        
        float dist = speed;
        gme::Vector2 desp = dir;
        if(!enemy_boss){
            float distance = gme::Vector2::distance(playerpos,enemypos);

            if(distance < 400 && !sprint && !home){
                sprint = true;
            }
            if(sprint) dist*=2;

            if(home ){
                //float disthome = gme::Vector2::distance(init,enemypos);
                if(clkW.currentTime().asSeconds() > 5){
                    home = false;
                    clkW.restart();
                }
            }
  
            


            if(!home)vectorDirector(playerpos,enemypos);
            if(home) vectorDirector(init,enemypos);
            if(boing && !grounded) desp.x =0;
            if(Vboing && !corner) desp.y = 0;
            getRigidBody()->setSpeed(desp, dist);
        }
        else{
            bossAttack(); 
             
            
            if(chase) {
                vectorDirector(playerpos,enemypos);
                std::cout << "CHASE" <<std::endl;
            }
            
            if(fallDown){
                fallDownAttack(playerpos,enemypos);
                std::cout << "FALL DOWN" <<std::endl;
                if(grounded && wait && caida){
                    clkW.restart();
                    caida = false;
                }
                
                if(wait && clkW.currentTime().asSeconds() < 2) dist = 0;
                if(wait && clkW.currentTime().asSeconds() >= 2){
                    wait = false;
                    if(mainGame::sound)fly_sound->play();
                }
                if(grounded && !wait && !caida) desp.y = -1;
                
            }
            
            
            
            if(wave){
                float iDist = gme::Vector2::distance(init,enemypos);
                float fDist = gme::Vector2::distance(finalpos,enemypos);
                float pDist = gme::Vector2::distance(attack,enemypos);
                float hDiff = std::abs(playerpos.y-enemypos.y);
                 
                if(!invert) waveAttack(playerpos,enemypos);
                
                //std::cout <<"init: " << init.x << " " <<init.y << std::endl;
                //std::cout <<"final: " << finalpos.x << " " <<finalpos.y << std::endl;
               
                if(iDist > 10 && !wait && !back){
                    vectorDirector(init,enemypos);
                }
                else if(iDist < 10 && !wait && !back){
                    wait = true;
                    clkW.restart();
                    
                }
                
                
                
                if(fDist > 10 && !wait && back){
                    vectorDirector(finalpos,enemypos);
                }
               if(fDist < 10 && !wait && back){
                   
                   std::cout <<"init: " << init.x << " " <<init.y << std::endl;
                std::cout <<"final: " << finalpos.x << " " <<finalpos.y << std::endl;
                
                std::cout <<"wait: " << wait  << " crash" << crash << std::endl;
                //std::cout <<"final: " << finalpos.x << " " <<finalpos.y << std::endl;
                   
                   
                     wait = true;
                    home = false;
                    back = false;
                    invert = false;
                    clkW.restart();
                }
               
                 if(wait && clkW.currentTime().asSeconds() < 2){
                     dist = 0;

                 }
                 if (wait && clkW.currentTime().asSeconds() >2){
                     wait = false;
                     if(!back)crash = true;
                     invert = true;
                     
                     
                 }
                
                if(crash && pDist > 10){
                    vectorDirector(attack,enemypos);
                    dist *=3;
                }
                else if(crash && pDist < 10){
                    wait = true;
                    clkW.restart();
                    back=true;
                    crash = false;
                }
               
                
                //getRigidBody()->setSpeed(10*speedX,1*speedY);
            }
            
            
            
            if(boing) desp.x =0;
            if(Vboing) desp.y = 0;
            getRigidBody()->setSpeed(desp, dist);
            
        }
        
        if(first){
            first=false;
            if(playerpos.x > enemypos.x){
                dir.x = 1;
                right = false;
            }
            if(playerpos.x < enemypos.x){
                dir.x = -1;
                right = true;
            }
        }
        
    }
    
    grounded = false;
    corner =  false;
    boing = false;
    Vboing = false;
    anmate();
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
    int rnd = rand() %3;
    init = positions.at(rnd);
    home = true;
    clkW.restart();
}


void IAfly::vectorDirector(gme::Vector2 player, gme::Vector2 enemy) {

    //std::cout << "Player: " << player.x << " " << player.y << std::endl;
    //std::cout << "enemy: " << enemy.x << " " << enemy.y << std::endl;
    
    if(!grounded && move) move = false;
    if(!grounded && randmove) randmove = false;
    
    float w = player.x - 5;
    float W = player.x + 5;
    
    float h = player.y -5;
    float H = player.y +5;
    
    float difference = std::abs(player.y-enemy.y);
   
    
    
    
    if(!move){
        if(enemy.x > w && enemy.x < W) boing = true;
        if(player.x > enemy.x && right && !randmove ){
            dir.x = 1;
            right = false;
            getTransform()->resize(gme::Vector2(-1,1));
        }
        if(player.x < enemy.x && !right && !randmove){
            dir.x = -1; 
            right = true;
            getTransform()->resize(gme::Vector2(-1,1));
        }

        if(enemy.y > h && enemy.y < H) Vboing = true;
        if(player.y > enemy.y && !down && !Vboing ){
            dir.y = 1;
            down = true;
        }
        if(player.y < enemy.y && down && !Vboing){
            dir.y = -1;
            down = false;
        }
    }
    
    if(grounded && !enemy_boss){
        if((enemy.x < 80 || enemy.x > 1500) && !move){
            dir.x = -dir.x;
            right = !right;
            move = true;
        }
        if(gdir.x != 0){
            if(difference < 50 || home){
                dir.y = -1;
                down = false;   
            }
            else{
                dir.y = 1;
                down = true;
            }
        }
        if(gdir.y != 0 && !randmove && difference > 25){
            int rnd = rand() % 2;
            if(rnd == 0){
                dir.x = -1;
                right = true;
                randmove = true;
            }
            if(rnd == 1){
                dir.x = 1;
                right = false;
                randmove = true;
            }
            
        }
    }
}

void IAfly::bossAttack() {
   
    if(clkCA.currentTime().asSeconds() > 7){
         
        int rnd = rand() % 3;
        
        if(chase){
            std::cout << "cambio chase" << std::endl;
            if(rnd != 1){
                wave = true;
                invert = false;
            }
            else{       
                fallDown = true;
                invert =  false;
                clkD.restart();
            }
            chase = false;
        }
        else if(wave){
            std::cout << "cambio wave" << std::endl;
            if(rnd != 0) {
                fallDown = true; 
                invert =false;
                clkD.restart();
            }
            else    chase = true;
            wave = false;
        }
        else if(fallDown){
            
            std::cout << "cambio falldown" << std::endl;
            if(rnd != 2) chase = true;
            else{
                wave = true;
                invert = false;
            }
            fallDown = false;
        }
        
        
        clkCA.restart();
        std::cout << "Cambio de ataque-> c: " << chase << " w: " << wave << " fd: " << fallDown << std::endl;
    }
}

void IAfly::fallDownAttack(gme::Vector2 player, gme::Vector2 enemy) {
    
    
    float w = player.x - 5;
    float W = player.x + 5;
    
    if(enemy.x > w && enemy.x < W) boing = true;
        if(player.x > enemy.x && right ){
            dir.x = 1;
            right = false;
            getTransform()->resize(gme::Vector2(-1,1));
        }
        if(player.x < enemy.x && !right ){
            dir.x = -1; 
            right = true;
            getTransform()->resize(gme::Vector2(-1,1));
        }
        
        dir.y = -1;
        if(enemy.y < -250 && !caida){
            dir.y = 0;
            clkD.restart();
            caida = true;
        }
        
        if(caida && clkD.currentTime().asSeconds() > 3){
            dir.x = 0;
            dir.y = 1;
        }
        
        if(grounded || (enemy.y > 470)){
            dir.y = 0;
            if(!wait) wait = true;
            if(!grounded) grounded = true;
        }
       
        
        std::cout << enemy.x << " " << enemy.y << std::endl;
}

void IAfly::waveAttack(gme::Vector2 player, gme::Vector2 enemy) {
    
    float distance1 = gme::Vector2::distance(enemy,wavePositions.at(0));
    float distance2 = gme::Vector2::distance(enemy,wavePositions.at(1));
    float distancePlayer1 = gme::Vector2::distance(player,wavePositions.at(0));
    float distancePlayer2 = gme::Vector2::distance(player,wavePositions.at(1));
    float heightDifference = std::abs(enemy.y-player.y);
    
    // std::cout <<" dp1: " << distance1 << " dp2: " << distance2  << " altura: " << heightDifference <<" middle: "<< middlePosition << std::endl;
    
    if(distance1 < distance2 && !home){
        init = wavePositions.at(0);
        finalpos = wavePositions.at(1);
        home  = true;
        std::cout << "caca 1 " << std::endl;
    }
    if(distance2 < distance1 && !home){
        init = wavePositions.at(1);
        finalpos = wavePositions.at(0);  
        home = true;
        std::cout << "caca 2 " << std::endl;
    }
    
    if(!crash &&  wait){
        attack = player;
        std::cout << "caca 3 " << std::endl;
    }
    
    //std::cout << "d1 " << distancePlayer1   << std::endl;
    
}



void IAfly::onCollision(gme::Collider* c) {
    gme::Vector2 rP = getCollider()->getRelativePosition(c);
   
    if(c->gameObject()->hasTag("floor")){
        std::cout << "suelo" << std::endl;
        grounded =  true;
        gdir = rP;
    }
    if(c->gameObject()->hasTag("corner")){
        corner = true;
        std::cout << "corner" << std::endl;
    }
}

void IAfly::onMessage(std::string m, float v) {
    if(m.compare("kill")==0 && !dead){
        if(mainGame::sound)explosionEnemigo_sound->play();
        std::cout << "muerte" << std::endl;
        dead = true;
        explode(20, 50, 50, 250);
    }
    
    if(m.compare("damage")==0 && !dead){
        if(mainGame::sound)danyoEnemigo_sound->play();
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

void IAfly::anmate() {
    if(animClock.currentTime().asSeconds() > 1.0f/walkFPS){
            animClock.restart();
            walkFrameCount++;
            if(walkFrameCount >= 9) walkFrameCount = 0;
            getRenderer()->setFrame("fly_"+std::to_string(walkFrameCount+1));
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
    
    else if(enemyPosWindow.y < 0){
        gme::GUI::globalRotation = 180;
        float posx = enemyPosWindow.x;
        if(posx < 16*3 ) posx = 16*3;
        else if(posx > 1024-16*3) posx = 576-16*3;
        gme::GUI::drawTexture(
            gme::Vector2(posx, 80),
            gme::Vector2(16*3, 16*3),
            gme::GUI::TextureName("indicator_enemy"),
            gme::GUI::Origin::Center,
            gme::GUI::ScaleToFit
        );
        gme::GUI::globalRotation = 0;
        gme::GUI::drawTexture(
            gme::Vector2(posx, 576-16*6),
            gme::Vector2(16*3, 16*3),
            gme::GUI::TextureName("indicator_enemy"),
            gme::GUI::Origin::Center,
            gme::GUI::ScaleToFit
        );
    }
    gme::GUI::globalRotation = 0;
}





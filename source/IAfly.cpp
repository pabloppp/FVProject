/* 
 * File:   IAfly.cpp
 * Author: albertomartinezmartinez
 * 
 * Created on 15 de mayo de 2015, 14:58
 */

#include "IAfly.hpp"
#include "defaultParticle.hpp"
#include "sprayParticleScript.hpp"

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

            if(home && !wait){
                float disthome = gme::Vector2::distance(init,enemypos);
                if(disthome < 10){
                    wait = true;
                    clkW.restart();
                }
            }
            if(wait && clkW.currentTime().asSeconds() > 5){
                home= false;
                wait = false;
            }
            


            if(!home)vectorDirector(playerpos,enemypos);
            if(home) vectorDirector(init,enemypos);
            if(boing && !grounded) desp.x =0;
            if(Vboing && !corner) desp.y = 0;
            getRigidBody()->setSpeed(desp, dist);
        }
        else{
            bossAttack();
            
            if(home){
                float distance = gme::Vector2::distance(init, enemypos);
                if(distance < 10){
                    wait = true;
                    home = false;
                    clkW.restart();
                }
            }
            
            if(wait && clkW.currentTime().asSeconds() < 2) dist = 0;
            if(wait && clkW.currentTime().asSeconds() >=2) wait = false;
            
           
            
            if(chase) vectorDirector(playerpos,enemypos);
            if(wave && !home && !wait) waveAttack(playerpos,enemypos);
            if(fallDown) fallDownAttack(playerpos,enemypos);
            if(home && !wait) vectorDirector(init,enemypos);
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
        }
        if(player.x < enemy.x && !right && !randmove){
            dir.x = -1; 
            right = true;
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
            std::cout << "caca" << std::endl;
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
    if(clkCA.currentTime().asSeconds() > 10 && !pruebawave){
         
        int rnd = rand() % 3;
        
        if(chase){
            std::cout << "cambio chase" << std::endl;
            if(rnd != 1){
                wave = true;
                home = true;
                pruebawave =true;
            }
            else{fallDown = true;}
            chase = false;
        }
        else if(wave){
            std::cout << "cambio wave" << std::endl;
            if(rnd != 0) fallDown = true;
            else    chase = true;
            wave = false;
        }
        else if(fallDown){
            std::cout << "cambio falldown" << std::endl;
            if(rnd != 2) chase = true;
            else{
                wave = true;
                home  = true;
                pruebawave = true;
            }
            fallDown = false;
        }
        
        
        if(home){
            init = wavePositions.at(0);
        }
        clkCA.restart();
        std::cout << "Cambio de ataque-> c: " << chase << " w: " << wave << " fd: " << fallDown << std::endl;
    }
}

void IAfly::fallDownAttack(gme::Vector2 player, gme::Vector2 enemy) {

}

void IAfly::waveAttack(gme::Vector2 player, gme::Vector2 enemy) {
    std::cout << "esperando para atacar" << std::endl;
    std::cout << "wait " << wait << " home: " << home << std::endl;
   
    dir.y =0;
    float distance1 = gme::Vector2::distance(enemy,wavePositions.at(0));
    float distance2 = gme::Vector2::distance(enemy,wavePositions.at(1));
    
    if (distance1 < 10 && distance2 > 1000 && leftPosition){
        dir.x = 1;
        leftPosition = false;
    }
    if (distance1 > 1000 && distance2 < 10 && !leftPosition){
        dir.x = -1;
        leftPosition = true;
    }
    
    std::cout << "d1 " << distance1 << " d2: " << distance2 << std::endl;
    
}



void IAfly::onCollision(gme::Collider* c) {
    gme::Vector2 rP = getCollider()->getRelativePosition(c);
   
    if(c->gameObject()->hasTag("floor")){
        grounded =  true;
        gdir = rP;
    }
    if(c->gameObject()->hasTag("corner")){
        corner = true;
    }
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





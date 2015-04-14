/* 
 * File:   IAMovement.cpp
 * Author: albertomartinezmartinez
 * 
 * Created on 14 de abril de 2015, 18:18
 */

#include "IAMovement.hpp"

void IAMovement::findPlayer() {
   player = gme::GameObject::find("p1").at(0);
}

void IAMovement::setup() {
    clk.restart();
    right = true;

}

void IAMovement::update() {
    findPlayer();
    if(player){
        gme::Vector2 playerpos = player->getTransform()->getPosition();
        gme::Vector2 enemypos = getTransform()->getPosition();
        
        float deltatime = gme::Game::deltaTime.asSeconds();
        float dist = gme::Game::getWindow()->getSize().x/4;
       
        std::cout << dist << std::endl;
        vectorDirector(playerpos,enemypos);
        
        getTransform()->translate(dir,dist*deltatime);
        
    }
    
}

void IAMovement::vectorDirector(gme::Vector2 player, gme::Vector2 enemy) {
    
    if(player.x < enemy.x && clk.currentTime().asSeconds()>0.5 && right){
        dir.x = -dir.x;
        clk.restart();
        right= false;
    }
    if(player.x > enemy.x && clk.currentTime().asSeconds()>0.5 && !right){
        dir.x = -dir.x;
        clk.restart();
        right= true;
    }
    
        
}



IAMovement::~IAMovement() {
}


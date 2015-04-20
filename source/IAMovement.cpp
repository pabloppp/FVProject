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
    right = true;
    timepas=3;
    check = 0;
    jumping = false;
}

void IAMovement::update() {
    findPlayer();
    if(player){
        gme::Vector2 playerpos = player->getTransform()->getPosition();
        gme::Vector2 enemypos = getTransform()->getPosition();
        
        float deltatime = gme::Game::deltaTime.asSeconds();
        float dist = gme::Game::getWindow()->getSize().x/4;
       
        
        vectorDirector(playerpos,enemypos);
        
        jump(playerpos,enemypos);
       
        
        getTransform()->translate(dir,dist*deltatime);
        
    }
    
}

void IAMovement::jump(gme::Vector2 player, gme::Vector2 enemy) {
    //getRigidBody()->pushImmediate(dir,40000*deltatime);
    
    if(player.y < enemy.y && !jumping && elapsetime == 0){
        std::cout << "jugador por encima" << std::endl;
        elapsetime = clkJ.currentTime().asSeconds();
    }
    
    if(clkJ.currentTime().asSeconds() - elapsetime > 5){
        std::cout << "deberia saltar el enemigo" << std::endl;
        elapsetime = 0;
        clkJ.restart();
        jumping = true;
    }
    
    if(jumping){
        std::cout << "jumping" << std::endl;
        dir.y = -1;
        getRigidBody()->pushImmediate(dir,40000*deltatime);
    }
    
      
}


void IAMovement::vectorDirector(gme::Vector2 player, gme::Vector2 enemy) {
   
    
    if(player.x == enemy.x) clk.restart();
    
    if(player.x < enemy.x && clk.currentTime().asSeconds()>timepas && right){
        dir.x = -dir.x;
        clk.restart();
        right= false;
    }
    
    if(player.x > enemy.x && clk.currentTime().asSeconds()>timepas && !right){
        dir.x = -dir.x;
        /*Falta cambiar la direccion del sprite*/
        
        clk.restart();
        right= true;
    }
    
        
}



IAMovement::~IAMovement() {
}


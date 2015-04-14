/* 
 * File:   LifeManager.cpp
 * Author: pablopernias
 * 
 * Created on 18 de marzo de 2015, 11:23
 */

#include "LifeManager.hpp"

void LifeManager::setup() {
    lives = maxLives;
    hp = maxHp;
}

void LifeManager::update() {

}

int LifeManager::getHp() {
    return hp;
}

int LifeManager::getLives() {
    return lives;
}

int LifeManager::getMaxLives() {
    return maxLives;
}

int LifeManager::getMaxHp() {
    return maxHp;
}

float LifeManager::getHpPercent() {
    return (1.0f*hp/maxHp)*100;
}



void LifeManager::onMessage(std::string m, float v) {
    if(m.compare("damage") == 0){ //recibe daño
        hp -= v;
        if(hp <= 0){
            sendMessage("kill", 0);
            lives -= 1;
            if(lives <= 0){
                lives = 0;
                hp = 0;
                sendMessage("gameover", 0);
            }
            else{
                hp = maxHp;
            }
        }
    }
    if(m.compare("heal") == 0){
        hp += v;
        if(hp > maxHp){
            hp = maxHp;
        }
    }
    if(m.compare("oneup") == 0){
        lives += v;
        if(lives > maxLives) lives = maxLives;
    }
    if(m.compare("sethp") == 0){
        if(v > 0){
            hp = v;
            if(hp > maxHp){
                hp = maxHp;
            }
        }
    }
}




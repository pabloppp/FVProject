
#include "LifeManager.hpp"

void LifeManager::setup() {
    lives = maxLives;
    hp = maxHp;
}

void LifeManager::update() {
    
    if(!startShowDamage && waitClock.currentTime().asSeconds() > waitTime) startShowDamage = true;
    
    if(!startShowDamage) return;
    
    if(waitClock.currentTime().asSeconds() < waitTime){
        if(!showDamage){
            showDamage = true;
            r = getRenderer()->getColorR();
            g = getRenderer()->getColorG();
            b = getRenderer()->getColorB();
        }
        else{
            getRenderer()->setColor(255,0,0);
        }
    }
    else{
        if(showDamage){
            showDamage = false;
            getRenderer()->setColor(r,g,b);
        }
    }
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
        if(waitClock.currentTime().asSeconds() < waitTime) return;
        
        waitClock.restart();
        hp -= v;
        if(hp <= 0){
            if(gameObject()->hasTag("enemy")) sendMessage("kill", 0);
            lives -= 1;
            if(lives <= 0){
                lives = 0;
                hp = 0;
                sendMessage("gameover", 0);
                if(gameObject()->hasTag("player")){
                    std::vector<gme::GameObject*> managerList = gme::GameObject::find("manager");
                    if(managerList.size() > 0){
                        managerList.at(0)->sendMessage("gameover",0);
                    }
                }
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
    if(m.compare("kill") == 0){
        destroyGameObject(gameObject());        
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
    if(m.compare("reset") == 0){
        hp = maxHp;
        lives = maxLives;
    }
}




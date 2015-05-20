
#include "LifeManager.hpp"
#include "mainGame.hpp"

void LifeManager::setup() {
    lives = maxLives;
    hp = maxHp;
    
    danyoJugador_sound = new gme::SoundPlayer();
    danyoJugador_sound->setSound("danyo1");
    danyoJugador_sound->setVolume(80.0);
    
    malditasea_sound = new gme::SoundPlayer();
    malditasea_sound->setSound("malditasea");
    malditasea_sound->setVolume(80.0);
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
        if(waitClock.currentTime().asSeconds() < waitTime && v < 20) return;
        
        if(gameObject()->hasTag("player")){
            contDanyo++;
            if(contDanyo==10){
                if(mainGame::sound) malditasea_sound->play();
                contDanyo=0;
            }
            if(mainGame::sound) danyoJugador_sound->play();
        }
        
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




#include "generaPosicion.hpp"
#include "../engine/Game.hpp"
#include "enemy.hpp"
#include "enemy_fast.hpp"
#include "colectableGameObject.hpp"
#include "GlobalStateManager.hpp"
#include "enemy_boss.hpp"
#include "mainGame.hpp"
#include "enemy_fly.hpp"
#include "enemy_explosive.hpp"


void generaPosicion::setup(){
    clkC.restart();
    clkE.restart();
    objects = 0;
    randomtime = 2;
    destroyed = false;
    lObjectType=0;
    objects = 0;
    
    std::vector<gme::GameObject*> gm = gme::GameObject::find("manager");
    if(gm.size() > 0){
        GlobalStateManager *gsm = (GlobalStateManager*)(gm.at(0)->getComponent<GlobalStateManager*>());
        if(gsm != NULL){
            manager = gsm;
        }
    }
}

void generaPosicion::update() { 
    
    if(manager->isPaused()) return;
    
    if(colectionable == true){
        if(clkC.currentTime().asSeconds() > 10){
            clkC.restart();
            generaColeccionable();
            randomtime = (rand()%5) + 8;
            destroyed = true;
        }
    }
   
    if(enemi == true){
        if(clkE.currentTime().asSeconds() > rat){
           clkE.restart();
           int cuantos = maxEnemigos;
           while(cuantos > 0){
                gme::Vector2 randomPos = posiciones.at(rand() % posiciones.size());
                generaEnemigo(randomPos.x, randomPos.y);
                cuantos--;
           }
           //std::cout << "genera enemigo: " << enemi << std::endl;
        }
    }
    
}

void generaPosicion::fuerzaGeneracion(int n) {
    int cuantos = n;
    while(cuantos > 0){
         gme::Vector2 randomPos = posiciones.at(rand() % posiciones.size());
         generaEnemigo(randomPos.x, randomPos.y);
         cuantos--;
    }
}


void generaPosicion::generaColeccionable(){
    int finalpos = colMinX + (int)rand() % (int)(v.x-colMinX) ;
    int randSet = 3;
    
    if(mainGame::flamethrower) randSet = 6;
    else if(mainGame::shotgun) randSet = 5;
    else if(mainGame::machinegun) randSet = 4;
    
    int objecType = rand() % randSet;
       
    while(objecType == lObjectType){
        objecType = rand() % randSet;
    }
    lObjectType = objecType;
    colectableGameObject *col =  new colectableGameObject("colectable",objecType);//objecType
    col->getTransform()->setPosition(gme::Vector2(finalpos,-288+16*3));
    instantiate(col);
    
    //std::cout << finalpos << std::endl; 
}


void generaPosicion::setColectionable(bool x){
    colectionable = x;
}
bool generaPosicion::getColectionable(){
    return colectionable;
}


void generaPosicion::generaEnemigo(int x, int y) {
    if (enemi == true ){
        int random = rand() % (ene1+ene2+ene3+ene4);
        
        
        gme::GameObject *enemigo;
        
        if(random < ene1){
            enemigo = new enemy("dino");
        }
        else if(random < ene1+ene2){
            enemigo = new enemy_fast("dino_fast");
        }
        else if(random < ene1+ene2+ene3){
            enemigo = new enemy_fly("dino_fly", false);
        }
        else if(random < ene1+ene2+ene3+ene4){
            enemigo = new enemy_explosive("dino_explosive");
        }
        enemigo->getTransform()->setPosition(gme::Vector2(x, y));
        instantiate(enemigo);
    }
}

void generaPosicion::setEnemi(bool x){
    enemi = x;
}

bool generaPosicion::getEnemi(){
    return enemi;
}

void generaPosicion::onGui() {
}

generaPosicion::generaPosicion(int x, int y,float ratio) : gme::Script(){
    v = gme::Vector2(1584-16*3*2, 576);
    colMinX = 16*3;
    posiciones.push_back(gme::Vector2(x, y));
    rat = ratio; 
    colectionable = false;
    enemi = false;
    ene1 = ene2 = ene3 = ene4 = 25;
    maxEnemigos = 1;
}

void generaPosicion::setCollectableLimits(int xmin, int xmax) {
    v.x = xmax;
    colMinX = xmin;
}


void generaPosicion::addPosition(int x, int y) {
    posiciones.push_back(gme::Vector2(x, y));
}

void generaPosicion::onMessage(std::string m, float v) {
    std::cout << "message recieved " << m << std::endl;
    if(m.compare("destroyed") == 0){
        std::cout << "colectable destruido" << std::endl;
        
    }
}

#include "generaPosicion.hpp"
#include "../engine/Game.hpp"
#include "enemy.hpp"
#include "enemy_fast.hpp"
#include "colectableGameObject.hpp"


void generaPosicion::setup(){
    w = gme::Game::getWindow();
    v = w->getSize();
    colectionable = false;
    enemi = false;
    clkC.restart();
    clkE.restart();
    objects = 0;
    randomtime = 5;
    destroyed = false;
    lObjectType=0;
}

void generaPosicion::update() {   
    
    
    if(colectionable == true){
        if(clkC.currentTime().asSeconds() > randomtime ){
            clkC.restart();
            generaColeccionable();
            
            randomtime = (rand()%10) + 8;
            destroyed = true;
        }
    }
    else{
        setColectionable(true);
    }
   
    if(enemi == true){
        if(clkE.currentTime().asSeconds() > rat){
           clkE.restart();
           gme::Vector2 randomPos = posiciones.at(rand() % posiciones.size());
           generaEnemigo(randomPos.x, randomPos.y);
           //std::cout << "genera enemigo: " << enemi << std::endl;
        }
    }
    else{
        setEnemi(true);
    }
    
}

void generaPosicion::generaColeccionable(){
    
    int pos = rand();
    int x = v.x + (16*3);
    int finalpos = (int)pos%(int)x;
    int objecType =  rand() %6;
    if(objecType == lObjectType){
        objecType+=1;
        lObjectType = objecType;
    }
    std::cout << "Ot: " << objecType << " lOt: " << lObjectType << std::endl;
    colectableGameObject *col =  new colectableGameObject("colectable",objecType);
    col->getTransform()->setPosition(gme::Vector2(finalpos,-300));
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
    if (enemi == true){
        
        int random = rand() % 100;
        
        gme::GameObject *enemigo;
        
        if(random < 70){
            enemigo = new enemy("dino");
        }
        else{
            enemigo = new enemy_fast("dino_fast");
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
    /*
    gme::Game::getWindow()->draw(ratio);*/
}

generaPosicion::generaPosicion(int x, int y,int ratio) : gme::Script(){    
    posiciones.push_back(gme::Vector2(x, y));
    rat = ratio; 
}

void generaPosicion::addPosition(int x, int y) {
    posiciones.push_back(gme::Vector2(x, y));
}

void generaPosicion::onMessage(std::string m, float v) {
    if(m.compare("destroyed") == 0){
        std::cout << "colectable destruido" << std::endl;
    }
}

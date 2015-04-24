#include "generaPosicion.hpp"
#include "../engine/Game.hpp"
#include "enemy.hpp"
#include "weapon.hpp"
#include "metralletaBehavior.hpp"
#include "pistolaBehavior.hpp"
#include "colectableGameObject.hpp"


void generaPosicion::setup(){
    w = gme::Game::getWindow();
    v = w->getSize();
    colectionable = false;
    enemi = false;
    clkC.restart();
    clkE.restart();
    randomtime = 5;
}

void generaPosicion::update() {   
    
    
    if(colectionable == true){
        if(clkC.currentTime().asSeconds() > randomtime && objects < 10){
            clkC.restart();
            generaColeccionable();
            objects ++;
            randomtime = (rand()%10) + 5;
            //std::cout << randomtime << std::endl;
        }
        else if(objects >= 10){
            //std::cout << "no se pueden generar mas objetos" << std::endl;
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
    int x = v.x +(16*35);
    int finalpos = (int)pos%(int)x;
    
    
    colectableGameObject *col =  new colectableGameObject("colectable");
    col->getTransform()->setPosition(gme::Vector2(finalpos, 0));
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
        
        
        enemy *enemigo = new enemy("dino");
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




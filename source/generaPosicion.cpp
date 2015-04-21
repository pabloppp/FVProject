#include "generaPosicion.hpp"
#include "../engine/Game.hpp"
#include "enemy.hpp"


void generaPosicion::setup(){
    w = gme::Game::getWindow();
    v = w->getSize();
    colectionable = false;
    enemi = false;
    clkC.restart();
    clkE.restart();
}

void generaPosicion::update() {   
    
    
    if(colectionable == true){
        if(clkC.currentTime().asSeconds() > 1){
            clkC.restart();
            generaColeccionable();
        }
    }
    else{
        setColectionable(true);
    }
   
    if(enemi == true){
        std::cout << "ctime: " << clkE.currentTime().asSeconds() << " : " << rat <<  std::endl;
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
    int finalpos = (int)pos%(int)v.x;
    gme::GameObject *coleccionable = new gme::GameObject("colleccionable");
    coleccionable->getRenderer()->setTexture("coleccionable"); 
    coleccionable->getRenderer()->setSize(gme::Vector2(32,32));
    coleccionable->getRenderer()->setFrame(gme::Vector2(0,0));
    coleccionable->addComponent(new gme::RigidBody);
    coleccionable->getTransform()->setPosition(gme::Vector2(finalpos, -3));
   
    
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




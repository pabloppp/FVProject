#include "generaPosicion.hpp"
#include "pruebaGameObject.hpp"
#include "../engine/Game.hpp"
#include "mueveEnemigo.hpp"

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
        if(clkE.currentTime().asSeconds() > rat){
           clkE.restart();
            generaEnemigo(posX,posY);
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
        
        gme::GameObject *enemigo = new gme::GameObject("emenigo");
        enemigo->getRenderer()->setTexture("coleccionable");
        enemigo->getRenderer()->setSize(gme::Vector2(32,32));
        enemigo->getRenderer()->setFrame(gme::Vector2(1,0));
        enemigo->getTransform()->setPosition(gme::Vector2(x,y));
        enemigo->addComponent(new mueveEnemigo(enemigo));
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

generaPosicion::generaPosicion(int x, int y,int ratio) {
    posX = x;
    posY = y;
    rat =ratio; 
}

generaPosicion::generaPosicion() {

}



generaPosicion::~generaPosicion() {
}


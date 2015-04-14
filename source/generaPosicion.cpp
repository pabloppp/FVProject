#include "generaPosicion.hpp"
#include "../engine/Game.hpp"
#include "enemy.hpp"
#include "IAMovement.hpp"

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
   
    
    
        if(clkE.currentTime().asSeconds() > rat){
           clkE.restart();
            generaEnemigo(posX,posY);
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
        gme::GameObject *e = new enemy("enemigo");
        e->getTransform()->setPosition(gme::Vector2(x,y));
        IAMovement *m =  new IAMovement();
        e->addComponent(m);
        instantiate(e);
       
        
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

generaPosicion::generaPosicion(int x, int y,double ratio) {
    posX = x;
    posY = y;
    rat =ratio; 
    
    
}

generaPosicion::generaPosicion() {

}



generaPosicion::~generaPosicion() {
}


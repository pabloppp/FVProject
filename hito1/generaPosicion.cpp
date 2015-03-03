#include "generaPosicion.hpp"
#include "pruebaGameObject.hpp"

void generaPosicion::setup(){
    gme::Window *w = gme::Game::getWindow();
    v = w->getSize();
    clk.restart();
}

void generaPosicion::update() {
    
    std::cout <<clk.currentTime().asSeconds() << std::endl;
    
    if(clk.currentTime().asSeconds() > 5){
        gme::GameObject *fo = new pruebaGameObject("ObjetoCaida");
        fo->getRenderer()->setTexture("prueba");
        posX=rand()%680;
        fo->getTransform()->setPosition(gme::Vector2(posX,-5));
        fo->addComponent(new gme::RigidBody);
        clk.restart();
    }
    

    
}

generaPosicion::~generaPosicion() {
}


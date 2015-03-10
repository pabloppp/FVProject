#include "generaPosicion.hpp"
#include "pruebaGameObject.hpp"
#include "../engine/Game.hpp"
#include <math.h>


void generaPosicion::setup(){
    w = gme::Game::getWindow();
    v = w->getSize();
    clk.restart();
}

void generaPosicion::update() {   
    
    int radio = ratio.getRadius();
    
    if(clk.currentTime().asSeconds() > 0.5){
        gme::GameObject *fo = new pruebaGameObject("ObjetoCaida");
        fo->getRenderer()->setTexture("prueba");
        angle=(rand()%360);
        
        float percen = 1+((double) rand() / (RAND_MAX+1));
        float posX  = ratio.getPosition().x+(cos(angle)*(radio*percen));
        float posY  = ratio.getPosition().y+(sin(angle)*(radio*percen));
        
      
        
        fo->getTransform()->setPosition(gme::Vector2(posX,posY));
        fo->addComponent(new gme::RigidBody);
        clk.restart();
    }
    

    
}

void generaPosicion::position(int x, int y,int rat){
   
    ratio.setOrigin(rat,rat);
    ratio.setRadius(rat);
    ratio.setPosition(x,y);
    ratio.setOutlineThickness(1);
    ratio.setFillColor(sf::Color::Transparent);
    ratio.setOutlineColor(sf::Color::Red);
    
}

void generaPosicion::onGui() {
    gme::Game::getWindow()->draw(ratio);
}


generaPosicion::~generaPosicion() {
}


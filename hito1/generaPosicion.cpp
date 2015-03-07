#include "generaPosicion.hpp"
#include "pruebaGameObject.hpp"
#include "../engine/Game.hpp"


void generaPosicion::setup(){
    w = gme::Game::getWindow();
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

void generaPosicion::position(int x, int y,int rat){
    std::cout << x << " " << y << " " << rat << std::endl;
  
    area.setOrigin(x,y);
    area.setPosition(x,y);
    area.setRadius(rat);
    area.setOutlineThickness(1);
    area.setFillColor(sf::Color::White);
    area.setOutlineColor(sf::Color::Red);
    
}

generaPosicion::~generaPosicion() {
}


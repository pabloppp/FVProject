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
    
    if(clk.currentTime().asSeconds() > 0.5 && stateObjeto==1){
        
        gme::GameObject *fo = new pruebaGameObject("ObjetoCaida");
        if(tipoObjeto=="enemigo")
            fo->getRenderer()->setTexture("particle");
        else
            fo->getRenderer()->setTexture("prueba");
        angle=(rand()%360);
        
        float percen = 1+((double) rand() / (RAND_MAX+1));
        float posX  = ratio.getPosition().x+(cos(angle)*(radio*percen));
        float posY  = ratio.getPosition().y+(sin(angle)*(radio*percen));
        
        if(posX>v.x) posX=v.x;
        if(posX<0) posX=0;
        if(posY>v.y) posY=v.y;
        if(posY<0) posY=0;
        
        fo->getTransform()->setPosition(gme::Vector2(posX,posY));
        fo->addComponent(new gme::RigidBody);
        clk.restart();
    }
    

    
}

void generaPosicion::position(int x, int y,int rat,std::string tipo,int state){
   
    ratio.setOrigin(rat,rat);
    ratio.setRadius(rat);
    ratio.setPosition(x,y);
    ratio.setOutlineThickness(1);
    ratio.setFillColor(sf::Color::Transparent);
    if(tipo == "enemigo")
        ratio.setOutlineColor(sf::Color::Red);
    if(tipo == "coleccionable")
        ratio.setOutlineColor(sf::Color::Blue);
    tipoObjeto=tipo;
    setState(state);
}

void generaPosicion::onGui() {
    gme::Game::getWindow()->draw(ratio);
}

void generaPosicion::setState(int i){
    stateObjeto=i;
}

int generaPosicion::getState(){
    return stateObjeto;
}



generaPosicion::~generaPosicion() {
}




#include "scenePrueba.hpp"
#include "enemy.hpp"
#include "player.hpp"
#include "GeneralIA.hpp"

void scenePrueba::setup(){
   
    gme::GameObject *e  = new enemy("enemigo");  
    
    //e->getRenderer()->setTexture("dino");
    e->getTransform()->setPosition(gme::Vector2(512,250));
    e->addComponent(new GeneralIA);
    
    
    
    gme::GameObject *e1  = new enemy("enemigo");
    //e1->getRenderer()->setTexture("dino");
    e1->getTransform()->setPosition(gme::Vector2(800,50));
    e1->addComponent(new GeneralIA);
    
    gme::GameObject *e2  = new enemy("enemigo");
    //e2->getRenderer()->setTexture("dino");
    e2->getTransform()->setPosition(gme::Vector2(20,2));
    e2->addComponent(new GeneralIA);
    
   
    
    gme::GameObject *p = new player("p1");
    p->getRenderer()->setTexture("playerTexture");
    p->getTransform()->setPosition(gme::Vector2(100,500));
  
  
    
    
}

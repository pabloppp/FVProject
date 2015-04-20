

#include "scenePrueba.hpp"
#include "enemy.hpp"
#include "generaPosicion.hpp"
#include "player.hpp"
#include "IAMovement.hpp"
#include "voidObject.hpp"

void scenePrueba::setup(){
   
    /*gme::GameObject *e = new voidObject("enemigoss");
    
    generaPosicion *g =  new generaPosicion(150,100,0.6);
    g->setEnemi(true);
    e->addComponent(g);*/
    
    
      gme::GameObject *e = new enemy("enemigo");
        e->getTransform()->setPosition(gme::Vector2(150,100));
        IAMovement *m =  new IAMovement();
        e->addComponent(m);
        instantiate(e);
     
    
    gme::GameObject *p = new player("p1");
    p->getTransform()->setPosition(gme::Vector2(500,350));
    
    
}

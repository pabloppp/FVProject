

#include "colectableScript.hpp"
#include "Animator.hpp"
#include "pistolaBehavior.hpp"
#include "weapon.hpp"
#include "metralletaBehavior.hpp"

void colectableScript::setup() {
    grounded = false;
    destroy = false;
    findPlayer();
    objectType = 0;//rand() % 2;
}

void colectableScript::update() {
    if(destroy){
        
        //destroyGameObject(gameObject());
    }
    if(player){
        gme::Vector2 pos = getTransform()->getPosition();
        gme::Vector2 ppos = player->getTransform()->getPosition();
        if(grounded){
            //std::cout << "position X " << ppos.x << ":" << pos.x << std::endl;
            //std::cout << "position Y " << ppos.y << ":" << pos.y << std::endl;
            /*if(ppos.x == pos.x && ppos.y == pos.y){
                std::cout << "equipar objeto" << std::endl;
                destroyGameObject(gameObject());
            }*/
          
        }
        grounded = false;
    }
}


void colectableScript::collected() {
    if(player){
        std::cout << "reoger aofijhaoifjhoa faojfaoijfa " << std::endl;
    }

}


void colectableScript::findPlayer() {
   player = gme::GameObject::find("p1").at(0);
}

void colectableScript::onCollision(gme::Collider* c) {
     gme::Vector2 relativePosition = getCollider()->getRelativePosition(c);
     //std::cout << relativePosition.x << " " << relativePosition.y << std::endl;
    if(gameObject()->hasTag("colectable") && c->gameObject()->hasTag("floor")){       
        if(relativePosition.y == -1){ //si golpea el suelo
            grounded = true;
        }
    }
     if(c->gameObject()->hasTag("player")){
        std::cout << "colision con jugador " << std::endl;
        std::vector<gme::GameObject*> children = c->gameObject()->getChildren();
        std::cout << children.at(0)->getName() << "objecttype: " << objectType << std::endl;
        if(objectType == 0){
            c->gameObject()->removeChild(children.at(0));
            
            std::cout << "remove children" << std::endl;
             std::cout << " children size " << c->gameObject()->getChildren().size() << std::endl;
           
            weapon *arma = new weapon("pistola2");
            arma->addComponent(new metralletaBehavior()); 
            arma->getTransform()->setPosition(gme::Vector2(0,0));
            
             c->gameObject()->addChild(arma);
             
             std::cout << "add children" << std::endl;
             std::cout << " children size " << c->gameObject()->getChildren().size() << std::endl;
            destroyGameObject(children.at(0));
            
            /* 
             arma->addComponent(new pistolaBehavior()); 
             c->gameObject()->addChild(arma);
             arma->getTransform()->setPosition(gme::Vector2(0,0));
             //destroyGameObject(gameObject());*/
        }
     }
     
     /*if(c->gameObject()->hasTag("player")){       
         std::cout << "colision con jugador " << std::endl;
         c->gameObject()->sendMessage("equipar",0);
    }*/
}

void colectableScript::onMessage(std::string m, float v) {
    if(m.compare("equipar") == 0){
       
       destroy = true;
    }
}



colectableScript::colectableScript() {
}

colectableScript::colectableScript(const colectableScript& orig) {
}

colectableScript::~colectableScript() {
}


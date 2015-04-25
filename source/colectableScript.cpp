
#include "ColectableScript.hpp"
#include "weapon.hpp"
#include "pistolaBehavior.hpp"
#include "metralletaBehavior.hpp"
#include "escopetaBehavior.hpp"
#include "lnzllamasBehavior.hpp"

void ColectableScript::setup() {
    //objectType = rand()% 6;
    grounded =false;
}

void ColectableScript::update() {
    if(grounded){
        if(clkD.currentTime().asSeconds() > 12 && grounded) destroyGameObject(gameObject());
    }
    grounded=false;
}

void ColectableScript::onCollision(gme::Collider* c) {
    gme::Vector2 relativePosition = getCollider()->getRelativePosition(c);
    if(c->gameObject()->hasTag("floor")){
        if(relativePosition.y == -1)   grounded = true;
    }
    if(c->gameObject()->hasTag("player")){   
        std::cout<< objectType << std::endl;
        if(objectType <=1){
            if(objectType == 0){ //sunar hp
                c->gameObject()->sendMessage("sethp",50);
                //gameObject()->sendMessage("destroy",0);
            }
            if(objectType == 1){ //sunar vida
                c->gameObject()->sendMessage("oneup",1);
                //gameObject()->sendMessage("destroy",0);
            }
        }
        else{
            std::vector<gme::GameObject*> children = c->gameObject()->getChildren();
            std::cout<< children.at(0)->getName() << std::endl;
            gme::Component *pb = children.at(0)->getComponent<pistolaBehavior*>();
            gme::Component *mb = children.at(0)->getComponent<metralletaBehavior*>();
            gme::Component *eb = children.at(0)->getComponent<escopetaBehavior*>();
            gme::Component *lb = children.at(0)->getComponent<lnzllamasBehavior*>();
            
            if(objectType == 2 && !pb->isActive()){
                pb->setActive(true);
                mb->setActive(false);
                eb->setActive(false);
                lb->setActive(false);
            }
            if(objectType == 3 && !mb->isActive()){
                pb->setActive(false);
                mb->setActive(true);
                eb->setActive(false);
                lb->setActive(false);
            }
            if(objectType == 4 && !eb->isActive()){
                pb->setActive(false);
                mb->setActive(false);
                eb->setActive(true);
                lb->setActive(false);
            }
            if(objectType == 5 && !lb->isActive()){
                pb->setActive(false);
                mb->setActive(false);
                eb->setActive(false);
                lb->setActive(true);
            }
        
           /*if(objectType == 2){ //Poner Pistola
                //c->gameObject()->sendMessage("sethp",50);
                //gameObject()->sendMessage("destroy",0);
                arma->addComponent(new pistolaBehavior());
            }
            if(objectType == 3){ //sunar Metralleta
                //c->gameObject()->sendMessage("sethp",50);
                //gameObject()->sendMessage("destroy",0);
                arma->addComponent(new metralletaBehavior());
            }
            if(objectType == 4){ //poner Escopeta
                //c->gameObject()->sendMessage("sethp",50);
                //gameObject()->sendMessage("destroy",0);
                arma->addComponent(new escopetaBehavior());
            }
            if(objectType == 5){ //poner lanzzallamas
                //c->gameObject()->sendMessage("sethp",50);
                //gameObject()->sendMessage("destroy",0);
                arma->addComponent(new lnzllamasBehavior());
            }*/
           
        }
        destroyGameObject(gameObject());
    }
}


ColectableScript::~ColectableScript() {
}


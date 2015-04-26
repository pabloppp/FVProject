
#include "ColectableScript.hpp"
#include "weapon.hpp"
#include "pistolaBehavior.hpp"
#include "metralletaBehavior.hpp"
#include "escopetaBehavior.hpp"
#include "lnzllamasBehavior.hpp"

void ColectableScript::setup() {
    //objectType = rand()% 6;
    grounded = false;
    destroyed = false;
    walkFrameCountFD = 0;
    walkFrameCountPD = 0;
    walkFrameCountL  = 0;
    walkFPS = 5;
    ((gme::BoxCollider*)getCollider())->setSize(12*3, 12*3);
    
}

void ColectableScript::update() {
    if(destroyed){
        destroyGameObject(gameObject());
    }
    if(grounded){
        if(clkD.currentTime().asSeconds() > 12 && grounded) destroyGameObject(gameObject());
    }
    animate();
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
                c->gameObject()->sendMessage("heal",50);
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
        destroyed = true;
        //destroyGameObject(gameObject());
    }
}

void ColectableScript::onGui() {
    gme::Vector2 boxPos = getTransform()->getPosition();
    gme::Vector2 boxPosWindow = boxPos.worldToScreen();
    if(boxPosWindow.x < -32*3){
        gme::GUI::globalRotation = 90;
        float posy = boxPosWindow.y;
        if(posy < 16*3 ) posy = 16*3;
        else if(posy > 576-16*3) posy = 576-16*3;
        gme::GUI::drawTexture(
            gme::Vector2(16*3+8*3, posy),
            gme::Vector2(16*3, 16*3),
            gme::GUI::TextureName("indicator_box"),
            gme::GUI::Origin::Center,
            gme::GUI::ScaleToFit
        );
    }
    else if(boxPosWindow.x > 1024+32*3){
        gme::GUI::globalRotation = -90;
        float posy = boxPosWindow.y;
        if(posy < 16*3 ) posy = 16*3;
        else if(posy > 576-16*3) posy = 576-16*3;
        gme::GUI::drawTexture(
            gme::Vector2(1024-8*3, posy),
            gme::Vector2(16*3, 16*3),
            gme::GUI::TextureName("indicator_box"),
            gme::GUI::Origin::Center,
            gme::GUI::ScaleToFit
        );
    }
}

void ColectableScript::animate() {
    if(animClock.currentTime().asSeconds() > 1.0f/walkFPS){
        animClock.restart();
        if(!grounded){
            walkFrameCountFD++;
            if(walkFrameCountFD >7) walkFrameCountFD = 0;
            getRenderer()->setFrame("ani_CaidaPaquete_"+std::to_string(walkFrameCountFD));
        }
        else {
            if(walkFPS == 5) walkFPS=10;
        
            if(walkFrameCountPD <=7){ 
                getRenderer()->setFrame("ani_LLegadaParacaidas_"+std::to_string(walkFrameCountPD));
                walkFrameCountPD++;
            }
            else{
                if(walkFrameCountL >5) walkFrameCountL=0;
                if(objectType == 0){
                    getRenderer()->setFrame("ani_HP_"+std::to_string(walkFrameCountL));
                }
                if(objectType == 1){
                    getRenderer()->setFrame("ani_NuevaVida_"+std::to_string(walkFrameCountL));
                    
                }
                if(objectType == 2){
                    
                    getRenderer()->setFrame("ani_Pistola_"+std::to_string(walkFrameCountL));
                }
                if(objectType == 3){
                    getRenderer()->setFrame("ani_Metralleta_"+std::to_string(walkFrameCountL));
                }
                if(objectType == 4){
                    getRenderer()->setFrame("ani_Escopeta_"+std::to_string(walkFrameCountL));                    
                }
                if(objectType == 5){
                    getRenderer()->setFrame("ani_Lanzallamas_"+std::to_string(walkFrameCountL));
                }
                walkFrameCountL++;
            }
        }
            
            
    }
}


ColectableScript::~ColectableScript() {
}


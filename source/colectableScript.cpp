
#include "ColectableScript.hpp"
#include "weapon.hpp"
#include "pistolaBehavior.hpp"
#include "metralletaBehavior.hpp"
#include "escopetaBehavior.hpp"
#include "lnzllamasBehavior.hpp"
#include "LifeManager.hpp"
#include "defaultParticle.hpp"
#include "mainGame.hpp"

void ColectableScript::setup() {
    grounded = false;
    destroyed = false;
    isHit = false;
    hp = 5;
    walkFrameCountFD = 0;
    walkFrameCountPD = 0;
    walkFrameCountL  = 0;
    walkFPS = 5;
    ((gme::BoxCollider*)getCollider())->setSize(12*3, 12*3);
    
    pistolaFrase_sound = new gme::SoundPlayer();
    pistolaFrase_sound->setSound("pistolaFrase");
    pistolaFrase_sound->setVolume(100.0);
    
    metralletaFrase_sound = new gme::SoundPlayer();
    metralletaFrase_sound->setSound("metralletaFrase");
    metralletaFrase_sound->setVolume(100.0);
    
    lanzallamasFrase_sound = new gme::SoundPlayer();
    lanzallamasFrase_sound->setSound("lanzallamasFrase");
    lanzallamasFrase_sound->setVolume(100.0);
    
    escopetaFrase_sound = new gme::SoundPlayer();
    escopetaFrase_sound->setSound("escopetaFrase");
    escopetaFrase_sound->setVolume(100.0);
    
    nuevaVidaFrase_sound = new gme::SoundPlayer();
    nuevaVidaFrase_sound->setSound("nuevaVidaFrase");
    nuevaVidaFrase_sound->setVolume(100.0);
    
    HPFrase_sound = new gme::SoundPlayer();
    HPFrase_sound->setSound("HPFrase");
    HPFrase_sound->setVolume(100.0);
    
    cajaRota_sound = new gme::SoundPlayer();
    cajaRota_sound->setSound("cajaRota");
    cajaRota_sound->setVolume(100.0);
    
    
    
    
    
    
}

void ColectableScript::update() {
    
    /*if(grounded){
        if(clkD.currentTime().asSeconds() > 12 && grounded) destroyGameObject(gameObject());
    }*/
    animate();
    grounded=false;
    if(destroyed){
        
        destroyGameObject(gameObject());
        return;
    }
}

void ColectableScript::onCollision(gme::Collider* c) {
    gme::Vector2 relativePosition = getCollider()->getRelativePosition(c);
    if(c->gameObject()->hasTag("floor")){
        if(relativePosition.y == -1)   grounded = true;
    }    
    if(c->gameObject()->hasTag("player")){ 
        std::cout << "objectType = " << objectType << std::endl;
        if(objectType <=1){
            if(objectType == 0){ 
                c->gameObject()->sendMessage("oneup",1);
                if(mainGame::sound) nuevaVidaFrase_sound->play();
            }
            if(objectType == 1){ 
                c->gameObject()->sendMessage("heal",20);
                if(mainGame::sound)  HPFrase_sound->play();
            }
        }
        else{
            std::vector<gme::GameObject*> children = c->gameObject()->getChildren();
            gme::Component *pb = children.at(0)->getComponent<pistolaBehavior*>();
            gme::Component *mb = children.at(0)->getComponent<metralletaBehavior*>();
            gme::Component *eb = children.at(0)->getComponent<escopetaBehavior*>();
            gme::Component *lb = children.at(0)->getComponent<lnzllamasBehavior*>();
            
            if(objectType == 2 && !pb->isActive()){
                if(mainGame::sound) pistolaFrase_sound->play();
                pb->setActive(true);
                mb->setActive(false);
                eb->setActive(false);
                lb->setActive(false);
            }
            if(objectType == 3 && !mb->isActive()){
                if(mainGame::sound) metralletaFrase_sound->play();
                pb->setActive(false);
                mb->setActive(true);
                eb->setActive(false);
                lb->setActive(false);
            }
            if(objectType == 4 && !eb->isActive()){
                if(mainGame::sound)  escopetaFrase_sound->play();
                pb->setActive(false);
                mb->setActive(false);
                eb->setActive(true);
                lb->setActive(false);
            }
            if(objectType == 5 && !lb->isActive()){
                if(mainGame::sound)  lanzallamasFrase_sound->play();
                pb->setActive(false);
                mb->setActive(false);
                eb->setActive(false);
                lb->setActive(true);
            }
           
        }
        destroyed = true;
    }
}

void ColectableScript::onMessage(std::string m, float v) {
    
    if(m.compare("damage") == 0 && isHit == false){
        //CUANDO RECIBE UN GOLPE EL COLIDER
        
        
        
        isHit = true;
        hp--;
        if(hp <= 0){
            explode(10,20,50,100);
            destroyed = true;
            
        }
        else explode(3,10,25,50);
    }
    isHit = false;
}

void ColectableScript::explode(int min, int max, float forcemin, float forcemax) {
    
	if(mainGame::sound) cajaRota_sound->play();
    if(mainGame::particles == 0) return;
    else if(mainGame::particles == 1){
        max /= 4.0;
        min /= 4.0;
    } 
    
    int cantidad = (rand() % (max-min)) + min;
    
    gme::Vector2 pos = getTransform()->getPosition();
    
    pos.y += 8*3;
    
    for(int i=0;i<cantidad;i++){
        float dirX = ( (rand() % 200) - 100 ) / 100.f;
        float dirY = ( (rand() % 200) - 100 ) / 100.f;
        int force = (rand() % (int)(forcemax-forcemin)) + forcemin;
        defaultParticle *particle = new defaultParticle("blood"); 
        particle->startingPosition = pos;
        instantiate(particle);
        particle->getTransform()->setPosition(pos);
        
        if(rand() % 10 == 1){
            particle->getRenderer()->setColor(33,51,32);
        }
        else{
            particle->getRenderer()->setColor(103,64,40);
        }
        particle->getRigidBody()->pushImmediate(gme::Vector2(dirX, dirY), force);
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
    
    gme::GUI::globalRotation = 0;
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
                    getRenderer()->setFrame("ani_NuevaVida_"+std::to_string(walkFrameCountL));
                }
                if(objectType == 1){
                    getRenderer()->setFrame("ani_HP_"+std::to_string(walkFrameCountL));
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


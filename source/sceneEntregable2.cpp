#include "sceneEntregable2.hpp"
#include "weapon.hpp"
#include <SFML/Graphics.hpp>
#include "fondoBlanco.hpp"
#include "pistolaBehavior.hpp"
#include "metralletaBehavior.hpp"
#include "lnzllamasBehavior.hpp"
#include "escopetaBehavior.hpp"

void sceneEntregable2::setup(){
    
    gme::Vector2 windowSize = gme::Game::getWindow()->getSize();
    
    gme::GameObject *fondo_Blanco= new fondoBlanco("fondoBlanco");
    fondo_Blanco->getTransform()->setPosition(gme::Vector2(320, 240));
    fondo_Blanco->getRenderer()->setTexture("fondo_blanco");
    
    //WEAPON por delante del player
    weapon *weapon1 = new weapon("weapon_1");
    pistolaBehavior *pb = new pistolaBehavior();
    metralletaBehavior *mb = new metralletaBehavior();
    lnzllamasBehavior *lb = new lnzllamasBehavior();
    escopetaBehavior *eb = new escopetaBehavior();
    weapon1->addComponent(eb);
        
}



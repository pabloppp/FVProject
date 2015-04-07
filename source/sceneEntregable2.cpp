#include "sceneEntregable2.hpp"
#include "weapon.hpp"
#include <SFML/Graphics.hpp>
#include "fondoBlanco.hpp"
#include "pistolaBehavior.hpp"

void sceneEntregable2::setup(){
    
    gme::Vector2 windowSize = gme::Game::getWindow()->getSize();
    
    gme::GameObject *fondo_Blanco= new fondoBlanco("fondoBlanco");
    fondo_Blanco->getTransform()->setPosition(gme::Vector2(320, 240));
    fondo_Blanco->getRenderer()->setTexture("fondo_blanco");
    
    //WEAPON por delante del player
    weapon *weapon1 = new weapon("weapon_1");
    pistolaBehavior *pb = new pistolaBehavior();
    weapon1->addComponent(pb);
        
}



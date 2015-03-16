#include "hito1Game.hpp"
#include "sceneEntregable2.hpp"

void hito1Game::setup(){
    
    //debugColliders = true;
    
    gme::Game::newTexture("hito1/recursos/Broniversal Soldier Anim.png", "playerTexture");
    gme::Game::newTexture("hito1/recursos/temple_bricks.png", "templeTexture");
    gme::Game::newTexture("hito1/recursos/Broniversal Soldier Gun Anim.png","weaponTexture");
    gme::Game::newTexture("hito1/recursos/bullet.png","bulletTexture");
    gme::Scene *newScene = new sceneEntregable2("sceneEntregable2");
    
    gme::Game::setCurrentScene("sceneEntregable2");
}




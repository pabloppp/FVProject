#include "hito1Game.hpp"
#include "sceneEntregable5.hpp"

void hito1Game::setup(){
    
    //debugColliders = true;
    
    gme::Game::newTexture("hito1/recursos/Broniversal Soldier Anim.png", "playerTexture");
    gme::Game::newTexture("hito1/recursos/temple_bricks.png", "templeTexture");
    
    gme::Scene *newScene = new sceneEntregable5("sceneEntregable5");
    
    gme::Game::setCurrentScene("sceneEntregable5");
}




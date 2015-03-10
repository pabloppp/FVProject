#include "hito1Game.hpp"
#include "scene51.hpp"

void hito1Game::setup(){
    
    //debugColliders = true;
    
    gme::Game::newTexture("hito1/recursos/Broniversal Soldier Anim.png", "playerTexture");
    gme::Game::newTexture("hito1/recursos/temple_bricks.png", "templeTexture");
    
    gme::Scene *newScene = new scene51("scene51");
    
    gme::Game::setCurrentScene("scene51");
}




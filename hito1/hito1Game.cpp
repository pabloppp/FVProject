#include "hito1Game.hpp"
#include "scene51.hpp"

void hito1Game::setup(){
    
    //debugColliders = true;
    
    gme::Game::newTexture("hito1/recursos/Broniversal Soldier Anim.png", "playerTexture");
    gme::Game::newTexture("hito1/recursos/temple_bricks.png", "templeTexture");
    gme::Game::newTexture("hito1/recursos/jungle_sky.png", "skyTexture");
    gme::Game::newTexture("hito1/recursos/jungle_frontA.png", "bgFrontATexture");
    gme::Game::newTexture("hito1/recursos/jungle_frontB.png", "bgFrontBTexture");
    gme::Game::newTexture("hito1/recursos/jungle_frontC.png", "bgFrontCTexture");
    gme::Game::newTexture("hito1/recursos/jungle_midA.png", "bgMidATexture");
    gme::Game::newTexture("hito1/recursos/jungle_midB.png", "bgMidBTexture");
    gme::Game::newTexture("hito1/recursos/jungle_midC.png", "bgMidCTexture");
    
    gme::Scene *newScene = new scene51("scene51");
    
    gme::Game::setCurrentScene("scene51");
}




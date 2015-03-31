#include "hito1Game.hpp"
#include "scene51.hpp"
#include "sceneEntregable3.hpp"
#include "sceneEntregable5.hpp"

void hito1Game::setup(){
    
    //debugColliders = true;
    
    gme::Game::newTexture("hito1/recursos/Noisy Cricket Ball.png", "coleccionable");
    gme::Game::newTexture("hito1/recursos/Broniversal Soldier Anim.png", "playerTexture");
    gme::Game::newTexture("hito1/recursos/temple_bricks.png", "templeTexture");
    gme::Game::newTexture("hito1/recursos/jungle_sky.png", "skyTexture");
    gme::Game::newTexture("hito1/recursos/jungle_frontA.png", "bgFrontATexture");
    gme::Game::newTexture("hito1/recursos/jungle_frontB.png", "bgFrontBTexture");
    gme::Game::newTexture("hito1/recursos/jungle_frontC.png", "bgFrontCTexture");
    gme::Game::newTexture("hito1/recursos/jungle_midA.png", "bgMidATexture");
    gme::Game::newTexture("hito1/recursos/jungle_midB.png", "bgMidBTexture");
    gme::Game::newTexture("hito1/recursos/jungle_midC.png", "bgMidCTexture");
    gme::Game::newTexture("hito1/recursos/alien2.png", "alien");
    gme::Game::newTexture("resources/sprites/walk_spr/sprites.png", "dino");
    
    gme::Scene *newScene = new sceneEntregable5("sceneEntregable5");
    
    gme::Game::setCurrentScene("sceneEntregable5");
}




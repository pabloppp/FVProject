#include "hito1Game.hpp"
#include "scene51.hpp"
#include "sceneEntregable3.hpp"

void hito1Game::setup(){
    
    //debugColliders = true;
    
    gme::Game::newTexture("hito1/recursos/Noisy Cricket Ball.png", "coleccionable");
    gme::Game::newTexture("hito1/recursos/temple_bricks.png", "templeTexture");
    
    //gme::Scene *newScene = new scene51("scene51");
    gme::Scene *newScene = new sceneEntregable3("sceneAlberto");
    
    gme::Game::setCurrentScene("sceneAlberto");
}




#include "hito1Game.hpp"
#include "sceneEntregable3.hpp"

void hito1Game::setup(){
    gme::Game::newTexture("demo/resources/starship.png", "prueba");
    gme::Game::newTexture("demo/resources/particle1.png", "particle");
    
    gme::Scene *sceneAlberto = new sceneEntregable3("sceneAlberto");
    gme::Game::setCurrentScene("sceneAlberto");
}




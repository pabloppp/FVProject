#include "sceneEntregable3.hpp"
#include "pruebaGameObject.hpp"
#include <SFML/Graphics.hpp>

void sceneEntregable3::setup(){
    
    gme::GameObject *player = new pruebaGameObject("prueba");
    player->getTransform()->setPosition(gme::Vector2(320, 240));
    
}


#include "sceneEntregable2.hpp"
#include "pruebaGameObject.hpp"
#include <SFML/Graphics.hpp>

void sceneEntregable2::setup(){
    
    gme::GameObject *player = new pruebaGameObject("prueba");
    player->getTransform()->setPosition(gme::Vector2(320, 240));
    
    gme::GameObject *arma;
    
    //el gameobject del arma tiene que ser hijo del jugador setParent()
    
}

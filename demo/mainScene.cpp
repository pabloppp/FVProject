#include "mainScene.hpp"
#include "Starship.hpp"
#include "CustomScript.hpp"
#include "JetParticle.hpp"

#include <SFML/Graphics.hpp>


void mainScene::setup(){
    

    
    //Creamos los objetos de la escena
    //y edición de los mismos
    
    gme::GameObject *player = new Starship("starship");
    player->getTransform()->setPosition(gme::Vector2(320, 240));

}



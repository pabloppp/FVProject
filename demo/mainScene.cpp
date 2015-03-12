#include "mainScene.hpp"
#include "Starship.hpp"
#include "CustomScript.hpp"
#include "JetParticle.hpp"
#include "Asteroid.hpp"

#include <SFML/Graphics.hpp>


void mainScene::setup(){
    

    
    //Creamos los objetos de la escena
    //y edición de los mismos
    for(int i = 0; i < 0; i++){
        gme::GameObject *player = new Starship("starship");
        player->getTransform()->setPosition(gme::Vector2(rand()%640, rand()%480));    
        //player->getTransform()->setPosition(gme::Vector2(320+(i+1)*30, 240));    
    }
    
    gme::GameObject *player = new Starship("starship");
    player->getTransform()->setPosition(gme::Vector2(320, 240));
    
    gme::GameObject *ast = new Asteroid("asteroid");
    gme::GameObject *ast2 = new Asteroid("asteroid");
    gme::GameObject *ast3 = new Asteroid("asteroid");
    gme::GameObject *ast4 = new Asteroid("asteroid");
    ast->getTransform()->setPosition(gme::Vector2(320, 5));
    ast2->getTransform()->setPosition(gme::Vector2(320, 475));
    ast3->getTransform()->setPosition(gme::Vector2(5, 240));
    ast3->getTransform()->rotate(90);
    ast4->getTransform()->setPosition(gme::Vector2(640, 235));
    ast4->getTransform()->rotate(90);

}



#include "mainGame.hpp"

#include "sceneSplash.hpp"
#include "sceneMenu.hpp"
#include "scenePrueba.hpp"



void mainGame::setup() {
    
    debugColliders = true;
    
    gme::Game::newTexture("resources/fondoSplash.png", "fondoSplash");  
    gme::Game::newTexture("resources/fondonuevo.png", "fondo_principal");
    gme::Game::newTexture("resources/gato.png", "logo");
    gme::Game::newTexture("resources/no.png", "no_icon");   
    gme::Game::newTexture("resources/dino.png","enemyTexture");
    gme::Game::newTexture("resources/Broniversal Soldier Anim.png","playerTexture");
   
    gme::Game::newMusic("resources/chores_rules.wav", "sound"); 
    gme::Game::newMusic("resources/boton.wav", "boton");
    gme::Game::newMusic("resources/deslizamiento.wav", "desplazamiento");
    
    //gme::Scene *splash_scene = new sceneSplash("splash");
    //gme::Scene *mainmenu_scene = new sceneMenu("mainmenu");
    
    gme::Scene *prueba = new scenePrueba("prueba");
    
    gme::Game::setCurrentScene("prueba");
}



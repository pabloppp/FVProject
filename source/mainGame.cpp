#include "mainGame.hpp"

#include "sceneSplash.hpp"
#include "sceneMenu.hpp"
#include "tilerJsonLoadScene.hpp"

void mainGame::setup() {
    
    //debugColliders = true;
    
    gme::Game::newTexture("resources/BGs/fondoSplash.png", "fondoSplash");  
    gme::Game::newTexture("resources/BGs/fondonuevo.png", "fondo_principal");
    gme::Game::newTexture("resources/BGs/gato.png", "logo");
    gme::Game::newTexture("resources/Effects/no.png", "no_icon"); 
    
    gme::Game::newTexture("resources/Effects/blood_particle.png", "spray_particle"); 
    
    gme::Game::newTexture("resources/Enemies/sprites/walk_spr/sprites.png", "dino00");   
   
    gme::Game::newMusic("resources/Sounds/chores_rules.wav", "sound");
    gme::Game::newMusic("resources/Sounds/boton.wav", "boton");
    gme::Game::newMusic("resources/Sounds/deslizamiento.wav", "desplazamiento");
    
    
    gme::Scene *splash_scene = new sceneSplash("splash");
    gme::Scene *mainmenu_scene = new sceneMenu("mainmenu");
    
    gme::Scene *tiledTest = new tilerJsonLoadScene("tiledTest");
    
    
    gme::Game::setCurrentScene("tiledTest");
}



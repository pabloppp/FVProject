#include "hito1Game.hpp"
#include "sceneMenu.hpp"
#include "sceneSplash.hpp"
#include "sceneMenu.hpp"
#include "sceneSplash.hpp"
//#include "sceneEntregable3.hpp"

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
    gme::Game::newTexture("hito1/recursos/Broniversal Soldier Gun Anim.png","weaponTexture");
    gme::Game::newTexture("hito1/recursos/pistola.png","weaponTexture2");
    gme::Game::newTexture("hito1/recursos/bullet.png","bulletTexture");
    gme::Game::newTexture("hito1/recursos/dino.png","enemyTexture");
   gme::Game::newTexture("hito1/recursos/fondoSplash.png", "fondoSplash");  
   gme::Game::newTexture("hito1/recursos/fondonuevo.png", "fondo_principal");
   gme::Game::newTexture("hito1/recursos/gato.png", "logo");
   gme::Game::newTexture("hito1/recursos/no.png", "no_icon");
   gme::Game::newTexture("hito1/recursos/ojo.png", "ojo");
   
   
   gme::Game::newMusic("hito1/recursos/chores_rules.wav", "sound");
   gme::Game::newMusic("hito1/recursos/boton.wav", "boton");
   gme::Game::newMusic("hito1/recursos/deslizamiento.wav", "desplazamiento");
   
    
    gme::Scene *newScene = new sceneEntregable5("sceneEntregable5");
    
    gme::Game::setCurrentScene("sceneEntregable5");
}




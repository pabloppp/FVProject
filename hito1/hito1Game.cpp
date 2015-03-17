#include "hito1Game.hpp"
#include "sceneMenu.hpp"
#include "sceneSplash.hpp"
//#include "sceneEntregable3.hpp"

void hito1Game::setup(){
    
    //debugColliders = true;
    
   gme::Game::newTexture("hito1/recursos/fondoSplash.png", "fondoSplash"); 
    
   gme::Game::newTexture("hito1/recursos/fondonuevo.png", "fondo_principal");
   gme::Game::newTexture("hito1/recursos/logoFV2.png", "logo");
   
   gme::Game::newMusic("hito1/recursos/animals.wav", "sound");
   
    
   gme::Scene *sceneM = new sceneMenu("sceneM"); 
   /*gme::Game::setCurrentScene("sceneM");*/
   
   gme::Scene *sceneS = new sceneSplash("sceneS"); 
   gme::Game::setCurrentScene("sceneS");
}





#include "sceneSplash.hpp"
#include "staticObject.hpp"
#include "MenuManager.hpp"

void sceneSplash::setup(){

   gme::GameObject *fondo= new staticObject("fondo");
   fondo->getTransform()->setPosition(gme::Vector2(512, 288));
   fondo->getRenderer()->setTexture("fondoSplash");
   fondo->getRenderer()->setColor(255,255,255,0);
   
    //gme::GameObject *menuManager = new MenuManager("mmanager");  
   
    
}

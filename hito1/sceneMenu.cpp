
#include "sceneMenu.hpp"
#include "imagenFondo.hpp"
#include "staticObject.hpp"

#include <SFML/Graphics.hpp>

void sceneMenu::setup(){
    
  
   
   
   
   gme::GameObject *fondo1= new imagenFondo("fondo1");
   fondo1->getTransform()->setPosition(gme::Vector2(320, 240));
   fondo1->getRenderer()->setTexture("fondo_principal");

   gme::GameObject *fondo2= new imagenFondo("fondo2");
   fondo2->getTransform()->setPosition(gme::Vector2(320+640, 240));
   fondo2->getTransform()->setScale(gme::Vector2(-1, 1));
   fondo2->getRenderer()->setTexture("fondo_principal");
   
   
   /* gme::GameObject *logo= new staticObject("logo");
    logo->getTransform()->setPosition(gme::Vector2(320, 130));
    logo->getRenderer()->setTexture("logo");
    //logo->getRenderer()->setSize(gme::Vector2(1, 1));
    logo->getTransform()->setScale(gme::Vector2(0.20,0.20));*/
 
    
    
}

   
    
  



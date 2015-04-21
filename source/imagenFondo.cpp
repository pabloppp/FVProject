#include "imagenFondo.hpp"
#include "moveFondo.hpp"
#include "MenuManager.hpp"

void imagenFondo::setup(){
    
    getRenderer()->setSize(gme::Vector2(640,480));
    
    //moveFondo *accion = new moveFondo();
    MenuManager *mmanaer = new MenuManager();
    addComponent(mmanaer);
}


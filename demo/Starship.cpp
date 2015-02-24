#include "Starship.hpp"
#include "MyGame.hpp"
#include "CustomScript.hpp"
#include "scriptDePrueba.hpp"

void Starship::setup(){
    
    //AÑADIMOS LOS SCRIPTS Y SE CUSTOMIZAN SI ES NECESARIO
    addTag("player");
    getRenderer()->setTexture("starship");
    //getRenderer()->setSize(gme::Vector2(32,32));
    CustomScript *script1 = new CustomScript();
    addComponent(script1);
    
    addComponent(new scriptDePrueba());
    
    addComponent(new gme::RigidBody());
    addComponent(new gme::CircleCollider());
    
    getTransform()->scale = gme::Vector2(3,3);  
    
    
}



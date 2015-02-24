#include "CustomScript.hpp"
#include "JetParticle.hpp"

//OBLIGATORIOS
void CustomScript::setup(){
    if(getRigidBody() != NULL) getRigidBody()->setGravity(true);
    timeLapse = 0.1;
}

void CustomScript::update(){
    float deltaTime = gme::Game::deltaTime.asSeconds();
    
    //std::cout << gme::Mouse::getPosition().x << ": mouseX" << std::endl;
    
    if(getRigidBody() != NULL){
        
        if(gme::Keyboard::isKeyPressed(gme::Keyboard::Space) && !spaceDown){
            if(getRigidBody()->hasGravity()) getRigidBody()->setGravity(false);
            else getRigidBody()->setGravity(true);
            spaceDown = true;
        }else if(!gme::Keyboard::isKeyPressed(gme::Keyboard::Space) && spaceDown){
            spaceDown = false;
        }
        
        if(gme::Keyboard::isKeyPressed(gme::Keyboard::Up)){
            getRigidBody()->push(getTransform()->forward(), 12*deltaTime);
        }
        if(gme::Keyboard::isKeyPressed(gme::Keyboard::Down))
            getRigidBody()->push(getTransform()->forward(), -10*deltaTime);
        
        if(gme::Keyboard::isKeyPressed(gme::Keyboard::Right))
            getRigidBody()->angularSpeed += 5*deltaTime;
        
        if(gme::Keyboard::isKeyPressed(gme::Keyboard::Left))
            getRigidBody()->angularSpeed -= 5*deltaTime;
        
        if(getRigidBody()->speed.magnitude() > 100 || gme::Keyboard::isKeyPressed(gme::Keyboard::Up)){
            timeOut+=deltaTime;
            if(timeOut > timeLapse){
                timeOut = 0;
                gme::GameObject *particle = new JetParticle("particle");
                instantiate(particle);
                particle->getTransform()->setPosition(gme::Vector2(
                    getTransform()->position.x-getTransform()->forward().x*20,
                    getTransform()->position.y-getTransform()->forward().y*20
                ));
                particle->getTransform()->setRotation(getTransform()->rotation);
            }
        }

    }
    
    if(getTransform()->position.y > 480+23){
        getTransform()->position.y = 0-23;
    }
    else if(getTransform()->position.y < 0-23){
        getTransform()->position.y = 480+23;
    }
    
    if(getTransform()->position.x > 640+23) getTransform()->position.x = 0-23;
    else if(getTransform()->position.x < 0-23) getTransform()->position.x = 640+23;
    
    //std::cout << "GameObjects: " << gme::Game::getCurrentScene()->getGameObjects()->size() << std::endl;
}

//OPCIONALES
CustomScript::~CustomScript(){ //onDestroy
    //std::cout << "destruyendome" << std::endl;
}

void CustomScript::onGui(){
    
}

void CustomScript::onMessage(std::string s, float f){
    
}


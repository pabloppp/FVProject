#include "particleDecay.hpp"

void particleDecay::setup(){
  frames = 6;  
  fps = 10;  
}

void particleDecay::update(){   
    //std::cout << gme::GameObject::findWithTag("particle").size() << std::endl;
    float deltaTime = gme::Game::deltaTime.asSeconds();
    elapsedTime += deltaTime;
    if(elapsedTime >= 1.0/fps && frameCount < frames){        
        frameCount++;
        getRenderer()->setFrame(gme::Vector2(frameCount,0));
        elapsedTime = 0;
    }
    if(frameCount >= frames){
        //std::cout << "could not delete object" << std::endl;
        destroyGameObject(gameObject());
    }
    
}


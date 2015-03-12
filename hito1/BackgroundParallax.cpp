#include "BackgroundParallax.hpp"

void BackgroundParallax::setup() {
    cameraTransform = gme::Game::mainCamera->getTransform();
    initialPosition = getTransform()->getPosition();
    
    initialDifference = gme::Vector2(cameraTransform->getPosition().x-initialPosition.x, cameraTransform->getPosition().y-initialPosition.y);
}

void BackgroundParallax::update() {
    

    
}

void BackgroundParallax::fixedUpdate() {
    //Lo pongo aqui y no en 'update' para que no vaya desfasado con respecto al movimiento de la camara
    
    gme::Vector2 difference(cameraTransform->getPosition().x-initialPosition.x, cameraTransform->getPosition().y-initialPosition.y);
    
    gme::Vector2 currentPosition(initialPosition.x+difference.x*parallaxFactor-initialDifference.x, initialPosition.y+difference.y-initialDifference.y);
    
    getTransform()->setPosition(currentPosition);
}


BackgroundParallax::~BackgroundParallax() {

}


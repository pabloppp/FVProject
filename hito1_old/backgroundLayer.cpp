#include "backgroundLayer.hpp"
#include "BackgroundParallax.hpp"

void backgroundLayer::setup() {
    if(parallaxFactor > 1) parallaxFactor = 1;
    else if(parallaxFactor < 0) parallaxFactor = 0;
    
    if(texture.length() > 0){
        getRenderer()->setTexture(texture);
        getRenderer()->setCenter(gme::Vector2(0.5f, 1));
    }
    
    getTransform()->setScale(gme::Vector2(3,3));
    
    BackgroundParallax *parallax = new BackgroundParallax;
    parallax->parallaxFactor = parallaxFactor;
    addComponent(parallax);
    
}



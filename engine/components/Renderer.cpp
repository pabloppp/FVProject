#include "Renderer.hpp"

#include "../Game.hpp"
#include "../facade/Vector2.hpp"

using namespace gme;

void Renderer::setup() {
    //drawable = NULL;
    //std::cout << "renderer setup" << std::endl;
}

void Renderer::update() {
    gme::Vector2 pos = Vector2(0.f,0.f);
    gme::Vector2 scl = Vector2(1,1);
    float rot = 0;
    if(gameObject() != NULL){
        pos = gameObject()->getTransform()->getPosition();
        rot = gameObject()->getTransform()->getRotation();
        scl = gameObject()->getTransform()->getScale();
    }
    if(drawable != NULL){
        if(dynamic_cast<sf::Sprite*>(drawable)){
            ((sf::Sprite*)drawable)->setPosition(pos.x, pos.y);
            ((sf::Sprite*)drawable)->setRotation(rot);
            ((sf::Sprite*)drawable)->setScale(scl.x, scl.y);
            ((sf::Sprite*)drawable)->setTextureRect(sf::IntRect(position.x*size.x, position.y*size.y, size.x, size.y));
            ((sf::Sprite*)drawable)->setOrigin(center.x*size.x,center.y*size.y);
        }
        Game::getWindow()->draw(*drawable);
        //std::cout << Game::getWindow()->getSize().x << std::endl;
    }
    
    if(Game::debugColliders && gameObject() != NULL && gameObject()->getCollider() != NULL){
        gameObject()->getCollider()->render();
    }
}

void Renderer::setTexture(Texture &t){
    drawable = new sf::Sprite(t.getTexture());
    if(size.x == 0 || size.y == 0){
        size.x = ((sf::Sprite*)drawable)->getTexture()->getSize().x;
        size.y = ((sf::Sprite*)drawable)->getTexture()->getSize().y;
        center.x = 0.5;
        center.y = 0.5;
    }
    
}

void Renderer::setTexture(const std::string& s){
    Texture *t = Game::getTexture(s);
    if(t != NULL) setTexture(*t);
}

void Renderer::setSize(gme::Vector2 f){
    size = f;
}

void Renderer::setFrame(gme::Vector2 f){
    position = f;
}

void Renderer::setCenter(gme::Vector2 f){
    center = f;
}
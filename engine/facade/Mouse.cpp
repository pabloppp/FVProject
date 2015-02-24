#include "Mouse.hpp"

#include <SFML/Graphics.hpp>
#include "../Game.hpp"

using namespace gme;

Vector2 Mouse::getPosition(Window w){
    sf::Vector2i vect = sf::Mouse::getPosition(*(w.getRWindow()));
    return Vector2(vect.x, vect.y);
}

Vector2 Mouse::getPosition(){
    sf::Vector2i vect = sf::Mouse::getPosition(*(Game::getWindow()->getRWindow())); 
    if(Game::getWindow() != NULL) return Vector2(vect.x, vect.y);
    else return Vector2(0,0);
}

Vector2 Mouse::worldPosition(Vector2 p){
    sf::Vector2f vect = Game::getWindow()->getRWindow()->mapPixelToCoords(sf::Vector2i(p.x, p.y));
    if(Game::getWindow() != NULL) return Vector2(vect.x, vect.y);
    else return Vector2(0,0);
}

bool Mouse::isButtonPressed(int i){
    if(i == LEFT) return sf::Mouse::isButtonPressed(sf::Mouse::Left);
    else if (i == RIGHT) return sf::Mouse::isButtonPressed(sf::Mouse::Right);
    else return false;
}


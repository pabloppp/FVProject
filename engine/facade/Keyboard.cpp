#include "Keyboard.hpp"
#include "../Game.hpp"

using namespace gme;

Keyboard::Keyboard() {
}

bool Keyboard::isKeyPressed(Key key){
    sf::Keyboard::Key k = static_cast<sf::Keyboard::Key>((int)key); 
    if(Game::isKeyPressed(k)) return true;
    else return sf::Keyboard::isKeyPressed(k);
}
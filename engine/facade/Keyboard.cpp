#include "Keyboard.hpp"

using namespace gme;

Keyboard::Keyboard() {
}

bool Keyboard::isKeyPressed(Key key){
    sf::Keyboard::Key k = static_cast<sf::Keyboard::Key>((int)key);   
    return sf::Keyboard::isKeyPressed(k);
}
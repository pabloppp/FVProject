#ifndef MYGAME_HPP
#define	MYGAME_HPP

#include "../engine/Game.hpp"

class MyGame : public gme::Game{    
public:
    MyGame(sf::Vector2f windowSize, std::string name) : gme::Game(windowSize, name){};
    void setup();
private:
};

#endif	/* MYGAME_HPP */


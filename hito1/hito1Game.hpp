#ifndef HITO1GAME_HPP
#define	HITO1GAME_HPP

#include "../engine/GMEngine.hpp"

class hito1Game : public gme::Game{    
public:
    hito1Game(sf::Vector2f windowSize, std::string name) : gme::Game(windowSize, name){};
    void setup();
private:
};

#endif	/* HITO1GAME_HPP */


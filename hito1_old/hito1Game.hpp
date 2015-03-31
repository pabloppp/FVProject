#ifndef HITO1GAME_HPP
#define	HITO1GAME_HPP

#include "../engine/GMEngine.hpp"

class hito1Game : public gme::Game{    
public:
    hito1Game(gme::Vector2 windowSize, std::string name) : gme::Game(windowSize, name){};
    void setup();
private:
};

#endif	/* HITO1GAME_HPP */


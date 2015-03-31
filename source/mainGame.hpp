#ifndef MAINGAME_HPP
#define	MAINGAME_HPP

#include "../engine/GMEngine.hpp"

class mainGame : public gme::Game{
public:
    mainGame(gme::Vector2 windowSize, std::string name) : gme::Game(windowSize, name){};
    void setup();
private:

};

#endif	/* MAINGAME_HPP */


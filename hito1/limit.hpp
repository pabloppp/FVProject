#ifndef LIMIT_HPP
#define	LIMIT_HPP

#include "../engine/GMEngine.hpp"

class limit : public gme::GameObject{
public:
    limit(std::string n) : gme::GameObject(n){};
    void setup();
    float width, height;
    gme::Vector2 position;
private:

};

#endif	/* PLAYER_HPP */


#ifndef TILE_HPP
#define	TILE_HPP

#include "../engine/GMEngine.hpp"

class tile : public gme::GameObject {
public:
    tile(std::string n) : gme::GameObject(n){
        side = 0;
    };
    void setup();
    void addCollider();
    int side;
private:

};

#endif	/* TILE_HPP */


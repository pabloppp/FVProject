#ifndef TILE_HPP
#define	TILE_HPP

#include "../engine/GMEngine.hpp"

class tile : public gme::GameObject {
public:
    tile(std::string n) : gme::GameObject(n){
    };
    void setup();
    void addCollider();
private:

};

#endif	/* TILE_HPP */


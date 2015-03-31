#ifndef TILE_HPP
#define	TILE_HPP

#include "../engine/GMEngine.hpp"

class tile : public gme::GameObject {
public:
    tile(std::string n) : gme::GameObject(n){
        texture = "";
    };
    void setup();
    std::string texture;
    gme::Vector2 size;
    gme::Vector2 frame;
private:

};

#endif	/* TILE_HPP */


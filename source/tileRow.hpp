#ifndef TILEROW_HPP
#define	TILEROW_HPP

#include "../engine/GMEngine.hpp"
#include "tile.hpp"

class tileRow : public gme::GameObject {
public:
    tileRow(std::string n) : gme::GameObject(n){};
    void setup();
    int tileSize;
private:

};

#endif	/* TILEROW_HPP */


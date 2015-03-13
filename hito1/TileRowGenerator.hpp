#ifndef TILEROWGENERATOR_HPP
#define	TILEROWGENERATOR_HPP

#include "../engine/GMEngine.hpp"

class TileRowGenerator : public gme::Script {
public:
    TileRowGenerator() : gme::Script(){};
    void setup();
    void update();
    virtual void onCollision(gme::Collider* c);
    virtual ~TileRowGenerator();
    int tileCount;
    float tileSize;
private:

};

#endif	/* TILEROWGENERATOR_HPP */


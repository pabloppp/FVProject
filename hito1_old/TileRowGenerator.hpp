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
    float tileSize;
private:
    int tileCount;
    void regenerateRow();
    void addRow(std::vector<gme::GameObject *> &tiles);

};

#endif	/* TILEROWGENERATOR_HPP */


#ifndef MAPGENERATOR_HPP
#define	MAPGENERATOR_HPP

#include "../engine/GMEngine.hpp"

class mapGenerator : public gme::Script{
public:
    mapGenerator() : gme::Script(){
        mapFile = "";
        origin = gme::Vector2(0, -6*16*3);
    }
    virtual void setup();
    virtual void update();  
    virtual ~mapGenerator();
    void addRow(float cx, float cy, float tsize);
    
    std::string mapFile;
    gme::Vector2 origin;
    std::vector<gme::GameObject*> tRowV;

private:

};

#endif	/* MAPGENERATOR_HPP */


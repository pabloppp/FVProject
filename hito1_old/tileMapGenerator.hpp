#ifndef TILEMAPGENERATOR_HPP
#define	TILEMAPGENERATOR_HPP

#include "../engine/GMEngine.hpp"

class tileMapGenerator : public gme::GameObject{
public:
    
    tileMapGenerator(std::string n)  : gme::GameObject(n){};
    void setup();
    std::string mainTexture;
    std::string mainMapFile;
    int tileColumns;
    gme::Vector2 origin;
    
private:

};

#endif	/* TILEMAPGENERATOR_HPP */


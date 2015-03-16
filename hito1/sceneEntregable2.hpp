#ifndef SCENEENTREGABLE2_HPP
#define	SCENEENTREGABLE2_HPP

#include "../engine/GMEngine.hpp"

class sceneEntregable2 : public gme::Scene {
    public:
        sceneEntregable2() : gme::Scene(){};
        sceneEntregable2(std::string n) : gme::Scene(n){};
        void setup();
    private:
        void setupTileMap();    
};

#endif	/* SCENEENTREGABLE2_HPP */


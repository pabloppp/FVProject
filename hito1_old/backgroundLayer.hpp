#ifndef BACKGROUNDLAYER_HPP
#define	BACKGROUNDLAYER_HPP

#include "../engine/GMEngine.hpp"

class backgroundLayer : public gme::GameObject{
public:
    backgroundLayer(std::string n) : gme::GameObject(n){
        texture = "";
    };
    void setup();
    float parallaxFactor;
    std::string texture;
private:

};

#endif	/* BACKGROUNDLAYER_HPP */


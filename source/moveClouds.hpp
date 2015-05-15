
#ifndef MOVECLOUDS_HPP
#define	MOVECLOUDS_HPP

#include "../engine/GMEngine.hpp"
class moveClouds: public gme::Script {
public:
    moveClouds() : gme::Script(){
        speed = 20;
    };
    void setup();
    void update();
    float speed;
    float initX, initY;
    virtual ~moveClouds();
private:

};

#endif	/* MOVECLOUDS_HPP */


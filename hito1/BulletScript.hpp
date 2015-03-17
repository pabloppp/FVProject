/* 
 * File:   BulletScript.hpp
 * Author: apple
 *
 * Created on 15 de marzo de 2015, 17:11
 */

#ifndef BULLETSCRIPT_HPP
#define	BULLETSCRIPT_HPP

#include "../engine/GMEngine.hpp"

class BulletScript : public gme::Script {
public:
    BulletScript();
    BulletScript(const BulletScript& orig);
    virtual ~BulletScript();
    void setup();
    void update();
    virtual void onCollision(gme::Collider *c);
    int direccion;
private:
   
    float winSize;
};

#endif	/* BULLETSCRIPT_HPP */


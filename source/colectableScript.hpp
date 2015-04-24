/* 
 * File:   colectableScript.hpp
 * Author: albertomartinezmartinez
 *
 * Created on 24 de abril de 2015, 16:09
 */

#ifndef COLECTABLESCRIPT_HPP
#define	COLECTABLESCRIPT_HPP

#include "../engine/GMEngine.hpp"

class colectableScript : public gme::Script {
public:
    colectableScript();
    void setup();
    void collected();
    void findPlayer();
    void update();
    virtual void onCollision(gme::Collider* c);

    virtual void onMessage(std::string m, float v);

    colectableScript(const colectableScript& orig);
    virtual ~colectableScript();
private:
    
    bool grounded;
    bool destroy;
    int objectType;
    gme::GameObject *player;

};

#endif	/* COLECTABLESCRIPT_HPP */


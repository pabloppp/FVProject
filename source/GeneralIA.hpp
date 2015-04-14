/* 
 * File:   GeneralIA.hpp
 * Author: albertomartinezmartinez
 *
 * Created on 7 de abril de 2015, 14:23
 */

#ifndef GENERALIA_HPP
#define	GENERALIA_HPP

#include "../engine/GMEngine.hpp"

class GeneralIA : public gme::Script {
public:
    GeneralIA() : gme::Script(){};
    void setup();
    void update();
    void getPlayer();
    gme::Vector2 vectorDirection(gme::Vector2 pp ,gme::Vector2 dp);
    virtual ~GeneralIA();

    virtual void onCollision(gme::Collider* c);

private:
    double dist;
    gme::GameObject *g;
    
};

#endif	/* GENERALIA_HPP */


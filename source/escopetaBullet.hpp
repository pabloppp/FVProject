/* 
 * File:   escopetaBullet.hpp
 * Author: apple
 *
 * Created on 21 de abril de 2015, 10:42
 */

#ifndef ESCOPETABULLET_HPP
#define	ESCOPETABULLET_HPP

#include "../engine/GMEngine.hpp"

class escopetaBullet: public gme::GameObject {
public:
    escopetaBullet(std::string n): gme::GameObject(n){};
    void setup();
private:

};

#endif	/* ESCOPETABULLET_HPP */


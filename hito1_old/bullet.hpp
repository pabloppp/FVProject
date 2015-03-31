/* 
 * File:   bullet.hpp
 * Author: apple
 *
 * Created on 10 de marzo de 2015, 20:21
 */

#ifndef BULLET_HPP
#define	BULLET_HPP

#include "../engine/GMEngine.hpp"

class bullet : public gme::GameObject{
public:
    bullet(std::string n) : gme::GameObject(n){};
    void setup();
    void update();
private:

};

#endif	/* BULLET_HPP */


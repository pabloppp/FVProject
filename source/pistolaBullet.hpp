/* 
 * File:   bullet.hpp
 * Author: apple
 *
 * Created on 10 de marzo de 2015, 20:21
 */

#ifndef PISTOLABULLET_HPP
#define	PISTOLABULLET_HPP

#include "../engine/GMEngine.hpp"

class pistolaBullet : public gme::GameObject{
public:
    pistolaBullet(std::string n) : gme::GameObject(n){};
    void setup();
    void update();
private:

};

#endif	/* BULLET_HPP */


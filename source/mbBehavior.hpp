/* 
 * File:   mbBehavior.hpp
 * Author: apple
 *
 * Created on 7 de abril de 2015, 18:10
 */

#ifndef MBBEHAVIOR_HPP
#define	MBBEHAVIOR_HPP

class mbBehavior: public gme::Script {
public:
    mbBehavior() : gme::Script(){};
    void setup();
    void update();
    virtual ~mbBehavior();
private:
    gme::Vector2 winSize;
};

#endif	/* MBBEHAVIOR_HPP */


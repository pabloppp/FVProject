/* 
 * File:   sbBehavior.hpp
 * Author: apple
 *
 * Created on 21 de abril de 2015, 10:41
 */

#ifndef SBBEHAVIOR_HPP
#define	SBBEHAVIOR_HPP

#include "../engine/GMEngine.hpp"

class sbBehavior: public gme::Script {
public:
    sbBehavior() : gme::Script(){};;
    void setup();
    void update();
    virtual ~sbBehavior();
private:

};

#endif	/* SBBEHAVIOR_HPP */


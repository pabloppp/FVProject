/* 
 * File:   DestroyScript.hpp
 * Author: albertomartinezmartinez
 *
 * Created on 25 de abril de 2015, 18:55
 */

#ifndef DESTROYSCRIPT_HPP
#define	DESTROYSCRIPT_HPP
#include "../engine/GMEngine.hpp"

class DestroyScript : public gme::Script{
public:
    DestroyScript() : gme::Script(){} ;
    virtual ~DestroyScript();
    void setup();
    void update();
    virtual void onMessage(std::string m, float v);

private:

};

#endif	/* DESTROYSCRIPT_HPP */


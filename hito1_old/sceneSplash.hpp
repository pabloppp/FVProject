/* 
 * File:   sceneSplash.hpp
 * Author: Vir
 *
 * Created on 16 de marzo de 2015, 11:14
 */

#ifndef SCENESPLASH_HPP
#define	SCENESPLASH_HPP

#include "../engine/GMEngine.hpp"

class sceneSplash : public gme::Scene{
public:
    sceneSplash() : gme::Scene(){};
    sceneSplash(std::string n) : gme::Scene(n){};
    void setup();
private:
   
};

#endif	/* SCENESPLASH_HPP */


#ifndef INTROMANAGER_HPP
#define	INTROMANAGER_HPP

#include "../engine/GMEngine.hpp"

class introManager : public gme::GameObject{
public:
    introManager(std::string n) : gme::GameObject(n){};
    void setup();
private:

};

#endif	/* INTROMANAGER_HPP */


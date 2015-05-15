
#ifndef METRALLETABULLET_HPP
#define	METRALLETABULLET_HPP

#include "../engine/GMEngine.hpp"

class metralletaBullet: public gme::GameObject {
public:
    metralletaBullet(std::string n): gme::GameObject(n){};
    void setup();
    int whoshoots;
private:

};

#endif	/* METRALLETABULLET_HPP */


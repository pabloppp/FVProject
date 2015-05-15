
#ifndef ESCOPETABULLET_HPP
#define	ESCOPETABULLET_HPP

#include "../engine/GMEngine.hpp"

class escopetaBullet: public gme::GameObject {
public:
    escopetaBullet(std::string n): gme::GameObject(n){};
    void setup();
    int whoshoots;
private:

};

#endif	/* ESCOPETABULLET_HPP */


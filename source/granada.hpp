#ifndef GRANADA_HPP
#define	GRANADA_HPP

#include "../engine/GMEngine.hpp"

class granada : public gme::GameObject {
public:
    granada(std::string n) : gme::GameObject(n){whoshoots=1; direction=0;};
    void setup();
    int whoshoots; 
    int direction;
private:

};

#endif	/* GRANADA_HPP */


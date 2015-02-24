#ifndef CLOCK_HPP
#define	CLOCK_HPP

#include <SFML/Graphics.hpp>
#include "Time.hpp"

namespace gme{  
    
class Clock{
public:
    Clock();
    Time restart();
private:
    sf::Clock clock;
};

}

#endif	/* CLOCK_HPP */


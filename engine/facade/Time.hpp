#ifndef TIME_HPP
#define	TIME_HPP

#include <SFML/Graphics.hpp>

namespace gme{

class Time{
public:
    Time();
    Time(sf::Time t);
    float asSeconds();
    void Zero();
    void set(sf::Time time);
private:
    sf::Time time;
};

}

#endif	/* TIME_HPP */


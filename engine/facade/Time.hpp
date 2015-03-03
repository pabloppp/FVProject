#ifndef TIME_HPP
#define	TIME_HPP

#include <SFML/Graphics.hpp>

namespace gme{

class Time{
public:
    Time();
    Time(sf::Time t);
    Time(float t);
    Time multiply(float s);
    float asSeconds();
    void Zero();
    void set(sf::Time time);
private:
    sf::Time time;
};

}

#endif	/* TIME_HPP */


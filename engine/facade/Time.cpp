#include "Time.hpp"

using namespace gme;

Time::Time(){
    Zero();
}

Time::Time(sf::Time t){
    time = t;
}


float Time::asSeconds(){
    return time.asSeconds();
}

void Time::Zero(){
    time = sf::Time::Zero;
}

void Time::set(sf::Time t){
    time = t;
}
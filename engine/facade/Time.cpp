#include "Time.hpp"
#include <iostream>

using namespace gme;

Time::Time(){
    Zero();
}

Time::Time(sf::Time t){
    time = t;
}

Time::Time(float t){
    time = sf::seconds(t);
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

Time Time::multiply(float s) { 
    float scs = time.asSeconds();
    scs *= s;
    
    return Time(sf::seconds(scs));
}

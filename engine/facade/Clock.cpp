#include "Clock.hpp"

using namespace gme;

Clock::Clock(){
    
}

Time Clock::restart(){
    return Time(clock.restart());
}

Time Clock::currentTime() {
    return Time(clock.getElapsedTime());
}



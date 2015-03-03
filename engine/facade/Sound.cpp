#include "Sound.hpp"

using namespace gme;

Sound::Sound() {
}

sf::SoundBuffer &Sound::getSoundBuffer(){
    return buffer;
}

bool Sound::loadFromFile(const std::string& s){
    return buffer.loadFromFile(s);
}

std::string Sound::getName(){
    return name;
}

void Sound::setName(std::string n){
    name = n;
}

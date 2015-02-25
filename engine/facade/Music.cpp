#include "Music.hpp"

using namespace gme;

Music::Music() {
}

sf::Music &Music::getMusic(){
    return music;
}

bool Music::openFromFile(const std::string& s){
    return music.openFromFile(s);
}

std::string Music::getName(){
    return name;
}

void Music::setName(std::string n){
    name = n;
}


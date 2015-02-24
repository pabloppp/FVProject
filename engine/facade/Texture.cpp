#include "Texture.hpp"

using namespace gme;

Texture::Texture() {
}

sf::Texture &Texture::getTexture(){
    return texture;
}

bool Texture::loadFromFile(const std::string &s){
    return texture.loadFromFile(s);
}

std::string Texture::getName(){
    return name;
}

void Texture::setName(std::string n){
    name = n;
}


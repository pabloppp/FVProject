#include "Texture.hpp"
#include <iostream>
#include <string>

using namespace gme;

Texture::Texture() {
    atlas = NULL;
}

sf::Texture &Texture::getTexture(){
    return texture;
}

bool Texture::loadFromFile(const std::string &s){
    path = s;
    return texture.loadFromFile(s);
}

std::string Texture::getName(){
    return name;
}

void Texture::setName(std::string n){
    name = n;
}

std::string Texture::getPath() {
    return path;
}


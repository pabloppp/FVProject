#ifndef TEXTURE_HPP
#define	TEXTURE_HPP

#include <SFML/Graphics.hpp>
#include "json.h"

namespace gme{

class Texture {
public:
    Texture();
    bool loadFromFile(const std::string &s);
    sf::Texture &getTexture();
    std::string getName();
    void setName(std::string n);
    std::string getPath();
    json_object *atlas;
private:
    sf::Texture texture;
    std::string name;
    std::string path;
};

}

#endif	/* TEXTURE_HPP */


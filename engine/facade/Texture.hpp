#ifndef TEXTURE_HPP
#define	TEXTURE_HPP

#include <SFML/Graphics.hpp>

namespace gme{

class Texture {
public:
    Texture();
    bool loadFromFile(const std::string &s);
    sf::Texture &getTexture();
    std::string getName();
    void setName(std::string n);
private:
    sf::Texture texture;
    std::string name;
};

}

#endif	/* TEXTURE_HPP */


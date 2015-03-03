#ifndef SOUND_HPP
#define	SOUND_HPP

#include <SFML/Audio.hpp>

namespace gme{

class Sound {
public:
    Sound();
    bool loadFromFile(const std::string &s);
    sf::SoundBuffer &getSoundBuffer();
    void setName(std::string n);
    std::string getName();
private:
    sf::SoundBuffer buffer;
    std::string name;
};

}

#endif	/* SOUND_HPP */


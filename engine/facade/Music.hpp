#ifndef MUSIC_HPP
#define	MUSIC_HPP

#include <SFML/Audio.hpp>

namespace gme{

class Music {
public:
    Music();
    bool openFromFile(const std::string &s);
    sf::Music &getMusic();
    void setName(std::string n);
    std::string getName();
private:
    sf::Music music;
    std::string name;
};

}

#endif	/* MUSIC_HPP */


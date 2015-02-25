#ifndef MUSICPLAYER_HPP
#define	MUSICPLAYER_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "../Component.hpp"
#include "../facade/Music.hpp"

namespace gme{
    
class MusicPlayer : public Component{
public:
    void setup();
    void update();
    void play();
    void pause();
    void stop();
    void setVolume(float v);
    void setPitch(float p);
    void setOffset(float offset);
    void setMusic(const std::string &s);
    void loop(bool b);
    bool autoplay;
    
private:
    sf::Music *music;
};

}

#endif	/* MUSICPLAYER_HPP */


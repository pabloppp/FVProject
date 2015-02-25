#ifndef SOUNDPLAYER_HPP
#define	SOUNDPLAYER_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "../Component.hpp"
#include "../facade/Sound.hpp"

namespace gme{

class SoundPlayer : public Component{
public:
    void setup();
    void update();
    void setSound(const std::string &s);
    void play();
    void pause();
    void stop();
    void setVolume(float v);
    void setPitch(float p);
    void setOffset(float offset);
    void loop(bool b);
    bool isPlaying();
    bool autoplay;
private:
    sf::Sound *sound;
    bool playing;
};

}

#endif	/* SOUNDPLAYER_HPP */


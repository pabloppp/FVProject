#include "MusicPlayer.hpp"

using namespace gme;

#include "../Game.hpp"

void MusicPlayer::setup() {
    if(autoplay) music->play();
}

void MusicPlayer::update() {
    
}

void MusicPlayer::setMusic(const std::string& s) {
    Music *msc = Game::getMusic(s);
    if(msc != NULL){
        music = &msc->getMusic();
    }
}

void MusicPlayer::play() {
    music->play();
}

void MusicPlayer::pause() {
    music->pause();
}

void MusicPlayer::stop() {
    music->stop();
}

void MusicPlayer::setOffset(float offset) {
    music->setPlayingOffset(sf::seconds(offset));
}

void MusicPlayer::setPitch(float p) {
    music->setPitch(p);
}

void MusicPlayer::setVolume(float v) {
    music->setVolume(v);
}

void MusicPlayer::loop(bool b) {
    music->setLoop(b);
}






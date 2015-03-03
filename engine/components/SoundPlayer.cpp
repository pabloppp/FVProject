#include "SoundPlayer.hpp"

using namespace gme;

#include "../Game.hpp"

void SoundPlayer::setup(){
    if(autoplay){
        sound->play();
        playing = true;
    }
}

void SoundPlayer::update(){
    
}

void SoundPlayer::setSound(const std::string& s){
    Sound *snd = Game::getSound(s);
    if(snd != NULL){
        sound = new sf::Sound();
        sound->setBuffer(snd->getSoundBuffer());
    }
}

void SoundPlayer::play(){
    sound->play();
    playing = true;
}

void SoundPlayer::pause(){
    sound->pause();
    playing = false;
}

void SoundPlayer::stop(){
    sound->stop();
    playing = false;
}

void SoundPlayer::setOffset(float offset){
    sound->setPlayingOffset(sf::seconds(offset));
}

void SoundPlayer::setVolume(float v){
    sound->setVolume(v);
}

void SoundPlayer::setPitch(float p){
    sound->setPitch(p);
}

void SoundPlayer::loop(bool b) {
    sound->setLoop(b);
}

bool SoundPlayer::isPlaying() {
    return playing;
}


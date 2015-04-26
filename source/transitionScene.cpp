#include "transitionScene.hpp"

void transitionScene::setup() {
    
    gme::Game::setCurrentScene(nextScene);
    
}

std::string transitionScene::nextScene = "";



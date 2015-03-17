/* 
 * File:   CameraFollowPlayer.cpp
 * Author: pablopernias
 * 
 * Created on 9 de marzo de 2015, 23:57
 */

#include "CameraFollowPlayer.hpp"

void CameraFollowPlayer::setup() {
    player = gme::GameObject::findWithTag("player").front();
    std::cout << "Camera following player: " << player->getName() << std::endl;
    currentPos = getObjPos();
}

void CameraFollowPlayer::update() {
    objPos = getObjPos();
    float lerpFactor = 0.2;
    currentPos.x = currentPos.x*(1-lerpFactor)+objPos.x*lerpFactor;
    getTransform()->setPosition(currentPos);
}


gme::Vector2 CameraFollowPlayer::getObjPos() {
    gme::Vector2 screenSize = gme::Game::getWindow()->getSize();
    
    gme::Vector2 gotoPos = player->getTransform()->position;
    gotoPos.x -= screenSize.x/2.f;
    gotoPos.y -= screenSize.y/2.f;
    
    if(gotoPos.x < limitX.x) gotoPos.x = limitX.x;
    else if(gotoPos.x > limitX.y) gotoPos.x = limitX.y;
    
    if(gotoPos.y < limitY.x) gotoPos.y = limitY.x;
    else if(gotoPos.y > limitY.y) gotoPos.y = limitY.y;
    return gotoPos;
}


CameraFollowPlayer::~CameraFollowPlayer() {
    
}




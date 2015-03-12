/* 
 * File:   CameraFollowPlayer.cpp
 * Author: pablopernias
 * 
 * Created on 9 de marzo de 2015, 23:57
 */

#include "CameraFollowPlayer.hpp"

void CameraFollowPlayer::setup() {
    player2 = NULL;
    std::vector<gme::GameObject*> found = gme::GameObject::findWithTag("player");
    player = found.front();
    if(found.size() > 1){
        player2 = found.back();
    }
    std::cout << "Camera following player: " << player->getName() << std::endl;
    currentPos = getObjPos();
}

void CameraFollowPlayer::update() {
    objPos = getObjPos();
    float lerpFactor = 0.2;
    currentPos.x = currentPos.x*(1-lerpFactor)+objPos.x*lerpFactor;
    currentPos.y = currentPos.y*(1-lerpFactor)+objPos.y*lerpFactor;
    getTransform()->setPosition(currentPos);
}


gme::Vector2 CameraFollowPlayer::getObjPos() {
    gme::Vector2 screenSize = gme::Game::getWindow()->getSize();
    
    gme::Vector2 gotoPos(0,0);
    if(player2 == NULL)
        gotoPos = player->getTransform()->position;
    else{
        gotoPos = gme::Vector2(player->getTransform()->position.x+player2->getTransform()->position.x,
                               player->getTransform()->position.y+player2->getTransform()->position.y);
        
        gotoPos.x /= 2.f;
        gotoPos.y /= 2.f;
    }
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




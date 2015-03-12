#ifndef CAMERAFOLLOWPLAYER_HPP
#define	CAMERAFOLLOWPLAYER_HPP

#include "../engine/GMEngine.hpp"

class CameraFollowPlayer : public gme::Script{
public:
    CameraFollowPlayer(): gme::Script(){};
    void setup();
    void update();
    virtual ~CameraFollowPlayer();
    gme::Vector2 limitX, limitY;   
private:
    gme::GameObject *player;
    gme::GameObject *player2;
    gme::Vector2 currentPos;
    gme::Vector2 objPos;
    gme::Vector2 getObjPos();
};

#endif	/* CAMERAFOLLOWPLAYER_HPP */


#ifndef GAMEMANAGER_HPP
#define	GAMEMANAGER_HPP

#include "../engine/GMEngine.hpp"
#include "Animator.hpp"

class GameManager : public gme::GameObject{
public:
    GameManager(std::string n) : gme::GameObject(n){};
    virtual void setup();
    Animator anim;
private:

};

#endif	/* GAMEMANAGER_HPP */


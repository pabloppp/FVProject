#ifndef IAGIRL_HPP
#define	IAGIRL_HPP

#include "../engine/GMEngine.hpp"
#include "GlobalStateManager.hpp"

class IAGirl  : public gme::Script {
public:
    IAGirl() : gme::Script(){
        estado = 0;
        player = NULL;
        flipped = disparando = false;
        damage = 0;
        disparos = 0;
        cargando = false;
    };
    void setup();
    void update();
    void animate();
    virtual void onMessage(std::string m, float v);
    virtual void onCollision(gme::Collider* c);
    virtual ~IAGirl();
private:
    GlobalStateManager *manager;
    int estado;
    gme::Clock movementClock;
    gme::Clock stateClock;
    gme::Clock shootClock;
    gme::Vector2 objectivePosition;
    void getPlayer();
    void shoot();
    void teleport();
    gme::GameObject *player;
    bool flipped, disparando, cargando;
    int damage, disparos;
    //0:random,  1: intenta golpear, 2: intenta disparar, 3: teletransporta
};

#endif	/* IAGIRL_HPP */


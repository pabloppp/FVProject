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
        maxLife = 500;
        life = maxLife;
        
    };
    void setup();
    void update();
    void animate();
    virtual void onMessage(std::string m, float v);
    virtual void onCollision(gme::Collider* c);

    virtual void onGui();

    virtual ~IAGirl();
private:
    GlobalStateManager *manager;
    int estado;
    gme::Clock movementClock;
    gme::Clock stateClock;
    gme::Clock shootClock;
    gme::Vector2 objectivePosition;
    void getPlayer();
    void shoot(int dir);
    void explode(int min, int max, float forcemin, float forcemax);
    void teleport();
    gme::GameObject *player;
    bool flipped, disparando, cargando;
    int damage, disparos;
    int life;
    int maxLife;
    
    gme::SoundPlayer *laserShot_sound;
    gme::SoundPlayer *laserCarga_sound;
    gme::SoundPlayer *jetpack_sound;
    gme::SoundPlayer *teletransport_sound;
    //0:random,  1: intenta golpear, 2: intenta disparar, 3: teletransporta
};

#endif	/* IAGIRL_HPP */


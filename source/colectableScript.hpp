#ifndef COLECTABLESCRIPT_HPP
#define	COLECTABLESCRIPT_HPP

#include "../engine/GMEngine.hpp"


class ColectableScript : public gme::Script {
public:
    ColectableScript(int i) : gme::Script(){
        objectType=i;
    };
    virtual ~ColectableScript();
    void setup();
    void update();
    virtual void onCollision(gme::Collider* c);
    virtual void onGui();
    void animate();
    void explode(int min, int max, float forcemin, float forcemax);
    int hp;

private:
    gme::Clock clkD;
    gme::Clock animClock;
    int walkFrameCountFD;
    int walkFrameCountPD;
    int walkFrameCountL;
    int walkFPS; 
    int objectType;
    bool grounded;
    bool destroyed;
    bool isHit;
    virtual void onMessage(std::string m, float v);
    
    gme::SoundPlayer *pistolaFrase_sound;
    gme::SoundPlayer *metralletaFrase_sound;
    gme::SoundPlayer *lanzallamasFrase_sound;
    gme::SoundPlayer *escopetaFrase_sound;
    gme::SoundPlayer *nuevaVidaFrase_sound;
    gme::SoundPlayer *HPFrase_sound;
    
    gme::SoundPlayer *cajaRota_sound;
    
    
    
    
};

#endif	/* COLECTABLESCRIPT_HPP */


#ifndef TILEDESTROYMANAGER_HPP
#define	TILEDESTROYMANAGER_HPP

#include "../engine/GMEngine.hpp"

class tileDestroyManager : public gme::Script{
public:
    tileDestroyManager() : gme::Script(){
        hp = 20;
    }
    virtual void setup();
    virtual void update();
    virtual void onMessage(std::string m, float v);
    virtual ~tileDestroyManager();
    
    int hp;


private:
    bool isHit;
    bool isHitTemp;
    gme::Clock hitclock;
    
    void explode(int min, int max, float forcemin, float forcemax);

};

#endif	/* TILEDESTROYMANAGER_HPP */


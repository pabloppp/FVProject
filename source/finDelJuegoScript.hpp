#ifndef FINDELJUEGOSCRIPT_HPP
#define	FINDELJUEGOSCRIPT_HPP

#include "../engine/GMEngine.hpp"

class finDelJuegoScript : public gme::Script {
public:
    finDelJuegoScript()  : gme::Script(){};
    void setup();
    void update();
    virtual void onGui();
    virtual ~finDelJuegoScript();
private:
    gme::Clock reloj;
    bool salir;
    float delays;
    int kills, brokentiles, victories, levelspassed, deaths;

};

#endif	/* FINDELJUEGOSCRIPT_HPP */


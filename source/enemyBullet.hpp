#ifndef ENEMYBULLET_HPP
#define	ENEMYBULLET_HPP

#include "../engine/GMEngine.hpp"

class enemyBullet : public gme::Script  {
public:
    enemyBullet() : gme::Script(){};
    void setup();
    void update();

    virtual void onCollision(gme::Collider* c);

    virtual ~enemyBullet();
private:

};

#endif	/* ENEMYBULLET_HPP */


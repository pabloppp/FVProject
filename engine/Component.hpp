#ifndef COMPONENT_HPP
#define	COMPONENT_HPP

#include <iostream>

namespace gme{
    
class GameObject;    
    
class Component {
public:
    Component();
    Component(const Component& orig);
    virtual ~Component();
    virtual void update() = 0;
    virtual void setup() = 0;
    void setActive(bool b);
    bool isActive();
    GameObject *gameObject();
    void setGameObject(GameObject *g);
private:
    GameObject *owner;
    bool active;
};

}

#endif	/* COMPONENT_H */


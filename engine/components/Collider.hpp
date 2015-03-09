#ifndef COLLIDER_HPP
#define	COLLIDER_HPP

#include "../Component.hpp"
#include "../facade/Vector2.hpp"
#include <unordered_map>
#include <Box2D/Box2D.h>

namespace gme{
    
class Collider : public Component{
public:
    void inheritRotation(bool b);
    void addFilterTag(const std::string &tag);
    void removeFilterTag(const std::string &tag);
    virtual void render() = 0;
    Vector2 getGlobalCenter();
    void noticeCollision(Collider *col);
    bool checkTags(Collider *col);
    Vector2 getRelativePosition(Collider * col);
    void isTrigger(bool b);
    bool checked;
private:
    
protected:
    bool canRotate;
    bool colliding;
    sf::Color debugColor;
    std::unordered_map<std::string, std::string> tagmap;
    float ownerRot;
    Vector2 ownerRotDisp;
    b2FixtureDef fixtureDef;   
    
};

}

#endif	/* COLLIDER_H */


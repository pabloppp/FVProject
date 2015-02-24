#ifndef COLLIDER_HPP
#define	COLLIDER_HPP

#include "../Component.hpp"
#include "../facade/Vector2.hpp"

namespace gme{
    
class Collider : public Component{
public:
    virtual void checkCollision(Collider *col) = 0;
    void inheritRotation(bool b);
    void addFilterTag(const std::string &tag);
    void removeFilterTag(const std::string &tag);
    virtual void render() = 0;
    Vector2 getGlobalCenter();
    Vector2 center;
    void noticeCollision(Collider *col);
    bool checkTags(Collider *col);
private:

protected:
    bool canRotate;
    bool colliding;
    sf::Color debugColor;
    std::vector<std::string> tags;
    
};

}

#endif	/* COLLIDER_H */


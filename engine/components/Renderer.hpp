#ifndef RENDERER_HPP
#define	RENDERER_HPP

#include "../Component.hpp"
#include "../facade/Texture.hpp"
#include "../facade/Vector2.hpp"
#include "SFML/Graphics.hpp"

namespace gme{
    
//class Game;    
    
class Renderer : public Component{
public:    
    void setup();
    void update();
    void setTexture(Texture &t);
    void setTexture(const std::string &s);
    void setSize(Vector2 f);
    void setFrame(Vector2 f);
    void setCenter(Vector2 f);
    void setColor(int r, int g, int b, int a = 255);
    int getColorR();
    int getColorG();
    int getColorB();
    int getColorA();
private:
    Vector2 size;
    Vector2 center;
    Vector2 position;
    sf::Drawable *drawable;

};

}

#endif	/* RENDERER_HPP */


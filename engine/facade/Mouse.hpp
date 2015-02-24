#ifndef MOUSE_HPP
#define	MOUSE_HPP

#include "Vector2.hpp"
#include "Window.hpp"

#define LEFT 0
#define RIGHT 1

namespace gme{
    
class Mouse {
public:
    static Vector2 getPosition(Window);
    static Vector2 getPosition();
    static Vector2 worldPosition(Vector2 p);
    static bool isButtonPressed(int i);
private:

};

}


#endif	/* MOUSE_HPP */


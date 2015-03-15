#ifndef WINDOW_HPP
#define	WINDOW_HPP

#include <SFML/Graphics.hpp>

#include "Vector2.hpp"

namespace gme{
    
class Window{
public:
    Window(int px, int py, std::string s);
    virtual ~Window();
    void draw(sf::Drawable &d);
    bool isOpen();
    void clear();
    void display();
    void close();
    void setVerticalSyncEnabled(bool b);
    void setFrameLimit(int l);
    bool pollEvent(sf::Event &e);
    void setView(const sf::View &v);
    const sf::View &getDefaultView();
    gme::Vector2 getSize();
    gme::Vector2 getOriginalSize();
    sf::RenderWindow *getRWindow();
    void enableFullScreen(bool b);
private:
    sf::RenderWindow *rwindow;
    gme::Vector2 originalSize;
    std::string title;
};

}

#endif	/* WINDOW_HPP */


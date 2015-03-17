#include "Window.hpp"
#include <iostream>

using namespace gme;

Window::Window(int px, int py, std::string s){
    rwindow = new sf::RenderWindow(sf::VideoMode(px, py), s, sf::Style::Close);
    originalSize = Vector2(px, py); 
    title = s;
}

Window::~Window(){
    delete rwindow; 
}

void Window::draw(sf::Drawable &d){
    rwindow->draw(d);
}

bool Window::isOpen(){
    return rwindow->isOpen();
}

void Window::clear(){
    rwindow->clear();
}

void Window::display(){
    rwindow->display();
}

void Window::close(){
    rwindow->close();
}

bool Window::pollEvent(sf::Event &e){
    return rwindow->pollEvent(e);
}

void Window::setVerticalSyncEnabled(bool b){
    rwindow->setVerticalSyncEnabled(b);
}

void Window::setView(const sf::View &v){
    rwindow->setView(v);
}

const sf::View &Window::getDefaultView() {
    return rwindow->getDefaultView();
}


gme::Vector2 Window::getSize(){
    //return rwindow->getSize();
    return gme::Vector2(rwindow->getSize().x, rwindow->getSize().y);
}

gme::Vector2 Window::getOriginalSize() {
    return originalSize;
}


sf::RenderWindow *Window::getRWindow(){
    return rwindow;
}

void Window::setFrameLimit(int l) {
    rwindow->setFramerateLimit(l);
}

void Window::enableFullScreen(bool b) {
    delete rwindow;
    if(b) 
        rwindow = new sf::RenderWindow(sf::VideoMode(getOriginalSize().x, getOriginalSize().y), title, sf::Style::Fullscreen);
    else
        rwindow = new sf::RenderWindow(sf::VideoMode(getOriginalSize().x, getOriginalSize().y), title, sf::Style::Close);

}



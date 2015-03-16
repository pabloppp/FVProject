#include "GUI.hpp"
#include "facade/Window.hpp"
#include "Game.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace gme;

void GUI::loadFont(const std::string path) {
    if (!font.loadFromFile(path)){
        std::cout << "error loading font from: " << path << std::endl;
        return;
    }
}


void GUI::box(Vector2 position, Vector2 size, const std::string& text, Origin origin, Texture *texture) {
    Window *window = Game::getWindow();
    if(window == NULL) return;
    sf::RectangleShape rshape;
    
    float px = position.x;
    float py = position.y;
    
    if(origin == Origin::BottomCenter || origin == Origin::TopCenter || origin == Origin::Center){
        px = position.x - size.x/2.f;   
    }
    else if(origin == Origin::BottomRight || origin == Origin::TopRight || origin == Origin::CenterRight){
        px = position.x - size.x;   
    }
    
    if(origin == Origin::CenterLeft || origin == Origin::CenterRight || origin == Origin::Center){
        py = position.y - size.y/2.f;   
    }
    else if(origin == Origin::BottomLeft || origin == Origin::BottomRight || origin == Origin::BottomCenter){
        py = position.y - size.y;   
    }
    
    rshape.setPosition(px+outlineThickness, py+outlineThickness);
    rshape.setSize(sf::Vector2f(size.x-outlineThickness*2.f, size.y-outlineThickness*2.f));
    rshape.setFillColor(sf::Color(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a));
    rshape.setOutlineThickness(outlineThickness);
    rshape.setOutlineColor(sf::Color(outlineColor.r, outlineColor.g, outlineColor.b, outlineColor.a));
    if(texture != NULL){
        rshape.setFillColor(sf::Color(tintColor.r, tintColor.g, tintColor.b, tintColor.a));
        sf::Texture &t = texture->getTexture();
        rshape.setTexture(&t);
        rshape.setTextureRect(sf::IntRect(0, 0, t.getSize().x, t.getSize().y));
    }
    window->draw(rshape);
    if(text.length() > 0){
        GUI::label(Vector2(px + size.x/2.f, px + size.y/2.f), text, Origin::Center);
    }
}

void GUI::box(Vector2 position, Vector2 size, Origin origin, Texture* texture){
    GUI::box(position, size, "", origin, texture); 
}


void GUI::box(Vector2 position, Vector2 size, const std::string& text, Origin origin, TextureName w){
    Texture *tex = Game::getTexture(w.path);
    if(tex == NULL) return;
    GUI::box(position, size, text, origin, tex); 
    
}

void GUI::box(Vector2 position, Vector2 size, Origin origin, TextureName w) {
    GUI::box(position, size, "", origin, w);
}

void GUI::box(Vector2 position, Vector2 size, const std::string& text, TextureName w){
     GUI::box(position, size, text, Origin::TopLeft, w);
}

void GUI::box(Vector2 position, Vector2 size, TextureName w) {
    GUI::box(position, size, "", Origin::TopLeft, w);
    
}

void GUI::label(Vector2 position, const std::string& txt, Origin origin) {
    Window *window = Game::getWindow();
    if(window == NULL) return;
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(fontSize);
    text.setString(txt);
    text.setColor(sf::Color(contentColor.r, contentColor.g, contentColor.b, contentColor.a));
    
    float space = fontSize-text.getLocalBounds().height;
    
    float px = position.x;
    float py = position.y;
    
    if(origin == Origin::BottomCenter || origin == Origin::TopCenter || origin == Origin::Center){
        px = position.x - text.getLocalBounds().width/2.f;   
    }
    else if(origin == Origin::BottomRight || origin == Origin::TopRight || origin == Origin::CenterRight){
        px = position.x - text.getLocalBounds().width;   
    }
    
    if(origin == Origin::CenterLeft || origin == Origin::CenterRight || origin == Origin::Center){
        py = position.y - text.getLocalBounds().height/2.f;   
    }
    else if(origin == Origin::BottomLeft || origin == Origin::BottomRight || origin == Origin::BottomCenter){
        py = position.y - text.getLocalBounds().height;   
    }
    
    text.setPosition(int(px), int(py-space));
    window->draw(text);
}

void GUI::drawTexture(Vector2 position, Vector2 size, Texture* texture, Origin origin, ScaleMode mode) {
    Window *window = Game::getWindow();
    if(window == NULL) return;
    sf::RectangleShape rshape;
    
    float px = position.x;
    float py = position.y;
    
    if(origin == Origin::BottomCenter || origin == Origin::TopCenter || origin == Origin::Center){
        px = position.x - size.x/2.f;   
    }
    else if(origin == Origin::BottomRight || origin == Origin::TopRight || origin == Origin::CenterRight){
        px = position.x - size.x;   
    }
    
    if(origin == Origin::CenterLeft || origin == Origin::CenterRight || origin == Origin::Center){
        py = position.y - size.y/2.f;   
    }
    else if(origin == Origin::BottomLeft || origin == Origin::BottomRight || origin == Origin::BottomCenter){
        py = position.y - size.y;   
    }
    
    rshape.setPosition(px, py);
    rshape.setSize(sf::Vector2f(size.x, size.y));
    rshape.setOutlineThickness(0);
    rshape.setFillColor(sf::Color(tintColor.r, tintColor.g, tintColor.b, tintColor.a));
    sf::Texture &t = texture->getTexture();
    rshape.setTexture(&t);
    if(mode == ScaleMode::StretchToFill)
        rshape.setTextureRect(sf::IntRect(0, 0, t.getSize().x, t.getSize().y));
    else if(mode == ScaleMode::ScaleToFit){
        float ratio = 1.0f*t.getSize().x/t.getSize().y;
        float ratioB = 1.0f*size.x/size.y;
        rshape.setTextureRect(sf::IntRect(0, 0, t.getSize().x, t.getSize().y));
        if(ratio < ratioB){
            rshape.setSize(sf::Vector2f(size.y*ratio, size.y));
            rshape.setPosition(sf::Vector2f(px + size.x/2.f - (size.y*ratio)/2.f, py));
        }
        else{
            rshape.setSize(sf::Vector2f(size.x, size.x/ratio));
            rshape.setPosition(sf::Vector2f(px, py + size.y/2.f - (size.x/ratio)/2.f));
        }
    } 
    else if(mode == ScaleMode::ScaleAndCrop){
        float ratio = 1.0f*t.getSize().x/t.getSize().y;
        if(size.x > size.y) rshape.setTextureRect(sf::IntRect(0, 0, t.getSize().x, t.getSize().y*(size.y/size.x)));
        else rshape.setTextureRect(sf::IntRect(0, 0, t.getSize().x*(size.x/size.y), t.getSize().y));
    }
        
    
    window->draw(rshape);
}


void GUI::drawTexture(Vector2 position, Vector2 size, TextureName w, Origin origin, ScaleMode mode) {
    Texture *tex = Game::getTexture(w.path);
    if(tex == NULL) return;
    drawTexture(position, size, tex, origin, mode);
}

void GUI::drawTexture(Vector2 position, TextureName w, Origin origin) {
    Texture *tex = Game::getTexture(w.path);
    if(tex == NULL) return;
    drawTexture(position, Vector2(tex->getTexture().getSize().x, tex->getTexture().getSize().y), tex, origin, ScaleMode::StretchToFill);
}





GUI::Color GUI::backgroundColor = GUI::Color(255,255,255);

GUI::Color GUI::tintColor = GUI::Color(255,255,255);

GUI::Color GUI::outlineColor = GUI::Color(0,0,0);

GUI::Color GUI::contentColor = GUI::Color(0,0,0);

GUI::Color GUI::red = GUI::Color(255,0,0);
GUI::Color GUI::green = GUI::Color(0,255,0);
GUI::Color GUI::blue = GUI::Color(0,0,255);
GUI::Color GUI::white = GUI::Color(255,255,255);
GUI::Color GUI::transparent = GUI::Color();

sf::Font GUI::font;

bool GUI::enabled = true;

int GUI::fontSize = 24;

float GUI::outlineThickness = 0;
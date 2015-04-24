#include "Renderer.hpp"

#include "../Game.hpp"
#include "../facade/Vector2.hpp"
#include "BoxCollider.hpp"
#include <sys/stat.h>

using namespace gme;

Renderer::Renderer() : Component() {
    center.x = 0.5;
    center.y = 0.5;
    pivot.x = center.x;
    pivot.y = center.y;
    drawable = NULL;
}

void Renderer::setup() {
    //drawable = NULL;
    //std::cout << "renderer setup" << std::endl;
}

void Renderer::update() {
    gme::Vector2 f_pos = Vector2(0.f,0.f);
    gme::Vector2 i_pos = Vector2(0.f,0.f);
    gme::Vector2 pos = Vector2(0.f,0.f);
    gme::Vector2 scl = Vector2(1,1);
    float rot = 0;
    float ticPercent = Game::ticPercent;
    float invTicPercent = 1-ticPercent;
    if(gameObject() != NULL && gameObject()->getTransform() != NULL){
        f_pos = gameObject()->getTransform()->getPosition();
        i_pos = gameObject()->getTransform()->o_position;
        
        float dx = f_pos.x-i_pos.x;
        float dy = f_pos.y-i_pos.y;
        
        if((dx*dx + dy*dy) < 320*320){
            pos.x = (invTicPercent*i_pos.x) + (ticPercent*f_pos.x);
            pos.y = (invTicPercent*i_pos.y) + (ticPercent*f_pos.y);
        }
        else{
            pos = f_pos;
        }

        //std::cout << f_pos.x << std::endl;
        
        rot = gameObject()->getTransform()->getRotation();
        scl = gameObject()->getTransform()->getScale();
    }
    if(drawable != NULL){
        if(dynamic_cast<sf::Sprite*>(drawable)){
         
            ((sf::Sprite*)drawable)->setPosition(pos.x, pos.y);
            ((sf::Sprite*)drawable)->setRotation(rot);
            ((sf::Sprite*)drawable)->setScale(scl.x, scl.y);
            ((sf::Sprite*)drawable)->setTextureRect(sf::IntRect(position.x, position.y, size.x, size.y));
            ((sf::Sprite*)drawable)->setOrigin(center.x*size.x,center.y*size.y);
        }
        Game::getWindow()->draw(*drawable);
        //std::cout << Game::getWindow()->getSize().x << std::endl;
    }
    
    if(Game::debugColliders && gameObject() != NULL && gameObject()->getCollider() != NULL){
        gameObject()->getCollider()->render();
    }
}

void Renderer::setTexture(Texture &t){
    atlas = NULL;
    if(t.atlas != NULL) atlas = t.atlas;
    drawable = new sf::Sprite(t.getTexture());
    if(size.x == 0 || size.y == 0){
        size.x = ((sf::Sprite*)drawable)->getTexture()->getSize().x;
        size.y = ((sf::Sprite*)drawable)->getTexture()->getSize().y;
        center.x = 0.5;
        center.y = 0.5;
        pivot.x = center.x;
        pivot.y = center.y;
    }
    
}

void Renderer::setTexture(const std::string& s){
    Texture *t = Game::getTexture(s);
    if(t != NULL){
        setTexture(*t);
        
        int lastindex = t->getPath().find_last_of("."); 
        std::string jsonFileName = t->getPath().substr(0, lastindex)+".json";
        
        if(FILE *file = fopen(jsonFileName.c_str(), "r")){
            fclose(file);
        
            if(t->atlas == NULL){
                atlas = json_object_new_object();


                struct stat   buffer;
                if(stat (jsonFileName.c_str(), &buffer) != 0) return;

                atlas = json_object_from_file(jsonFileName.c_str());  
                if(atlas){
                    std::cout << "Loaded atlas for "+s << std::endl;
                }
                else atlas = NULL;
                t->atlas = atlas;
            }
            
        }
        else{
            atlas = NULL;
        }
        
    }
    
    
}

void Renderer::setSize(gme::Vector2 f){
    size = f;
}

void Renderer::setFrame(gme::Vector2 f){
    position = Vector2(f.x*size.x, f.y*size.y);
}

void Renderer::setFrame(const std::string& framename){
    if(atlas != NULL){
        
        json_object *frames = json_object_object_get(atlas, "frames");
        json_object *frameinfo = json_object_object_get(frames, framename.c_str());
        json_object *framedims = json_object_object_get(frameinfo, "frame");
        if(framedims){
            int px = json_object_get_int(json_object_object_get(framedims, "x"));
            int py = json_object_get_int(json_object_object_get(framedims, "y"));
            int sx = json_object_get_int(json_object_object_get(framedims, "w"));
            int sy = json_object_get_int(json_object_object_get(framedims, "h"));
            if(size.x != sx || size.y != sy){
                size = Vector2(sx, sy);
            }
            position = Vector2(px, py);
            
            //std::cout << "size: " << sx << " " << sy << std::endl; 
            //std::cout << "position: " << px << " " << py << std::endl; 
        }
        else{
           std::cout << "frame "+framename+" does not exist..."<< std::endl; 
        }
    }
}


void Renderer::setCenter(gme::Vector2 f){
    center = f;
    if(center.x > 1) center.x = 1;
    else if (center.x < 0) center.y = 0;
    if(center.y > 1) center.y = 1;
    else if (center.y < 0) center.y = 0;
}

void Renderer::setPivot(Vector2 f) {
    pivot = f;
    if(pivot.x > 1) pivot.x = 1;
    else if (pivot.x < 0) pivot.y = 0;
    if(pivot.y > 1) pivot.y = 1;
    else if (pivot.y < 0) pivot.y = 0;
    setCenter(f);
    calculateDisplacement();
}

Vector2 Renderer::getDisplacement() {
    calculateDisplacement();
    return displacement;
}


void Renderer::calculateDisplacement() {
    Vector2 disp(0,0);
    if(pivot.x == center.x && pivot.y == center.y){
        disp.x = (0.5f-pivot.x);
        disp.y = (0.5f-pivot.y);
    }
    displacement = disp;
    
}



void Renderer::setColor(int r, int g, int b, int a) {
    if(dynamic_cast<sf::Sprite*>(drawable)){
        return ((sf::Sprite*)drawable)->setColor(sf::Color(r,g,b,a));
    }
}

int Renderer::getColorR() {
    if(dynamic_cast<sf::Sprite*>(drawable)){
        return ((sf::Sprite*)drawable)->getColor().r;
    }
    return -1;
}

int Renderer::getColorG() {
    if(dynamic_cast<sf::Sprite*>(drawable)){
        return ((sf::Sprite*)drawable)->getColor().g;
    }
    return -1;
}

int Renderer::getColorB() {
    if(dynamic_cast<sf::Sprite*>(drawable)){
        return ((sf::Sprite*)drawable)->getColor().b;
    }
    return -1;
}

int Renderer::getColorA() {
    if(dynamic_cast<sf::Sprite*>(drawable)){
        return ((sf::Sprite*)drawable)->getColor().a;
    }
    return -1;
}

Renderer::~Renderer() {
    delete drawable;
    drawable = NULL;
}


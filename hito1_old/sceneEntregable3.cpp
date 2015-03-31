#include "sceneEntregable3.hpp"
#include "pruebaGameObject.hpp"
#include "limit.hpp"
#include "tile.hpp"

#include <SFML/Graphics.hpp>

void sceneEntregable3::setup(){
    
    
    setupLimits();
    
    setupTileMap();
    
    gme::GameObject *player = new pruebaGameObject("prueba");
    player->getTransform()->setPosition(gme::Vector2(320, 240));
    
    
}


void sceneEntregable3::setupLimits() {
    gme::Vector2 windowSize = gme::Game::getWindow()->getSize();
    
    limit *lup = new limit("limit_up");
    lup->width = windowSize.x*2;
    lup->height = 1;
    lup->position = gme::Vector2(windowSize.x, 1);
    
    limit *ldown = new limit("limit_down");
    ldown->width = windowSize.x*2;
    ldown->height = 1;
    ldown->position = gme::Vector2(windowSize.x, windowSize.y-1);
    
    limit *lleft = new limit("limit_left");
    lleft->width = 1;
    lleft->height = windowSize.y;
    lleft->position = gme::Vector2(1, windowSize.y/2);
    
    limit *lright = new limit("limit_right");
    lright->width = 1;
    lright->height = windowSize.y;
    lright->position = gme::Vector2(2*windowSize.x-1, windowSize.y/2);
}

void sceneEntregable3::setupTileMap() {
    gme::Vector2 windowSize = gme::Game::getWindow()->getSize();
    
    int maxFloorTiles = ceil(2*windowSize.x/(16*3));
    //templeTexture
    for(int i=0;i<maxFloorTiles;i++){
        int randomizer = rand()%4;
        tile *t = new tile("ruina");
        t->addTag("floor");
        t->texture = "templeTexture";
        t->size = gme::Vector2(16,16);
        t->frame = gme::Vector2(6+randomizer,0);
        t->getTransform()->setPosition(gme::Vector2((i)*16*3+8*3,windowSize.y-8*3));
    }
}

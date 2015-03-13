#include "sceneEntregable5.hpp"
#include "tile.hpp"
#include "animationTest.hpp"
#include "introManager.hpp"

void sceneEntregable5::setup() {
    gme::Vector2 windowSize = gme::Game::getWindow()->getSize();
    
    //setupTileMap();
    
    //SETUP ANIMATION
    introManager *introMng = new introManager("intro");
    introMng->getTransform()->setPosition(gme::Vector2(windowSize.x/2, windowSize.y/2));
}


void sceneEntregable5::setupTileMap() {
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


#include "sceneEntregable2.hpp"
#include "player.hpp"
#include "weapon.hpp"
#include "bullet.hpp"
#include "pruebaGameObject.hpp"
#include "tile.hpp"
#include <SFML/Graphics.hpp>

void sceneEntregable2::setup(){
    gme::Vector2 windowSize = gme::Game::getWindow()->getSize();
    
    setupTileMap();
    
    //WEAPON por delante del player
    weapon *weapon1 = new weapon("weapon_1");
    //bullet *bullet1 = new bullet("bullet_1");
    //ADD PLAYER
    player *player1 = new player("player_1");
    player1->getTransform()->setPosition(gme::Vector2(windowSize.x/2, windowSize.y/2));
    
    weapon1->setParent(player1);
}

void sceneEntregable2::setupTileMap() {
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

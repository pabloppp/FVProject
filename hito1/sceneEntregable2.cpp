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
    
    weapon *weapon2 = new weapon("weapon_2");
    //ADD SECOND PLAYER
    player *player2 = new player("player_2");
    player2->getTransform()->setPosition(gme::Vector2(windowSize.x/2, windowSize.y/2));
    player2->overrideKeys = true;
    player2->downKey = gme::Keyboard::Down;
    player2->upKey = gme::Keyboard::Up;
    player2->leftKey = gme::Keyboard::Left;
    player2->rightKey = gme::Keyboard::Right;
    player2->weaponKey = gme::Keyboard::L;
    player2->jumpKey = gme::Keyboard::Comma;
    
    
    weapon2 ->setParent(player2);
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

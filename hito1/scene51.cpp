#include "scene51.hpp"
#include "limit.hpp"
#include "player.hpp"
#include "CameraFollowPlayer.hpp"
#include "PlayerMovement.hpp"
#include "tile.hpp"

void scene51::setup() {
    gme::Vector2 windowSize = gme::Game::getWindow()->getSize();
    
    setupLimits();
    
    setupTileMap();
    
    //ADD PLAYER
    player *player1 = new player("player_1");
    player1->getTransform()->setPosition(gme::Vector2(windowSize.x/2, windowSize.y/2));
    
    /* DESCOMENTAR PARA AÑADIR 2º JUGADOR
    player *player2 = new player("player_2");
    player2->getTransform()->setPosition(gme::Vector2(windowSize.x/2, windowSize.y/2));
    player2->overrideKeys = true;
    player2->upKey = gme::Keyboard::Up;
    player2->downKey = gme::Keyboard::Down;
    player2->leftKey = gme::Keyboard::Left;
    player2->rightKey = gme::Keyboard::Right;
    player2->jumpKey = gme::Keyboard::Space;
    player2->weaponKey = gme::Keyboard::RSystem;
    player2->actionKey = gme::Keyboard::RAlt;*/
     
    
    //SETUP CAMERA
    CameraFollowPlayer *cameraFollow = new CameraFollowPlayer;
    cameraFollow->limitX = gme::Vector2(0, windowSize.x);
    cameraFollow->limitY = gme::Vector2(-windowSize.y, 0);
    gme::Game::mainCamera->addComponent(cameraFollow);
    
}

void scene51::setupLimits() {
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

void scene51::setupTileMap() {
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





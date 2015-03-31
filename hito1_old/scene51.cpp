#include "scene51.hpp"
#include "limit.hpp"
#include "player.hpp"
#include "CameraFollowPlayer.hpp"
#include "PlayerMovement.hpp"
#include "tile.hpp"
#include "backgroundLayer.hpp"
#include "tileMapGenerator.hpp"
#include "genericEnemy.hpp"


void scene51::setup() {
    
    gme::Vector2 windowSize = gme::Game::getWindow()->getSize();

    
    setupBg();
    
    setupLimits();
    
    //setupTileMap();
    tileMapGenerator *mapGen = new tileMapGenerator("mapGenerator");
    mapGen->mainMapFile = "hito1/recursos/maptest1.csv";
    mapGen->mainTexture = "templeTexture";
    mapGen->tileColumns = 27;
    mapGen->origin = gme::Vector2(0,-windowSize.y);
    //ADD PLAYER
    player *player1 = new player("player1");
    player1->getTransform()->setPosition(gme::Vector2(windowSize.x/2, windowSize.y/2));
    
    
    /*player *player2 = new player("player2");
    player2->getTransform()->setPosition(gme::Vector2(windowSize.x/2+50, windowSize.y/2));
    player2->overrideKeys = true;
    player2->upKey = gme::Keyboard::Up;
    player2->downKey = gme::Keyboard::Down;
    player2->leftKey = gme::Keyboard::Left;
    player2->rightKey = gme::Keyboard::Right;
    player2->jumpKey = gme::Keyboard::Space;
    player2->weaponKey = gme::Keyboard::RSystem;
    player2->actionKey = gme::Keyboard::RAlt;*/
    
    genericEnemy *enemy = new genericEnemy("enemy1");
    enemy->getTransform()->setPosition(gme::Vector2(windowSize.x, windowSize.y/2));
    
    
    
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
    lup->position = gme::Vector2(windowSize.x, 1-windowSize.y);
    
    limit *ldown = new limit("limit_down");
    ldown->width = windowSize.x*2;
    ldown->height = 1;
    ldown->position = gme::Vector2(windowSize.x, windowSize.y-1);
    
    limit *lleft = new limit("limit_left");
    lleft->width = 1;
    lleft->height = windowSize.y*2;
    lleft->position = gme::Vector2(1, 0);
    
    limit *lright = new limit("limit_right");
    lright->width = 1;
    lright->height = windowSize.y*2;
    lright->position = gme::Vector2(2*windowSize.x-1, 0);
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

void scene51::setupBg() {
    srand (time(NULL));
    gme::Vector2 windowSize = gme::Game::getWindow()->getSize();
    
    float yDisp = 50.f;
    
    //SKY
    float bgWidth = gme::Game::getTexture("skyTexture")->getTexture().getSize().x;
    int howMany = windowSize.x/bgWidth;
    std::cout << bgWidth << " " << howMany << std::endl;
    for(int i=0;i<howMany;i++){
        backgroundLayer *bgSkyLayer = new backgroundLayer("BGSky");
        bgSkyLayer->texture = "skyTexture";
        bgSkyLayer->parallaxFactor = 1; //fixed
        bgSkyLayer->getTransform()->position = gme::Vector2((i*bgWidth) + bgWidth/2, windowSize.y);
    }
    
    backgroundLayer *bgLayerMidA = new backgroundLayer("BGMidA");
    bgLayerMidA->texture = "bgMidATexture";
    bgLayerMidA->getTransform()->position = gme::Vector2(windowSize.x/2, windowSize.y+yDisp);
    bgLayerMidA->parallaxFactor = 0.7;
    
    backgroundLayer *bgLayerMidB = new backgroundLayer("BGMidB");
    bgLayerMidB->texture = "bgMidBTexture";
    bgLayerMidB->getTransform()->position = gme::Vector2(0, windowSize.y+yDisp);
    bgLayerMidB->parallaxFactor = 0.8;
    
    backgroundLayer *bgLayerMidC = new backgroundLayer("BGMidC");
    bgLayerMidC->texture = "bgMidCTexture";
    bgLayerMidC->getTransform()->position = gme::Vector2(windowSize.x, windowSize.y+yDisp);
    bgLayerMidC->parallaxFactor = 0.8;
    
    
    backgroundLayer *bgLayerA = new backgroundLayer("BGFrontA");
    bgLayerA->texture = "bgFrontATexture";
    bgLayerA->getTransform()->position = gme::Vector2(0, windowSize.y+yDisp);
    bgLayerA->parallaxFactor = 0.4;
    
    backgroundLayer *bgLayerB = new backgroundLayer("BGFrontB");
    bgLayerB->texture = "bgFrontBTexture";
    bgLayerB->getTransform()->position = gme::Vector2(rand() % (int)(windowSize.x/3.f)+windowSize.x/3.f, windowSize.y+yDisp);
    bgLayerB->parallaxFactor = 0.4;
    std::cout << bgLayerB->getTransform()->position.x << std::endl;
    
    backgroundLayer *bgLayerC = new backgroundLayer("BGFrontC");
    bgLayerC->texture = "bgFrontCTexture";
    bgLayerC->getTransform()->position = gme::Vector2(windowSize.x, windowSize.y+yDisp);
    bgLayerC->parallaxFactor = 0.4;
}







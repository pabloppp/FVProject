#include "tilerJsonLoadScene.hpp"
#include "emptyGameObject.hpp"
#include "mapGenerator.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "CameraFollowPlayer.hpp"
#include "backgroundLayer.hpp"
#include "generaPosicion.hpp"
#include "weapon.hpp"
#include "pistolaBehavior.hpp"
#include "metralletaBehavior.hpp"
#include "lnzllamasBehavior.hpp"
#include "escopetaBehavior.hpp"
#include "GameManager.hpp"
#include "limit.hpp"

void tilerJsonLoadScene::setup() {
    
    if(reseting){
        setupScenario();
        return;
    }
    
    GameManager *gm = new GameManager("manager");
    
    gme::Game::newTexture("resources/maps/Tileset.png", "selvaTiles");
    gme::Game::newTexture("resources/sprites/player_spr/player_sheet.png", "playerTexture");

    
    gme::Game::newTexture("resources/BGs/jungle_sky.png", "skyTexture");
    gme::Game::newTexture("resources/BGs/jungle_frontA.png", "bgFrontATexture");
    gme::Game::newTexture("resources/BGs/jungle_frontB.png", "bgFrontBTexture");
    gme::Game::newTexture("resources/BGs/jungle_frontC.png", "bgFrontCTexture");
    gme::Game::newTexture("resources/BGs/jungle_midA.png", "bgMidATexture");
    gme::Game::newTexture("resources/BGs/jungle_midB.png", "bgMidBTexture");
    gme::Game::newTexture("resources/BGs/jungle_midC.png", "bgMidCTexture");
    
    gme::Game::newTexture("resources/Weapons/soldier_gun.png", "gun");
    gme::Game::newTexture("resources/Bullets/Bullet2.png", "bullet");
    
    setupBg(); 
    
    weapon *arma = new weapon("weapon");
    arma->addComponent(new pistolaBehavior()); 
    
    
    player *p1 = new player("p1");
    p1->getTransform()->setPosition(gme::Vector2(16*3, 576-16*9));
    
    p1->addChild(arma);
    arma->getTransform()->setPosition(gme::Vector2(0,0));
    
    weapon *arma2 = new weapon("weapon");
    arma2->addComponent(new pistolaBehavior()); 
    
    player *p2 = new player("p2");
    p2->overrideKeys = true;
    p2->leftKey = gme::Keyboard::A;
    p2->rightKey = gme::Keyboard::D;
    p2->upKey = gme::Keyboard::W;
    p2->downKey = gme::Keyboard::S;
    p2->jumpKey = gme::Keyboard::F;
    p2->weaponKey = gme::Keyboard::G;
    p2->actionKey = gme::Keyboard::H;
    
    p2->getTransform()->setPosition(gme::Vector2(16*3*2, 576-16*9));
    
    p2->addChild(arma2);
    arma2->getTransform()->setPosition(gme::Vector2(0,0));
    

    
    /*enemy *e = new enemy("dino");
    e->getTransform()->setPosition(gme::Vector2(150, 50));
    enemy *e2 = new enemy("dino");
    e2->getTransform()->setPosition(gme::Vector2(250, 50));*/
    
    /*for(int i=0;i<10;i++){
        enemy *e = new enemy("dino");
        e->getTransform()->setPosition(gme::Vector2(rand() % 1584, 0));
    }*/
    
    limit *lu = new limit("limit_up");
    lu->width = 1584;
    lu->height = 3;
    lu->position = gme::Vector2(1584/2, -288);
    
    limit *ll = new limit("limit_left");
    ll->width = 3;
    ll->height = 864;
    ll->position = gme::Vector2(-3, 144);
    
    limit *lr = new limit("limit_right");
    lr->width = 3;
    lr->height = 864;
    lr->position = gme::Vector2(1584-16*3, 144);
    
    setupScenario();
    
    //SETUP CAMERA
    CameraFollowPlayer *cameraFollow = new CameraFollowPlayer;
    cameraFollow->limitX = gme::Vector2(0, 1024/2);
    cameraFollow->limitY = gme::Vector2(-576/2, 0);
    gme::Game::mainCamera->addComponent(cameraFollow);

    reseting = true;
}


void tilerJsonLoadScene::setupBg() {
    srand (time(NULL));
    gme::Vector2 windowSize = gme::Game::getWindow()->getSize();
    
    float yDisp = 0.f;
    
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
    bgLayerC->getTransform()->position = gme::Vector2(windowSize.x*2, windowSize.y+yDisp);
    bgLayerC->parallaxFactor = 0.4;
}

void tilerJsonLoadScene::setupScenario() {
    emptyGameObject *sceneLoaderObject = new emptyGameObject("sceneLoader");
    
    generaPosicion *g =  new generaPosicion(-1,280,3);
    g->addPosition(1520, 280);
    g->addPosition(802, -300);
    g->setEnemi(true);
    sceneLoaderObject->addComponent(g);
    
    sceneLoaderObject->addComponent(new mapGenerator());
    
    
    sceneLoaderObject->customize([](gme::GameObject* obj) {
        mapGenerator *gen = (mapGenerator*)(obj->getComponent<mapGenerator*>());
        if(gen){
            gen->mapFile = "resources/maps/wave1.json";
        }
    });
}





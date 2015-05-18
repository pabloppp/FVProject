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
#include "GlobalStateManager.hpp"
#include "enemy_boss.hpp"
#include "mainGame.hpp"
#include "oleada2.hpp"

void tilerJsonLoadScene::setup() {   
    
    mainGame::continueLevel = 1;
    mainGame::saveProfile();
    
    gme::Scene *s = mainGame::getScene("oleada2");
    if(!s || s == NULL){
        gme::Scene *ol2 = new oleada2("oleada2");
    }    
    //addGameObject(gme::Game::mainCamera);
    
    if(reseting){
        setupScenario();
        return;
    }
    
    GameManager *gm = new GameManager("manager");
    
    gm->customize([](gme::GameObject* obj) {
        GlobalStateManager *gsm = (GlobalStateManager*)(obj->getComponent<GlobalStateManager*>());
        gsm->gameType = 1;
        gsm->winCondition = 60*3;
        gsm->nextScene = "oleada2";
    });
    
    
    setupBg(); 
    
    weapon *arma = new weapon("weapon");
    arma->addComponent(new pistolaBehavior()); 
    
    /* DISTINTAS ARMAS */
    metralletaBehavior *mb = new metralletaBehavior();
    mb->setActive(false);
    arma->addComponent(mb);
    escopetaBehavior *eb =  new escopetaBehavior();
    eb->setActive(false);
    arma->addComponent(eb);
    lnzllamasBehavior *lb =  new lnzllamasBehavior();
    lb->setActive(false);
    arma->addComponent(lb);

    
    player *p1 = new player("p1");
    p1->getTransform()->setPosition(gme::Vector2(16*3, 576-16*9));
    
    p1->addChild(arma);
    arma->getTransform()->setPosition(gme::Vector2(0,0));
   
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
    
    generaPosicion *g =  new generaPosicion(-1, 280, 1.5);
    g->addPosition(1520, 280);
    g->addPosition(802, -300);
    g->setEnemi(true);
    g->setColectionable(true);
    g->ene4 = 100; //0;
    g->ene3 = 0;
    g->ene2 = 0; //25;
    g->ene1 = 0;//75;
    sceneLoaderObject->addComponent(g);
    
    sceneLoaderObject->addComponent(new mapGenerator());
    
    
    sceneLoaderObject->customize([](gme::GameObject* obj) {
        mapGenerator *gen = (mapGenerator*)(obj->getComponent<mapGenerator*>());
        if(gen){
            gen->mapFile = "resources/maps/wave1.json";
        }
    });
}





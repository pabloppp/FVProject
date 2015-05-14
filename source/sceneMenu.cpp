
#include "sceneMenu.hpp"
#include "imagenFondo.hpp"
#include "staticObject.hpp"
#include "GameManager.hpp"
#include "backgroundLayer.hpp"
#include "MainMenuSetup.hpp"
#include "myMenu.hpp"
#include "moveClouds.hpp"

#include <SFML/Graphics.hpp>

void sceneMenu::setup(){
   
    gme::GameObject *mymenu = new myMenu("mymenu");
   /*gme::GameObject *fondo1= new imagenFondo("fondo1");
   fondo1->getTransform()->setPosition(gme::Vector2(320, 240));
   fondo1->getRenderer()->setTexture("fondo_principal");

   gme::GameObject *fondo2= new imagenFondo("fondo2");
   fondo2->getTransform()->setPosition(gme::Vector2(320+640, 240));
   fondo2->getTransform()->setScale(gme::Vector2(-1, 1));
   fondo2->getRenderer()->setTexture("fondo_principal");
   
   gme::GameObject *gameManager = new GameManager("gmanager");*/
   
    gme::Game::newTexture("resources/BGs/jungle_cloud.png", "bgCloud");
    gme::Game::newTexture("resources/BGs/jungle_cloudB.png", "bgCloudB");
  
    setupBg(); 
    
}

void sceneMenu::setupBg() {
    srand (time(NULL));
    gme::Vector2 windowSize = gme::Game::getWindow()->getSize();
    
    //SKY
    float bgWidth = gme::Game::getTexture("skyTexture")->getTexture().getSize().x;
    int howMany = windowSize.x/bgWidth;
    for(int i=0;i<howMany;i++){
        backgroundLayer *bgSkyLayer = new backgroundLayer("BGSky");
        bgSkyLayer->texture = "skyTexture";
        bgSkyLayer->parallaxFactor = 1; //fixed
        bgSkyLayer->getTransform()->position = gme::Vector2((i*bgWidth) + bgWidth/2, windowSize.y);
    }
    
    backgroundLayer *bgLayerMidA = new backgroundLayer("BGMidA");
    bgLayerMidA->texture = "bgMidATexture";
    bgLayerMidA->getTransform()->position = gme::Vector2(windowSize.x/2, windowSize.y);
    bgLayerMidA->parallaxFactor = 0.7;
    
    backgroundLayer *bgLayerMidB = new backgroundLayer("BGMidB");
    bgLayerMidB->texture = "bgMidBTexture";
    bgLayerMidB->getTransform()->position = gme::Vector2(0, windowSize.y);
    bgLayerMidB->parallaxFactor = 0.8;
    
    backgroundLayer *bgLayerMidC = new backgroundLayer("BGMidC");
    bgLayerMidC->texture = "bgMidCTexture";
    bgLayerMidC->getTransform()->position = gme::Vector2(windowSize.x, windowSize.y);
    bgLayerMidC->parallaxFactor = 0.8;
   
    
    backgroundLayer *bgLayerCloud = new backgroundLayer("BGCloud");
    bgLayerCloud->texture = "bgCloud";
    bgLayerCloud->getTransform()->position = gme::Vector2(200, 100);
    bgLayerCloud->active = false;
    bgLayerCloud->addComponent(new moveClouds);
    
    backgroundLayer *bgLayerCloudB = new backgroundLayer("BGCloudB");
    bgLayerCloudB->texture = "bgCloudB";
    bgLayerCloudB->getTransform()->position = gme::Vector2(350, 180);
    bgLayerCloudB->active = false;
    moveClouds *mv = new moveClouds();
    mv->speed = 30;
    bgLayerCloudB->addComponent(mv);
    
    backgroundLayer *bgLayerCloud2 = new backgroundLayer("BGCloud");
    bgLayerCloud2->texture = "bgCloud";
    bgLayerCloud2->getTransform()->position = gme::Vector2(200-1024, 100);
    bgLayerCloud2->active = false;
    bgLayerCloud2->addComponent(new moveClouds);
    
    backgroundLayer *bgLayerCloudB2 = new backgroundLayer("BGCloudB");
    bgLayerCloudB2->texture = "bgCloudB";
    bgLayerCloudB2->getTransform()->position = gme::Vector2(350-1024, 180);
    bgLayerCloudB2->active = false;
    moveClouds *mv2 = new moveClouds();
    mv2->speed = 30;
    bgLayerCloudB2->addComponent(mv2);
    
    backgroundLayer *bgLayerA = new backgroundLayer("BGFrontA");
    bgLayerA->texture = "bgFrontATexture";
    bgLayerA->getTransform()->position = gme::Vector2(0, windowSize.y+100);
    bgLayerA->parallaxFactor = 1;
    
    backgroundLayer *bgLayerB = new backgroundLayer("BGFrontB");
    bgLayerB->texture = "bgFrontBTexture";
    bgLayerB->getTransform()->position = gme::Vector2(windowSize.x, windowSize.y+100);
    bgLayerB->parallaxFactor = 1;
}


   
    
  



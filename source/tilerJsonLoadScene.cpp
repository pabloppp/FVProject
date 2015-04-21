#include "tilerJsonLoadScene.hpp"
#include "emptyGameObject.hpp"
#include "mapGenerator.hpp"
#include "player.hpp"

void tilerJsonLoadScene::setup() {
    
    
    player *p1 = new player("p1");
    p1->getTransform()->setPosition(gme::Vector2(50, 50));
    
    emptyGameObject *sceneLoaderObject = new emptyGameObject("sceneLoader");
    
    gme::Game::newTexture("resources/temple_bricks.png", "selvaTiles");
    gme::Game::newTexture("resources/Broniversal Soldier Anim.png", "playerTexture");   
    
    sceneLoaderObject->addComponent(new mapGenerator());
    
    
    sceneLoaderObject->customize([](gme::GameObject* obj) {
        mapGenerator *gen = (mapGenerator*)(obj->getComponent<mapGenerator*>());
        if(gen){
            gen->mapFile = "resources/maps/test.json";
        }
    });
    
    

}





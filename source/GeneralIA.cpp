
#include "GeneralIA.hpp"
#include "LifeManager.hpp"
void GeneralIA::setup(){
    
    
}

void GeneralIA::update(){
   getPlayer();
    if(g){
        gme::Vector2 pp = g->getTransform()->getPosition();
        gme::Vector2 dp = getTransform()->getPosition();

        float deltatime = gme::Game::deltaTime.asSeconds();

        double x = std::pow(dp.x-pp.x,2);
        double y = std::pow(dp.y-pp.y,2);
        dist = std::sqrt(x+y);

        gme::Vector2 dir = vectorDirection(pp,dp);
        getTransform()->translate(dir,dist*deltatime);
    }
    
    
    
}

void GeneralIA::getPlayer(){
    g = gme::GameObject::find("p1").at(0);
}

gme::Vector2 GeneralIA::vectorDirection(gme::Vector2 pp, gme::Vector2 dp){
    
    gme::Vector2 dir = gme::Vector2(0,0);
    
    if(dp.x < pp.x){
        dir.x = 1;
    }
    if(dp.x > pp.x){
        dir.x = -1;
    }
    
    /*if(dp.x < pp.x+0.9 && dp.x > pp.x-0.9){
        dir.x = 0;
    }*/
   
    
    return dir;
}


GeneralIA::~GeneralIA() {
     
}

void GeneralIA::onCollision(gme::Collider* c) {
    LifeManager *lm = (LifeManager*)(gameObject()->getComponent<LifeManager*>()) ;
    std::cout << c->gameObject()->getName() << " " << lm->getHp() << std::endl;
    if(lm->getHp() == 0){
        destroyGameObject(gameObject());
    }
    
    c->gameObject()->sendMessage("damage", 5);
}



#include "lnzllamasBehavior.hpp"
#include "llamasBullet.hpp"
#include "PlayerMovement.hpp"
#include "mainGame.hpp"

void lnzllamasBehavior::setup() {
    
    
    
    getRenderer()->setTexture("gun");
    speedBullet = 15.f;
    recargando = false;
    numBullets = 100;
    
    lanzallamasShot_sound = new gme::SoundPlayer();
    lanzallamasShot_sound->setSound("lanzallamasShot");
    lanzallamasShot_sound->setVolume(60.0);
    
    lanzallamasReload_sound = new gme::SoundPlayer();
    lanzallamasReload_sound->setSound("lanzallamasReload");
    
    direction = 1;
    std::vector<gme::GameObject*> *objects = gme::Game::getCurrentScene()->getGameObjects();
    for(int i=0;i<objects->size();i++){
        if(objects->at(i) == gameObject()){
            objects->erase(objects->begin()+i);
            objects->push_back(gameObject());
            break;
        }
    }
    
    ShotKey = ((PlayerMovement*)(gameObject()->getParent()->getComponent<PlayerMovement*>()))->weaponKey;
    keyUp = ((PlayerMovement*)(gameObject()->getParent()->getComponent<PlayerMovement*>()))->upKey;
    keyDown = ((PlayerMovement*)(gameObject()->getParent()->getComponent<PlayerMovement*>()))->downKey;
    keyLeft = ((PlayerMovement*)(gameObject()->getParent()->getComponent<PlayerMovement*>()))->leftKey;
    keyRight = ((PlayerMovement*)(gameObject()->getParent()->getComponent<PlayerMovement*>()))->rightKey;
    std::vector<gme::GameObject*> gm = gme::GameObject::find("manager");
    if(gm.size() > 0){
        GlobalStateManager *gsm = (GlobalStateManager*)(gm.at(0)->getComponent<GlobalStateManager*>());
        if(gsm != NULL){
            manager = gsm;
        }
    }
}

void lnzllamasBehavior::update() {
    if(manager->isPaused()) return;
    if(!isActive()) return;
    
    if(numBullets <= 0 && !recargando){
        recargando = true;
        return;
    }
    if(recargando){        
        if(tlkClock.currentTime().asSeconds() > 4){
            if(mainGame::sound) lanzallamasReload_sound->play();
            tlkClock.restart();
        }
        if(clock.currentTime().asSeconds() > 0.2){
            clock.restart();
            numBullets = numBullets + 5;
        } 
        if(numBullets >= 50) recargando = false;
        return;
    }
    else if(numBullets < 100 && !recargando){
        if(clock.currentTime().asSeconds() > 0.5){
            clock.restart();
            numBullets = numBullets + 5;
        } 
    }
     //std::cout << "BULLETS" << numBullets << std::endl;
    verticalDirection = -1;
    if(gme::Keyboard::isKeyPressed(keyUp)){
        verticalDirection = 0;
    }
    else if(gme::Keyboard::isKeyPressed(keyDown)){
        verticalDirection = 2;
    } 
    else verticalDirection = -1;
    
    if(gme::Keyboard::isKeyPressed(keyLeft)){
        direction = 3;
    }
    else if(gme::Keyboard::isKeyPressed(keyRight)) {
        direction = 1;
    }
        
    if(gme::Keyboard::isKeyPressed(ShotKey) && !recargando){
        animator.animate();
        if(tlkClock.currentTime().asSeconds() > 15 || pauseArma ){
              
            pauseArma=false;
             if(mainGame::sound) lanzallamasShot_sound->play();
             tlkClock.restart();
        }
        if(numBullets==0){
            pauseArma=true;
            lanzallamasShot_sound->pause();
        }
        if(verticalDirection != -1) shoot(verticalDirection);
        else shoot(direction);
    } 
    else if(!gme::Keyboard::isKeyPressed(ShotKey)){
        
        pauseArma=true;
        lanzallamasShot_sound->pause();
        animator.restart();
    }
    
}

void lnzllamasBehavior::onGui() {
    int disp = 0;
    if(gameObject()->getParent()->getName().compare("p2") == 0) disp = 1024 - 170;
    gme::GUI::fontSize = 16;
    gme::GUI::label(gme::Vector2(10+disp,58), "WP", gme::GUI::Origin::TopLeft);

    gme::GUI::backgroundColor = gme::GUI::Color(0,0,0,50);
    gme::GUI::outlineThickness = 3;
    gme::GUI::outlineColor = gme::GUI::white;

    gme::GUI::box(gme::Vector2(40+disp,55), gme::Vector2(117, 3*6));
    int bars = (int)( 1.0f*numBullets/ 5.555); 
    gme::GUI::backgroundColor = gme::GUI::Color(255, 142, 110);
    gme::GUI::outlineThickness = 0;
    for(int i=0;i<bars;i++){
        gme::GUI::box(gme::Vector2(46+i*6+disp, 55+6), gme::Vector2(3, 3*2));
    }    
}


void lnzllamasBehavior::shoot(int d) {

    float timePassed = 0.04f;
    directionSp = d;
   
    animator.at(timePassed, [](void* ctx) {
       lnzllamasBehavior *q = static_cast<lnzllamasBehavior*> (ctx);
       llamasBullet *bulletx = new llamasBullet("bullet");
       if(q->gameObject()->getParent()->getName().compare("p2") == 0) bulletx->whoshoots = 2;
       q->instantiate(bulletx);
       q->numBullets--;
       int v1 = rand() % 7+0;
       if(q->directionSp == 1 || q->directionSp == 3){
            bulletx->getTransform()->setPosition(
                gme::Vector2(q->getTransform()->getPosition().x,
               (q->getTransform()->getPosition().y-30+v1))
            );
       }
       else if(q->directionSp == 0 || q->directionSp == 2){
            bulletx->getTransform()->setPosition(
                gme::Vector2(q->getTransform()->getPosition().x+v1,
               (q->getTransform()->getPosition().y-30))
            );
       }
       switch(q->directionSp){
            case 0:
                bulletx->getRigidBody()->setSpeed(0.0, -q->speedBullet);
                break;
            case 1:
                bulletx->getRigidBody()->setSpeed(q->speedBullet,0.0);
                break;
            case 2:
                bulletx->getRigidBody()->setSpeed(0.0,q->speedBullet);
                break;
            case 3:
                bulletx->getRigidBody()->setSpeed(-q->speedBullet,0.0);
                break;
        }
    }, this);
    timePassed += cadency;
  
}

lnzllamasBehavior::~lnzllamasBehavior() {

}






#include "PlayerMovement.hpp"
#include "LifeManager.hpp"

void PlayerMovement::setup() {
    std::vector<gme::GameObject*> *objects = gme::Game::getCurrentScene()->getGameObjects();
    for(int i=0;i<objects->size();i++){
        if(objects->at(i) == gameObject()){
            objects->erase(objects->begin()+i);
            objects->push_back(gameObject());
            std::cout << "pushing to back" << std::endl;
            break;
        }
    }
}

void PlayerMovement::update() {
    
    
    
    float deltaTime = gme::Game::deltaTime.asSeconds();
    
    if(getRigidBody() == NULL) return;
    if(getRenderer() == NULL) return;
    
    float speedX = getRigidBody()->getSpeed().x;
    float speedY = getRigidBody()->getSpeed().y;
    
    if(!down && grounded && gme::Keyboard::isKeyPressed(downKey)){
        ((gme::BoxCollider*)getCollider())->setSize(10*3, 13*3);
        //((gme::BoxCollider*)getCollider())->setCenter(0,(3.f*6)/2.0f);
        down = true;
        animGraceTimeClock.restart();
    }
    else if(down && !gme::Keyboard::isKeyPressed(downKey) ){
        ((gme::BoxCollider*)getCollider())->setSize(10*3,19*3);
        //((gme::BoxCollider*)getCollider())->setCenter(0.f,0.f);
        down = false;
        animGraceTimeClock.restart();
    }
    
    if(gme::Keyboard::isKeyPressed(leftKey) && !hitWallLeft){
        if(gme::Keyboard::isKeyPressed(downKey))
            getRigidBody()->setSpeed(-(walkingSpeed/2.f)*deltaTime, speedY);
        else 
            getRigidBody()->setSpeed(-walkingSpeed*deltaTime, speedY);
        if(!flipped){
            getTransform()->resize(gme::Vector2(-1,1));
            flipped = true;
        }
    }
    else if(gme::Keyboard::isKeyPressed(rightKey) && !hitWallRight){
        if(gme::Keyboard::isKeyPressed(downKey))
            getRigidBody()->setSpeed((walkingSpeed/2.f)*deltaTime, speedY);
        else 
            getRigidBody()->setSpeed(walkingSpeed*deltaTime, speedY);
        if(flipped){
            getTransform()->resize(gme::Vector2(-1,1));
            flipped = false;
        }
    }
    else{
        getRigidBody()->setSpeed(0, speedY);
    }
    
    if(gme::Keyboard::isKeyPressed(jumpKey) && grounded && !jumped){
        if(gme::Keyboard::isKeyPressed(downKey))
            getRigidBody()->pushImmediate(gme::Vector2(0,-1), (jumpForce/2.f)*deltaTime);
        else 
            getRigidBody()->pushImmediate(gme::Vector2(0,-1), jumpForce*deltaTime);
        jumped = true;
    }
    else if(jumped && !gme::Keyboard::isKeyPressed(jumpKey)){
        jumped = false;
    }
    
    animate();
    
    grounded = false;
    hitWallLeft = false;
    hitWallRight = false;
}

void PlayerMovement::onCollision(gme::Collider* c) {
    gme::Vector2 relativePosition = getCollider()->getRelativePosition(c);
    if(c->gameObject()->hasTag("floor")){       
        if(relativePosition.y == -1){ //si golpea el suelo
            grounded = true;
        }
    }
    //si golpea las paredes
    if(relativePosition.x == 1 && relativePosition.y == 0){
        hitWallLeft = true;
        std::cout << "hit left" << std::endl;
    }
    else if(relativePosition.x == -1 && relativePosition.y == 0){
        hitWallRight = true;
        std::cout << "hit right" << std::endl;
    }
    
    /*if(relativePosition.y == 1 && relativePosition.x == 0){
        //destroyGameObject(c->gameObject());
        if(c && c->gameObject()){
            c->gameObject()->sendMessage("damage", 20);
        }
        
    }*/
    
    //HARDCODED FOR ENEMY COLLISION
    else if(c->gameObject()->hasTag("enemy")){
        sendMessage("damage", 5);
        if(c->gameObject()->getTransform()->getPosition().x > getTransform()->getPosition().x){
            getRigidBody()->push(gme::Vector2(-1, 0), 10000);
        }
        else{
            getRigidBody()->push(gme::Vector2(1, 0), 10000);
        }
    }
}

void PlayerMovement::animate() {
    if(animGraceTimeClock.currentTime().asSeconds() < animGraceTime) return;
    if(grounded && getRigidBody()->getSpeed().x != 0){
        
        if(animClock.currentTime().asSeconds() > 1.0f/walkFPS){
            animClock.restart();
            walkFrameCount++;
            if(walkFrameCount >= 8) walkFrameCount = 0;
            if(gme::Keyboard::isKeyPressed(downKey)) 
                getRenderer()->setFrame(gme::Vector2(8+walkFrameCount,1));
            else 
                getRenderer()->setFrame(gme::Vector2(walkFrameCount,1));
        }
        
    }
    else if(grounded && getRigidBody()->getSpeed().x == 0){
        if(gme::Keyboard::isKeyPressed(downKey)){
           getRenderer()->setFrame(gme::Vector2(20,1)); 
        }
        else if(gme::Keyboard::isKeyPressed(upKey)){
           getRenderer()->setFrame(gme::Vector2(21,3)); 
        }
        else{
            getRenderer()->setFrame(gme::Vector2(0,0));
        } 
        walkFrameCount = 0;
    }
    else if(!grounded){
        if(getRigidBody()->getSpeed().y < -10){
            getRenderer()->setFrame(gme::Vector2(1,0));
        }
        else if(getRigidBody()->getSpeed().y > 10){
            getRenderer()->setFrame(gme::Vector2(3,0));
        }
        else{
            getRenderer()->setFrame(gme::Vector2(2,0));
        }
    }
}

void PlayerMovement::onGui() {
    
    LifeManager *stats = (LifeManager*)(gameObject()->getComponent<LifeManager*>());
    //gme::GUI::backgroundColor = gme::GUI::Color(255,255,255,50)
    //gme::GUI::box(getTransform()->getPosition().worldToScreen(), gme::Vector2(50,50), gme::GUI::Origin::Center);
    gme::GUI::fontSize = 12;
    gme::GUI::contentColor = gme::GUI::Color(255,255,255,70);
    gme::Vector2 pos = getTransform()->getPosition().worldToScreen();
    pos.y -= 70;
    gme::GUI::label(pos, gameObject()->getName(), gme::GUI::Origin::BottomCenter);
    gme::GUI::contentColor = gme::GUI::white;
    if(stats != NULL){
        gme::GUI::label(gme::Vector2(15,10), "Lives "+std::to_string(stats->getLives()), gme::GUI::Origin::TopLeft);
        gme::GUI::backgroundColor = gme::GUI::green;
        gme::GUI::box(gme::Vector2(10,25), gme::Vector2(stats->getHpPercent(), 10));
    }
    //std::cout << "ENTERING HERE" << std::endl;
}

PlayerMovement::~PlayerMovement() {

}



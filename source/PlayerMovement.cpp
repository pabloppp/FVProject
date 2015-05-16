#include "PlayerMovement.hpp"
#include "LifeManager.hpp"
#include "tile.hpp"

void PlayerMovement::setup() {
    dead = false;
    points = 0;
    for(int i=0;i<gameObject()->getChildren().size();i++){
        gameObject()->getChildren().at(i)->setActive(true);
    }
    
    std::vector<gme::GameObject*> gm = gme::GameObject::find("manager");
    if(gm.size() > 0){
        GlobalStateManager *gsm = (GlobalStateManager*)(gm.at(0)->getComponent<GlobalStateManager*>());
        if(gsm != NULL){
            manager = gsm;
        }
    }
    if(flipped && getTransform()->getScale().x < 0){
        getTransform()->resize(gme::Vector2(-1,1));
        //flipped = false;
    }
    flipped = false;
}

void PlayerMovement::onMessage(std::string m, float v) {
    if(m.compare("gameover") == 0){
        dead = true;
        for(int i=0;i<gameObject()->getChildren().size();i++){
            gameObject()->getChildren().at(i)->setActive(false);
        }
    }
    if(m.compare("givePoints") == 0){
        points+=v;
    }
}


void PlayerMovement::update() {
    
    //std::cout << getTransform()->getPosition().x << ":" << getTransform()->getPosition().y << std::endl;
    
    if(manager->isPaused()){
        getRigidBody()->setSpeed(0, 0);
        getRigidBody()->setActive(false);
        return;
    }
    else getRigidBody()->setActive(true);
    
    if(dead) return;
    
        
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
        if(!flipped && getTransform()->getScale().x > 0){
            getTransform()->resize(gme::Vector2(-1,1));
            flipped = true;
        }
    }
    else if(gme::Keyboard::isKeyPressed(rightKey) && !hitWallRight){
        if(gme::Keyboard::isKeyPressed(downKey))
            getRigidBody()->setSpeed((walkingSpeed/2.f)*deltaTime, speedY);
        else 
            getRigidBody()->setSpeed(walkingSpeed*deltaTime, speedY);
        if(flipped && getTransform()->getScale().x < 0){
            getTransform()->resize(gme::Vector2(-1,1));
            flipped = false;
        }
    }
    else{
        getRigidBody()->setSpeed(0, speedY);
    }
    
    if((gme::Keyboard::isKeyPressed(jumpKey)) && grounded && !jumped ){
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
    }
    else if(relativePosition.x == -1 && relativePosition.y == 0){
        hitWallRight = true;
    }
    
    if(relativePosition.y == 1 && relativePosition.x == 0){
        //destroyGameObject(c->gameObject());
        if(c && c->gameObject()){
            c->gameObject()->sendMessage("damage", 1);
        }
        
    }
    
    //HARDCODED FOR ENEMY COLLISION
    /*else if(c->gameObject()->hasTag("enemy")){
        sendMessage("damage", 5);
        if(c->gameObject()->getTransform()->getPosition().x > getTransform()->getPosition().x){
            getRigidBody()->push(gme::Vector2(-1, 0), 10000);
        }
        else{
            getRigidBody()->push(gme::Vector2(1, 0), 10000);
        }
    }*/
}

void PlayerMovement::animate() {
    if(animGraceTimeClock.currentTime().asSeconds() < animGraceTime) return;
    if(grounded && getRigidBody()->getSpeed().x != 0){
        
        if(animClock.currentTime().asSeconds() > 1.0f/walkFPS){
            animClock.restart();
            walkFrameCount++;
            if(walkFrameCount >= 8) walkFrameCount = 0;
            if(gme::Keyboard::isKeyPressed(downKey)) 
                getRenderer()->setFrame("run-down_"+std::to_string(walkFrameCount));
            else 
                getRenderer()->setFrame("run_"+std::to_string(walkFrameCount));
        }
        
    }
    else if(grounded && getRigidBody()->getSpeed().x == 0){
        if(gme::Keyboard::isKeyPressed(downKey)){
           getRenderer()->setFrame("idle-down"); 
        }
        else if(gme::Keyboard::isKeyPressed(upKey)){
           getRenderer()->setFrame("idle-up");
        }
        else{
            getRenderer()->setFrame("idle_0");
        }
        walkFrameCount = 0;
    }
    else if(!grounded){
        if(getRigidBody()->getSpeed().y < -10){
            getRenderer()->setFrame("jump_0");
        }
        else if(getRigidBody()->getSpeed().y > 10){
            getRenderer()->setFrame("jump_2");
        }
        else{
            getRenderer()->setFrame("jump_1");
        }
    }
}

void PlayerMovement::onGui() {
    
    int disp = 0;
    if(gameObject()->getName().compare("p2")==0){
        disp = 1024 - 170;
    }
    
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
        
        gme::GUI::drawTexture(
            gme::Vector2(10+disp, 5),
            gme::Vector2(8*3, 8*3),
            gme::GUI::TextureName("heart"),
            gme::GUI::Origin::TopLeft,
            gme::GUI::ScaleToFit
        );
        
        
        
        gme::GUI::fontSize = 20;
        gme::GUI::label(gme::Vector2(50+disp, 12), "x "+std::to_string(stats->getLives()), gme::GUI::Origin::TopLeft);
        
        
        gme::GUI::fontSize = 16;
        gme::GUI::label(gme::Vector2(10+disp,38), "HP", gme::GUI::Origin::TopLeft);
        gme::GUI::label(gme::Vector2(10+disp,58), std::to_string(points), gme::GUI::Origin::TopLeft);
        
        gme::GUI::backgroundColor = gme::GUI::Color(0,0,0,50);
        gme::GUI::outlineThickness = 3;
        gme::GUI::outlineColor = gme::GUI::white;
        
        gme::GUI::box(gme::Vector2(40+disp,35), gme::Vector2(117, 3*6));
        
        int bars = (int)( stats->getHpPercent() / 5.555); 
        if(stats->getHpPercent() > 50) gme::GUI::backgroundColor = gme::GUI::Color(172, 255, 135);
        else if(stats->getHpPercent() > 25) gme::GUI::backgroundColor = gme::GUI::Color(255, 218, 117);
        else gme::GUI::backgroundColor = gme::GUI::Color(255, 142, 110);
        gme::GUI::outlineThickness = 0;
        for(int i=0;i<bars;i++){
            gme::GUI::box(gme::Vector2(46+i*6+disp, 35+6), gme::Vector2(3, 3*2));
        }
        //BOTTOM STATS    
        gme::GUI::drawTexture(
            gme::Vector2(0, 576),
            gme::Vector2(64*3, 64*3),
            gme::GUI::TextureName("interface_p1"),
            gme::GUI::Origin::BottomLeft,
            gme::GUI::ScaleToFit
        );
        gme::GUI::drawTexture(
            gme::Vector2(20, 530),
            gme::Vector2(27*3, 37*3),
            gme::GUI::TextureName("max-willis"),
            gme::GUI::Origin::BottomLeft,
            gme::GUI::ScaleToFit
        );
        gme::GUI::drawTexture(
            gme::Vector2(103, 525),
            gme::Vector2(15*3, 7*3),
            gme::GUI::TextureName("pistola-inter"),
            gme::GUI::Origin::BottomLeft,
            gme::GUI::ScaleToFit
        );
    }
    //std::cout << "ENTERING HERE" << std::endl;
}

PlayerMovement::~PlayerMovement() {

}



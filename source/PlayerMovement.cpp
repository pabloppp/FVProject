#include "PlayerMovement.hpp"
#include "LifeManager.hpp"
#include "tile.hpp"
#include "granada.hpp"
#include "mainGame.hpp"

void PlayerMovement::setup() {
    
    footsteps_sound = new gme::SoundPlayer();
    footsteps_sound->setSound("footsteps");
    
    jump_sound = new gme::SoundPlayer();
    jump_sound->setSound("jump");
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
    grenades = maxGrenades;
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
    if(gme::Keyboard::isKeyPressed(gme::Keyboard::H)) std::cout << getTransform()->getPosition().x << ":" << getTransform()->getPosition().y << std::endl;
    
    if(manager->isPaused()){
        getRigidBody()->setSpeed(0, 0);
        getRigidBody()->setActive(false);
        footsteps_sound->pause();
        return;
    }
    else getRigidBody()->setActive(true);
    
    float posPlayerY = getTransform()->getPosition().y;
    if(posPlayerY > 1200){
        sendMessage("damage", 151);
    }
    if(dead){
        footsteps_sound->stop();
        jump_sound->stop();
        return;
    }    
        
    float deltaTime = gme::Game::deltaTime.asSeconds();
    
    if(getRigidBody() == NULL) return;
    if(getRenderer() == NULL) return;
    
    float speedX = getRigidBody()->getSpeed().x;
    float speedY = getRigidBody()->getSpeed().y;
    
    if(grenades > 0 && !grenadeLaunched && gme::Keyboard::isKeyPressed(actionKey)){        
        granada *gr = new granada("granada");
        gme::Vector2 pos = getTransform()->getPosition();
        if(gameObject()->getName().compare("p2") == 0) gr->whoshoots = 2;
        pos.y -= 8*3;
        gr->getTransform()->setPosition(pos);
        if(flipped) gr->direction = 1;
        instantiate(gr);
        grenades -= 1;
        grenadeLaunched = true;
    }
    else if(grenadeLaunched && !gme::Keyboard::isKeyPressed(actionKey)){
        grenadeLaunched = false;
    }
    
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
         //if(GlobalStateManager.gameover)   
         if(tlkClock.currentTime().asSeconds() > 0.9){
            
             if(mainGame::sound && grounded && !dead)footsteps_sound->play();
             tlkClock.restart();
            
        }
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
         
        
          if(tlkClock.currentTime().asSeconds() > 0.9){
              
             if(mainGame::sound && grounded && !dead)footsteps_sound->play();
             tlkClock.restart();
        }
        
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
        footsteps_sound->pause();
        salto=false;
        salto=0;
    }
    
    if(gme::Keyboard::isKeyPressed(jumpKey) && grounded && !jumped){
        
        footsteps_sound->pause();
        if(mainGame::sound)jump_sound->play();
        
        if(gme::Keyboard::isKeyPressed(downKey))
            getRigidBody()->pushImmediate(gme::Vector2(0,-1), (jumpForce/2.f)*deltaTime);
        else 
            getRigidBody()->pushImmediate(gme::Vector2(0,-1), jumpForce*deltaTime);
        jumped = true;
    }
    else if(jumped && !gme::Keyboard::isKeyPressed(jumpKey)){
        jumped = false;
        footsteps_sound->pause();
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
    gme::GUI::fontSize = 12;
    gme::GUI::contentColor = gme::GUI::Color(255,255,255,70);
    gme::Vector2 pos = getTransform()->getPosition().worldToScreen();
    pos.y -= 70;
    gme::GUI::label(pos, gameObject()->getName(), gme::GUI::Origin::BottomCenter);
    gme::GUI::contentColor = gme::GUI::white;
    if(stats != NULL){
        std::string puntosp1 = std::to_string(points);
        int cp1 = 9-puntosp1.length();
        for(int i = 0; i < cp1; i++){
          puntosp1 = "0"+puntosp1;
        }
        
        if(gameObject()->getName().compare("p1")==0){
            gme::GUI::drawTexture(
                gme::Vector2(0, 576),
                gme::Vector2(100*3, 37*3),
                gme::GUI::TextureName("interface_p1"),
                gme::GUI::Origin::BottomLeft,
                gme::GUI::ScaleToFit
            );
            gme::GUI::drawTexture(
                gme::Vector2(5, 580),
                gme::Vector2(27*3, 37*3),
                gme::GUI::TextureName("max-willis"),
                gme::GUI::Origin::BottomLeft,
                gme::GUI::ScaleToFit
            );
            
            gme::GUI::fontSize = 25;
            gme::GUI::contentColor = gme::GUI::Color(0,0,0);
            gme::GUI::label(gme::Vector2(195, 555), puntosp1, gme::GUI::Origin::Center);
            gme::GUI::contentColor = gme::GUI::white;
            
            for(int i=0; i<grenades; i++){
                gme::GUI::drawTexture(
                    gme::Vector2(115+8*3*i, 530),
                    gme::Vector2(16*3, 16*3),
                    gme::GUI::TextureName("grenade"),
                    gme::GUI::Origin::Center,
                    gme::GUI::ScaleToFit
                );        
            }
        }         
        
        if(gameObject()->getName().compare("p2")==0){
            gme::GUI::drawTexture(
                gme::Vector2(723, 576),
                gme::Vector2(100*3, 37*3),
                gme::GUI::TextureName("interface_p2"),
                gme::GUI::Origin::BottomLeft,
                gme::GUI::ScaleToFit
            );
             gme::GUI::fontSize = 25;
             gme::GUI::contentColor = gme::GUI::Color(0,0,0);
             gme::GUI::label(gme::Vector2(833, 555), puntosp1, gme::GUI::Origin::Center);
             gme::GUI::contentColor = gme::GUI::white;
             
             gme::GUI::drawTexture(
                gme::Vector2(940, 580),
                gme::Vector2(27*3, 37*3),
                gme::GUI::TextureName("max-willis-2"),
                gme::GUI::Origin::BottomLeft,
                gme::GUI::ScaleToFit
            );
             
             for(int i=0; i<grenades; i++){
                gme::GUI::drawTexture(
                    gme::Vector2(865+8*3*i, 530),
                    gme::Vector2(16*3, 16*3),
                    gme::GUI::TextureName("grenade"),
                    gme::GUI::Origin::Center,
                    gme::GUI::ScaleToFit
                );        
            }
        }
        
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
        
    }
    //std::cout << "ENTERING HERE" << std::endl;
}

PlayerMovement::~PlayerMovement() {

}



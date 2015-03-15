#include "animationTest.hpp"
#include <vector>


void animationTest::onGui(){
    gme::GUI::fontSize = textsize;
    gme::GUI::label(textposition, "El Eterno Max Willis", gme::GUI::Origin::CenterRight); 
    gme::GUI::contentColor =  gme::GUI::white;
}   

void animationTest::setup() {
   pauseKey = gme::Keyboard::P;
   resumeKey = gme::Keyboard::R;
   paused = false; 
   textposition = gme::Vector2(500,450);
   textsize = 22;
   
   
   animator.at(2, [](void* ctx) {
       animationTest *q = static_cast<animationTest*> (ctx);
   }, this);
   animator.until(4, [](void* ctx) {
      animationTest *q = static_cast<animationTest*> (ctx);
       q->getTransform()->translate(gme::Vector2(5,0), 5);
       q->textposition.y -= 5;
   }, this);
   animator.at(5, [](void* ctx) {
      animationTest *q = static_cast<animationTest*> (ctx);
       q->getTransform()->translate(gme::Vector2(5,0), 1);
   }, this);
   animator.until(8, [](void* ctx) {
       animationTest *q = static_cast<animationTest*> (ctx);
       q->getTransform()->rotate(90);
       q->getTransform()->scale = gme::Vector2(5,5);
       q->getTransform()->translate(gme::Vector2(5,-10), 5);
       q->textposition.x += 13;
        q->textposition.y -=11;
        //q->textsize += 1;
   }, this);
   
}

void animationTest::update() {    
    if(gme::Keyboard::isKeyPressed(pauseKey)){
       animator.loop(true);
       std::cout << "restarting at " << animator.timeLapsed << std::endl;
    }
    else if(gme::Keyboard::isKeyPressed(resumeKey)){
       animator.resume();
       std::cout << "Looping...  " << std::endl;
    }
    animator.animate();
}



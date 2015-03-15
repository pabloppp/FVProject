#include "animationTest.hpp"

void animationTest::setup() {
   pauseKey = gme::Keyboard::P;
   resumeKey = gme::Keyboard::R;
   paused = false;


   animator.at(2, [](void* ctx) {
       animationTest *q = static_cast<animationTest*> (ctx);
       
   }, this);
   animator.until(4, [](void* ctx) {
      animationTest *q = static_cast<animationTest*> (ctx);
      q->getTransform()->translate(gme::Vector2(5,0));
   }, this);
   animator.at(7, [](void* ctx) {
       animationTest *q = static_cast<animationTest*> (ctx);
       q->getTransform()->scale = gme::Vector2(10,10);
   }, this);
   animator.at(8, [](void* ctx) {
       animationTest *q = static_cast<animationTest*> (ctx);
       q->getTransform()->rotate(90);
   }, this);
}

void animationTest::update() {    
    if(gme::Keyboard::isKeyPressed(pauseKey)){
       animator.restart();
       std::cout << "restarting at " << animator.timeLapsed << std::endl;
    }
    else if(gme::Keyboard::isKeyPressed(resumeKey)){
       animator.resume();
       std::cout << "Looping...  " << std::endl;
    }
    animator.animate();
}



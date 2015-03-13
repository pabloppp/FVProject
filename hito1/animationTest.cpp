#include "animationTest.hpp"

void animationTest::setup() {
   pauseKey = gme::Keyboard::P;
   resumeKey = gme::Keyboard::R;
   paused = false;

   animator.at(2, [](void* ctx) {
       animationTest *q = static_cast<animationTest*> (ctx);
       std::cout << "Starting at 2 in time " << q->animator.timeLapsed << std::endl;
       q->getTransform()->scale = gme::Vector2(5,5);
   }, this);
   animator.at(4, [](void* ctx) {
      animationTest *q = static_cast<animationTest*> (ctx);
      std::cout << "Starting at 4 in time " << q->animator.timeLapsed << std::endl;
      q->getTransform()->scale = gme::Vector2(2,2);
   }, this);
   animator.at(6, [](void* ctx) {
       animationTest *q = static_cast<animationTest*> (ctx);
       std::cout << "Starting at 6 in time " << q->animator.timeLapsed << std::endl;
       q->getTransform()->scale = gme::Vector2(10,10);
   }, this);
   animator.at(10, [](void* ctx) {
       animationTest *q = static_cast<animationTest*> (ctx);
       std::cout << "Starting at 10 in time " << q->animator.timeLapsed << std::endl;
       q->getTransform()->scale = gme::Vector2(2,2);
   }, this);
   
   
   
}

void animationTest::update() {    
    if(gme::Keyboard::isKeyPressed(pauseKey)){
       animator.pause();
       std::cout << "Paused at " << animator.timeLapsed << std::endl;
    }
    else if(gme::Keyboard::isKeyPressed(resumeKey)){
       animator.resume();
       std::cout << "Resumed at " << animator.timeLapsed << std::endl;
    }
    animator.animate();
}



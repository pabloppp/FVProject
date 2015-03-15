#include "animationTest.hpp"

void animationTest::setup() {
   pauseKey = gme::Keyboard::P;
   resumeKey = gme::Keyboard::R;
   paused = false;

   animator.at(2, [](void* ctx) {
       animationTest *q = static_cast<animationTest*> (ctx);
       std::cout << "start animation " << q->animator.timeLapsed << std::endl;
       q->getTransform()->scale = gme::Vector2(2,2);
   }, this);
   animator.at(3, [](void* ctx) {
      animationTest *q = static_cast<animationTest*> (ctx);
      std::cout << "2 paso " << q->animator.timeLapsed << std::endl;
      q->getTransform()->scale = gme::Vector2(5,5);
   }, this);
   animator.at(4, [](void* ctx) {
       animationTest *q = static_cast<animationTest*> (ctx);
       std::cout << "3 paso " << q->animator.timeLapsed << std::endl;
       q->getTransform()->scale = gme::Vector2(10,10);
   }, this);
   animator.at(5, [](void* ctx) {
       animationTest *q = static_cast<animationTest*> (ctx);
       std::cout << "ending animation " << q->animator.timeLapsed << std::endl;
       q->getTransform()->scale = gme::Vector2(15,15);
   }, this);
}

void animationTest::update() {    
    if(gme::Keyboard::isKeyPressed(pauseKey)){
       animator.loop(false);
       std::cout << "Paused at " << animator.timeLapsed << std::endl;
    }
    else if(gme::Keyboard::isKeyPressed(resumeKey)){
       animator.loop(true);
       std::cout << "Looping...  " << std::endl;
    }
    animator.animate();
}



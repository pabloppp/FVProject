#include "introManager.hpp"
#include "animationTest.hpp"

void introManager::setup() {
    getRenderer()->setTexture("playerTexture");
    getRenderer()->setSize(gme::Vector2(32,32));
    getRenderer()->setCenter(gme::Vector2(0.5, 0.7));
    getTransform()->scale = gme::Vector2(3,3);
    addComponent(new animationTest);
}
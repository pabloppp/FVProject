#include "TileRowGenerator.hpp"

void TileRowGenerator::setup() {
    tileCount = gameObject()->getChildren().size();
    ((gme::BoxCollider*)getCollider())->setSize(tileCount*tileSize, tileSize);
}

void TileRowGenerator::update() {

}

TileRowGenerator::~TileRowGenerator() {

}

void TileRowGenerator::onCollision(gme::Collider* c) {
        //std::cout << gameObject()->getChildren().size() << std::endl;
}




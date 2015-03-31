#include "TileRowGenerator.hpp"
#include "tileRow.hpp"

void TileRowGenerator::setup() {
    std::cout << "creating new tile row" << std::endl;
    tileCount = gameObject()->getChildren().size();
    if(tileCount > 0)
        ((gme::BoxCollider*)getCollider())->setSize(tileCount*tileSize, tileSize);
    else 
        destroyGameObject(gameObject());
}

void TileRowGenerator::update() {
    int c = gameObject()->getChildren().size();
    if(tileCount != c){
        if(c > 0){
            tileCount = c;
            regenerateRow();
        }
        else{
            destroyGameObject(gameObject());
        }
    }
}

TileRowGenerator::~TileRowGenerator() {

}

void TileRowGenerator::onCollision(gme::Collider* c) {
        //std::cout << gameObject()->getChildren().size() << std::endl;
}

void TileRowGenerator::regenerateRow() {

    std::vector<gme::GameObject *> tiles;
    while(!gameObject()->getChildren().empty()){
        tiles.push_back(gameObject()->getChildren().back());
        gameObject()->removeChild(gameObject()->getChildren().back());
    }
    int c = 0;
    int c_final = tiles.size();
    float lastX;
    std::vector<gme::GameObject *> newRow;
    bool resized = false;
    
    lastX = tiles.front()->getTransform()->getPosition().x;
    while(c < c_final){
        float newX = tiles.at(c)->getTransform()->getPosition().x;
        if(fabs(newX - lastX) > tileSize){
            addRow(newRow);
        }
        newRow.push_back(tiles.at(c));
        lastX = newX;
        c++;
    }
    addRow(newRow);
    //tileCount = -1;
}

void TileRowGenerator::addRow(std::vector<gme::GameObject *> &tiles) {
    if(!tiles.empty()){
        tileRow *tro = new tileRow("tileRow");
        tro->tileSize = tileSize;
        for ( auto it = gameObject()->getTags()->begin(); it != gameObject()->getTags()->end(); ++it ){
            tro->addTag(it->first);
        }
        float px = (tiles.back()->getTransform()->getPosition().x + tiles.front()->getTransform()->getPosition().x)/2.f;
        float py = getTransform()->getPosition().y;
        tro->getTransform()->setPosition(gme::Vector2(px, py));
        while(!tiles.empty()){
            tro->addChild(tiles.back());
            tiles.pop_back();
        }
        instantiate(tro);
    }
}






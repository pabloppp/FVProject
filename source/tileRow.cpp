#include "tileRow.hpp"
#include "TileRowGenerator.hpp"

void tileRow::setup() {
    TileRowGenerator *tgen = new TileRowGenerator;
    tgen->tileSize = tileSize;
    addComponent(tgen);
    
    addComponent(new gme::RigidBody);
    getRigidBody()->isKinematic();
    getRigidBody()->setFixedRot(true);
    getRigidBody()->setFriction(0);
    getRigidBody()->setElasticity(0);
    getRigidBody()->setWeight(0);
    
    std::vector<gme::GameObject*> tiles = getChildren();
    gme::BoxCollider *collider = new gme::BoxCollider;
    addComponent(collider);  
    

}





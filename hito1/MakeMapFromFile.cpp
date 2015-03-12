#include "MakeMapFromFile.hpp"
#include "tile.hpp"
#include <fstream>
#include <istream>

void MakeMapFromFile::setup() {
    
    float tileSize = 16;
    float tileSizeFixed = tileSize*3;

    if(mainMapFile.length() > 0 && mainTexture.length() > 0){
        std::ifstream file(mainMapFile); 
        std::string value;
        int colPos = 0;
        int rowPos = 0;
        while (file.good()){
            if(colPos < tileColumns-1) getline ( file, value, ',' );
            else getline(file, value);
            
            int whatTile = atoi(value.c_str());
             
            if(whatTile != -1){
                
                int tx = whatTile % 16;
                int ty = whatTile / 16;
                
                tile *t = new tile("tile");
                t->addTag("floor");
                t->texture = mainTexture;
                t->size = gme::Vector2(tileSize,tileSize);
                t->frame = gme::Vector2(tx,ty);
                t->getTransform()->setPosition(gme::Vector2(origin.x+(tileSizeFixed/2.f)+colPos*tileSizeFixed, origin.y+(tileSizeFixed/2.f)+rowPos*tileSizeFixed));
                instantiate(t);
                
            }
            
            colPos++;
            if(colPos >= tileColumns){
                colPos = 0;
                rowPos++;
            }
        }
    }
    
}

void MakeMapFromFile::update() {

}

MakeMapFromFile::~MakeMapFromFile() {

}



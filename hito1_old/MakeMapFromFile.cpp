#include "MakeMapFromFile.hpp"
#include "tile.hpp"
#include "tileRow.hpp"
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
        bool rowInProgress = false;
        float initRowX, endRowX, rowY;
        while (file.good()){
            if(colPos < tileColumns-1) getline ( file, value, ',' );
            else getline(file, value);
            
            int whatTile = atoi(value.c_str());
             
            if(whatTile != -1){
                
                if(rowInProgress && rowY != rowPos){
                    rowInProgress = false;
                    addRow((initRowX+endRowX)/2.f, rowY, tileSizeFixed);
                }
                if(!rowInProgress){
                    tRowV.clear();
                    rowInProgress = true;
                    initRowX = colPos;
                    rowY = rowPos;
                }
                
                
                int tx = whatTile % 16;
                int ty = whatTile / 16;
                
                tile *t = new tile("tile");
                t->texture = mainTexture;
                t->size = gme::Vector2(tileSize,tileSize);
                t->frame = gme::Vector2(tx,ty);
                t->getTransform()->setPosition(gme::Vector2(origin.x+(tileSizeFixed/2.f)+colPos*tileSizeFixed, origin.y+(tileSizeFixed/2.f)+rowPos*tileSizeFixed));
                instantiate(t);
                tRowV.push_back(t);
                
            }
            
            else if(rowInProgress){
                rowInProgress = false;
                addRow((initRowX+endRowX)/2.f, rowY, tileSizeFixed);
            }
            
            endRowX = colPos;
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

void MakeMapFromFile::addRow(float cx, float cy, float tsize) {
    tileRow *tr = new tileRow("tileRow");
    tr->addTag("floor");
    tr->getTransform()->setPosition(gme::Vector2(origin.x+(tsize/2.f)+cx*tsize, origin.y+(tsize/2.f)+cy*tsize));
    for(int i = 0; i<tRowV.size(); i++){
        tr->addChild(tRowV.at(i));
    }
    tr->tileSize = tsize;
    instantiate(tr);
}




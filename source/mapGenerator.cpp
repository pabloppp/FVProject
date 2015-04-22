#include "mapGenerator.hpp"

#include "tileRow.hpp"
#include "tileDestroyManager.hpp"

void mapGenerator::setup() {
    std::cout << mapFile << std::endl;
    json_object *jobj = json_object_new_object();
    jobj = json_object_from_file(mapFile.c_str()); 
    
    int tileSizeFixed = 16*3;
    //JSON LOADED
    int mapwidth = json_object_get_int(json_object_object_get(jobj, "width"));
    int mapheight = json_object_get_int(json_object_object_get(jobj, "height"));
    
    //TILESET DATA
    json_object *tileAttributes = json_object_new_object();
    json_object *tilesetDataArray = json_object_object_get(jobj, "tilesets");
    if(tilesetDataArray){
        json_object *tilesetData = json_object_array_get_idx(tilesetDataArray, 0);
        if(tilesetData){
            tileAttributes = json_object_object_get(tilesetData, "tileproperties");
        }
    }
    
    //TILESET MAP READ
    json_object *mapArray = json_object_object_get(jobj, "layers"); 
    if(mapArray){
        int layerNumber = json_object_array_length(mapArray);
        //LOOKING FOR BG
        for(int i=0;i<layerNumber;i++){
            json_object *mapObj = json_object_array_get_idx(mapArray, i); 
            std::string type = json_object_get_string(json_object_object_get(mapObj, "name"));            
            if(type.compare("bg") == 0){ //FOUND BG
                json_object *mapDataArray = json_object_object_get(mapObj, "data");
                for(int j=0;j<mapheight;j++){
                    for(int k=0;k<mapwidth;k++){
                        int tileNumber = json_object_get_int( json_object_array_get_idx(mapDataArray, k+(j*mapwidth)) );

                        if(tileNumber != 0){
                            tileNumber -= 1;
                            tile *t = new tile("tile");
                            instantiate(t);
                            int tx = tileNumber%16;
                            int ty = tileNumber/16;
                            t->getRenderer()->setTexture("selvaTiles");
                            t->getRenderer()->setSize(gme::Vector2(16,16));
                            t->getRenderer()->setFrame(gme::Vector2(tx, ty));
                            t->getTransform()->setPosition(gme::Vector2(origin.x+(tileSizeFixed/2.f)+k*tileSizeFixed, origin.y+(tileSizeFixed/2.f)+j*tileSizeFixed));
                          
                            
                        }
                        
                    }
                }
            }
        }
        
        //LOOKING FOR FG
        for(int i=0;i<layerNumber;i++){
            json_object *mapObj = json_object_array_get_idx(mapArray, i); 
            std::string type = json_object_get_string(json_object_object_get(mapObj, "name"));            
            if(type.compare("fg") == 0){ //FOUND BG
                json_object *mapDataArray = json_object_object_get(mapObj, "data");
                for(int j=0;j<mapheight;j++){
                    for(int k=0;k<mapwidth;k++){
                        int tileNumber = json_object_get_int( json_object_array_get_idx(mapDataArray, k+(j*mapwidth)) );
                            
                        if(tileNumber != 0){
                            tileNumber -= 1;
                            tile *t = new tile("tile");
                            instantiate(t);
                            int tx = tileNumber%16;
                            int ty = tileNumber/16;
                            t->getRenderer()->setTexture("selvaTiles");
                            t->getRenderer()->setSize(gme::Vector2(16,16));
                            t->getRenderer()->setFrame(gme::Vector2(tx, ty));
                            t->getTransform()->setPosition(gme::Vector2(origin.x+(tileSizeFixed/2.f)+k*tileSizeFixed, origin.y+(tileSizeFixed/2.f)+j*tileSizeFixed));
                            tRowV.push_back(t);
                        }
                        if(tRowV.size() > 0 && (tileNumber == 0 || k == mapwidth-1) ){
                            int cx = (tRowV.at(0)->getTransform()->getPosition().x+tRowV.at(tRowV.size()-1)->getTransform()->getPosition().x)/2.0;
                            int cy = (tRowV.at(0)->getTransform()->getPosition().y+tRowV.at(tRowV.size()-1)->getTransform()->getPosition().y)/2.0;
                            addRow(cx, cy, tileSizeFixed);
                            tRowV.clear();
                        }
                    }
                }
            }
        }
        for(int i=0;i<layerNumber;i++){
            json_object *mapObj = json_object_array_get_idx(mapArray, i); 
            std::string type = json_object_get_string(json_object_object_get(mapObj, "name"));            
            if(type.compare("fgd") == 0){ //FOUND BG
                json_object *mapDataArray = json_object_object_get(mapObj, "data");
                for(int j=0;j<mapheight;j++){
                    for(int k=0;k<mapwidth;k++){
                        int tileNumber = json_object_get_int( json_object_array_get_idx(mapDataArray, k+(j*mapwidth)) );

                        if(tileNumber != 0){
                            tile *t = new tile("tile"); 
                            instantiate(t);
                            tileDestroyManager *tdm = new tileDestroyManager();
                            //tdm->hp = 100;
                            json_object *tileAttrs = json_object_object_get(tileAttributes, std::to_string(tileNumber).c_str() );
                            if(tileAttrs){
                                int hp = json_object_get_int(json_object_object_get(tileAttrs, "hp"));
                                if(hp){
                                    tdm->hp = hp;
                                }
                            }
                            
                            t->addComponent(tdm);
                            
                            t->addCollider();
                            
                            int tx = (tileNumber-1)%16;
                            int ty = (tileNumber-1)/16;
                            t->getRenderer()->setTexture("selvaTiles");
                            t->getRenderer()->setSize(gme::Vector2(16,16));
                            t->getRenderer()->setFrame(gme::Vector2(tx, ty));
                            t->getTransform()->setPosition(gme::Vector2(origin.x+(tileSizeFixed/2.f)+k*tileSizeFixed, origin.y+(tileSizeFixed/2.f)+j*tileSizeFixed));
                            t->addTag("floor");
                            tRowV.push_back(t);
                        }
                        if(tRowV.size() > 0 && (tileNumber == 0 || k == mapwidth-1) ){
                            int cx = (tRowV.at(0)->getTransform()->getPosition().x+tRowV.at(tRowV.size()-1)->getTransform()->getPosition().x)/2.0;
                            int cy = (tRowV.at(0)->getTransform()->getPosition().y+tRowV.at(tRowV.size()-1)->getTransform()->getPosition().y)/2.0;
                            addRow(cx, cy, tileSizeFixed);
                            tRowV.clear();
                        }
                    }
                }
            }
        }
    }
    
}

void mapGenerator::update() {

}

mapGenerator::~mapGenerator() {

}

void mapGenerator::addRow(float cx, float cy, float tsize) {
    tileRow *tr = new tileRow("tileRow");
    tr->addTag("floor");
    tr->getTransform()->setPosition(gme::Vector2(cx, cy));
    for(int i = 0; i<tRowV.size(); i++){
        tr->addChild(tRowV.at(i));
    }
    tr->tileSize = tsize;
    instantiate(tr);
}


#include "tileMapGenerator.hpp"
#include "MakeMapFromFile.hpp"

void tileMapGenerator::setup() {
    MakeMapFromFile *mapGenScript = new MakeMapFromFile;
    mapGenScript->mainMapFile = mainMapFile;
    mapGenScript->mainTexture = mainTexture;
    mapGenScript->tileColumns = tileColumns;
    mapGenScript->origin = origin;
    addComponent(mapGenScript);
}


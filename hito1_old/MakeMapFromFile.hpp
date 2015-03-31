#ifndef MAKEMAPFROMFILE_HPP
#define	MAKEMAPFROMFILE_HPP

#include "../engine/GMEngine.hpp"

class MakeMapFromFile : public gme::Script{
public:
    MakeMapFromFile(): gme::Script(){};
    void setup();
    void update();
    virtual ~MakeMapFromFile();
    std::string mainTexture;
    std::string mainMapFile;
    int tileColumns;
    gme::Vector2 origin;
    void addRow(float cx, float cy, float tsize);
    std::vector<gme::GameObject*> tRowV;
private:

};

#endif	/* MAKEMAPFROMFILE_HPP */


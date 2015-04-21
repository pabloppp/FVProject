
#ifndef SAVEMANAGER_HPP
#define	SAVEMANAGER_HPP

#include "../engine/GMEngine.hpp"

class SaveManager : public gme::Script {
public:
    SaveManager() : gme::Script() {};
    virtual ~SaveManager();
    void setup();
    void update();
    void save();
private:

};

#endif	/* SAVEMANAGER_HPP */


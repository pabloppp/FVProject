#include "myMenu.hpp"
#include "MainMenuSetup.hpp"

void myMenu::setup() {
    getRenderer()->setSize(gme::Vector2(1024,576));
    
    MainMenuSetup *msetup = new MainMenuSetup();
    addComponent(msetup);
}


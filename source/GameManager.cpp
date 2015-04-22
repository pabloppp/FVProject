#include "GameManager.hpp"
#include "GlobalStateManager.hpp"
#include "SaveManager.hpp"
#include "IntroS1Manager.hpp"
#include "MenuManager.hpp"

void GameManager::setup() {
    
    GlobalStateManager *stateManager = new GlobalStateManager();
    SaveManager *saveManager = new SaveManager();
    MenuManager *menuManager = new MenuManager();
    
    IntroS1Manager *intros1Manager = new IntroS1Manager();
    
    addComponent(stateManager);
    addComponent(saveManager);
    addComponent(menuManager);
    
}


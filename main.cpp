#include "engine/GMEngine.hpp"
#include "source/mainGame.hpp"

int main() {
    gme::Game *game = new mainGame(gme::Vector2(1024, 576), "hito1 game");

    game->run();
    
    delete game;
    
    return 0;
}


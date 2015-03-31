#include "engine/GMEngine.hpp"
#include "source/mainGame.hpp"

int main() {
    gme::Game *game = new mainGame(gme::Vector2(640, 480), "hito1 game");

    game->run();
    
    delete game;
    
    return 0;
}


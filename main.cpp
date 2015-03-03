#include <SFML/Graphics.hpp>

#include "engine/GMEngine.hpp"
#include "hito1/hito1Game.hpp"
#include "demo/MyGame.hpp"

int main() {
    gme::Game *H1G = new hito1Game(sf::Vector2f(640, 480), "hito1 game");
    //gme::Game *H1G = new MyGame(sf::Vector2f(640, 480), "My game");

    H1G->run();
    
    delete H1G;
    
    return 0;
}


#include <SFML/Graphics.hpp>

#include "engine/GMEngine.hpp"
#include "hito1/hito1Game.hpp"
#include "demo/MyGame.hpp"

int main() {
    //gme::Game *H1G = new hito1Game(sf::Vector2f(640, 480), "hito1 game");
    gme::Game *demo= new MyGame(sf::Vector2f(640, 480), "demo");
    //H1G->run();
    demo->run();
    //delete H1G;
    delete demo;
    
    return 0;
}


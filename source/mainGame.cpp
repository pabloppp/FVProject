#include "mainGame.hpp"
#include "imagenFondo.hpp"

#include "sceneSplash.hpp"
#include "sceneMenu.hpp"
#include "sceneEntregable2.hpp"

void mainGame::setup() {
    
    gme::Game::newTexture("resources/BGs/fondoSplash.png", "fondoSplash");  
    gme::Game::newTexture("resources/BGs/fondonuevo.png", "fondo_principal");
    gme::Game::newTexture("resources/BGs/gato.png", "logo");
    gme::Game::newTexture("resources/Effects/no.png", "no_icon");  
    gme::Game::newTexture("resources/BGs/fondo.jpg", "fondo_blanco"); 
   
    gme::Game::newMusic("resources/Sounds/chores_rules.wav", "sound");
    gme::Game::newMusic("resources/Sounds/boton.wav", "boton");
    gme::Game::newMusic("resources/Sounds/deslizamiento.wav", "desplazamiento");
    
    gme::Game::newTexture("resources/Bullets/Bullet2.png", "bullet");
    gme::Game::newTexture("resources/Bullets/flamebullet.png", "flame_bullet");
    gme::Game::newTexture("resources/Bullets/projectil.png", "proj_bullet");
    gme::Game::newTexture("resources/Weapons/soldier_gun.png", "gun");
    gme::Game::newTexture("resources/Weapons/weapon.png", "lanzallamas");
    
    gme::Scene *splash_scene = new sceneSplash("splash");
    gme::Scene *mainmenu_scene = new sceneMenu("mainmenu");
    gme::Scene *ataque_scene = new sceneEntregable2("ataque");
    
    
    gme::Game::setCurrentScene("ataque");
}



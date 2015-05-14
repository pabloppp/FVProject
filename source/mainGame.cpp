#include "mainGame.hpp"

#include "sceneSplash.hpp"
#include "sceneMenu.hpp"
#include "tilerJsonLoadScene.hpp"
#include "transitionScene.hpp"
#include "oleada2.hpp"

void mainGame::setup() {
    
    //debugColliders = true;
    
    //BACKGROUND
    gme::Game::newTexture("resources/BGs/jungle_sky.png", "skyTexture");
    gme::Game::newTexture("resources/BGs/jungle_frontA.png", "bgFrontATexture");
    gme::Game::newTexture("resources/BGs/jungle_frontB.png", "bgFrontBTexture");
    gme::Game::newTexture("resources/BGs/jungle_frontC.png", "bgFrontCTexture");
    gme::Game::newTexture("resources/BGs/jungle_midA.png", "bgMidATexture");
    gme::Game::newTexture("resources/BGs/jungle_midB.png", "bgMidBTexture");
    gme::Game::newTexture("resources/BGs/jungle_midC.png", "bgMidCTexture");
    
    gme::Game::newTexture("resources/BGs/fondoSplash.png", "fondoSplash");  
    gme::Game::newTexture("resources/BGs/fondonuevo.png", "fondo_principal");
    gme::Game::newTexture("resources/BGs/gato.png", "logo");
    gme::Game::newTexture("resources/Effects/no.png", "no_icon");
    
    //TILESETS
    gme::Game::newTexture("resources/maps/Tileset.png", "selvaTiles");
    
    
    gme::Game::newTexture("resources/Weapons/soldier_gun.png", "gun");
    gme::Game::newTexture("resources/Bullets/Bullet2.png", "bullet");
    
    gme::Game::newTexture("resources/Effects/blood_particle.png", "spray_particle"); 
    
    gme::Game::newTexture("resources/Enemies/sprites/walk_spr/sprites.png", "dino00");
    gme::Game::newTexture("resources/sprites/boss00.png","boss00");
    gme::Game::newTexture("resources/Others/caja.png","boxes");
    
    
    gme::Game::newTexture("resources/Others/indicator_0.png", "indicator_enemy"); 
    gme::Game::newTexture("resources/Others/indicator_1.png", "indicator_box");
    gme::Game::newTexture("resources/Others/heart.png", "heart");   
    
    gme::Game::newTexture("resources/sprites/player_spr/player_sheet.png", "playerTexture");
    gme::Game::newTexture("resources/sprites/player1_spr/player1_sheet.png", "player1Texture");
    
    //BALAS
    gme::Game::newTexture("resources/Bullets/fthrower.png", "fthrower_bullet");
    gme::Game::newTexture("resources/Bullets/shotgun.png", "escopeta_bullet");
    
    
    //SONIDOS 
    gme::Game::newMusic("resources/Sounds/chores_rules.wav", "sound");
    gme::Game::newMusic("resources/Sounds/boton.wav", "boton");
    gme::Game::newMusic("resources/Sounds/deslizamiento.wav", "desplazamiento");
    
    gme::Game::newMusic("resources/Sounds/shot.wav", "gunShot");
    gme::Game::newMusic("resources/Sounds/jungle.wav","jungle");
    
    //SONIDOS
    
    
    gme::Scene *splash_scene = new sceneSplash("splash");
    gme::Scene *mainmenu_scene = new sceneMenu("mainmenu");
    
    gme::Scene *trscene = new transitionScene("transition");
    
    /* AQUI LAS ESCENAS/OLEADAS */
    gme::Scene *tiledTest = new tilerJsonLoadScene("oleada1");
    gme::Scene *scene_oleada2 = new oleada2("oleada2");   
    
    
    gme::Game::setCurrentScene("splash");
}



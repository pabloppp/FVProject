#include "mainGame.hpp"

#include "sceneSplash.hpp"
#include "sceneMenu.hpp"
#include "tilerJsonLoadScene.hpp"
#include "transitionScene.hpp"
#include "oleada2.hpp"
#include "oleada3.hpp"

#include <fstream>

void mainGame::setup() {
    
    //debugColliders = true;
    loadOpts();

    gme::Game::newTexture("resources/BGs/fondoSplash.jpg", "fondoSplash");  
    gme::Game::newTexture("resources/BGs/fondonuevo.png", "fondo_principal");
    gme::Game::newTexture("resources/BGs/gato.png", "logo");
    gme::Game::newTexture("resources/BGs/fondo_menu.png", "fondo_menu");
    gme::Game::newTexture("resources/Effects/no.png", "no_icon"); 
    gme::Game::newTexture("resources/BGs/titulo.png", "title");
    gme::Game::newTexture("resources/BGs/cartel_lose.png", "cartel_lose");
    gme::Game::newTexture("resources/BGs/cartel_win.png", "cartel_win");

    //BACKGROUND
    gme::Game::newTexture("resources/BGs/jungle_sky.png", "skyTexture");
    gme::Game::newTexture("resources/BGs/jungle_frontA.png", "bgFrontATexture");
    gme::Game::newTexture("resources/BGs/jungle_frontB.png", "bgFrontBTexture");
    gme::Game::newTexture("resources/BGs/jungle_frontC.png", "bgFrontCTexture");
    gme::Game::newTexture("resources/BGs/jungle_midA.png", "bgMidATexture");
    gme::Game::newTexture("resources/BGs/jungle_midB.png", "bgMidBTexture");
    gme::Game::newTexture("resources/BGs/jungle_midC.png", "bgMidCTexture");
    
    //INTERFAZ
    gme::Game::newTexture("resources/Interface/interfaz_P1.png", "interface_p1");
    gme::Game::newTexture("resources/Interface/interfaz_P2.png", "interface_p2");
    gme::Game::newTexture("resources/Interface/max-willis-2.png", "max-willis");
    gme::Game::newTexture("resources/Interface/pistola-inter.png", "pistola-inter");
    gme::Game::newTexture("resources/Interface/pistola-inter.png", "metralleta-inter");
    gme::Game::newTexture("resources/Interface/pistola-inter.png", "escopeta-inter");
    gme::Game::newTexture("resources/Interface/pistola-inter.png", "llamas-inter");
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
    
    gme::Game::newTexture("resources/Effects/smallExplosion.png", "explosion_small");
    
    //SONIDOS
    
    gme::Game::newMusic("resources/Sounds/chores_rules.wav", "sound");
    gme::Game::newMusic("resources/Sounds/boton.wav", "boton");
   // gme::Game::newMusic("resources/Sounds/Jungle.wav", "jungle");
    gme::Game::newMusic("resources/Sounds/deslizamiento.wav", "desplazamiento");
    
        //ARMAS
    gme::Game::newMusic("resources/Sounds/shot.wav", "gunShot");
    
    gme::Game::newMusic("resources/Sounds/metralleta.wav", "metralletaShot");
    gme::Game::newMusic("resources/Sounds/metralletaReload.wav","metralletaReload");
    
    gme::Game::newMusic("resources/Sounds/lanzallamas.wav", "lanzallamasShot");
    gme::Game::newMusic("resources/Sounds/lanzallamasReload.wav","lanzallamasReload");
    
    gme::Game::newMusic("resources/Sounds/escopeta.wav", "escopetaShot");
    gme::Game::newMusic("resources/Sounds/escopetaReload.wav", "escopetaReload");
    
        //COLAIDERS
    
    gme::Game::newMusic("resources/Sounds/cajaRota.wav","cajaRota");
    
    
        //AMBIENTE
    gme::Game::newMusic("resources/Sounds/Jungle.wav", "jungle");
    
    
        //PERSONAJE
    gme::Game::newMusic("resources/Sounds/footsteps.wav","footsteps");
    gme::Game::newMusic("resources/Sounds/salto.wav","jump");
    
    jungleFondo_sound = new gme::MusicPlayer();
    jungleFondo_sound->setMusic("jungle");
    
    jungleFondo_sound->play();
    jungleFondo_sound->loop(true);
    
    if(music)jungleFondo_sound->setVolume(20.0);
    else jungleFondo_sound->setVolume(0.0);
    
    
    
    
    //SONIDOS
    
    //PRE ESCENAS
    gme::Scene *splash_scene = new sceneSplash("splash");
    gme::Scene *mainmenu_scene = new sceneMenu("mainmenu");
    
    gme::Scene *trscene = new transitionScene("transition");
    
    /* AQUI LAS ESCENAS/OLEADAS */
    gme::Scene *tiledTest = new tilerJsonLoadScene("oleada1");
    gme::Scene *scene_oleada2 = new oleada2("oleada2");   
    gme::Scene *scene_oleada3 = new oleada3("oleada3"); 
    
    gme::Game::setCurrentScene("mainmenu");
}

void mainGame::saveOpts() {
    std::ofstream myfile ("global.conf");
    if(myfile.is_open()){
        if(music) myfile << "music true\n";
        else myfile << "music false\n";
        
        if(sound) myfile << "sound true\n";
        else myfile << "sound false\n";
        
        if(fullscreen) myfile << "fullscreen true\n";
        else myfile << "fullscreen false\n";
        
        if(particles == 2) myfile << "particles high";
        else if(particles == 1) myfile << "particles low";
        else myfile << "particles none";
        
        myfile.close();
    }
}

void mainGame::loadOpts() {
    std::string str;
    std::ifstream infile;
    infile.open("global.conf");
    if(infile.is_open()){
        while(!infile.eof()){
            getline(infile, str);
            std::string opt = str.substr(0, str.find(" "));
            str = str.erase(0, str.find(" ")+1);
            std::string val = str.substr(0, str.find(" "));
            std::cout <<opt << ": " << val << std::endl;
            
            if(opt.compare("music") == 0){
                if(val.compare("false") == 0) music = false;
            }
            if(opt.compare("sound") == 0){
                if(val.compare("false") == 0) sound = false;
            }
            if(opt.compare("fullscreen") == 0){
                if(val.compare("false") == 0) fullscreen = false;
            }
            if(opt.compare("particles") == 0){
                if(val.compare("low") == 0) particles = 1;
                else if(val.compare("none") == 0) particles = 0;
            }
        }
        infile.close();
    }
    else saveOpts();
    
}



bool mainGame::coop = false;
bool mainGame::music = true;
bool mainGame::sound = true;
bool mainGame::fullscreen = true;
int mainGame::particles = 2;

gme::MusicPlayer *mainGame::jungleFondo_sound;
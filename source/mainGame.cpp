#include "mainGame.hpp"

#include "sceneSplash.hpp"
#include "sceneMenu.hpp"
#include "tilerJsonLoadScene.hpp"
#include "transitionScene.hpp"
#include "oleada2.hpp"
#include "oleada3.hpp"
#include "oleada4.hpp"
#include "oleada5.hpp"
#include "oleada6.hpp"
#include "oleada7.hpp"
#include "oleada8.hpp"
#include "oleada9.hpp"
#include "oleada10.hpp"

#include <fstream>

void mainGame::setup() {
    
    debugColliders = true;
    
    loadOpts();
    loadProfile();
    loadPoints();

    gme::Game::newTexture("resources/BGs/fondoSplash.jpg", "fondoSplash");  
    gme::Game::newTexture("resources/BGs/fondonuevo.png", "fondo_principal");
    gme::Game::newTexture("resources/BGs/gato.png", "logo");
    gme::Game::newTexture("resources/BGs/fondo_menu.png", "fondo_menu");
    gme::Game::newTexture("resources/Effects/no.png", "no_icon"); 
    gme::Game::newTexture("resources/BGs/titulo.png", "title");
    gme::Game::newTexture("resources/BGs/cartel_lose.png", "cartel_lose");
    gme::Game::newTexture("resources/BGs/cartel_win.png", "cartel_win");
    gme::Game::newTexture("resources/BGs/Ready.png", "ready");
    gme::Game::newTexture("resources/BGs/Go.png", "go");

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
    gme::Game::newTexture("resources/Enemies/fly.png","fly");
    gme::Game::newTexture("resources/Enemies/sprites/expl_spr/sprites.png", "dino_explosive");
    gme::Game::newTexture("resources/Others/caja.png","boxes");
    
    
    gme::Game::newTexture("resources/Others/indicator_0.png", "indicator_enemy"); 
    gme::Game::newTexture("resources/Others/indicator_1.png", "indicator_box");
    gme::Game::newTexture("resources/Others/heart.png", "heart");   
    
    gme::Game::newTexture("resources/sprites/player_spr/player_sheet.png", "playerTexture");
    gme::Game::newTexture("resources/sprites/player1_spr/player1_sheet.png", "player1Texture");
    
    gme::Game::newTexture("resources/sprites/chica.png", "chicaJetpack");
    
    //BALAS
    gme::Game::newTexture("resources/Bullets/fthrower.png", "fthrower_bullet");
    gme::Game::newTexture("resources/Bullets/shotgun.png", "escopeta_bullet");
    gme::Game::newTexture("resources/Bullets/grenade.png", "grenade");
    
    gme::Game::newTexture("resources/Effects/smallExplosion.png", "explosion_small");
    gme::Game::newTexture("resources/Effects/Noisy Cricket Ball.png", "explosion_teleport");
    gme::Game::newTexture("resources/Effects/ExplosionBallFlame.png", "explosion_big");
    
    //SONIDOS
    
    gme::Game::newMusic("resources/Sounds/chores_rules.wav", "sound");
    gme::Game::newSound("resources/Sounds/boton.wav", "boton");
   // gme::Game::newMusic("resources/Sounds/Jungle.wav", "jungle");
    gme::Game::newSound("resources/Sounds/deslizamiento.wav", "desplazamiento");
    
    
        //JUEGO
    gme::Game::newSound("resources/Sounds/introCancion.wav","introCancion");
    gme::Game::newMusic("resources/Sounds/cancion.wav","cancion");
    gme::Game::newSound("resources/Sounds/Ready2.wav","ready_sound");
        //ARMAS
    gme::Game::newSound("resources/Sounds/shot.wav", "gunShot");
    
    gme::Game::newSound("resources/Sounds/metralleta.wav", "metralletaShot");
    gme::Game::newSound("resources/Sounds/metralletaReload.wav","metralletaReload");
    
    gme::Game::newSound("resources/Sounds/lanzallamas.wav", "lanzallamasShot");
    gme::Game::newSound("resources/Sounds/lanzallamasReload.wav","lanzallamasReload");
    
    gme::Game::newSound("resources/Sounds/escopeta.wav", "escopetaShot");
    gme::Game::newSound("resources/Sounds/escopetaReload.wav", "escopetaReload");
    
    gme::Game::newSound("resources/Sounds/granada.wav", "granada");
    
    
        //NOMBRES COLAIDERS
    
    gme::Game::newSound("resources/Sounds/EscopetaFrase.wav", "escopetaFrase");
    gme::Game::newSound("resources/Sounds/MetralletaFrase.wav", "metralletaFrase");
    gme::Game::newSound("resources/Sounds/LanzallamasFrase.wav", "lanzallamasFrase");
    gme::Game::newSound("resources/Sounds/PistolaFrase.wav", "pistolaFrase");
    gme::Game::newSound("resources/Sounds/NuevaVidaFrase.wav", "nuevaVidaFrase");
    gme::Game::newSound("resources/Sounds/HPFrase.wav", "HPFrase");
    
        //COLAIDERS
    
    gme::Game::newSound("resources/Sounds/cajarota.wav","cajaRota");
    
        //BLOQUES   
    gme::Game::newSound("resources/Sounds/bloque.wav", "bloque");
    //gme::Game::newSound("resources/Sounds/bloque.wav","b");
    
        //AMBIENTE
    gme::Game::newMusic("resources/Sounds/Jungle1.wav", "jungle");
    
    
        //PERSONAJE
    gme::Game::newSound("resources/Sounds/footsteps.wav","footsteps");
    gme::Game::newSound("resources/Sounds/salto.wav","jump");
    gme::Game::newSound("resources/Sounds/danyo1.wav","danyo1");
    gme::Game::newSound("resources/Sounds/malditasea.wav","malditasea");
    gme::Game::newSound("resources/Sounds/ohyeah.wav","ohyeah");
    gme::Game::newSound("resources/Sounds/frase1.wav","frase1");
    
        //ENEMIGOS
    gme::Game::newSound("resources/Sounds/danyo2.wav","danyo2");
    gme::Game::newSound("resources/Sounds/explosiondino.wav","explosionEnemigo");
    gme::Game::newSound("resources/Sounds/flySound.wav","flySound");
    
       //CHICA
    
    gme::Game::newSound("resources/Sounds/laserShot.wav","laserShot");
    gme::Game::newSound("resources/Sounds/laserCarga.wav","laserCarga");
    gme::Game::newSound("resources/Sounds/jetpack.wav","jetpack");
    gme::Game::newSound("resources/Sounds/teletransport.wav","teletransport");
    
    
    
            
            
    jungleFondo_sound = new gme::MusicPlayer();
    jungleFondo_sound->setMusic("jungle");
    
    jungleFondo_sound->play();
    jungleFondo_sound->loop(true);
    
    if(music)jungleFondo_sound->setVolume(20.0);
    else jungleFondo_sound->setVolume(0.0);
    
    //PRE ESCENAS
    gme::Scene *splash_scene = new sceneSplash("splash");
    gme::Scene *mainmenu_scene = new sceneMenu("mainmenu");
    
    gme::Scene *trscene = new transitionScene("transition");
    
    /* AQUI LAS ESCENAS/OLEADAS */
    gme::Scene *tiledTest = new tilerJsonLoadScene("oleada1");
    gme::Scene *scene_oleada2 = new oleada2("oleada2");   
    gme::Scene *scene_oleada3 = new oleada3("oleada3"); 
    gme::Scene *scene_oleada4 = new oleada4("oleada4");   
    gme::Scene *scene_oleada5 = new oleada5("oleada5"); 
    gme::Scene *scene_oleada6 = new oleada6("oleada6"); 
    gme::Scene *scene_oleada7 = new oleada7("oleada7");   
    gme::Scene *scene_oleada8 = new oleada8("oleada8");
    gme::Scene *scene_oleada9 = new oleada9("oleada9");   
    gme::Scene *scene_oleada10 = new oleada10("oleada10");
    
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

void mainGame::loadProfile() {
    std::string str;
    std::ifstream infile;
    infile.open("profile.conf");
    if(infile.is_open()){
        while(!infile.eof()){
            getline(infile, str);
            std::string opt = str.substr(0, str.find(" "));
            str = str.erase(0, str.find(" ")+1);
            std::string val = str.substr(0, str.find(" "));
            std::cout <<opt << ": " << val << std::endl;
            
            if(opt.compare("level") == 0){
                continueLevel = atoi(val.c_str());
            }
            //WEAPONS
            if(opt.compare("machinegun") == 0){
                if(val.compare("unlocked") == 0) machinegun = true;
            }
            if(opt.compare("shotgun") == 0){
                if(val.compare("unlocked") == 0) shotgun = true;
            }
            if(opt.compare("snipper") == 0){
                if(val.compare("unlocked") == 0) snipper = true;
            }
            if(opt.compare("flamethrower") == 0){
                if(val.compare("unlocked") == 0) flamethrower = true;
            }
            if(opt.compare("bazooka") == 0){
                if(val.compare("unlocked") == 0) bazooka = true;
            }
            
            //PJ
            if(opt.compare("will") == 0){
                if(val.compare("unlocked") == 0) will = true;
            }
            if(opt.compare("marty") == 0){
                if(val.compare("unlocked") == 0) marty = true;
            }
            if(opt.compare("drwho") == 0){
                if(val.compare("unlocked") == 0) drwho = true;
            }
            
            //STATS
            if(opt.compare("kills") == 0){
                kills = atoi(val.c_str());
            }
            if(opt.compare("deaths") == 0){
                deaths = atoi(val.c_str());
            }
            if(opt.compare("brokentiles") == 0){
                brokentiles = atoi(val.c_str());
            }
            if(opt.compare("victories") == 0){
                victories = atoi(val.c_str());
            }
            if(opt.compare("levelspassed") == 0){
                levelspassed = atoi(val.c_str());
            }
            if(opt.compare("newgames") == 0){
                newgames = atoi(val.c_str());
            }
            
        }
        infile.close();
    }
    else saveProfile();
}

void mainGame::saveProfile() {
    std::ofstream myfile ("profile.conf");
    if(myfile.is_open()){
        myfile << "level "<< continueLevel << "\n";
        
        if(machinegun) myfile << "machinegun unlocked\n";
        else myfile << "machinegun locked\n";
        if(shotgun) myfile << "shotgun unlocked\n";
        else myfile << "shotgun locked\n";
        if(flamethrower) myfile << "flamethrower unlocked\n";
        else myfile << "flamethrower locked\n";
        if(snipper) myfile << "snipper unlocked\n";
        else myfile << "snipper locked\n";
        if(bazooka) myfile << "bazooka unlocked\n";
        else myfile << "bazooka locked\n";
        if(will) myfile << "will unlocked\n";
        else myfile << "will locked\n";
        if(marty) myfile << "marty unlocked\n";
        else myfile << "marty locked\n";
        if(drwho) myfile << "drwho unlocked\n";
        else myfile << "drwho locked\n";
        
        myfile << "kills "<< kills << "\n";
        myfile << "deaths "<< deaths << "\n";
        myfile << "brokentiles "<< brokentiles << "\n";
        myfile << "victories "<< victories << "\n";
        myfile << "newgames "<< newgames << "\n";
        myfile << "levelspassed "<< levelspassed;
        myfile.close();
    }
}

void mainGame::loadPoints() {
    std::string str;
    std::ifstream infile;
    infile.open("scores.conf");
    if(infile.is_open()){
        while(!infile.eof()){
            getline(infile, str);
            std::string opt = str.substr(0, str.find(" "));
            str = str.erase(0, str.find(" ")+1);
            std::string val = str.substr(0, str.find(" "));
            std::cout <<opt << ": " << val << std::endl;
            
            if(opt.compare("lvl1") == 0){
                maxpoints[0] = atoi(val.c_str());
            }
            if(opt.compare("lvl2") == 0){
                maxpoints[1] = atoi(val.c_str());
            }
            if(opt.compare("lvl3") == 0){
                maxpoints[2] = atoi(val.c_str());
            }
            if(opt.compare("lvl4") == 0){
                maxpoints[3] = atoi(val.c_str());
            }
            if(opt.compare("lvl5") == 0){
                maxpoints[4] = atoi(val.c_str());
            }
            if(opt.compare("lvl6") == 0){
                maxpoints[5] = atoi(val.c_str());
            }
            if(opt.compare("lvl7") == 0){
                maxpoints[6] = atoi(val.c_str());
            }
            if(opt.compare("lvl8") == 0){
                maxpoints[7] = atoi(val.c_str());
            }
            if(opt.compare("lvl9") == 0){
                maxpoints[8] = atoi(val.c_str());
            }
            if(opt.compare("lvl10") == 0){
                maxpoints[9] = atoi(val.c_str());
            }

        }
        infile.close();
    }
    else savePoints();
}

void mainGame::savePoints() {
    std::ofstream myfile ("scores.conf");
    if(myfile.is_open()){
        myfile << "lvl1 "<< maxpoints[0] << "\n";
        myfile << "lvl2 "<< maxpoints[1] << "\n";
        myfile << "lvl3 "<< maxpoints[2] << "\n";
        myfile << "lvl4 "<< maxpoints[3] << "\n";
        myfile << "lvl5 "<< maxpoints[4] << "\n";
        myfile << "lvl6 "<< maxpoints[5] << "\n";
        myfile << "lvl7 "<< maxpoints[6] << "\n";
        myfile << "lvl8 "<< maxpoints[7] << "\n";
        myfile << "lvl9 "<< maxpoints[8] << "\n";
        myfile << "lvl10 "<< maxpoints[9];
        
        myfile.close();
    }
}





bool mainGame::coop = false;
bool mainGame::music = true;
bool mainGame::sound = true;
bool mainGame::fullscreen = true;
int mainGame::particles = 2;
int mainGame::continueLevel = 1;
bool mainGame::machinegun = false;
bool mainGame::shotgun = false;
bool mainGame::flamethrower = false;
bool mainGame::bazooka = false;
bool mainGame::snipper = false;
bool mainGame::will = false;
bool mainGame::marty = false;
bool mainGame::drwho = false;
/* USER DATA */
int mainGame::kills = 0;
int mainGame::brokentiles = 0;
int mainGame::victories = 0;
int mainGame::newgames = 0;
int mainGame::levelspassed = 0;
int mainGame::deaths = 0;

int mainGame::maxpoints[] = {0,0,0,0,0,0,0,0,0,0};

gme::MusicPlayer *mainGame::jungleFondo_sound;
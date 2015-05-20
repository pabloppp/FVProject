#include "MainMenuSetup.hpp"
#include "mainGame.hpp"
#include "tilerJsonLoadScene.hpp"
#include "oleada2.hpp"
#include "oleada3.hpp"
#include "oleada4.hpp"
#include "oleada5.hpp"
#include "oleada6.hpp"
#include "oleada7.hpp"
#include "oleada8.hpp"
#include "oleada9.hpp"
#include "oleada10.hpp"

void MainMenuSetup::setup() {
    w = gme::Game::getWindow();
    menu = 1;
    posX = 512;
    num_apre = 0;
    num_apre_ini = 0;
    
    if(mainGame::continueLevel > 1) num_apre_ini = 1; 
        
    reloj_fondo.restart();
    entered = true;
    izq=false; dre=false;
    button_sound = new gme::SoundPlayer();
    button_sound->setSound("boton");
    button_sound->setVolume(100.0);   
}

void MainMenuSetup::update() {
    movement();
}

void MainMenuSetup::movement() {    
    
    if(reloj_fondo.currentTime().asSeconds() > 0.01){
        getTransform()->translate(gme::Vector2(-x, 0));
        if(getTransform()->position.x <= -320) getTransform()->position.x = 960-x;
        reloj_fondo.restart();
    }
    /* MOVIMIENTO A LA IZQUIERDA */
    if(izq==true && apretar.currentTime().asSeconds()<1) { 
        posX=posX-30;
        apretar.restart();
        if(posX < -155) izq=false;
    }
    /* MOVIMIENTO A LA DERECHA */
    if(dre==true && apretar.currentTime().asSeconds()<1) { 
        posX=posX+30;
        apretar.restart();
        if(posX > 482) {dre=false; menu=1;}
    }
    /* CERRAR JUEGO */
    if(menu==1 && num_apre_ini==3 && gme::Keyboard::isKeyPressed(introKey)) w->close();
    
    /* ENTRAR EN OPCIONES */
    if(menu==1 && num_apre_ini==2 && gme::Keyboard::isKeyPressed(introKey)){ 
       izq=true;
       menu=2;
       num_apre=0;
       entered = true;
    }
    /* CONTINUA JUEGO */
    if(menu==1 && num_apre_ini==1 && gme::Keyboard::isKeyPressed(introKey)){
       continueLevel = true;
       izq=true;
       menu=3;
       entered = true;
       num_apre=0;
    } 
    /* ENTRAR EN NUEVA PARTIDA */
    if(menu==1 && num_apre_ini==0 && gme::Keyboard::isKeyPressed(introKey)){
       continueLevel = false;
       izq=true;
       menu=3;
       entered = true;
       num_apre=0;
    }
    //OPCIONES - OPCION SOUND
    if(menu==2 && (num_apre==0 && gme::Keyboard::isKeyPressed(introKey)) && !entered){ 
       if(mainGame::sound) button_sound->play();
       mainGame::sound = !mainGame::sound;    
       entered = true;
       mainGame::saveOpts();
    }
    //OPCIONES - OPCION MUSIC
    if(menu==2 && (num_apre==1 && gme::Keyboard::isKeyPressed(introKey)) && !entered){ 
       if(mainGame::sound) button_sound->play();
       mainGame::music = !mainGame::music;  
       
       if(mainGame::music) mainGame::jungleFondo_sound->setVolume(20.0);
       else if(!mainGame::music) mainGame::jungleFondo_sound->setVolume(0.0);
       entered = true;
       mainGame::saveOpts();
    }
    //OPCIONES - OPCION PARTICLES
    if(menu==2 && (num_apre==2 && gme::Keyboard::isKeyPressed(introKey)) && !entered){ 
       if(mainGame::sound) button_sound->play();
       mainGame::particles -= 1;    
       if(mainGame::particles < 0) mainGame::particles = 2;
       entered = true;
       mainGame::saveOpts();
    }
    /* VOLVER DESDE OPCIONES */    
    if(menu==2 && (num_apre==3 && gme::Keyboard::isKeyPressed(introKey))){ 
       dre=true;    
    }
    /* VOLVER DESDE NUEVA PARTIDA */
    if(menu==3 && (num_apre==2 && gme::Keyboard::isKeyPressed(introKey))){
       dre=true;    
    }
    // INICIAR JUEGO INDIVIDUAL 
    if(menu==3 && (num_apre==0 && gme::Keyboard::isKeyPressed(introKey)) && !entered){
       //music_jungle->stop();
       mainGame::coop = false;
       loadLevel();
    }
     if(menu==3 && (num_apre==1 && gme::Keyboard::isKeyPressed(introKey)) && !entered){
       //music_jungle->stop();
       mainGame::coop = true;
       loadLevel();
       
    }
    if(entered && ! gme::Keyboard::isKeyPressed(introKey)) entered = false;
}

void MainMenuSetup::loadLevel() {
    int lvl = mainGame::continueLevel;
    std::string lvl_s = "";
    if(!continueLevel || lvl == 1){
        if(!continueLevel){
            mainGame::newgames += 1;
            mainGame::saveProfile();
        }
        lvl_s = "oleada1";
    }
    else if(lvl == 2) lvl_s = "oleada2";
    else if(lvl == 3) lvl_s = "oleada3";
    else if(lvl == 4) lvl_s = "oleada4";
    else if(lvl == 5) lvl_s = "oleada5";
    else if(lvl == 6) lvl_s = "oleada6";
    else if(lvl == 7) lvl_s = "oleada7";
    else if(lvl == 8) lvl_s = "oleada8";
    else if(lvl == 9) lvl_s = "oleada9";
    else if(lvl == 10) lvl_s = "oleada10";
    //if(continueLevel || lvl == 1) 
    gme::Scene *olds = mainGame::removeScene(lvl_s);
    gme::Scene *s = mainGame::getScene(lvl_s);
    if(!s || s == NULL){
        gme::Scene *tiledTest;
        if(!continueLevel || lvl == 1) tiledTest = new tilerJsonLoadScene(lvl_s);
        else if(lvl == 2) tiledTest = new oleada2(lvl_s);
        else if(lvl == 3) tiledTest = new oleada3(lvl_s);
        else if(lvl == 4) tiledTest = new oleada4(lvl_s);
        else if(lvl == 5) tiledTest = new oleada5(lvl_s);
        else if(lvl == 6) tiledTest = new oleada6(lvl_s);
        else if(lvl == 7) tiledTest = new oleada7(lvl_s);
        else if(lvl == 8) tiledTest = new oleada8(lvl_s);
        else if(lvl == 9) tiledTest = new oleada9(lvl_s);
        else if(lvl == 10) tiledTest = new oleada10(lvl_s);
        mainGame::setCurrentScene(tiledTest);  
    }
    else mainGame::setCurrentScene(lvl_s);
}

void MainMenuSetup::onGui() {
    gme::GUI::fontSize = 28;
    //Titulo de juego  
    gme::GUI::drawTexture(
        gme::Vector2(512,130), 
        gme::Vector2(512,220),
        gme::GUI::TextureName("title"),  
        gme::GUI::Origin::Center,
        gme::GUI::ScaleToFit
    );
    gme::GUI::contentColor = gme::GUI::white;
    gme::GUI::drawTexture(
            gme::Vector2(gme::Mouse::getPosition().x, gme::Mouse::getPosition().y),
            gme::Vector2(20, 20),
            gme::GUI::TextureName("no_icon"),
            gme::GUI::Origin::Center,
            gme::GUI::ScaleToFit
    );
    gme::GUI::fontSize = 17;
    gme::GUI::globalRotation = 1.5;
    gme::GUI::label(
    
        gme::Vector2(512,230), 
        "Ahora con el doble de queso!",
        gme::GUI::Origin::Center     
    );
    gme::GUI::globalRotation = 0;
     gme::GUI::fontSize = 28;
    
    if(menu==1){
        if(gme::Keyboard::isKeyPressed(upKey)){
            if(mainGame::sound) button_sound->play();
            if(apretar.currentTime().asSeconds()>0.2){                
                if(num_apre_ini==0) num_apre_ini=3;
                else num_apre_ini--;
                apretar.restart();
            }
        }
        if(gme::Keyboard::isKeyPressed(downKey)){
            if(mainGame::sound) button_sound->play();
            if(apretar.currentTime().asSeconds()>0.2){
                if(num_apre_ini==3) num_apre_ini=0;
                else num_apre_ini++;
                apretar.restart();
            }
        }
    }
    
    if(num_apre_ini==0){
            gme::GUI::backgroundColor = gme::GUI::blue;
            gme::GUI::contentColor = gme::GUI::white;
    }
    else{
        gme::GUI::backgroundColor = gme::GUI::Color(255,255,255,255);
        gme::GUI::contentColor = gme::GUI::blue;
    }
    
    gme::GUI::box(
            gme::Vector2(posX,280), 
            gme::Vector2(largo,ancho), 
            "NUEVA PARTIDA",
            gme::GUI::Origin::Center    
    );
    
    if(num_apre_ini==1){
            gme::GUI::backgroundColor = gme::GUI::blue;
            gme::GUI::contentColor = gme::GUI::white;
    }
    else{
        gme::GUI::backgroundColor = gme::GUI::Color(255,255,255,255);
        gme::GUI::contentColor = gme::GUI::blue;
    }

    gme::GUI::box(
        gme::Vector2(posX,330), 
        gme::Vector2(largo,ancho), 
        "CONTINUAR",
        gme::GUI::Origin::Center    
    );
    
    if(num_apre_ini==2){
            gme::GUI::backgroundColor = gme::GUI::blue;
            gme::GUI::contentColor = gme::GUI::white;
    }
    else{
        gme::GUI::backgroundColor = gme::GUI::Color(255,255,255,255);
        gme::GUI::contentColor = gme::GUI::blue;
    }

    gme::GUI::box(
        gme::Vector2(posX,380), 
        gme::Vector2(largo,ancho), 
        "OPCIONES",
        gme::GUI::Origin::Center   
    );
    
    if(num_apre_ini==3){
            gme::GUI::backgroundColor = gme::GUI::blue;
            gme::GUI::contentColor = gme::GUI::white;
    }
    else{
        gme::GUI::backgroundColor = gme::GUI::Color(255,255,255,255);
        gme::GUI::contentColor = gme::GUI::blue;
    }

    gme::GUI::box(
        gme::Vector2(posX,430), 
        gme::Vector2(largo, ancho), 
        "SALIR",
        gme::GUI::Origin::Center   
    );
    
    //---------------------OPCIONES--------------------------------------
    if(menu==2){ 
        if(gme::Keyboard::isKeyPressed(upKey)){    
            if(mainGame::sound) button_sound->play();
            if(apretar.currentTime().asSeconds()>0.2){
                if(num_apre==0) num_apre=3;
                else num_apre--;
                apretar.restart();
            }
        }
        if(gme::Keyboard::isKeyPressed(downKey)){   
            if(mainGame::sound) button_sound->play();
            if(apretar.currentTime().asSeconds()>0.2){
                if(num_apre==3) num_apre=0;
                else num_apre++;                
                apretar.restart();
            }
        }    
        if(num_apre==0){
            gme::GUI::backgroundColor = gme::GUI::blue;
            gme::GUI::contentColor = gme::GUI::white;
        }
        else{
            gme::GUI::backgroundColor = gme::GUI::Color(255,255,255,255);
            gme::GUI::contentColor = gme::GUI::blue;
        }    
        std::string s_sounds = "ON";
        if(!mainGame::sound) s_sounds = "OFF";
        gme::GUI::box(
            gme::Vector2(posX+690,280), 
            gme::Vector2(largo+90,ancho), 
            "SONIDOS: "+s_sounds,
            gme::GUI::Origin::Center  
        );
        if(num_apre==1){
        gme::GUI::backgroundColor = gme::GUI::blue;
        gme::GUI::contentColor = gme::GUI::white;
        }
        else{
            gme::GUI::backgroundColor = gme::GUI::Color(255,255,255,255);
            gme::GUI::contentColor = gme::GUI::blue;
        }    
        std::string s_music = "ON";
        if(!mainGame::music) s_music = "OFF";
        gme::GUI::box(
            gme::Vector2(posX+690,330), 
            gme::Vector2(largo+90,ancho), 
            "MUSICA: "+s_music,
            gme::GUI::Origin::Center    
        );
        if(num_apre==2){
            gme::GUI::backgroundColor = gme::GUI::blue;
            gme::GUI::contentColor = gme::GUI::white;
        }
        else{
            gme::GUI::backgroundColor = gme::GUI::Color(255,255,255,255);
            gme::GUI::contentColor = gme::GUI::blue;
        }
        std::string s_particles = "HIGH";
        if(mainGame::particles == 1) s_particles = "LOW";
        else if(mainGame::particles == 0) s_particles = "NONE";
        gme::GUI::box(
            gme::Vector2(posX+690,380), 
            gme::Vector2(largo+90,ancho), 
            "PARTICULAS: "+s_particles,
            gme::GUI::Origin::Center   
        );    
        if(num_apre==3){
            gme::GUI::backgroundColor = gme::GUI::blue;
            gme::GUI::contentColor = gme::GUI::white;
        }
        else{
            gme::GUI::backgroundColor = gme::GUI::Color(255,255,255,255);
            gme::GUI::contentColor = gme::GUI::blue;
        }    
        gme::GUI::box(
            gme::Vector2(posX+690,430), 
            gme::Vector2(largo+90, ancho), 
            "VOLVER",
            gme::GUI::Origin::Center   
        );    
    }
    
    //--NUEVA PARTIDA-----------------------    
    if(menu==3){ 
        if(gme::Keyboard::isKeyPressed(upKey)){
            if(mainGame::sound) button_sound->play();
            if(apretar.currentTime().asSeconds()>0.2){
                if(num_apre==0) num_apre=2;
                else num_apre--;                
                apretar.restart();
            }
        }
        if(gme::Keyboard::isKeyPressed(downKey)){
            if(mainGame::sound) button_sound->play();
            if(apretar.currentTime().asSeconds()>0.2){
                if(num_apre==2) num_apre=0;
                else num_apre++;                
                apretar.restart();
            }
        }        
        if(num_apre==0){
            gme::GUI::backgroundColor = gme::GUI::blue;
            gme::GUI::contentColor = gme::GUI::white;
        }
        else{
            gme::GUI::backgroundColor = gme::GUI::Color(255,255,255,255);
            gme::GUI::contentColor = gme::GUI::blue;
        }
        gme::GUI::box(
            gme::Vector2(posX+690,280), 
            gme::Vector2(largo,ancho), 
            "INDIVIDUAL",
            gme::GUI::Origin::Center  
        );
        if(num_apre==1){
            gme::GUI::backgroundColor = gme::GUI::blue;
            gme::GUI::contentColor = gme::GUI::white;
        }
        else{
            gme::GUI::backgroundColor = gme::GUI::Color(255,255,255,255);
            gme::GUI::contentColor = gme::GUI::blue;
        }    
        gme::GUI::box(
            gme::Vector2(posX+690,330), 
            gme::Vector2(largo,ancho), 
            "COOP",
            gme::GUI::Origin::Center  
        );   
        if(num_apre==2){
            gme::GUI::backgroundColor = gme::GUI::blue;
            gme::GUI::contentColor = gme::GUI::white;
        }
        else{
            gme::GUI::backgroundColor = gme::GUI::Color(255,255,255,255);
            gme::GUI::contentColor = gme::GUI::blue;
        }    
        gme::GUI::box(
            gme::Vector2(posX+690,380), 
            gme::Vector2(largo, ancho), 
            "VOLVER",
            gme::GUI::Origin::Center   
        );
    }
}


MainMenuSetup::~MainMenuSetup() {
}


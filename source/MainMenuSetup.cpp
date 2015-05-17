#include "MainMenuSetup.hpp"
#include "mainGame.hpp"
#include "tilerJsonLoadScene.hpp"

void MainMenuSetup::setup() {
    w = gme::Game::getWindow();
    menu = 1;
    posX = 512;
    num_apre = 0;
    num_apre_ini = 0;
    reloj_fondo.restart();
    entered = true;
    izq=false; dre=false; juegoNuevo1p = false; juegoNuevo2p = false;
    button_sound = new gme::SoundPlayer();
    //music_jungle=new gme::MusicPlayer();
    //music_jungle->setMusic("jungle");
   // music_jungle->setVolume(15.0);
    //music_jungle->loop(true);
    button_sound->setSound("boton");
    button_sound->setVolume(50.0);
   // music_jungle->play();
   // if(!mainGame::music) music_jungle->setVolume(0.0);
    
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
        juegoNuevo1p = false;
        juegoNuevo2p = false;
        sendMessage("hideMenu", 0);
    } 
    /* ENTRAR EN NUEVA PARTIDA */
    if(menu==1 && num_apre_ini==0 && gme::Keyboard::isKeyPressed(introKey)){
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
       juegoNuevo1p = true;
       mainGame::coop = false;
       gme::Scene *olds = mainGame::removeScene("oleada1");
       gme::Scene *s = mainGame::getScene("oleada1");
       if(!s || s == NULL){
           gme::Scene *tiledTest = new tilerJsonLoadScene("oleada1");
           mainGame::setCurrentScene(tiledTest);  
       }
       else mainGame::setCurrentScene("oleada1");
    }
     if(menu==3 && (num_apre==1 && gme::Keyboard::isKeyPressed(introKey)) && !entered){
       //music_jungle->stop();
       juegoNuevo2p = true;
       mainGame::coop = true;
       gme::Scene *olds = mainGame::removeScene("oleada1");
       gme::Scene *s = mainGame::getScene("oleada1");
       if(!s || s == NULL){
           gme::Scene *tiledTest = new tilerJsonLoadScene("oleada1");
           mainGame::setCurrentScene(tiledTest);  
       }
       else mainGame::setCurrentScene("oleada1");
    }
    if(entered && ! gme::Keyboard::isKeyPressed(introKey)) entered = false;
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


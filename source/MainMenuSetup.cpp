#include "MainMenuSetup.hpp"

void MainMenuSetup::setup() {
    w = gme::Game::getWindow();
    menu = 1;
    posX = 512;
    reloj_fondo.restart();
    
    izq=false; dre=false; juegoNuevo1p = false; juegoNuevo2p = false;
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
       num_apre=0;
    }
    /* VOLVER DESDE OPCIONES */    
    if(menu==2 && (num_apre==3 && gme::Keyboard::isKeyPressed(introKey))){ 
       dre=true;    
    }
    /* VOLVER DESDE NUEVA PARTIDA */
    if(menu==3 && (num_apre==2 && gme::Keyboard::isKeyPressed(introKey))){
       dre=true;    
    }
    /* INICIAR JUEGO INDIVIDUAL 
    if(menu==3 && (num_apre==0 && gme::Keyboard::isKeyPressed(introKey)) && pausa==false ){
       juegoNuevo1p = true;
       sendMessage("hideMenu",0);
    }
     if(menu==3 && (num_apre==1 && gme::Keyboard::isKeyPressed(introKey)) && pausa==false ){
       juegoNuevo2p = true;
       sendMessage("hideMenu",0);
    }*/
}


void MainMenuSetup::onGui() {
    gme::GUI::fontSize = 28;
    //Titulo de juego  
    /*gme::GUI::drawTexture(
        gme::Vector2(512,130), 
        gme::Vector2(512,220),
        gme::GUI::TextureName("logo"),  
        gme::GUI::Origin::Center,
        gme::GUI::ScaleToFit
    );*/
    gme::GUI::contentColor = gme::GUI::white;
    gme::GUI::drawTexture(
            gme::Vector2(gme::Mouse::getPosition().x, gme::Mouse::getPosition().y),
            gme::Vector2(20, 20),
            gme::GUI::TextureName("no_icon"),
            gme::GUI::Origin::Center,
            gme::GUI::ScaleToFit
    );
    
    gme::GUI::label(
        gme::Vector2(512,230), 
        "MENU",
        gme::GUI::Origin::Center     
    );
    
    if(menu==1){
        if(gme::Keyboard::isKeyPressed(upKey)){
            if(apretar.currentTime().asSeconds()>0.2){
                if(num_apre_ini==0) num_apre_ini=3;
                else num_apre_ini--;
                apretar.restart();
            }
        }
        if(gme::Keyboard::isKeyPressed(downKey)){
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
            if(apretar.currentTime().asSeconds()>0.2){
                if(num_apre==0) num_apre=3;
                else num_apre--;
                apretar.restart();
            }
        }
        if(gme::Keyboard::isKeyPressed(downKey)){              
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
        gme::GUI::box(
            gme::Vector2(posX+690,280), 
            gme::Vector2(largo+90,ancho), 
            "CAMBIAR CONTROLES",
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
            gme::Vector2(largo+90,ancho), 
            "CONFIGURAR SONIDO",
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
            gme::Vector2(largo+90,ancho), 
            "CONFIGURAR EFECTOS",
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
            if(apretar.currentTime().asSeconds()>0.2){
                if(num_apre==0) num_apre=2;
                else num_apre--;                
                apretar.restart();
            }
        }
        if(gme::Keyboard::isKeyPressed(downKey)){
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
            "COLECTIVA",
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


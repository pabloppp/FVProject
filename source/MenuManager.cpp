
#include "MenuManager.hpp"

void MenuManager::setup(){
    w = gme::Game::getWindow();
    /* MUSIC DEFINITION */
    music = new gme::MusicPlayer();
    button_sound = new gme::MusicPlayer();
    change_sound= new gme::MusicPlayer();
    
    music->setMusic("sound");
    button_sound->setMusic("boton");
    change_sound->setMusic("desplazamiento");
    
    button_sound->setVolume(20.0);
    change_sound->setVolume(20.0);
    
    /* BOOLEAN STATES */
    sonando=false;izq=false;dre=false;apretado=false;music_pausa=false;
    pausa=false;
    menudejuego = false;
    juegoNuevo1p = false;
    juegoNuevo2p = false;
    /* CLOCKS */
    reloj_fondo.restart();
    
    /* VARS */
    menu=1;
    posX= 320;
    pausa_visible = 0;
    
    showGameOver = false;
}

void MenuManager::update(){
    /* MUSICA SONANDO */
    /*if(sonando==true){
        music->pause();
        sonando=false;

    }else if(sonando==false){
        music->play();
        music->loop(true);
        sonando=true;
    }*/
    if(pausa && !menudejuego) openPause();
    else if(!pausa && menudejuego) openMenu();
}

void MenuManager::onMessage(std::string m, float v) {
    if(m.compare("openPause")==0) {
        pausa=true;
        menudejuego = false;
        pausa_visible=100;
        num_apre=0;
        if(sonando){
            music_pausa=true;
            music->pause();
        }
    }
    else if(m.compare("openMenu")==0){
        pausa=false;
        menudejuego = true;
        pausa_visible=0;
        if(music_pausa==true){
            music->play();
            music_pausa=false;
        }
        
    }
    else if(m.compare("hidePause") == 0){
        pausa=false;
        pausa_visible=0;
        if(music_pausa==true){
            music->play();
            music_pausa=false;
        }
        sendMessage("resume",0);
    }
    else if(m.compare("hideMenu") == 0){
        menudejuego = false;
        if(sonando) music->pause();
        if(juegoNuevo1p) sendMessage("newGame1p",0);
        else if(juegoNuevo2p) sendMessage("newGame2p",0);
        else sendMessage("resume", 0);
    }
    
    else if(m.compare("gameover") == 0){ 
        showGameOver = true;
    }
    
    else if(m.compare("reset") == 0){ 
        showGameOver = false;
        menudejuego = false;
        pausa = false;
    }
}

void MenuManager::openMenu(){
    /* FONDO MOVIENDOSE */
        if(reloj_fondo.currentTime().asSeconds() > 0.01 && pausa==false){
            getTransform()->translate(gme::Vector2(-x, 0));
            if(getTransform()->position.x <= -320) getTransform()->position.x = 960-x;
            reloj_fondo.restart();
        }
    /* MOVIMIENTO A LA IZQUIERDA */
    if(izq==true && apretar.currentTime().asSeconds()<1) { 
        posX=posX-20;
        apretar.restart();
        if(posX==-320) izq=false;
    }
    /* MOVIMIENTO A LA DERECHA */
    if(dre==true && apretar.currentTime().asSeconds()<1) { 
        posX=posX+20;
        apretar.restart();
        if(posX==320) {dre=false; menu=1;}
    }
    /* CERRAR JUEGO */
    if(menu==1 && num_apre_ini==3 && gme::Keyboard::isKeyPressed(introKey) && pausa==false) w->close();
    
    /* ENTRAR EN OPCIONES */
    if(menu==1 && num_apre_ini==2 && gme::Keyboard::isKeyPressed(introKey) && pausa==false ){       
       change_sound->play();
       izq=true;
       menu=2;
       num_apre=0;
    }
    /* CONTINUA JUEGO */
    if(menu==1 && num_apre_ini==1 && gme::Keyboard::isKeyPressed(introKey) && pausa==false){
        juegoNuevo1p = false;
        juegoNuevo2p = false;
        sendMessage("hideMenu", 0);
    } 
    /* ENTRAR EN NUEVA PARTIDA */
    if(menu==1 && num_apre_ini==0 && gme::Keyboard::isKeyPressed(introKey) && pausa==false){
       change_sound->play();
       izq=true;
       menu=3;
       num_apre=0;
    }
    /* VOLVER DESDE OPCIONES */    
    if(menu==2 && (num_apre==3 && gme::Keyboard::isKeyPressed(introKey)) && pausa==false){ 
       change_sound->play();
       dre=true;    
    }
    /* VOLVER DESDE NUEVA PARTIDA */
    if(menu==3 && (num_apre==2 && gme::Keyboard::isKeyPressed(introKey)) && pausa==false ){
       change_sound->play();
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

void MenuManager::openPause(){
    /*if(pausa==true){
        pausa=false;
        pausa_visible=0;
        if(music_pausa==true){
            music->play();
            music_pausa=false;
        }
    } 
   */
   
    /* CONTINUA JUEGO */
    if(pausa==true &&  num_apre==0 && gme::Keyboard::isKeyPressed(introKey)){
        apretado=true;
        sendMessage("resume", 0);
    }
    if(pausa == true && gme::Keyboard::isKeyPressed(resumeKey)) sendMessage("hidePause", 0);
    
    if(pausa==true && num_apre==1 && gme::Keyboard::isKeyPressed(introKey)) w->close();
    if(!gme::Keyboard::isKeyPressed(introKey) && apretado==true){
           pausa=false;
           pausa_visible=0;
           apretado=false;
           if(music_pausa==true){
               music->play();
               music_pausa=false;
           }
    }
}

void MenuManager::onGui() {
  
  if(showGameOver){
      gme::GUI::backgroundColor = gme::GUI::Color(255,255,255,100);
      gme::GUI::contentColor = gme::GUI::Color(0,0,0);
      gme::GUI::fontSize = 30;
      gme::GUI::box(gme::Vector2((1024/2)-200, (576/2)-100),gme::Vector2(400,200));
      gme::GUI::label(gme::Vector2(1024/2, 576/2), "HAS MUERTO", gme::GUI::Origin::Center );
      gme::GUI::fontSize = 15;
      gme::GUI::label(gme::Vector2(1024/2, 576/2 + 50), "Pulsa ENTER para reiniciar", gme::GUI::Origin::Center );
      return;
  }  
    
  if(!pausa && menudejuego){  
    //------------LOGO------------------
      
      gme::GUI::fontSize = 24;
      
      gme::GUI::drawTexture(
        gme::Vector2(320,130), 
        gme::Vector2(320,220),
        gme::GUI::TextureName("logo"),  
        gme::GUI::Origin::Center,
        gme::GUI::ScaleToFit
          
    );
    //-----------LETRA MENU-------------
    gme::GUI::contentColor = gme::GUI::white;
    gme::GUI::drawTexture(
            gme::Vector2(gme::Mouse::getPosition().x, gme::Mouse::getPosition().y),
            gme::Vector2(20, 20),
            gme::GUI::TextureName("no_icon"),
            gme::GUI::Origin::Center,
            gme::GUI::ScaleToFit
    );
    
    gme::GUI::label(
        gme::Vector2(320,280), 
        "MENU",
        gme::GUI::Origin::Center     
     );
      
    if(menu==1){
            if(gme::Keyboard::isKeyPressed(upKey)){

                if(apretar.currentTime().asSeconds()>0.2){
                    button_sound->play();
                    if(num_apre_ini==0) num_apre_ini=3;
                    else
                        num_apre_ini--;

                    apretar.restart();
                }

            }

            if(gme::Keyboard::isKeyPressed(downKey)){

                if(apretar.currentTime().asSeconds()>0.2){
                    button_sound->play();
                    if(num_apre_ini==3) num_apre_ini=0;
                    else
                        num_apre_ini++;

                    apretar.restart();
                }
            }

        }

        if(num_apre_ini==0){
            gme::GUI::backgroundColor = gme::GUI::blue;
            gme::GUI::contentColor = gme::GUI::white;
            //musicabtn->play();
        }
        else{
            gme::GUI::backgroundColor = gme::GUI::Color(255,255,255,255);
            gme::GUI::contentColor = gme::GUI::blue;
        }
       // gme::GUI::tintColor = gme::GUI::red;

        gme::GUI::box(
            gme::Vector2(posX,320), 
            gme::Vector2(largo,ancho), 
            "NUEVA PARTIDA",
            gme::GUI::Origin::Center
            //gme::GUI::TextureName("logo")    
        );

       if(num_apre_ini==1){
            gme::GUI::backgroundColor = gme::GUI::blue;
            gme::GUI::contentColor = gme::GUI::white;
            //musicabtn->play();
        }
        else{
            gme::GUI::backgroundColor = gme::GUI::Color(255,255,255,255);
            gme::GUI::contentColor = gme::GUI::blue;
        }

        gme::GUI::box(
            gme::Vector2(posX,360), 
            gme::Vector2(largo,ancho), 
            "CONTINUAR",
            gme::GUI::Origin::Center
            //gme::GUI::TextureName("logo")    
        );

        if(num_apre_ini==2){
            gme::GUI::backgroundColor = gme::GUI::blue;
            gme::GUI::contentColor = gme::GUI::white;
           // musicabtn->play();
        }
        else{
            gme::GUI::backgroundColor = gme::GUI::Color(255,255,255,255);
            gme::GUI::contentColor = gme::GUI::blue;
        }

        gme::GUI::box(
            gme::Vector2(posX,400), 
            gme::Vector2(largo,ancho), 
            "OPCIONES",
            gme::GUI::Origin::Center
            //gme::GUI::TextureName("logo")    
        );

        if(num_apre_ini==3){
            gme::GUI::backgroundColor = gme::GUI::blue;
            gme::GUI::contentColor = gme::GUI::white;
            //musicabtn->play();
        }
        else{
            gme::GUI::backgroundColor = gme::GUI::Color(255,255,255,255);
            gme::GUI::contentColor = gme::GUI::blue;
        }

        gme::GUI::box(
            gme::Vector2(posX,440), 
            gme::Vector2(largo, ancho), 
            "SALIR",
            gme::GUI::Origin::Center
            //gme::GUI::TextureName("logo")    
        );
    
    
  }
  
  
 //---------------------OPCIONES-------------------------------------- 
  
  
  if(menu==2 && !pausa && menudejuego){  
      
  
        if(gme::Keyboard::isKeyPressed(upKey)){
            
            if(apretar.currentTime().asSeconds()>0.2){
                button_sound->play();
                if(num_apre==0) num_apre=3;
                else
                    num_apre--;
                
                apretar.restart();
            }

        }

        if(gme::Keyboard::isKeyPressed(downKey)){
              
            if(apretar.currentTime().asSeconds()>0.2){
                button_sound->play();
                if(num_apre==3) num_apre=0;
                else
                    num_apre++;
                
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
   // gme::GUI::tintColor = gme::GUI::red;
    
    gme::GUI::box(
        gme::Vector2(posX+640,320), 
        gme::Vector2(largo+90,ancho), 
        "CAMBIAR CONTROLES",
        gme::GUI::Origin::Center
        //gme::GUI::TextureName("logo")    
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
        gme::Vector2(posX+640,360), 
        gme::Vector2(largo+90,ancho), 
        "CONFIGURAR SONIDO",
        gme::GUI::Origin::Center
        //gme::GUI::TextureName("logo")    
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
        gme::Vector2(posX+640,400), 
        gme::Vector2(largo+90,ancho), 
        "CONFIGURAR EFECTOS",
        gme::GUI::Origin::Center
        //gme::GUI::TextureName("logo")    
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
        gme::Vector2(posX+640,440), 
        gme::Vector2(largo+90, ancho), 
        "VOLVER",
        gme::GUI::Origin::Center
        //gme::GUI::TextureName("logo")    
    );
    
    
  }
    
 //--NUEVA PARTIDA-----------------------
    
     if(menu==3 && !pausa && menudejuego){  
         
        // std::cout <<num_apre << std::endl;
        // std::cout <<menu << std::endl;
  
       if(gme::Keyboard::isKeyPressed(upKey)){
            button_sound->play();
            if(apretar.currentTime().asSeconds()>0.2){

                if(num_apre==0) num_apre=2;
                else
                    num_apre--;
                
                apretar.restart();
            }

        }

        if(gme::Keyboard::isKeyPressed(downKey)){
             button_sound->play();
            if(apretar.currentTime().asSeconds()>0.2){
                if(num_apre==2) num_apre=0;
                else
                    num_apre++;
                
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
        gme::Vector2(posX+640,340), 
        gme::Vector2(largo,ancho), 
        "INDIVIDUAL",
        gme::GUI::Origin::Center
        //gme::GUI::TextureName("logo")    
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
        gme::Vector2(posX+640,380), 
        gme::Vector2(largo,ancho), 
        "COLECTIVA",
        gme::GUI::Origin::Center
        //gme::GUI::TextureName("logo")    
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
        gme::Vector2(posX+640,420), 
        gme::Vector2(largo, ancho), 
        "VOLVER",
        gme::GUI::Origin::Center
        //gme::GUI::TextureName("logo")    
    );
    
  }
    
    if(pausa && !menudejuego){
        
        gme::GUI::contentColor = gme::GUI::white;
        gme::GUI::backgroundColor = gme::GUI::Color(0,0,0,pausa_visible);
        
        gme::GUI::box(
            gme::Vector2(320,240), 
            gme::Vector2(640, 480), 
            "",
            gme::GUI::Origin::Center
        );
        
        gme::GUI::fontSize = 60;
        
        gme::GUI::label(
            gme::Vector2(320,240), 
            "PAUSE",
            gme::GUI::Origin::Center     
        );
        
            if(gme::Keyboard::isKeyPressed(upKey)){
                  button_sound->play();
               if(apretar.currentTime().asSeconds()>0.2){

                   if(num_apre==0) num_apre=1;
                   else
                       num_apre--;

                   apretar.restart();
               }

           }

           if(gme::Keyboard::isKeyPressed(downKey)){
                button_sound->play();
               if(apretar.currentTime().asSeconds()>0.2){
                   if(num_apre==1) num_apre=0;
                   else
                       num_apre++;

                   apretar.restart();
               }
           }
        
         gme::GUI::fontSize = 24;
        
         if(num_apre==0){
            gme::GUI::backgroundColor = gme::GUI::red;
            gme::GUI::contentColor = gme::GUI::white;
            }
        else{
            gme::GUI::backgroundColor = gme::GUI::Color(255,255,255,255);
            gme::GUI::contentColor = gme::GUI::red;
        }
    
        gme::GUI::box(
            gme::Vector2(320,310), 
            gme::Vector2(largo,ancho), 
            "CONTINUAR",
            gme::GUI::Origin::Center
            //gme::GUI::TextureName("logo")    
        );
   
        if(num_apre==1){
            gme::GUI::backgroundColor = gme::GUI::red;
            gme::GUI::contentColor = gme::GUI::white;
        }
        else{
            gme::GUI::backgroundColor = gme::GUI::Color(255,255,255,255);
            gme::GUI::contentColor = gme::GUI::red;
        }
    
        gme::GUI::box(
            gme::Vector2(320,350), 
            gme::Vector2(largo, ancho), 
            "SALIR",
            gme::GUI::Origin::Center
            //gme::GUI::TextureName("logo")    
        );
    }  
}

MenuManager::~MenuManager() {

}

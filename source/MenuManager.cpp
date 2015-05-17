#include "MenuManager.hpp"
#include "sceneMenu.hpp"
#include "mainGame.hpp"

void MenuManager::setup(){
    w = gme::Game::getWindow();
    /* MUSIC DEFINITION */
    music = new gme::MusicPlayer();
    button_sound = new gme::SoundPlayer();
    change_sound= new gme::SoundPlayer();
    
    music->setMusic("sound");
    button_sound->setSound("boton");
    change_sound->setSound("desplazamiento");
    
    button_sound->setVolume(30.0);
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
    showLevelSuccess = false;
    
    manager = (GlobalStateManager*)(gameObject()->getComponent<GlobalStateManager*>());
}

void MenuManager::update(){
    if(pausa && !menudejuego) openPause();
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
    /*else if(m.compare("openMenu")==0){
        pausa=false;
        menudejuego = true;
        pausa_visible=0;
        if(music_pausa==true){
            music->play();
            music_pausa=false;
        }
        
    }*/
    else if(m.compare("hidePause") == 0){
        pausa=false;
        pausa_visible=0;
        sendMessage("resume",0);
    }
    /*else if(m.compare("hideMenu") == 0){
        menudejuego = false;
        if(sonando) music->pause();
        if(juegoNuevo1p) sendMessage("newGame1p",0);
        else if(juegoNuevo2p) sendMessage("newGame2p",0);
        else sendMessage("resume", 0);
    }
    */
    else if(m.compare("gameover") == 0){ 
        showGameOver = true;
    }
    else if(m.compare("reset") == 0){ 
        showGameOver = false;
        menudejuego = false;
        pausa = false;
    }
    else if(m.compare("showLevelSuccess") == 0){
        showGameOver = false;
        showLevelSuccess = true;
        menudejuego = false;
        pausa = false;
        
    }
}

void MenuManager::openMenu(){
    gme::Scene *olds = mainGame::removeScene("mainmenu");
    gme::Scene *olds2 = gme::Game::removeScene(gme::Game::getCurrentScene());
    gme::Scene *mm = new sceneMenu("mainmenu");
    gme::Game::setCurrentScene("mainmenu");
    
}

void MenuManager::openPause(){
    /* CONTINUA JUEGO */
    if(pausa==true &&  num_apre==0 && gme::Keyboard::isKeyPressed(introKey)){
        apretado=true;
        sendMessage("resume", 0);
    }
    if(pausa == true && gme::Keyboard::isKeyPressed(resumeKey)) sendMessage("hidePause", 0);
    if(pausa==true && num_apre==1 && gme::Keyboard::isKeyPressed(introKey)){
        openMenu();
    }
    if(!gme::Keyboard::isKeyPressed(introKey) && apretado==true){
           pausa=false;
           pausa_visible=0;
           apretado=false;
    }
}

void MenuManager::onGui() {
  if(manager->gameType==1){
      int timeLeft = (int)(manager->winCondition-(manager->lastScore+manager->gameClock.currentTime().asSeconds()));
      if(manager->isPaused()) timeLeft = (int)(manager->winCondition-manager->lastScore);
      if(timeLeft < 0) timeLeft = 0;
      int minutes = timeLeft/60;
      int seconds = timeLeft%60;
      gme::GUI::fontSize = 45;
      std::string secondsString = std::to_string(seconds);
      if(secondsString.size() == 1) secondsString = "0"+secondsString;
      gme::GUI::label(gme::Vector2(1024/2, 30), std::to_string(minutes)+":"+secondsString, gme::GUI::Origin::Center);
  }  
  if(showLevelSuccess){
      gme::GUI::drawTexture(
        gme::Vector2(512,288), 
        gme::Vector2(512,288),
        gme::GUI::TextureName("cartel_win"),  
        gme::GUI::Origin::Center,
        gme::GUI::ScaleToFit
      );
      /*gme::GUI::backgroundColor = gme::GUI::Color(255,255,255,100);
      gme::GUI::contentColor = gme::GUI::Color(0,0,0);
      gme::GUI::fontSize = 30;
      gme::GUI::box(gme::Vector2((1024/2)-200, (576/2)-100),gme::Vector2(400,200));
      gme::GUI::label(gme::Vector2(1024/2, 576/2), "HAS GANADO", gme::GUI::Origin::Center );
      gme::GUI::fontSize = 15;
      gme::GUI::label(gme::Vector2(1024/2, 576/2 + 50), "Pulsa ENTER para continuar", gme::GUI::Origin::Center );
     */ return;
  }  
  if(showGameOver){
       gme::GUI::drawTexture(
        gme::Vector2(512,288), 
        gme::Vector2(512,288),
        gme::GUI::TextureName("cartel_lose"),  
        gme::GUI::Origin::Center,
        gme::GUI::ScaleToFit
      );/*
      gme::GUI::backgroundColor = gme::GUI::Color(255,255,255,100);
      gme::GUI::contentColor = gme::GUI::Color(0,0,0);
      gme::GUI::fontSize = 30;
      gme::GUI::box(gme::Vector2((1024/2)-200, (576/2)-100),gme::Vector2(400,200));
      gme::GUI::label(gme::Vector2(1024/2, 576/2), "HAS MUERTO", gme::GUI::Origin::Center );
      gme::GUI::fontSize = 15;
      gme::GUI::label(gme::Vector2(1024/2, 576/2 + 50), "Pulsa ENTER para reiniciar", gme::GUI::Origin::Center );
      */return;
  }  
    
    if(pausa){
        gme::GUI::contentColor = gme::GUI::white;
        gme::GUI::backgroundColor = gme::GUI::Color(0,0,0,pausa_visible);
        
        gme::GUI::box(
            gme::Vector2(512, 288), 
            gme::Vector2(1024, 576), "",
            gme::GUI::Origin::Center
        );
        
        gme::GUI::fontSize = 60;        
        gme::GUI::label(
            gme::Vector2(512, 248), "PAUSA",
            gme::GUI::Origin::Center     
        );
        
        if(gme::Keyboard::isKeyPressed(upKey)){
            if(mainGame::sound) button_sound->play();
            if(apretar.currentTime().asSeconds()>0.2){
                if(num_apre==0) num_apre=1;
                else num_apre--;
                apretar.restart();
            }
        }
        if(gme::Keyboard::isKeyPressed(downKey)){
            if(mainGame::sound) button_sound->play();
            if(apretar.currentTime().asSeconds()>0.2){
                if(num_apre==1) num_apre=0;
                else num_apre++;
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
            gme::Vector2(512, 318), 
            gme::Vector2(largo,ancho), 
            "CONTINUAR",
            gme::GUI::Origin::Center
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
            gme::Vector2(512,358), 
            gme::Vector2(largo, ancho), 
            "SALIR",
            gme::GUI::Origin::Center  
        );
    }  
}

MenuManager::~MenuManager() {

}

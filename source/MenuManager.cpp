#include "MenuManager.hpp"
#include "sceneMenu.hpp"
#include "mainGame.hpp"
#include "GameManager.hpp"

void MenuManager::setup(){
    w = gme::Game::getWindow();
    /* MUSIC DEFINITION */
    intro = new gme::SoundPlayer();
    button_sound = new gme::SoundPlayer();
    change_sound= new gme::SoundPlayer();
    ready_player= new gme::SoundPlayer();
    
    
    intro->setSound("introCancion");
    button_sound->setSound("boton");
    change_sound->setSound("desplazamiento");
    ready_player->setSound("ready_sound");
    musicMain->setMusic("cancion");
    musicMain->loop(true);
    
    
    ready_player->setVolume(100.0);
    intro->setVolume(25.0);
    musicMain->setVolume(25.0);
    button_sound->setVolume(600.0);
    change_sound->setVolume(20.0);
    
    /* BOOLEAN STATES */
    sonando=false;izq=false;dre=false;apretado=false;music_pausa=false;
    pausa=false;
    readygo = false;
    readygoGo = false;
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
    
    kills_10 = kills_100 = kills_200 = kills_300 = kills_400 = kills_500 = kills_600 = false;
    brokentiles_30 = brokentiles_100 = brokentiles_300 = brokentiles_500 = false;
    showNotification = false;
    
    if(mainGame::kills >= 10) kills_10 = true;
    if(mainGame::kills >= 100) kills_100 = true;
    if(mainGame::kills >= 200) kills_200 = true;
    if(mainGame::kills >= 300) kills_300 = true;
    if(mainGame::kills >= 400) kills_400 = true;
    if(mainGame::kills >= 500) kills_500 = true;
    if(mainGame::kills >= 600) kills_600 = true;
    
    if(mainGame::brokentiles >= 30) brokentiles_30 = true;
    if(mainGame::brokentiles >= 100) brokentiles_100 = true;
    if(mainGame::brokentiles >= 300) brokentiles_300 = true;
    if(mainGame::brokentiles >= 500) brokentiles_500 = true;
    
    manager = (GlobalStateManager*)(gameObject()->getComponent<GlobalStateManager*>());
    
    ohyeah_sound = new gme::SoundPlayer();
    ohyeah_sound->setSound("ohyeah");
    ohyeah_sound->setVolume(200.0);
}

void MenuManager::update(){
    readyGo();
    if(pausa){
        openPause();
    } 
    if(!pausa && !ready_player->isPlaying() && mainGame::music) musicMain->play();    
    if(!kills_10 && !showNotification && mainGame::kills >= 10){
        if(mainGame::sound) ohyeah_sound->play();
        kills_10 = true;
        showNotification = true;
        notificationClock.restart();
        notificationTitle = "APRENDIZ DE VETERINARIO";
        notificationText = "Has matado a tus primeros 10 dinosaurios!\nDesbloqueado: Ametralladora";
        mainGame::machinegun = true;
        mainGame::saveProfile();
    }    
    if(!kills_100 && !showNotification && mainGame::kills >= 100){
        if(mainGame::sound) ohyeah_sound->play();
        kills_100 = true;
        showNotification = true;
        notificationClock.restart();
        notificationTitle = "VETERANO JURASICO";
        notificationText = "Brutal! Ya has matado a tus 100 dinosaurios!\nDesbloqueado: Escopeta";
        mainGame::shotgun = true;
        mainGame::saveProfile();
    }
    if(!kills_200 && !showNotification && mainGame::kills >= 200){
        if(mainGame::sound) ohyeah_sound->play();
        kills_200 = true;
        showNotification = true;
        notificationClock.restart();
        notificationTitle = "SIN REMORDIMIENTOS";
        notificationText = "Ya llevas 200 dinosaurios.\nNo te dan pena?";
    }
    if(!kills_300 && !showNotification && mainGame::kills >= 300){
        if(mainGame::sound) ohyeah_sound->play();
        kills_300 = true;
        showNotification = true;
        notificationClock.restart();
        notificationTitle = "CALDO DE POLLO";
        notificationText = "300 pobres dinosaurios y contando.\nSabias que los pollos son dinosaurios?";
    
    }
    if(!kills_400 && !showNotification && mainGame::kills >= 400){
        if(mainGame::sound) ohyeah_sound->play();
        kills_400 = true;
        showNotification = true;
        notificationClock.restart();
        notificationTitle = "FELIZ ANIVERSARIO!";
        notificationText = "Ya has matado a 400...\nRecuerdas cuando solo llevabas 4?";
   
    }
    if(!kills_500 && !showNotification && mainGame::kills >= 500){
        if(mainGame::sound) ohyeah_sound->play();
        kills_500 = true;
        showNotification = true;
        notificationClock.restart();
        notificationTitle = "EXTERMINADOR FEROZ";
        notificationText = "Con 500 dinosaurios muertos deberias ir pensando dejarlo, no?";
 
    }
    if(!kills_600 && !showNotification && mainGame::kills >= 600){
        if(mainGame::sound) ohyeah_sound->play();
        kills_600 = true;
        showNotification = true;
        notificationClock.restart();
        notificationTitle = "HERALDO DEL APOCALIPSIS";
        notificationText = "Has destruido a 600 dinosaurios... \nIlusos los que dijeron que fue un meteorito...";

    }
    if(!brokentiles_30 && !showNotification && mainGame::brokentiles >= 30){
        if(mainGame::sound) ohyeah_sound->play();
        brokentiles_30= true;
        showNotification = true;
        notificationClock.restart();
        notificationTitle = "INICIACION A LA JARDINERIA";
        notificationText = "Has destruido 30 bloques de tierra, que planeas plantar? \nDesbloqueado: Lanzallamas";
        mainGame::flamethrower = true;
        mainGame::saveProfile();
    }
    if(!brokentiles_100 && !showNotification && mainGame::brokentiles >= 100){
        if(mainGame::sound) ohyeah_sound->play();
        brokentiles_100= true;
        showNotification = true;
        notificationClock.restart();
        notificationTitle = "CALENTAMIENTO GLOBAL";
        notificationText = "Destruir 100 bloques de tierra causa que se derritan los polos?";
    }
    if(!brokentiles_300 && !showNotification && mainGame::brokentiles >= 300){
        if(mainGame::sound) ohyeah_sound->play();
        brokentiles_300= true;
        showNotification = true;
        notificationClock.restart();
        notificationTitle = "REMODELADO TOTAL";
        notificationText = "Has destruido 300 bloques... \nTienes algo que comentarle a nuestros diseñadores?";
    }
    if(!brokentiles_500 && !showNotification && mainGame::brokentiles >= 500){
        if(mainGame::sound) ohyeah_sound->play();
        brokentiles_500= true;
        showNotification = true;
        notificationClock.restart();
        notificationTitle = "ANOMALIA TEMPORAL";
        notificationText = "Quien lo diria, has destruido 500 bloques de tierra. \nLos arquelogos del futuro no encontraron ningun fosil.";
    }
    
}

void MenuManager::onMessage(std::string m, float v) {
    if(m.compare("openPause")==0) {
        pausa=true;
        menudejuego = false;
        pausa_visible=100;
        num_apre=0;
        if(mainGame::music) musicMain->pause();
    }
    else if(m.compare("hidePause") == 0){
        pausa=false;
        pausa_visible=0;
        sendMessage("resume",0);
        
    }
    else if(m.compare("readygo") == 0){
        readygo = true;
        if(mainGame::music) intro->play();
        ready_player->play();
    }
    else if(m.compare("gameover") == 0){ 
        showGameOver = true;
        if(mainGame::music) musicMain->stop();
    }
    else if(m.compare("reset") == 0){ 
        showGameOver = false;
        menudejuego = false;
        pausa = false;
        if(mainGame::music) musicMain->play();
    }
    else if(m.compare("showLevelSuccess") == 0){
        showGameOver = false;
        showLevelSuccess = true;
        menudejuego = false;
        pausa = false;
        if(mainGame::music) musicMain->stop();        
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
        if(mainGame::music) musicMain->play();
    }
    if(pausa == true && gme::Keyboard::isKeyPressed(resumeKey)){
        sendMessage("hidePause", 0);        
        if(mainGame::music) musicMain->play();
    }
    if(pausa==true && num_apre==1 && gme::Keyboard::isKeyPressed(introKey)){
        if(mainGame::music) musicMain->stop();
        openMenu();
    }
    if(!gme::Keyboard::isKeyPressed(introKey) && apretado==true){
        pausa=false;
        pausa_visible=0;
        apretado=false;           
        if(mainGame::music) musicMain->play();
    }
}

void MenuManager::readyGo() {
    if(readyClock.currentTime().asSeconds() > 5 && readygo){        
        readygo = false;             
        sendMessage("resume",0);
    } 
}


void MenuManager::onGui() {
  float seconds = 10;  
  if(readygo){      
      if(readyClock.currentTime().asSeconds() < 3){
        gme::GUI::drawTexture(
          gme::Vector2(512,288), 
          gme::Vector2(441,105),
          gme::GUI::TextureName("ready"),  
          gme::GUI::Origin::Center,
          gme::GUI::ScaleToFit
        );
      }
      if(readyClock.currentTime().asSeconds() > 3){
        gme::GUI::drawTexture(
          gme::Vector2(512,288), 
          gme::Vector2(207,102),
          gme::GUI::TextureName("go"),  
          gme::GUI::Origin::Center,
          gme::GUI::ScaleToFit
        );
      }
      
  }
  //NOTIFICATIONS  
  if(showNotification){
   
    int desfase = 0;
    if(notificationClock.currentTime().asSeconds() < 1){
        desfase = 500 - notificationClock.currentTime().asSeconds()*500;
    }
    
    if(notificationClock.currentTime().asSeconds() > seconds-1){
        desfase = 500 - (seconds-notificationClock.currentTime().asSeconds())*500;
    }
    
    gme::GUI::contentColor = gme::GUI::white;
    gme::GUI::backgroundColor = gme::GUI::Color(0,0,0, 200);
    gme::GUI::outlineColor = gme::GUI::Color(255,255,255, 200);
    gme::GUI::outlineThickness = 3;
    gme::GUI::box(
        gme::Vector2(512, 576-120+desfase), 
        gme::Vector2(800, 80), "",
        gme::GUI::Origin::Center
    ); 
    gme::GUI::fontSize = 20;
    gme::GUI::label(gme::Vector2(512, 576-140+desfase), notificationTitle, gme::GUI::Origin::Center );
    gme::GUI::fontSize = 15;
    gme::GUI::label(gme::Vector2(512, 576-130+desfase), notificationText, gme::GUI::Origin::TopCenter );
    
    gme::GUI::outlineThickness = 0;
    if(notificationClock.currentTime().asSeconds() > seconds){
        showNotification = false;
    }
  }  
    
  if(manager->gameType==1){
      int timeLeft = (int)(manager->winCondition-(manager->lastScore+manager->gameClock.currentTime().asSeconds()));
      if(manager->isPaused()) timeLeft = (int)(manager->winCondition-manager->lastScore);
      if(timeLeft < 0) timeLeft = 0;
      int minutes = timeLeft/60;
      int seconds = timeLeft%60;
      gme::GUI::fontSize = 45;
      std::string secondsString = std::to_string(seconds);
      if(secondsString.size() == 1) secondsString = "0"+secondsString;
      gme::GUI::backgroundColor = gme::GUI::Color(0,0,0, 100);      
      gme::GUI::box(
        gme::Vector2(512, 30), 
        gme::Vector2(230, 50), "",
        gme::GUI::Origin::Center
      );
      gme::GUI::label(gme::Vector2(1024/2, 30), std::to_string(minutes)+":"+secondsString, gme::GUI::Origin::Center);
  }  
  else if(manager->gameType==3){
      int kills = mainGame::kills - manager->prevkills;
      int enemiesLeft = (int)(manager->winCondition-kills);
      gme::GUI::fontSize = 38;
      gme::GUI::backgroundColor = gme::GUI::Color(0,0,0, 100);      
      gme::GUI::box(
        gme::Vector2(512, 30), 
        gme::Vector2(230, 50), "",
        gme::GUI::Origin::Center
      );
      gme::GUI::label(gme::Vector2(1024/2, 30), "KILL "+std::to_string(enemiesLeft), gme::GUI::Origin::Center);
  }
  else if(manager->gameType==2){
      int pointsto = (int)(manager->winCondition);
      gme::GUI::fontSize = 30;
      gme::GUI::backgroundColor = gme::GUI::Color(0,0,0, 100);      
      gme::GUI::box(
        gme::Vector2(512, 30), 
        gme::Vector2(260, 50), "",
        gme::GUI::Origin::Center
      );
      gme::GUI::label(gme::Vector2(1024/2, 30), std::to_string(pointsto)+" POINTS", gme::GUI::Origin::Center);
  }
  else if(manager->gameType==4){
      gme::GUI::fontSize = 45;
      gme::GUI::backgroundColor = gme::GUI::Color(0,0,0, 100);      
      gme::GUI::box(
        gme::Vector2(512, 30), 
        gme::Vector2(230, 50), "",
        gme::GUI::Origin::Center
      );
      gme::GUI::label(gme::Vector2(1024/2, 30),"BOSS", gme::GUI::Origin::Center);
  }
  if(showLevelSuccess){
      gme::GUI::drawTexture(
        gme::Vector2(512,288), 
        gme::Vector2(512,288),
        gme::GUI::TextureName("cartel_win"),  
        gme::GUI::Origin::Center,
        gme::GUI::ScaleToFit
      );
      
      gme::GUI::backgroundColor = gme::GUI::Color(0,0,0, 200);
      
      gme::GUI::box(
        gme::Vector2(512, 288+110+25), 
        gme::Vector2(512-20, 50), "",
        gme::GUI::Origin::Center
      );
      
      std::string puntosp1 = std::to_string(GlobalStateManager::pointsp1);
      std::string puntosp2 = std::to_string(GlobalStateManager::pointsp2);
      std::string maxppuntos = std::to_string(GlobalStateManager::maxpoints);
      int cp1 = 9-puntosp1.length();
      int cp2 = 9-puntosp2.length();
      int cpmax = 9-maxppuntos.length();
      
      for(int i = 0; i < cp1; i++){
        puntosp1 = "0"+puntosp1;
      }
      for(int i = 0; i < cp2; i++){
        puntosp2 = "0"+puntosp2;
      }
      for(int i = 0; i < cpmax; i++){
        maxppuntos = "0"+maxppuntos;
      }
      
      gme::GUI::fontSize = 20;
      gme::GUI::label(gme::Vector2(256+20, 288+110), "P1: "+puntosp1, gme::GUI::Origin::TopLeft);
      if(mainGame::coop) gme::GUI::label(gme::Vector2(768-20, 288+110), "P2: "+puntosp2, gme::GUI::Origin::TopRight);
      gme::GUI::fontSize = 28;
      gme::GUI::label(gme::Vector2(256+20, 288+110+25), "HIGH SCORE: "+maxppuntos, gme::GUI::Origin::TopLeft);
      
      return;
  }  
  if(showGameOver){
       gme::GUI::drawTexture(
        gme::Vector2(512,288), 
        gme::Vector2(512,288),
        gme::GUI::TextureName("cartel_lose"),  
        gme::GUI::Origin::Center,
        gme::GUI::ScaleToFit
      );
       return;
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

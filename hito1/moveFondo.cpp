/* 
 * File:   fondo.cpp
 * Author: Vir
 * 
 * Created on 15 de marzo de 2015, 13:25
 */

#include "imagenFondo.hpp"
#include "moveFondo.hpp"
#include "hito1Game.hpp"

void moveFondo::setup(){
    
    w = gme::Game::getWindow();
   // w->setFrameLimit(60);
    vec = w->getSize();
    reloj.restart();
    num_apre=0;num_apre_ini=0;
    musica = new gme::MusicPlayer();
    musica->setMusic("sound");
    sonando=false;izq=false;dre=false;pausa=false;apretado=false;music_pausa=false;
    menu=1;
    posX=320;
    pausa_visible = 0;

}

void moveFondo::update(){
     
    
    
    
    if(reloj.currentTime().asSeconds() > 0.01 && pausa==false ){
        
        getTransform()->translate(gme::Vector2(-x, 0));
        if(getTransform()->position.x <= -320) getTransform()->position.x = 960-x;
        
      reloj.restart();
    
    }
    
    if(gme::Keyboard::isKeyPressed(spaceKey) && pausa==false){ // BUCLE PARA QUE SUENE LA MUSICA
       if(apretar.currentTime().asSeconds()>0.2){ 
           
           std::cout << music_pausa << std::endl;
            if(sonando==true){
                musica->stop();
                sonando=false;

            }else if(sonando==false){
                musica->play();
                musica->loop(true);
                sonando=true;
            }
            apretar.restart();
       }
        
    }//----------------------------------------------
    
    if(izq==true && apretar.currentTime().asSeconds()<1) { //MOVIMIENTO A LA IZQUIERDA
                posX=posX-20;
                apretar.restart();
                if(posX==-320) izq=false;
            }
    if(dre==true && apretar.currentTime().asSeconds()<1) { //MOVIMIENTO A LA DERECHA
                posX=posX+20;
                apretar.restart();
                if(posX==320) {dre=false;menu=1;}
            }
    
    if(menu==1 && num_apre_ini==3 && gme::Keyboard::isKeyPressed(introKey) && pausa==false )w->close();
        
    if(menu==1 && num_apre_ini==2 && gme::Keyboard::isKeyPressed(introKey) && pausa==false ){ //APRETAR OPCIONES
       
      // std::cout <<posX<< std::endl;
       izq=true;
       menu=2;
       num_apre=0;
           
    }
    
    if(menu==1 && num_apre_ini==0 && gme::Keyboard::isKeyPressed(introKey) && pausa==false){ //APRETAR NUEVA PARTIDA
       
     //std::cout <<posX<< std::endl;
       izq=true;
       menu=3;
       num_apre=0;
           
    }
    
    
    if(menu==2 && (num_apre==3 && gme::Keyboard::isKeyPressed(introKey) /*|| gme::Keyboard::isKeyPressed(bacKey)*/) && pausa==false  ){ //APRETAR VOLVER DESDE OPCIONES
       
      // std::cout <<posX<< std::endl;
       //menu=1;
      // num_apre=0;
       dre=true;    
    }
    
     if(menu==3 && (num_apre==2 && gme::Keyboard::isKeyPressed(introKey) /*|| gme::Keyboard::isKeyPressed(bacKey)*/) && pausa==false ){ //APRETAR VOLVER DESDE NUEVA PARTIDA
       
      // std::cout <<posX<< std::endl;
       //menu=3;
       //num_apre=0;
       dre=true;    
    }
    
    //--------------- MENU DE PAUSA ------------------------
    
    if(gme::Keyboard::isKeyPressed(pauseKey) && apretar.currentTime().asSeconds()>0.2){
        
        
        if(pausa==true){
            pausa=false;
            pausa_visible=0;
            //num_apre=0;
        }else if(pausa==false){
            pausa=true;
            pausa_visible=100;
            num_apre=0;
            if(sonando){
                music_pausa=true;
                musica->pause();
            }
        }
        
        apretar.restart();
         
    }
    
    //---------------MENU DE PAUSA------------------------
    if(pausa==true &&  num_apre==0 && gme::Keyboard::isKeyPressed(introKey) ){
        
        apretado=true;
        
   }
    if(pausa==true && num_apre==1 && gme::Keyboard::isKeyPressed(introKey)) w->close();
    
    if(!gme::Keyboard::isKeyPressed(introKey) && apretado==true){
            //num_apre=0;
            pausa=false;
            pausa_visible=0;
            apretado=false;
            if(music_pausa==true){
                musica->play();
                music_pausa=false;
            }
           
          }

    //---------------MENU DE PAUSA------------------------
    
    
     
            
}

void moveFondo::onGui() {
    
    
    
  if(pausa==false){  
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

                    if(num_apre_ini==0) num_apre_ini=3;
                    else
                        num_apre_ini--;

                    apretar.restart();
                }

            }

            if(gme::Keyboard::isKeyPressed(downKey)){

                if(apretar.currentTime().asSeconds()>0.2){
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
  
  
  if(menu==2 && pausa==false){  
      
  
        if(gme::Keyboard::isKeyPressed(upKey)){
            
            if(apretar.currentTime().asSeconds()>0.2){

                if(num_apre==0) num_apre=3;
                else
                    num_apre--;
                
                apretar.restart();
            }

        }

        if(gme::Keyboard::isKeyPressed(downKey)){
              
            if(apretar.currentTime().asSeconds()>0.2){
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
    
     if(menu==3 && pausa==false){  
         
        // std::cout <<num_apre << std::endl;
        // std::cout <<menu << std::endl;
  
       if(gme::Keyboard::isKeyPressed(upKey)){
            
            if(apretar.currentTime().asSeconds()>0.2){

                if(num_apre==0) num_apre=2;
                else
                    num_apre--;
                
                apretar.restart();
            }

        }

        if(gme::Keyboard::isKeyPressed(downKey)){
              
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
    
    if(pausa){
        
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

               if(apretar.currentTime().asSeconds()>0.2){

                   if(num_apre==0) num_apre=1;
                   else
                       num_apre--;

                   apretar.restart();
               }

           }

           if(gme::Keyboard::isKeyPressed(downKey)){

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

moveFondo::~moveFondo(){


}

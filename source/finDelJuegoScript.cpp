/* 
 * File:   finDelJuegoScript.cpp
 * Author: pablopernias
 * 
 * Created on 20 de mayo de 2015, 11:07
 */

#include "finDelJuegoScript.hpp"
#include "mainGame.hpp"
#include "sceneMenu.hpp"

void finDelJuegoScript::setup() {
    std::cout << "entro en casa!!!" << std::endl;
    salir = false;
    delays = 5; //segundos
    kills = brokentiles = victories = levelspassed = deaths = 0;
    mainGame::victories++;
    mainGame::saveProfile();
}

void finDelJuegoScript::update() {
    
    if(!salir && reloj.currentTime().asSeconds() <= delays/2){
        float multip = reloj.currentTime().asSeconds()/(delays/2);
        kills = mainGame::kills*multip;
        brokentiles = mainGame::brokentiles*multip;
        victories = mainGame::victories*multip;
        levelspassed = mainGame::levelspassed*multip;
        deaths = mainGame::deaths*multip;
    }
    else{
        kills = mainGame::kills;
        brokentiles = mainGame::brokentiles;
        victories = mainGame::victories;
        levelspassed = mainGame::levelspassed;
        deaths = mainGame::deaths;
    }
    
    if(salir == false && reloj.currentTime().asSeconds() > delays/2){
        if(gme::Keyboard::isKeyPressed(gme::Keyboard::Return)){
            salir = true;
            reloj.restart();
        }
    }
    if(salir && reloj.currentTime().asSeconds() > delays){
        gme::Scene *olds = mainGame::removeScene("mainmenu");
        gme::Scene *olds2 = gme::Game::removeScene(gme::Game::getCurrentScene());
        gme::Scene *mm = new sceneMenu("mainmenu");
        gme::Game::setCurrentScene("mainmenu");
    }
}

void finDelJuegoScript::onGui() {
    
    
    if(!salir){
        int colorOpacity = 255*reloj.currentTime().asSeconds()/delays;
        if(colorOpacity > 255) colorOpacity = 255;
        gme::GUI::contentColor = gme::GUI::Color(255,255,255,colorOpacity);
    }
    if(salir){
        int colorOpacity = 255 - 255*reloj.currentTime().asSeconds()/delays;
        if(colorOpacity < 0) colorOpacity = 0;
        gme::GUI::contentColor = gme::GUI::Color(255,255,255,colorOpacity);
    }
    
    gme::GUI::fontSize = 48;
    gme::GUI::label(gme::Vector2(1024/2, 576/2 -200), "...CONTINUARA...", gme::GUI::Origin::Center);
    
    gme::GUI::fontSize = 18;
    gme::GUI::label(gme::Vector2(1024/2, 576/2 -250), "La chica ha escapado con tu gato...", gme::GUI::Origin::Center);
    
    gme::GUI::fontSize = 28;
    gme::GUI::label(gme::Vector2(1024/2, 576/2 -150), "ESTAS SON TUS ESTADISTICAS:", gme::GUI::Origin::Center);
    
    gme::GUI::fontSize = 18;
    
    gme::GUI::label(gme::Vector2(1024/2, 576/2 -100), "Dinosaurios destruidos: "+std::to_string(kills), gme::GUI::Origin::Center);
    gme::GUI::label(gme::Vector2(1024/2, 576/2 -70), "Bloques destruidos: "+std::to_string(brokentiles), gme::GUI::Origin::Center);
    gme::GUI::label(gme::Vector2(1024/2, 576/2 -40), "Veces que has superado el juego: "+std::to_string(victories), gme::GUI::Origin::Center);
    gme::GUI::label(gme::Vector2(1024/2, 576/2 -10), "Niveles superados: "+std::to_string(levelspassed), gme::GUI::Origin::Center);
    gme::GUI::label(gme::Vector2(1024/2, 576/2 +20), "Veces que has muerto: "+std::to_string(deaths), gme::GUI::Origin::Center);

    gme::GUI::fontSize = 28;
    gme::GUI::label(gme::Vector2(1024/2, 576/2 +80), "-PULSA ENTER PARA VOLVER AL MENU-", gme::GUI::Origin::Center);

    gme::GUI::fontSize = 18;
    gme::GUI::label(gme::Vector2(1024/2, 576/2 +120), "CAST:", gme::GUI::Origin::Center);
    gme::GUI::fontSize = 11;
    gme::GUI::label(gme::Vector2(1024/2, 576/2 +140), "Roxanne Lopez van Dooren - Actor Secundario", gme::GUI::Origin::Center);
    gme::GUI::label(gme::Vector2(1024/2, 576/2 +160), "Alberto Martinez Martinez - Camara n.2", gme::GUI::Origin::Center);
    gme::GUI::label(gme::Vector2(1024/2, 576/2 +180), "Andrea Lorente Ramon - Efectos especiales con Movie Maker", gme::GUI::Origin::Center);
    gme::GUI::label(gme::Vector2(1024/2, 576/2 +200), "Virgilio Domenech Perez - Disfraz de palmera", gme::GUI::Origin::Center);
    gme::GUI::label(gme::Vector2(1024/2, 576/2 +220), "Jose Carlos Valls Gras - Chico de los refrescos", gme::GUI::Origin::Center);
    gme::GUI::label(gme::Vector2(1024/2, 576/2 +240), "Pablo Pernias Pascual del Pobil - Doble de accion del velocirraptor", gme::GUI::Origin::Center);

}

finDelJuegoScript::~finDelJuegoScript() {

}



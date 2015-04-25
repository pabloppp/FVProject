/* 
 * File:   DestroyScript.cpp
 * Author: albertomartinezmartinez
 * 
 * Created on 25 de abril de 2015, 18:55
 */

#include "DestroyScript.hpp"

void DestroyScript::setup() {

}

void DestroyScript::update() {

}

void DestroyScript::onMessage(std::string m, float v) {
    if(m.compare("destroy") == 0){
        std::cout << "debe destruir el objeto" << std::endl;
        destroyGameObject(gameObject());
    }
}


DestroyScript::~DestroyScript() {
}


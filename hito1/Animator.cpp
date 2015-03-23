#include "Animator.hpp"

Animator::Animator() {
    paused = false;
    lastTime = 0;
    onSecond = 0;
    clock.restart();
    timeLapsed = 0;
    looping = false;
}

void Animator::at(float f, void(*fptr)(void*), void* context){
    event e;
    e.from = f;
    e.to = e.from;
    lastTime = e.to;
    e.fptr = fptr;
    e.ctx = context;
    events.push_back(e);
    aux_events.push_back(e);
}

void Animator::until(float f, void(*fptr)(void*), void* context){
    event e;
    e.from = lastTime;
    e.to = f;
    lastTime = e.to;
    e.fptr = fptr;
    e.ctx = context;
    events.push_back(e);
    aux_events.push_back(e);
}   

void Animator::from(float f){
    lastTime = f;
}

void Animator::animate(){
    if(looping){
        if(events.empty()){
            for(int i=0; i<aux_events.size(); i++){
                events.push_back(aux_events.at(i));
            }
            timeLapsed = 0;
            clock.restart();
        }
    }
    timeLapsed = clock.currentTime().asSeconds()+onSecond;    
    if(paused || events.empty()) return;
    if(events.front().from <= clock.currentTime().asSeconds() + onSecond){
        events.front().fptr(events.front().ctx);
        if(events.front().to <= clock.currentTime().asSeconds() + onSecond)
            events.erase(events.begin());
    }
    
}

void Animator::pause(){
    paused = true;
    onSecond += clock.currentTime().asSeconds(); 
}

void Animator::resume(){
    paused = false;
    clock.restart();
    timeLapsed = clock.currentTime().asSeconds()+onSecond;  
}

void Animator::restart(){
    events.clear();
    for(int i=0; i<aux_events.size(); i++){
        events.push_back(aux_events.at(i));
    }
    timeLapsed = 0;
    clock.restart();
}

void Animator::loop(bool b){
    if(b) looping = true;
    else looping = false;
}
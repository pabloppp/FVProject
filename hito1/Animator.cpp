#include "Animator.hpp"

Animator::Animator() {
    paused = false;
    lastTime = 0;
    onSecond = 0;
    clock.restart();
    timeLapsed = 0;
}

void Animator::at(float f, void(*fptr)(void*), void* context){
    event e;
    e.from = f;
    e.to = e.from;
    lastTime = e.to;
    e.fptr = fptr;
    e.ctx = context;
    events.push_back(e);
}

void Animator::until(float f, void(*fptr)(void*), void* context){
    event e;
    e.from = lastTime;
    e.to = f;
    lastTime = e.to;
    e.fptr = fptr;
    e.ctx = context;
    events.push_back(e);
}   

void Animator::from(float f){
    lastTime = f;
}

void Animator::animate(){
    timeLapsed = clock.currentTime().asSeconds();    
    if(paused || events.empty()) return;
    if(events.front().from <= clock.currentTime().asSeconds() + onSecond){
        events.front().fptr(events.front().ctx);
        if(events.front().to <= clock.currentTime().asSeconds() + onSecond)
            events.erase(events.begin());
    }
}

void Animator::pause(){
    paused = true;
    onSecond = clock.currentTime().asSeconds(); 
}

void Animator::resume(){
    paused = false;
    clock.restart();
    
}

void Animator::restart(){
    clock.restart();
    //TODO
}

void Animator::loop(bool b){
    //TODO
    
}
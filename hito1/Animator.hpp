#ifndef ANIMATOR_HPP
#define	ANIMATOR_HPP

#include "../engine/GMEngine.hpp"
#include <vector>

class Animator {
public:
    Animator();
    Animator(std::string n);
    void at(float f, void(*fptr)(void*), void* context = NULL);
    void until(float f, void(*fptr)(void*), void* context = NULL);
    void from(float f);
    void animate();
    void pause();
    void resume();
    void restart();
    void loop(bool b);
    float lastTime;
    float timeLapsed;
private:
   struct event {
        float from;
        float to;
        void(*fptr)(void*);
        void *ctx;   
    };
    std::vector<event> events;
    bool paused;
    gme::Clock clock;
    float onSecond;
};

#endif	/* ANIMATOR_HPP */


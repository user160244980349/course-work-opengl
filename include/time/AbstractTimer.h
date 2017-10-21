//
// Created by user on 14.10.2017.
//

#ifndef OPENGL_ABSTRACT_TIMER_H
#define OPENGL_ABSTRACT_TIMER_H

#ifdef __linux__
#include <SDL2/SDL_timer.h>
#elif _WIN32
#include <SDL_timer.h>
#endif

class ITimer {
public:
    virtual int reset() = 0;
    virtual int run() = 0;
    virtual int stop() = 0;
};


#endif //OPENGL_ABSTRACT_TIMER_H

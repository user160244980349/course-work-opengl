//
// Created by user on 14.10.2017.
//

#ifndef OPENGL_ABSTRACT_TIMER_HPP
#define OPENGL_ABSTRACT_TIMER_HPP

#ifdef __linux__
#include <SDL2/SDL_timer.h>
#elif _WIN32
#include <SDL_timer.h>
#endif

class abstract_timer {
public:
    Uint32 time;

    virtual int reset();
    virtual int run();
    virtual int stop();

protected:

};


#endif //OPENGL_ABSTRACT_TIMER_HPP

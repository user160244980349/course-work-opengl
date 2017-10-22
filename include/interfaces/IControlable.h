//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_CONTROLABLEINTERFACE_H
#define OPENGL_CONTROLABLEINTERFACE_H


#include <SDL_events.h>

namespace application::input {

    class IControlable {
    public:
        virtual int update() = 0;
        virtual int control(SDL_Event event) = 0;
    };

};

#endif //OPENGL_CONTROLABLEINTERFACE_H

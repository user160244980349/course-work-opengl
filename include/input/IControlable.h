//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_CONTROLABLEINTERFACE_H
#define OPENGL_CONTROLABLEINTERFACE_H

#include <SDL2/SDL_events.h>
#include "commands/IInputCommand.h"
#include <list>

namespace application::input {

    class IControlable {
    public:
        virtual int initCommands() = 0;
        virtual std::list<commands::IInputCommand*> getCommands() = 0;
    };

};

#endif //OPENGL_CONTROLABLEINTERFACE_H
//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_CONTROLABLEINTERFACE_H
#define OPENGL_CONTROLABLEINTERFACE_H

#include <SDL2/SDL_events.h>
#include "IInputCommand.h"
#include <list>


class IControlable {
public:
    virtual ~IControlable() = default;;

    virtual void initCommands() {};
};


#endif //OPENGL_CONTROLABLEINTERFACE_H

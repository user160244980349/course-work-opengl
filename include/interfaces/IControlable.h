#ifndef OPENGL_CONTROLABLEINTERFACE_H
#define OPENGL_CONTROLABLEINTERFACE_H


#include <list>
#include <SDL2/SDL_events.h>

#include "IInputCommand.h"

class IControlable {
public:
    virtual ~IControlable() = default;
    virtual void initCommands() {};
};


#endif //OPENGL_CONTROLABLEINTERFACE_H

#ifndef OPENGL_CONTROLABLEINTERFACE_H
#define OPENGL_CONTROLABLEINTERFACE_H


#include <list>
#include <SDL_events.h>

#include "IInputCommand.h"

class IControlable {
public:
    virtual ~IControlable() = default;
    virtual void initCommands() = 0;
};


#endif //OPENGL_CONTROLABLEINTERFACE_H

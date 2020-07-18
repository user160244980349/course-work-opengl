#ifndef OPENGL_AINPUTCOMMAND_H
#define OPENGL_AINPUTCOMMAND_H


#include <SDL2/SDL_events.h>

#include "../interfaces/IControlable.h"

class BaseInputCommand : public IInputCommand {
public:
    explicit BaseInputCommand(IControlable &object);

protected:
    IControlable &_object;
};


#endif //OPENGL_AINPUTCOMMAND_H

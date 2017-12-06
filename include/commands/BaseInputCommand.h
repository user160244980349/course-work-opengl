//
// Created by user on 27.11.2017.
//

#ifndef OPENGL_AINPUTCOMMAND_H
#define OPENGL_AINPUTCOMMAND_H

#include <interfaces/IControlable.h>
#include <SDL2/SDL_events.h>

class BaseInputCommand : public IInputCommand {
public:
    explicit BaseInputCommand(IControlable &object);

protected:
    IControlable& _object;
};



#endif //OPENGL_AINPUTCOMMAND_H

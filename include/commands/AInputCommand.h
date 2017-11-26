//
// Created by user on 27.11.2017.
//

#ifndef OPENGL_AINPUTCOMMAND_H
#define OPENGL_AINPUTCOMMAND_H


#include <input/IControlable.h>
#include <SDL2/SDL_events.h>

namespace application::commands {

    class AInputCommand : public IInputCommand {
    public:
        AInputCommand(input::IControlable* o);

    protected:
        input::IControlable* _object;
    };

}


#endif //OPENGL_AINPUTCOMMAND_H

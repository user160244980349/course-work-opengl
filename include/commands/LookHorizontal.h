//
// Created by user on 31.10.2017.
//

#ifndef OPENGL_LOOKHORIZONTAL_H
#define OPENGL_LOOKHORIZONTAL_H


#include "AInputCommand.h"

namespace application::commands {
    class LookHorizontal : public commands::AInputCommand {
    public:
        explicit LookHorizontal(input::IControlable* o);
        int execute(SDL_Event event) override;
    };
}


#endif //OPENGL_LOOKHORIZONTAL_H

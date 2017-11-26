//
// Created by user on 31.10.2017.
//

#ifndef OPENGL_MOVEFORWARD_H
#define OPENGL_MOVEFORWARD_H


#include "AInputCommand.h"

namespace application::commands {
    class MoveForward : public commands::AInputCommand {
    public:
        explicit MoveForward(input::IControlable* o);
        int execute(SDL_Event event) override;
    };
}


#endif //OPENGL_MOVEFORWARD_H

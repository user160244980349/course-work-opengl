//
// Created by user on 31.10.2017.
//

#ifndef OPENGL_MOVELEFT_H
#define OPENGL_MOVELEFT_H


#include "AInputCommand.h"

namespace application::commands {
    class MoveLeft : public commands::AInputCommand {
    public:
        explicit MoveLeft(input::IControlable* o);
        int execute(SDL_Event event) override;
    };
}


#endif //OPENGL_MOVELEFT_H

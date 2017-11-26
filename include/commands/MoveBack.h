//
// Created by user on 31.10.2017.
//

#ifndef OPENGL_MOVEBACK_H
#define OPENGL_MOVEBACK_H


#include "AInputCommand.h"

namespace application::commands {
    class MoveBack : public commands::AInputCommand {
    public:
        explicit MoveBack(input::IControlable* o);
        int execute(SDL_Event event) override;
    };
}


#endif //OPENGL_MOVEBACK_H

//
// Created by user on 31.10.2017.
//

#ifndef OPENGL_IINPUTCOMMAND_H
#define OPENGL_IINPUTCOMMAND_H

#include <SDL2/SDL_events.h>

namespace application::commands {

    class IInputCommand {
    public:
        virtual int execute(SDL_Event event) = 0;
    };

}

#endif //OPENGL_IINPUTCOMMAND_H

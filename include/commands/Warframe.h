//
// Created by user on 27.11.2017.
//

#ifndef OPENGL_WARFRAME_H
#define OPENGL_WARFRAME_H


#include "AInputCommand.h"

namespace application::commands {
    class Warframe : public commands::AInputCommand {
    public:
        explicit Warframe(input::IControlable* o);
        int execute(SDL_Event event) override;
    };
}


#endif //OPENGL_WARFRAME_H

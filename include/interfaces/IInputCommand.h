//
// Created by user on 31.10.2017.
//

#ifndef OPENGL_IINPUTCOMMAND_H
#define OPENGL_IINPUTCOMMAND_H

#include <SDL2/SDL_events.h>


class IInputCommand {
public:
    virtual ~IInputCommand() = default;;

    virtual void execute(SDL_Event event) {};
};


#endif //OPENGL_IINPUTCOMMAND_H

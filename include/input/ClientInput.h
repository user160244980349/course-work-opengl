//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_CLIENTINPUT_H
#define OPENGL_CLIENTINPUT_H

#include <SDL2/SDL_events.h>
#include <list>
#include <input/IControlable.h>


class ClientInput {
public:
    static ClientInput& getInstance();
    int perform();
    int addCommand(IInputCommand* command);
    int addCommands(std::list<IInputCommand*> commands);

protected:
    ClientInput();

    std::list<IInputCommand*> _commands;
    SDL_Event _event{};
};


#endif //OPENGL_CLIENTINPUT_H

//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_UserInput_H
#define OPENGL_UserInput_H

#include <SDL2/SDL_events.h>
#include <list>
#include <input/IControlable.h>


class UserInput {
public:
    static UserInput& getInstance();
    int perform();
    int addCommand(IInputCommand* command);
    ~UserInput();

protected:
    UserInput();

    std::list<IInputCommand*> _commands{};
    SDL_Event _event{};
};


#endif //OPENGL_UserInput_H

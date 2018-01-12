//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_USERINPUT_H
#define OPENGL_USERINPUT_H

#include <SDL2/SDL_events.h>
#include <list>
#include <interfaces/IControlable.h>

class UserInput {
public:
    ~UserInput();

    static UserInput &getInstance();

    void perform();

    void addCommand(IInputCommand *command);

    void addCommands(std::list<IInputCommand *> commands);

    void removeCommand(IInputCommand *command);

    void removeCommands(std::list<IInputCommand *> commands);

protected:
    UserInput();

    std::list<IInputCommand *> _commands{};
    SDL_Event _event{};
};


#endif //OPENGL_USERINPUT_H

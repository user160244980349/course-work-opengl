#ifndef OPENGL_USERINPUT_H
#define OPENGL_USERINPUT_H


#include <list>
#include <SDL2/SDL_events.h>

#include "../interfaces/IControlable.h"

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
    std::list<IInputCommand *> _commands {};
    SDL_Event _event {};

    UserInput();
};


#endif //OPENGL_USERINPUT_H

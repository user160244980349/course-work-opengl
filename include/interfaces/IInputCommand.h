#ifndef OPENGL_IINPUTCOMMAND_H
#define OPENGL_IINPUTCOMMAND_H


#include <SDL_events.h>

class IInputCommand {
public:
    virtual ~IInputCommand() = default;
    virtual void execute(SDL_Event event) = 0;
};


#endif //OPENGL_IINPUTCOMMAND_H

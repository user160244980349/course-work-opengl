#ifndef OPENGL_QUITCOMMAND_H
#define OPENGL_QUITCOMMAND_H


#include "../core/Kernel.h"
#include "../interfaces/IInputCommand.h"

class QuitCommand : public IInputCommand {
public:
    void execute(SDL_Event event) override;
};


#endif //OPENGL_QUITCOMMAND_H

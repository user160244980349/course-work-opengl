#ifndef OPENGL_QUITCOMMAND_H
#define OPENGL_QUITCOMMAND_H


#include <interfaces/IInputCommand.h>
#include <core/Kernel.h>

class QuitCommand : public IInputCommand {
public:
    void execute(SDL_Event event) override;
};


#endif //OPENGL_QUITCOMMAND_H

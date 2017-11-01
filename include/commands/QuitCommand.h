//
// Created by user on 31.10.2017.
//

#ifndef OPENGL_QUITCOMMAND_H
#define OPENGL_QUITCOMMAND_H

#include <commands/IInputCommand.h>
#include <Kernel.h>

namespace application::commands {
    class QuitCommand : public commands::IInputCommand {
    public:
        explicit QuitCommand(Kernel* kernel);
        int execute(SDL_Event event) override;

    protected:
        Kernel* _kernel;
    };
}


#endif //OPENGL_QUITCOMMAND_H

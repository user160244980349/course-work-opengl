//
// Created by user on 31.10.2017.
//

#ifndef OPENGL_QUITCOMMAND_H
#define OPENGL_QUITCOMMAND_H

#include <commands/IInputCommand.h>
#include <Kernel.h>


class QuitCommand : public IInputCommand {
public:
    virtual ~QuitCommand() override;
    int execute(SDL_Event event) override;
};


#endif //OPENGL_QUITCOMMAND_H

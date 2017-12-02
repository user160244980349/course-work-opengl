//
// Created by user on 31.10.2017.
//

#include "commands/QuitCommand.h"

int QuitCommand::execute(SDL_Event event) {

    if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
        Kernel::getInstance().stop();

    return 0;
}

QuitCommand::~QuitCommand() {}


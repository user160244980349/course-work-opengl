//
// Created by user on 31.10.2017.
//

#include "commands/QuitCommand.h"

int application::commands::QuitCommand::execute(SDL_Event event) {

    if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
        _kernel->running = false;

    return 0;
}

application::commands::QuitCommand::QuitCommand(application::Kernel *kernel) {

    _kernel = kernel;

}

#include "../include/commands/QuitCommand.h"

void QuitCommand::execute(SDL_Event event) {

    if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
        Kernel::getInstance().stop();

}

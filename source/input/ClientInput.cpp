//
// Created by user on 20.10.2017.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "input/ClientInput.h"

int application::input::ClientInput::perform() {

    while(SDL_PollEvent(&_event)) {

        for (auto &_command : _commands)
            _command->execute(_event);

    }

    return 0;
}

application::input::ClientInput::ClientInput() {

    if ( SDL_Init(SDL_INIT_EVENTS) != 0 ){
        std::cout << "Unable to init SDL, error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    SDL_SetRelativeMouseMode(SDL_TRUE);
    SDL_ShowCursor(SDL_DISABLE);

}

int application::input::ClientInput::addCommands(std::list<application::commands::IInputCommand*> commands) {
    _commands.merge(commands);
    return 0;
}

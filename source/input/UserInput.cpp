//
// Created by user on 20.10.2017.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "input/UserInput.h"

int UserInput::perform() {

    while(SDL_PollEvent(&_event)) {

        for (auto &_command : _commands)
            _command->execute(_event);

    }

    return 0;
}

UserInput::UserInput() {

    if ( SDL_Init(SDL_INIT_EVENTS) != 0 ){
        std::cout << "Unable to init SDL, error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    SDL_SetRelativeMouseMode(SDL_TRUE);
    SDL_ShowCursor(SDL_DISABLE);

}

int UserInput::addCommand(IInputCommand *command) {
    _commands.push_back(command);
    return 0;
}

UserInput &UserInput::getInstance() {
    static UserInput instance;
    return instance;
}

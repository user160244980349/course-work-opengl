//
// Created by user on 20.10.2017.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "input/UserInput.h"

UserInput::UserInput() {

    if ( SDL_Init(SDL_INIT_EVENTS) != 0 ){
        std::cout << "Unable to init SDL, error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    SDL_SetRelativeMouseMode(SDL_TRUE);
    SDL_ShowCursor(SDL_DISABLE);

}

UserInput::~UserInput() {
    for (auto &command : _commands) {
        delete(command);
    }
    _commands.clear();
}

void UserInput::perform() {

    while(SDL_PollEvent(&_event)) {
        for (auto &command : _commands)
            command->execute(_event);
    }
}

void UserInput::addCommand(IInputCommand *command) {
    _commands.push_back(command);
}

UserInput &UserInput::getInstance() {
    static UserInput instance;
    return instance;
}

void UserInput::addCommands(std::list<IInputCommand*> commands) {
    _commands.merge(commands);
}

void UserInput::removeCommand(IInputCommand *command) {
    _commands.remove(command);
}

void UserInput::removeCommands(std::list<IInputCommand *> commands) {
    for (auto &command : commands)
        _commands.remove(command);
}

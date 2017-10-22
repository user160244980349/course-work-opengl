//
// Created by user on 20.10.2017.
//

#include <iostream>
#include "input/KeyLogger.h"

int application::input::KeyLogger::control(SDL_Event event) {

    std::cout << event.key.keysym.sym << std::endl;

    return 0;
}

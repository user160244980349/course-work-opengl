//
// Created by user on 20.10.2017.
//

#include <iostream>
#include "test/KeyLogger.h"

int application::test::KeyLogger::update(SDL_Event event) {

    std::cout << event.key.keysym.sym << std::endl;

    return 0;
}

application::test::KeyLogger::KeyLogger(Subject* subject) {
    subject->subscribe(this);
}

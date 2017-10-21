//
// Created by user on 20.10.2017.
//

#include <iostream>
#include "input/ClientInput.h"

int application::input::ClientInput::perform() {

    notify();

    return 0;
}

int application::input::ClientInput::notify() {
    while(SDL_PollEvent(&_event)) {

        for (auto &_observer : _observers)
            _observer->update(_event);

    }
    return 0;
}

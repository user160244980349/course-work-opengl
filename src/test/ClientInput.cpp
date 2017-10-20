//
// Created by user on 20.10.2017.
//

#include <iostream>
#include "test/ClientInput.h"

int application::test::ClientInput::perform() {

    notify();

    return 0;
}

int application::test::ClientInput::notify() {
    while(SDL_PollEvent(&_event)) {

        for (auto &_observer : _observers)
            _observer->update(_event);

    }
    return 0;
}

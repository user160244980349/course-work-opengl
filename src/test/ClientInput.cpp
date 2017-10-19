//
// Created by user on 20.10.2017.
//

#include "test/ClientInput.h"

int application::test::ClientInput::perform() {

    while(SDL_PollEvent(&_event)) {

        for (auto &_observer : _observers)
            _observer->update(_event);

    }

    return 0;
}

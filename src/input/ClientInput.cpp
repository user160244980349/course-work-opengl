//
// Created by user on 20.10.2017.
//

#include <iostream>
#include <SDL.h>
#include "input/ClientInput.h"

int application::input::ClientInput::perform() {

    while(SDL_PollEvent(&_event)) {

        for (auto &_observer : _observers)
            _observer->control(_event);

    }

    return 0;
}

int application::input::ClientInput::subscribe(IControlable* observer) {
    _observers.push_back(observer);
    return 0;
}

int application::input::ClientInput::unsubscribe(IControlable* observer) {
    _observers.remove(observer);
    return 0;
}

application::input::ClientInput::ClientInput() {

    if ( SDL_Init(SDL_INIT_EVENTS) != 0 ){
        std::cout << "Unable to init SDL, error: " << SDL_GetError() << std::endl;
        exit(1);
    }

}

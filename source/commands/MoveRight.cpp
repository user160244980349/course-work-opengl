//
// Created by user on 31.10.2017.
//

#include "commands/MoveRight.h"

application::input::commands::MoveRight::MoveRight(application::objects::DynamicCamera *camera) {
    _camera = camera;
}

int application::input::commands::MoveRight::execute(SDL_Event event) {

    static bool state = false;

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_d && !state) {
        state = !state;
        _camera->moveRight();
    }

    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_d) {
        state = !state;
        _camera->moveRight();
    }

    return 0;
}

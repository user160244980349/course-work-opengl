//
// Created by user on 31.10.2017.
//

#include "commands/MoveForward.h"

application::input::commands::MoveForward::MoveForward(application::objects::DynamicCamera *camera) {
    _camera = camera;
}

int application::input::commands::MoveForward::execute(SDL_Event event) {

    static bool state = false;

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_w && !state) {
        state = !state;
        _camera->moveForward();
    }

    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_w) {
        state = !state;
        _camera->moveForward();
    }

    return 0;
}
//
// Created by user on 31.10.2017.
//

#include "commands/MoveLeft.h"

application::input::commands::MoveLeft::MoveLeft(application::objects::DynamicCamera *camera) {
    _camera = camera;
}

int application::input::commands::MoveLeft::execute(SDL_Event event) {

    static bool state = false;

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_a && !state) {
        state = !state;
        _camera->moveLeft();
    }

    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_a) {
        state = !state;
        _camera->moveLeft();
    }

    return 0;
}

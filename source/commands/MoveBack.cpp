//
// Created by user on 31.10.2017.
//

#include "commands/MoveBack.h"

application::commands::MoveBack::MoveBack(application::objects::DynamicCamera *camera) {
    _camera = camera;
}

int application::commands::MoveBack::execute(SDL_Event event) {

    static bool state = false;

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_s && !state) {
        state = !state;
        _camera->moveBack();
    }

    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_s) {
        state = !state;
        _camera->moveBack();
    }

    return 0;
}
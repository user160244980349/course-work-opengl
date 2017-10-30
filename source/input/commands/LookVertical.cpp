//
// Created by user on 31.10.2017.
//

#include "input/commands/LookVertical.h"

application::input::commands::LookVertical::LookVertical(application::objects::DynamicCamera *camera) {
    _camera = camera;
}

int application::input::commands::LookVertical::execute(SDL_Event event) {

    if (event.type == SDL_MOUSEMOTION)
        _camera->lookVertical(event.motion.yrel);

    return 0;
}

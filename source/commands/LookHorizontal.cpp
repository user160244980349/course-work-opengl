//
// Created by user on 31.10.2017.
//

#include "commands/LookHorizontal.h"

application::input::commands::LookHorizontal::LookHorizontal(application::objects::DynamicCamera *camera) {
    _camera = camera;
}

int application::input::commands::LookHorizontal::execute(SDL_Event event) {

    if (event.type == SDL_MOUSEMOTION)
        _camera->lookHorizontal(event.motion.xrel);

    return 0;
}

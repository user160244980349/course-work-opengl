//
// Created by user on 31.10.2017.
//

#include "commands/LookHorizontal.h"

application::commands::LookHorizontal::LookHorizontal(application::objects::DynamicCamera *camera) {
    _camera = camera;
}

int application::commands::LookHorizontal::execute(SDL_Event event) {

    if (event.type == SDL_MOUSEMOTION)
        _camera->lookHorizontal(event.motion.xrel);

    return 0;
}

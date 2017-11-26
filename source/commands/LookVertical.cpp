//
// Created by user on 31.10.2017.
//

#include <objects/DynamicCamera.h>
#include "commands/LookVertical.h"

int application::commands::LookVertical::execute(SDL_Event event) {

    if (event.type == SDL_MOUSEMOTION)
        dynamic_cast<objects::DynamicCamera*>(_object)->lookVertical(event.motion.yrel);

    return 0;
}

application::commands::LookVertical::LookVertical(application::input::IControlable *o) : AInputCommand(o) {

}

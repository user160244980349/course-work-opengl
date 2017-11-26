//
// Created by user on 31.10.2017.
//

#include <objects/DynamicCamera.h>
#include "commands/LookHorizontal.h"

application::commands::LookHorizontal::LookHorizontal(application::input::IControlable *o) : AInputCommand(o) {

}

int application::commands::LookHorizontal::execute(SDL_Event event) {

    if (event.type == SDL_MOUSEMOTION)
        dynamic_cast<objects::DynamicCamera*>(_object)->lookHorizontal(event.motion.xrel);

    return 0;
}

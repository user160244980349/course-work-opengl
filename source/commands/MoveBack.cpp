//
// Created by user on 31.10.2017.
//

#include <objects/DynamicCamera.h>
#include "commands/MoveBack.h"


int application::commands::MoveBack::execute(SDL_Event event) {

    static bool state = false;

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_s && !state) {
        state = !state;
        dynamic_cast<objects::DynamicCamera*>(_object)->moveBack();
    }

    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_s) {
        state = !state;
        dynamic_cast<objects::DynamicCamera*>(_object)->moveBack();
    }

    return 0;
}

application::commands::MoveBack::MoveBack(application::input::IControlable *o) : AInputCommand(o) {

}

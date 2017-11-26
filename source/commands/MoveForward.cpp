//
// Created by user on 31.10.2017.
//

#include <objects/DynamicCamera.h>
#include "commands/MoveForward.h"

int application::commands::MoveForward::execute(SDL_Event event) {

    static bool state = false;

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_w && !state) {
        state = !state;
        dynamic_cast<objects::DynamicCamera*>(_object)->moveForward();
    }

    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_w) {
        state = !state;
        dynamic_cast<objects::DynamicCamera*>(_object)->moveForward();
    }

    return 0;
}

application::commands::MoveForward::MoveForward(application::input::IControlable *o) : AInputCommand(o) {

}

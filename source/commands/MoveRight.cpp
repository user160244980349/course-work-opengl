//
// Created by user on 31.10.2017.
//

#include <objects/DynamicCamera.h>
#include "commands/MoveRight.h"


int MoveRight::execute(SDL_Event event) {

    static bool state = false;

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_d && !state) {
        state = !state;
        dynamic_cast<DynamicCamera*>(_object)->moveRight();
    }

    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_d) {
        state = !state;
        dynamic_cast<DynamicCamera*>(_object)->moveRight();
    }

    return 0;
}

MoveRight::MoveRight(IControlable *o) : AInputCommand(o) {

}

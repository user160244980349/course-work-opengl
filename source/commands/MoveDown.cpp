//
// Created by user on 02.12.2017.
//

#include <objects/DynamicCamera.h>
#include "commands/MoveDown.h"

MoveDown::MoveDown(IControlable *o) : AInputCommand(o) {}

int MoveDown::execute(SDL_Event event) {

    static bool state = false;

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_q && !state) {
        state = !state;
        dynamic_cast<DynamicCamera*>(_object)->moveDown();
    }

    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_q) {
        state = !state;
        dynamic_cast<DynamicCamera*>(_object)->moveDown();
    }

    return 0;
}

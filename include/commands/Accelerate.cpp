//
// Created by user on 06.12.2017.
//

#include <objects/DynamicCamera.h>
#include "Accelerate.h"

Accelerate::Accelerate(IControlable *o) : AInputCommand(o) {

}

Accelerate::~Accelerate() {

}

int Accelerate::execute(SDL_Event event) {
    static bool state = false;

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LSHIFT && !state) {
        state = !state;
        dynamic_cast<DynamicCamera*>(_object)->accelerate();
    }

    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_LSHIFT) {
        state = !state;
        dynamic_cast<DynamicCamera*>(_object)->accelerate();
    }

    return 0;
}

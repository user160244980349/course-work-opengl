//
// Created by user on 02.12.2017.
//

#include <objects/DynamicCamera.h>

MoveUp::MoveUp(IControlable *o) : AInputCommand(o) {}

int MoveUp::execute(SDL_Event event) {

    static bool state = false;

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_e && !state) {
        state = !state;
        dynamic_cast<DynamicCamera*>(_object)->moveUp();
    }

    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_e) {
        state = !state;
        dynamic_cast<DynamicCamera*>(_object)->moveUp();
    }

    return 0;
}

MoveUp::~MoveUp() {}

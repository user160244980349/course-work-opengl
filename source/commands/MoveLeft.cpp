//
// Created by user on 31.10.2017.
//

#include <objects/DynamicCamera.h>


MoveLeft::MoveLeft(IControlable *o) : AInputCommand(o) {}

int MoveLeft::execute(SDL_Event event) {

    static bool state = false;

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_a && !state) {
        state = !state;
        dynamic_cast<DynamicCamera*>(_object)->moveLeft();
    }

    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_a) {
        state = !state;
        dynamic_cast<DynamicCamera*>(_object)->moveLeft();
    }

    return 0;
}

MoveLeft::~MoveLeft() {}

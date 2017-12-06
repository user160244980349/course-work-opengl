//
// Created by user on 31.10.2017.
//

#include <objects/DynamicCamera.h>

MoveRight::MoveRight(IControlable &object) : BaseInputCommand(object) {}

void MoveRight::execute(SDL_Event event) {

    static bool state = false;

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_d && !state) {
        state = !state;
        dynamic_cast<DynamicCamera&>(_object).moveRight();
    }

    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_d) {
        state = !state;
        dynamic_cast<DynamicCamera&>(_object).moveRight();
    }
}

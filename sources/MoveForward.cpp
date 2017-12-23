//
// Created by user on 31.10.2017.
//

#include <objects/DynamicCamera.h>

MoveForward::MoveForward(IControlable &object) : BaseInputCommand(object) {}

void MoveForward::execute(SDL_Event event) {

    static bool state = false;

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_w && !state) {
        state = !state;
        dynamic_cast<DynamicCamera &>(_object).moveForward();
    }

    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_w) {
        state = !state;
        dynamic_cast<DynamicCamera &>(_object).moveForward();
    }
}


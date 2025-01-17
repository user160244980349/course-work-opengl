#include "../include/objects/DynamicCamera.h"

MoveLeft::MoveLeft(IControlable &object) : BaseInputCommand(object) {}

void MoveLeft::execute(SDL_Event event) {

    static bool state = false;

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_a && !state) {
        state = !state;
        dynamic_cast<DynamicCamera &>(_object).moveLeft();
    }

    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_a) {
        state = !state;
        dynamic_cast<DynamicCamera &>(_object).moveLeft();
    }
}

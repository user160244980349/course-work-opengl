#include "../include/objects/DynamicCamera.h"

MoveBack::MoveBack(IControlable &object) : BaseInputCommand(object) {}

void MoveBack::execute(SDL_Event event) {

    static bool state = false;

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_s && !state) {
        state = !state;
        dynamic_cast<DynamicCamera &>(_object).moveBack();
    }

    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_s) {
        state = !state;
        dynamic_cast<DynamicCamera &>(_object).moveBack();
    }
}

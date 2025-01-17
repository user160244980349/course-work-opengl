#include "../include/objects/DynamicCamera.h"

MoveDown::MoveDown(IControlable &object) : BaseInputCommand(object) {}

void MoveDown::execute(SDL_Event event) {

    static bool state = false;

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_q && !state) {
        state = !state;
        dynamic_cast<DynamicCamera &>(_object).moveDown();
    }

    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_q) {
        state = !state;
        dynamic_cast<DynamicCamera &>(_object).moveDown();
    }
}

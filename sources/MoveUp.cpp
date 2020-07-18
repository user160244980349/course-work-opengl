#include "../include/objects/DynamicCamera.h"

MoveUp::MoveUp(IControlable &object) : BaseInputCommand(object) {}

void MoveUp::execute(SDL_Event event) {

    static bool state = false;

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_e && !state) {
        state = !state;
        dynamic_cast<DynamicCamera &>(_object).moveUp();
    }

    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_e) {
        state = !state;
        dynamic_cast<DynamicCamera &>(_object).moveUp();
    }
}

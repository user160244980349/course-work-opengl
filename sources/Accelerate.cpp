#include "../include/objects/DynamicCamera.h"
#include "../include/commands/Accelerate.h"

Accelerate::Accelerate(IControlable &object) : BaseInputCommand(object) {}

void Accelerate::execute(SDL_Event event) {
    static bool state = false;

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LSHIFT && !state) {
        state = !state;
        dynamic_cast<DynamicCamera &>(_object).accelerate();
    }

    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_LSHIFT) {
        state = !state;
        dynamic_cast<DynamicCamera &>(_object).accelerate();
    }
}

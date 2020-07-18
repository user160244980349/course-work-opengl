#include "../include/objects/DynamicCamera.h"

LookHorizontal::LookHorizontal(IControlable &object) : BaseInputCommand(object) {}

void LookHorizontal::execute(SDL_Event event) {

    if (event.type == SDL_MOUSEMOTION)
        dynamic_cast<DynamicCamera &>(_object).lookHorizontal(event.motion.xrel);

}

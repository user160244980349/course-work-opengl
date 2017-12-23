//
// Created by user on 31.10.2017.
//

#include <objects/DynamicCamera.h>

LookVertical::LookVertical(IControlable &object) : BaseInputCommand(object) {}

void LookVertical::execute(SDL_Event event) {

    if (event.type == SDL_MOUSEMOTION)
        dynamic_cast<DynamicCamera &>(_object).lookVertical(event.motion.yrel);

}

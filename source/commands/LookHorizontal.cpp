//
// Created by user on 31.10.2017.
//

#include <objects/DynamicCamera.h>

LookHorizontal::LookHorizontal(IControlable *o) : AInputCommand(o) {}

int LookHorizontal::execute(SDL_Event event) {

    if (event.type == SDL_MOUSEMOTION)
        dynamic_cast<DynamicCamera*>(_object)->lookHorizontal(event.motion.xrel);

    return 0;
}

LookHorizontal::~LookHorizontal() {}

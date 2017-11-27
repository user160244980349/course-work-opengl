//
// Created by user on 27.11.2017.
//

#include <objects/Cube.h>
#include "commands/Warframe.h"


int Warframe::execute(SDL_Event event) {

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_r)
        dynamic_cast<Cube*>(_object)->warframe();

    return 0;
}

Warframe::Warframe(IControlable *o) : AInputCommand(o) {

};

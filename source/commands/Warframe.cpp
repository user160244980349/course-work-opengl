//
// Created by user on 27.11.2017.
//

#include <objects/Cube.h>
#include "commands/Warframe.h"


int application::commands::Warframe::execute(SDL_Event event) {

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_r)
        dynamic_cast<objects::Cube*>(_object)->warframe();

    return 0;
}

application::commands::Warframe::Warframe(application::input::IControlable *o) : AInputCommand(o) {

};

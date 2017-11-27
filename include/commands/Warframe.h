//
// Created by user on 27.11.2017.
//

#ifndef OPENGL_WARFRAME_H
#define OPENGL_WARFRAME_H


#include "AInputCommand.h"


class Warframe : public AInputCommand {
public:
    explicit Warframe(IControlable* o);
    int execute(SDL_Event event) override;
};


#endif //OPENGL_WARFRAME_H

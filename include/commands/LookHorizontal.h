//
// Created by user on 31.10.2017.
//

#ifndef OPENGL_LOOKHORIZONTAL_H
#define OPENGL_LOOKHORIZONTAL_H


#include "AInputCommand.h"


class LookHorizontal : public AInputCommand {
public:
    explicit LookHorizontal(IControlable* o);
    int execute(SDL_Event event) override;
};


#endif //OPENGL_LOOKHORIZONTAL_H

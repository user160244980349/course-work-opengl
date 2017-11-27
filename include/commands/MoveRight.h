//
// Created by user on 31.10.2017.
//

#ifndef OPENGL_MOVERIGHT_H
#define OPENGL_MOVERIGHT_H


#include "AInputCommand.h"


class MoveRight : public AInputCommand {
public:
    explicit MoveRight(IControlable* o);
    int execute(SDL_Event event) override;
};


#endif //OPENGL_MOVERIGHT_H

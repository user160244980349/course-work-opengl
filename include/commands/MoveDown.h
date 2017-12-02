//
// Created by user on 02.12.2017.
//

#ifndef OPENGL_MOVEDOWN_H
#define OPENGL_MOVEDOWN_H


#include "AInputCommand.h"

class MoveDown : public AInputCommand {
public:
    explicit MoveDown(IControlable* o);
    int execute(SDL_Event event) override;
};


#endif //OPENGL_MOVEDOWN_H

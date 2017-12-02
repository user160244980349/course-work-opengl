//
// Created by user on 02.12.2017.
//

#ifndef OPENGL_MOVEUP_H
#define OPENGL_MOVEUP_H


#include "AInputCommand.h"

class MoveUp : public AInputCommand {
public:
    explicit MoveUp(IControlable* o);
    int execute(SDL_Event event) override;
};


#endif //OPENGL_MOVEUP_H

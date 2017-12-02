//
// Created by user on 31.10.2017.
//

#ifndef OPENGL_MOVELEFT_H
#define OPENGL_MOVELEFT_H


#include "AInputCommand.h"


class MoveLeft : public AInputCommand {
public:
    virtual ~MoveLeft() override;
    explicit MoveLeft(IControlable* o);
    int execute(SDL_Event event) override;
};


#endif //OPENGL_MOVELEFT_H

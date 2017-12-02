//
// Created by user on 31.10.2017.
//

#ifndef OPENGL_MOVEFORWARD_H
#define OPENGL_MOVEFORWARD_H


#include "AInputCommand.h"


class MoveForward : public AInputCommand {
public:
    virtual ~MoveForward() override;
    explicit MoveForward(IControlable* o);
    int execute(SDL_Event event) override;
};


#endif //OPENGL_MOVEFORWARD_H

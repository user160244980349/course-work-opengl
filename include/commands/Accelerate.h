//
// Created by user on 06.12.2017.
//

#ifndef OPENGL_ACCELERATE_H
#define OPENGL_ACCELERATE_H


#include "AInputCommand.h"

class Accelerate : public AInputCommand {
public:
    virtual ~Accelerate() override;
    explicit Accelerate(IControlable* o);
    int execute(SDL_Event event) override;
};


#endif //OPENGL_ACCELERATE_H

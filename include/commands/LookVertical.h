//
// Created by user on 31.10.2017.
//

#ifndef OPENGL_LOOKVERTICAL_H
#define OPENGL_LOOKVERTICAL_H


#include "AInputCommand.h"


class LookVertical : public AInputCommand {
public:
    virtual ~LookVertical() override;
    explicit LookVertical(IControlable* o);
    int execute(SDL_Event event) override;
};


#endif //OPENGL_LOOKVERTICAL_H

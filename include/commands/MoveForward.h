//
// Created by user on 31.10.2017.
//

#ifndef OPENGL_MOVEFORWARD_H
#define OPENGL_MOVEFORWARD_H

#include "BaseInputCommand.h"

class MoveForward : public BaseInputCommand {
public:
    explicit MoveForward(IControlable &object);
    void execute(SDL_Event event) override;
};


#endif //OPENGL_MOVEFORWARD_H

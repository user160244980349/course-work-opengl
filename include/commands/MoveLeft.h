//
// Created by user on 31.10.2017.
//

#ifndef OPENGL_MOVELEFT_H
#define OPENGL_MOVELEFT_H

#include "BaseInputCommand.h"

class MoveLeft : public BaseInputCommand {
public:
    explicit MoveLeft(IControlable &object);
    void execute(SDL_Event event) override;
};


#endif //OPENGL_MOVELEFT_H

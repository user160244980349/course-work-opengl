//
// Created by user on 31.10.2017.
//

#ifndef OPENGL_LOOKVERTICAL_H
#define OPENGL_LOOKVERTICAL_H

#include "BaseInputCommand.h"

class LookVertical : public BaseInputCommand {
public:
    explicit LookVertical(IControlable &object);

    void execute(SDL_Event event) override;
};


#endif //OPENGL_LOOKVERTICAL_H

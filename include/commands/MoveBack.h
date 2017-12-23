//
// Created by user on 31.10.2017.
//

#ifndef OPENGL_MOVEBACK_H
#define OPENGL_MOVEBACK_H

#include "BaseInputCommand.h"

class MoveBack : public BaseInputCommand {
public:
    explicit MoveBack(IControlable &object);

    void execute(SDL_Event event) override;
};


#endif //OPENGL_MOVEBACK_H

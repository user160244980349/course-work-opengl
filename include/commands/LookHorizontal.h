#ifndef OPENGL_LOOKHORIZONTAL_H
#define OPENGL_LOOKHORIZONTAL_H


#include "BaseInputCommand.h"

class LookHorizontal : public BaseInputCommand {
public:
    explicit LookHorizontal(IControlable &object);
    void execute(SDL_Event event) override;
};


#endif //OPENGL_LOOKHORIZONTAL_H

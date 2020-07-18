#ifndef OPENGL_MOVERIGHT_H
#define OPENGL_MOVERIGHT_H


#include "BaseInputCommand.h"

class MoveRight : public BaseInputCommand {
public:
    explicit MoveRight(IControlable &object);
    void execute(SDL_Event event) override;
};


#endif //OPENGL_MOVERIGHT_H

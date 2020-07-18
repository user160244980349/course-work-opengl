#ifndef OPENGL_MOVEDOWN_H
#define OPENGL_MOVEDOWN_H


#include "BaseInputCommand.h"

class MoveDown : public BaseInputCommand {
public:
    explicit MoveDown(IControlable &object);
    void execute(SDL_Event event) override;
};


#endif //OPENGL_MOVEDOWN_H

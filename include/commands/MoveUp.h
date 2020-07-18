#ifndef OPENGL_MOVEUP_H
#define OPENGL_MOVEUP_H


#include "BaseInputCommand.h"

class MoveUp : public BaseInputCommand {
public:
    explicit MoveUp(IControlable &object);
    void execute(SDL_Event event) override;
};


#endif //OPENGL_MOVEUP_H

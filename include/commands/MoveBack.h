#ifndef OPENGL_MOVEBACK_H
#define OPENGL_MOVEBACK_H


#include "BaseInputCommand.h"

class MoveBack : public BaseInputCommand {
public:
    explicit MoveBack(IControlable &object);
    void execute(SDL_Event event) override;
};


#endif //OPENGL_MOVEBACK_H

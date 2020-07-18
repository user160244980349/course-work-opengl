#ifndef OPENGL_ACCELERATE_H
#define OPENGL_ACCELERATE_H


#include "BaseInputCommand.h"

class Accelerate : public BaseInputCommand {
public:
    explicit Accelerate(IControlable &object);
    void execute(SDL_Event event) override;
};


#endif //OPENGL_ACCELERATE_H

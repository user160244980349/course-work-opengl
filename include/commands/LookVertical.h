#ifndef OPENGL_LOOKVERTICAL_H
#define OPENGL_LOOKVERTICAL_H


#include "BaseInputCommand.h"

class LookVertical : public BaseInputCommand {
public:
    explicit LookVertical(IControlable &object);
    void execute(SDL_Event event) override;
};


#endif //OPENGL_LOOKVERTICAL_H

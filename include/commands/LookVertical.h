//
// Created by user on 31.10.2017.
//

#ifndef OPENGL_LOOKVERTICAL_H
#define OPENGL_LOOKVERTICAL_H


#include <interfaces/IInputCommand.h>
#include <objects/DynamicCamera.h>
#include "LookVertical.h"

namespace application::input::commands {
    class LookVertical : public interfaces::IInputCommand {
    public:
        explicit LookVertical(objects::DynamicCamera* camera);
        int execute(SDL_Event event) override;

    protected:
        objects::DynamicCamera* _camera;
    };
}


#endif //OPENGL_LOOKVERTICAL_H

//
// Created by user on 31.10.2017.
//

#ifndef OPENGL_LOOKHORIZONTAL_H
#define OPENGL_LOOKHORIZONTAL_H


#include <commands/IInputCommand.h>
#include <objects/DynamicCamera.h>

namespace application::commands {
    class LookHorizontal : public commands::IInputCommand {
    public:
        explicit LookHorizontal(objects::DynamicCamera* camera);
        int execute(SDL_Event event) override;

    protected:
        objects::DynamicCamera* _camera;
    };
}


#endif //OPENGL_LOOKHORIZONTAL_H

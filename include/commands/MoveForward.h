//
// Created by user on 31.10.2017.
//

#ifndef OPENGL_MOVEFORWARD_H
#define OPENGL_MOVEFORWARD_H


#include <interfaces/IInputCommand.h>
#include <objects/DynamicCamera.h>

namespace application::input::commands {
    class MoveForward : public interfaces::IInputCommand {
    public:
        explicit MoveForward(objects::DynamicCamera* camera);
        int execute(SDL_Event event) override;

    protected:
        objects::DynamicCamera* _camera;
    };
}


#endif //OPENGL_MOVEFORWARD_H

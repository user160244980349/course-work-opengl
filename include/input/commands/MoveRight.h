//
// Created by user on 31.10.2017.
//

#ifndef OPENGL_MOVERIGHT_H
#define OPENGL_MOVERIGHT_H


#include <interfaces/IInputCommand.h>
#include <objects/DynamicCamera.h>

namespace application::input::commands {
    class MoveRight : public interfaces::IInputCommand {
    public:
        explicit MoveRight(objects::DynamicCamera* camera);
        int execute(SDL_Event event) override;

    protected:
        objects::DynamicCamera* _camera;
    };
}


#endif //OPENGL_MOVERIGHT_H

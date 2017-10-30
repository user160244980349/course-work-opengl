//
// Created by user on 31.10.2017.
//

#ifndef OPENGL_MOVELEFT_H
#define OPENGL_MOVELEFT_H


#include <interfaces/IInputCommand.h>
#include <objects/DynamicCamera.h>

namespace application::input::commands {
    class MoveLeft : public interfaces::IInputCommand {
    public:
        explicit MoveLeft(objects::DynamicCamera* camera);
        int execute(SDL_Event event) override;

    protected:
        objects::DynamicCamera* _camera;
    };
}


#endif //OPENGL_MOVELEFT_H

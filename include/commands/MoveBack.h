//
// Created by user on 31.10.2017.
//

#ifndef OPENGL_MOVEBACK_H
#define OPENGL_MOVEBACK_H


#include <commands/IInputCommand.h>
#include <SDL2/SDL_events.h>
#include <objects/DynamicCamera.h>

namespace application::commands {
    class MoveBack : public commands::IInputCommand {
    public:
        explicit MoveBack(objects::DynamicCamera* camera);
        int execute(SDL_Event event) override;

    protected:
        objects::DynamicCamera* _camera;
    };
}


#endif //OPENGL_MOVEBACK_H

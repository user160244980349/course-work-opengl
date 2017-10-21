//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_DYNAMICCAMERA_H
#define OPENGL_DYNAMICCAMERA_H


#include <Interfaces&Abstractions/DynamicCameraInterface.h>

namespace application::objects {

    class DynamicCamera : public DynamicCameraInterface {
    public:
        DynamicCamera();
        int use(GLuint shaderProgramId) override;
        int controlResponse(SDL_Event event) override;
        int update(SDL_Event event) override;

    protected:
        GLfloat _sensitivity;
        GLfloat _mouse_x;
        GLfloat _mouse_y;
    };

}


#endif //OPENGL_DYNAMICCAMERA_H

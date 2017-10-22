//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_DYNAMICCAMERA_H
#define OPENGL_DYNAMICCAMERA_H


#include <interfaces/IDynamicCamera.h>
#include <SDL_events.h>
#include <GL/glew.h>
#include <graphics/Ubo.h>

namespace application::objects {

    class DynamicCamera : public IDynamicCamera {
    public:
        DynamicCamera();
        int use(GLuint shaderProgramId) override;
        int controlResponse(SDL_Event event) override;

    protected:
        graphics::Ubo _ubo;

        struct {
            glm::mat4 projection;
            glm::mat4 viewPoint;
        } _transform;

        glm::vec3 _cameraPos;
        glm::vec3 _cameraUp;
        glm::vec3 _cameraFront;

        GLfloat _sensitivity;
        GLfloat _mouse_x;
        GLfloat _mouse_y;
    };

}


#endif //OPENGL_DYNAMICCAMERA_H

//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_DYNAMICCAMERA_H
#define OPENGL_DYNAMICCAMERA_H

#include <interfaces/ICamera.h>
#include <SDL2/SDL_events.h>
#include <graphics/Ubo.h>
#include <interfaces/ICamera.h>
#include <interfaces/IControlable.h>

namespace application::objects {

    class DynamicCamera : public ICamera, public input::IControlable  {
    public:
        DynamicCamera();
        int use(GLuint shaderProgramId) override;
        int control(SDL_Event event) override;
        int update() override;

    protected:
        graphics::Ubo _ubo;

        struct {
            glm::mat4 projection;
            glm::mat4 viewPoint;
        } _transform;

        struct {
            bool w = false;
            bool s = false;
            bool a = false;
            bool d = false;
            bool q = false;
            bool e = false;
        } _keys;

        glm::vec3 _cameraPos;
        glm::vec3 _cameraUp;
        glm::vec3 _cameraFront;

        GLfloat _sensitivity;
        GLfloat _mouseX;
        GLfloat _mouseY;
        GLfloat _speedFront;
        GLfloat _speedUp;
    };

}

#endif //OPENGL_DYNAMICCAMERA_H

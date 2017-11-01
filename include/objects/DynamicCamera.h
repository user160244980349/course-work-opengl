//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_DYNAMICCAMERA_H
#define OPENGL_DYNAMICCAMERA_H

#include <SDL2/SDL_events.h>
#include <graphics/Ubo.h>
#include <objects/ICamera.h>
#include <input/AControlable.h>


namespace application::objects {

    class DynamicCamera : public objects::ICamera, public input::AControlable  {
    public:
        DynamicCamera();
        int use(GLuint shaderProgramId) override;
        int update() override;
        int initCommands() override;

        int moveForward();
        int moveBack();
        int moveRight();
        int moveLeft();

        int lookHorizontal(int x);
        int lookVertical(int y);

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

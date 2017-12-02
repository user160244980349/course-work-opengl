//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_DYNAMICCAMERA_H
#define OPENGL_DYNAMICCAMERA_H

#include <SDL2/SDL_events.h>
#include <graphics/Ubo.h>
#include <objects/ICamera.h>
#include <input/IControlable.h>
#include <commands/LookVertical.h>
#include <commands/LookHorizontal.h>
#include <commands/MoveForward.h>
#include <commands/MoveBack.h>
#include <commands/MoveRight.h>
#include <commands/MoveLeft.h>
#include <commands/MoveUp.h>
#include <commands/MoveDown.h>


class DynamicCamera : public ICamera , public IControlable {
public:
    DynamicCamera();
    int use(GLuint shaderProgramId) override;
    int update() override;

    int initCommands() override;
    int moveForward();
    int moveBack();
    int moveRight();
    int moveLeft();
    int moveUp();
    int moveDown();

    int lookHorizontal(int x);
    int lookVertical(int y);

protected:
    Ubo _ubo;

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

    struct {
        LookVertical lv;
        LookHorizontal lh;
        MoveForward mf;
        MoveBack mb;
        MoveRight mr;
        MoveLeft  ml;
        MoveUp mu;
        MoveDown md;
    } _commands;

    glm::vec3 _cameraPos;
    glm::vec3 _cameraUp;
    glm::vec3 _cameraFront;

    GLfloat _sensitivity;
    GLfloat _mouseX;
    GLfloat _mouseY;
    GLfloat _speedFront;
    GLfloat _speedUp;
};


#endif //OPENGL_DYNAMICCAMERA_H

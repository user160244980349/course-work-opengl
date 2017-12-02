//
// Created by user on 21.10.2017.
//

#include "objects/DynamicCamera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <commands/LookVertical.h>
#include <commands/LookHorizontal.h>
#include <commands/MoveForward.h>
#include <commands/MoveBack.h>
#include <commands/MoveRight.h>
#include <commands/MoveLeft.h>

DynamicCamera::DynamicCamera() {

    _mouseX = 0.0f;
    _mouseY = 0.0f;
    _speedUp = 0.2f;
    _speedFront = 0.2f;
    _sensitivity = 0.1f;

    glm::vec3 front = glm::vec3(1.0f, 0.0f, 0.0f);

    _cameraPos   = glm::vec3(-4.0f, 1.0f,  0.0f);
    _cameraUp    = glm::vec3(0.0f, 1.0f, 0.0f);
    _cameraFront = glm::normalize(front);

    _transform.projection = glm::perspective(glm::radians(50.0f), 16.0f / 9.0f, 0.1f, 100.0f);
    _transform.viewPoint = glm::lookAt(_cameraPos, _cameraPos + _cameraFront, _cameraUp);

    _ubo.create();
    _ubo.set(static_cast<GLvoid*>(&_transform), sizeof(_transform));

    initCommands();
}

int DynamicCamera::use(GLuint shaderProgramId) {

    _ubo.connect(shaderProgramId, CAMERA_BIND_INDEX, "camera");

    return 0;
}

int DynamicCamera::update() {

    _cameraFront = glm::normalize(glm::vec3(
            cosf(glm::radians(_mouseY)) * cosf(glm::radians(_mouseX)),
            sinf(glm::radians(_mouseY)),
            cosf(glm::radians(_mouseY)) * sinf(glm::radians(_mouseX)))
    );

    if (!_keys.w)
        _cameraPos += -_cameraFront * _speedFront;

    if (!_keys.s)
        _cameraPos += _cameraFront * _speedFront;

    if (!_keys.a)
        _cameraPos += glm::normalize(glm::cross(_cameraFront, _cameraUp)) * _speedUp;

    if (!_keys.d)
        _cameraPos += -glm::normalize(glm::cross(_cameraFront, _cameraUp)) * _speedUp;

    _transform.viewPoint = glm::lookAt(_cameraPos, _cameraPos + _cameraFront, _cameraUp);
    _ubo.update(static_cast<GLvoid*>(&_transform), sizeof(_transform));

    return 0;
}

int DynamicCamera::initCommands() {

    new LookVertical(this);
    new LookHorizontal(this);
    new MoveForward(this);
    new MoveBack(this);
    new MoveRight(this);
    new MoveLeft(this);

    return 0;
}

int DynamicCamera::moveForward() {
    _keys.w = !_keys.w;
    return 0;
}

int DynamicCamera::moveBack() {
    _keys.s = !_keys.s;
    return 0;
}

int DynamicCamera::moveRight() {
    _keys.d = !_keys.d;
    return 0;
}

int DynamicCamera::moveLeft() {
    _keys.a = !_keys.a;
    return 0;
}

int DynamicCamera::lookVertical(int y) {
    _mouseY -= y * _sensitivity;
    if (_mouseY > 89.0f)
        _mouseY = 89.0f;
    if (_mouseY < -89.0f)
        _mouseY = -89.0f;
    return 0;
}

int DynamicCamera::lookHorizontal(int x) {
    _mouseX += x * _sensitivity;
    return 0;
}

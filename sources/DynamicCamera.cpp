//
// Created by user on 21.10.2017.
//

#include "objects/DynamicCamera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <commands/Accelerate.h>
#include <core/UserInput.h>

DynamicCamera::DynamicCamera() {
    _mouseX = 0.0f;
    _mouseY = 0.0f;
    _speedUp = 0.2f;
    _speedFront = 0.2f;
    _sensitivity = 0.1f;
    _acceleration = 10.0f;

    _cameraPos = glm::vec3(-6.0f, 0.0f, 0.0f);
    _cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 front = glm::vec3(1.0f, 0.0f, 0.0f);
    _cameraFront = glm::normalize(front);

    projection = glm::perspective(glm::radians(75.0f), 16.0f / 9.0f, 0.1f, 500.0f);
    viewPoint = glm::lookAt(_cameraPos, _cameraPos + _cameraFront, _cameraUp);

    initCommands();
}

void DynamicCamera::initCommands() {

    _commands.push_back(new LookHorizontal(*this));
    _commands.push_back(new LookVertical(*this));
    _commands.push_back(new MoveBack(*this));
    _commands.push_back(new MoveDown(*this));
    _commands.push_back(new MoveForward(*this));
    _commands.push_back(new MoveLeft(*this));
    _commands.push_back(new MoveRight(*this));
    _commands.push_back(new MoveUp(*this));
    _commands.push_back(new Accelerate(*this));

    UserInput::getInstance().addCommands(_commands);
}

void DynamicCamera::update() {
    _cameraFront = glm::normalize(glm::vec3(
            cosf(glm::radians(_mouseY)) * cosf(glm::radians(_mouseX)),
            sinf(glm::radians(_mouseY)),
            cosf(glm::radians(_mouseY)) * sinf(glm::radians(_mouseX)))
    );

    if (!_keys.shift) {
        if (!_keys.w)
            _cameraPos += -glm::normalize(_cameraFront) * _speedFront;
        if (!_keys.s)
            _cameraPos += glm::normalize(_cameraFront) * _speedFront;
        if (!_keys.a)
            _cameraPos += glm::normalize(glm::cross(_cameraFront, _cameraUp)) * _speedUp;
        if (!_keys.d)
            _cameraPos += -glm::normalize(glm::cross(_cameraFront, _cameraUp)) * _speedUp;
        if (!_keys.e)
            _cameraPos += -glm::normalize(_cameraUp) * _speedUp;
        if (!_keys.q)
            _cameraPos += glm::normalize(_cameraUp) * _speedUp;
    } else {
        if (!_keys.w)
            _cameraPos += -glm::normalize(_cameraFront) * _speedFront * _acceleration;
        if (!_keys.s)
            _cameraPos += glm::normalize(_cameraFront) * _speedFront * _acceleration;
        if (!_keys.a)
            _cameraPos += glm::normalize(glm::cross(_cameraFront, _cameraUp)) * _speedUp * _acceleration;
        if (!_keys.d)
            _cameraPos += -glm::normalize(glm::cross(_cameraFront, _cameraUp)) * _speedUp * _acceleration;
        if (!_keys.e)
            _cameraPos += -glm::normalize(_cameraUp) * _speedUp * _acceleration;
        if (!_keys.q)
            _cameraPos += glm::normalize(_cameraUp) * _speedUp * _acceleration;
    }

    viewPoint = glm::lookAt(_cameraPos, _cameraPos + _cameraFront, _cameraUp);

}

void DynamicCamera::moveForward() {
    _keys.w = !_keys.w;
}

void DynamicCamera::moveBack() {
    _keys.s = !_keys.s;
}

void DynamicCamera::moveRight() {
    _keys.d = !_keys.d;
}

void DynamicCamera::moveLeft() {
    _keys.a = !_keys.a;
}

void DynamicCamera::moveUp() {
    _keys.e = !_keys.e;
}

void DynamicCamera::moveDown() {
    _keys.q = !_keys.q;
}

void DynamicCamera::accelerate() {
    _keys.shift = !_keys.shift;
}

void DynamicCamera::lookVertical(int y) {
    _mouseY -= y * _sensitivity;
    if (_mouseY > 89.0f)
        _mouseY = 89.0f;
    if (_mouseY < -89.0f)
        _mouseY = -89.0f;
}

void DynamicCamera::lookHorizontal(int x) {
    _mouseX += x * _sensitivity;
}

DynamicCamera::~DynamicCamera() {
    UserInput::getInstance().removeCommands(_commands);
    for (auto command : _commands)
        delete (command);
    _commands.clear();
}

glm::mat4 DynamicCamera::getView() {
    return viewPoint;
}

glm::mat4 DynamicCamera::getProjection() {
    return projection;
}

glm::vec3 DynamicCamera::getPosition() {
    return _cameraPos;
}

//
// Created by user on 21.10.2017.
//

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <graphics/UboBindIndexes.h>
#include "objects/DynamicCamera.h"

application::objects::DynamicCamera::DynamicCamera() {

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

}

int application::objects::DynamicCamera::use(GLuint shaderProgramId) {

    _ubo.connect(shaderProgramId, CAMERA_BIND_INDEX, "camera");

    return 0;
}

int application::objects::DynamicCamera::control(SDL_Event event) {

    switch (event.type) {

        case SDL_MOUSEMOTION:
            _mouseX += event.motion.xrel * _sensitivity;
            _mouseY -= event.motion.yrel * _sensitivity;

            if (_mouseY > 89.0f)
                _mouseY = 89.0f;
            if (_mouseY < -89.0f)
                _mouseY = -89.0f;

            _cameraFront = glm::normalize(glm::vec3(
                    cosf(glm::radians(_mouseY)) * cosf(glm::radians(_mouseX)),
                    sinf(glm::radians(_mouseY)),
                    cosf(glm::radians(_mouseY)) * sinf(glm::radians(_mouseX)))
            );
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_w:
                    _keys.w = true;
                    break;
                case SDLK_s:
                    _keys.s = true;
                    break;
                case SDLK_a:
                    _keys.a = true;
                    break;
                case SDLK_d:
                    _keys.d = true;
                    break;
                case SDLK_q:
                    _keys.q = true;
                    break;
                case SDLK_e:
                    _keys.e = true;
                default: break;
            }
            break;

        case SDL_KEYUP:
            switch (event.key.keysym.sym) {
                case SDLK_w:
                    _keys.w = false;
                    break;
                case SDLK_s:
                    _keys.s = false;
                    break;
                case SDLK_a:
                    _keys.a = false;
                    break;
                case SDLK_d:
                    _keys.d = false;
                    break;
                case SDLK_q:
                    _keys.q = false;
                    break;
                case SDLK_e:
                    _keys.e = false;
                default: break;
            }
            break;

        default: break;
    }

    return 0;
}

int application::objects::DynamicCamera::update() {

    if (!_keys.w)
        _cameraPos += -_cameraFront * _speedFront;

    if (!_keys.s)
        _cameraPos += _cameraFront * _speedFront;

    if (!_keys.a)
        _cameraPos += glm::normalize(glm::cross(_cameraFront, _cameraUp)) * _speedUp;

    if (!_keys.d)
        _cameraPos += -glm::normalize(glm::cross(_cameraFront, _cameraUp)) * _speedUp;

    if (!_keys.q)
        _cameraPos += _cameraUp * _speedFront;

    if (!_keys.e)
        _cameraPos += -_cameraUp * _speedFront;

    _transform.viewPoint = glm::lookAt(_cameraPos, _cameraPos + _cameraFront, _cameraUp);
    _ubo.update(static_cast<GLvoid*>(&_transform), sizeof(_transform));

    return 0;
}

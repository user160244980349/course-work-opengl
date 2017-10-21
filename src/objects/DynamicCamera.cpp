//
// Created by user on 21.10.2017.
//

#include <glm/gtc/matrix_transform.hpp>
#include "objects/DynamicCamera.h"


application::objects::DynamicCamera::DynamicCamera() {

    _mouse_x = 0.0f;
    _mouse_y = 0.0f;
    _sensitivity = 0.1f;

    glm::vec3 front = glm::vec3(1.0f, 0.0f, 0.0f);

    _cameraPos   = glm::vec3(-6.0f, 1.0f,  2.0f);
    _cameraUp    = glm::vec3(0.0f, 1.0f, 0.0f);
    _cameraFront = glm::normalize(front);

    _transform.projection = glm::perspective(glm::radians(50.0f), 16.0f / 9.0f, 0.1f, 100.0f);
    _transform.viewPoint = glm::lookAt(_cameraPos, _cameraPos + _cameraFront, _cameraUp);

    _ubo.create();
    _ubo.set((GLvoid*)&_transform, sizeof(_transform));

}

int application::objects::DynamicCamera::use(GLuint shaderProgramId) {

    _ubo.connect(shaderProgramId, 0, "camera");

    return 0;
}

int application::objects::DynamicCamera::controlResponse(SDL_Event event) {

    switch (event.type) {
        case SDL_MOUSEMOTION:
            _mouse_x += event.motion.xrel * _sensitivity;
            _mouse_y -= event.motion.yrel * _sensitivity;

            if (_mouse_y > 89.0f)
                _mouse_y = 89.0f;
            if (_mouse_y < -89.0f)
                _mouse_y = -89.0f;

            _cameraFront = glm::normalize(glm::vec3(
                    cosf(glm::radians(_mouse_y)) * cosf(glm::radians(_mouse_x)),
                    sinf(glm::radians(_mouse_y)),
                    cosf(glm::radians(_mouse_y)) * sinf(glm::radians(_mouse_x)))
            );
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_w:
                    _cameraPos += _cameraFront;
                    break;
                case SDLK_s:
                    _cameraPos -= _cameraFront;
                    break;
                case SDLK_q:
                    _cameraPos += _cameraUp;
                    break;
                case SDLK_e:
                    _cameraPos -= _cameraUp;
                    break;
                default:
                    break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym) {


                default:
                    break;
            }
            break;
        default:
            break;
    }

    _transform.viewPoint = glm::lookAt(_cameraPos, _cameraPos + _cameraFront, _cameraUp);
    _ubo.update((GLvoid*)&_transform, sizeof(_transform));

    return 0;
}

int application::objects::DynamicCamera::update(SDL_Event event) {

    controlResponse(event);

    return 0;
}
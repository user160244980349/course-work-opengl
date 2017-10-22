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

    _cameraPos   = glm::vec3(-6.0f, 1.0f,  2.0f);
    _cameraUp    = glm::vec3(0.0f, 1.0f, 0.0f);
    _cameraFront = glm::normalize(front);

    _transform.projection = glm::perspective(glm::radians(50.0f), 16.0f / 9.0f, 0.1f, 100.0f);
    _transform.viewPoint = glm::lookAt(_cameraPos, _cameraPos + _cameraFront, _cameraUp);

    _ubo.create();
    _ubo.set((GLvoid*)&_transform, sizeof(_transform));

}

int application::objects::DynamicCamera::use(GLuint shaderProgramId) {

    _ubo.connect(shaderProgramId, CAMERA_BIND_INDEX, "camera");

    return 0;
}

int application::objects::DynamicCamera::controlResponse(SDL_Event event) {

    static glm::vec3 movement{};

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
                    movement = _cameraFront * _speedFront;
                    break;
                case SDLK_s:
                    movement = -_cameraFront * _speedFront;
                    break;
                case SDLK_q:
                    movement = _cameraUp * _speedUp;
                    break;
                case SDLK_e:
                    movement = -_cameraUp * _speedUp;
                    break;
                default: break;
            }
            break;

        case SDL_KEYUP:
//        case SDLK_DOWN:
//            if( alien_yvel > 0 )
//                alien_yvel = 0;
            movement = glm::vec3(0.0f, 0.0f, 0.0f);
            break;
        default: break;
    }

    _cameraPos += movement;
    _transform.viewPoint = glm::lookAt(_cameraPos, _cameraPos + _cameraFront, _cameraUp);
    _ubo.update((GLvoid*)&_transform, sizeof(_transform));

    return 0;
}
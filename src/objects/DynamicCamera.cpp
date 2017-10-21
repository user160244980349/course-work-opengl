//
// Created by user on 21.10.2017.
//

#include <glm/gtc/matrix_transform.hpp>
#include "objects/DynamicCamera.h"


application::objects::DynamicCamera::DynamicCamera() {

    glm::vec3 front = glm::vec3(1.0f, 0.0f, 0.0f);

    _cameraPos   = glm::vec3(-6.0f, 0.0f,  0.0f);
    _cameraUp    = glm::vec3(0.0f, 1.0f, 0.0f);
    _cameraFront = glm::normalize(front);

    _transform.projection = glm::perspective(glm::radians(50.0f), 16.0f / 9.0f, 0.1f, 100.0f);
    _transform.viewPoint = glm::lookAt(_cameraPos, _cameraPos + _cameraFront, _cameraUp);

    _ubo.create();
    _ubo.set((GLvoid*)&_transform, sizeof(_transform));

}

int application::objects::DynamicCamera::use(GLuint shaderProgramId) {

    _ubo.connect(shaderProgramId, "camera");

    return 0;
}

int application::objects::DynamicCamera::controlResponse(SDL_Event event) {

    glm::vec3 front;
    GLfloat mouse_x = event.motion.xrel;
    GLfloat mouse_y = event.motion.yrel;

    if(mouse_y > 89.0f)
        mouse_y =  89.0f;
    if(mouse_y < -89.0f)
        mouse_y = -89.0f;

    front.x = cosf(glm::radians(mouse_y)) * cosf(glm::radians(mouse_x));
    front.y = sinf(glm::radians(mouse_y));
    front.z = cosf(glm::radians(mouse_y)) * sinf(glm::radians(mouse_x));

    _cameraFront = glm::normalize(front);

    _transform.viewPoint = glm::lookAt(_cameraPos, _cameraPos + _cameraFront, _cameraUp);

    _ubo.update(&_transform, sizeof(_transform));

    return 0;
}

int application::objects::DynamicCamera::update(SDL_Event event) {

    controlResponse(event);

    return 0;
}
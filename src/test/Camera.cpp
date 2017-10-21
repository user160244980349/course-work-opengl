//
// Created by user on 21.10.2017.
//

#include <glm/gtc/matrix_transform.hpp>
#include "test/Camera.h"

int application::test::Camera::use(GLuint shaderProgramId) {

    _ubo.connect(shaderProgramId, 0, "camera");

    return 0;
}

application::test::Camera::Camera() {

    glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);

    _ubo.create();
    _ubo.set((GLvoid*)&_transform, sizeof(_transform));

    _cameraPos   = glm::vec3(0.0f, 1.0f, 4.0f);
    _cameraUp    = glm::vec3(0.0f, 0.0f, 0.0f);
    _cameraFront = glm::normalize(front);

    _transform.projection = glm::perspective(glm::radians(50.0f), 16.0f / 9.0f, 0.1f, 100.0f);
    _transform.viewPoint = glm::lookAt(_cameraPos, _cameraPos + _cameraFront, _cameraUp);

}





//    if(environment::mouse_y > 89.0f)
//        environment::mouse_y =  89.0f;
//    if(environment::mouse_y < -89.0f)
//        environment::mouse_y = -89.0f;
//    front.x = cos(glm::radians(environment::mouse_y)) * cos(glm::radians(environment::mouse_x));
//    front.y = sin(glm::radians(environment::mouse_y));
//    front.z = cos(glm::radians(environment::mouse_y)) * sin(glm::radians(environment::mouse_x));
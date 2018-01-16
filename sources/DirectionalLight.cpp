//
// Created by user on 16.01.2018.
//

#include <glm/gtc/matrix_transform.hpp>
#include <SDL2/SDL_timer.h>
#include <core/Shader.h>
#include <vector>
#include <functional>
#include <iostream>
#include "core/DirectionalLight.h"

void DirectionalLight::prepare() {
    float near_plane = 1.0f, far_plane = 7.5f;
    _lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, near_plane, far_plane);
    _lightIntense = 0.1f;
}

void DirectionalLight::update(std::vector<std::reference_wrapper<Shader>> shaders) {

    float time = SDL_GetTicks() * 0.001f;
    glm::vec3 _lightColor = glm::normalize(glm::vec3(sinf(time), cosf(time + 1), sinf(time + 2)));
    _lightView = glm::lookAt(_lightPosition, glm::vec3(0.0f), glm::vec3(0.0, 1.0, 0.0));

    for (std::reference_wrapper<Shader> shader : shaders) {
        shader.get().use();
        shader.get().setUniform("lightColor", _lightColor);
        shader.get().setUniform("lightIntense", _lightIntense);
    }
}

glm::mat4 DirectionalLight::getProjection() {
    return _lightProjection;
}

glm::vec3 DirectionalLight::getPosition() {
    return _lightPosition;
}

glm::mat4 DirectionalLight::getView() {
    return _lightView;
}

glm::vec3 DirectionalLight::getLightColor() {
    return _lightColor;
}

float DirectionalLight::getLightIntense() {
    return _lightIntense;
}

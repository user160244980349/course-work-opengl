//
// Created by user on 16.01.2018.
//

#include <glm/gtc/matrix_transform.hpp>
#include <core/Shader.h>
#include <vector>
#include <functional>
#include <iostream>
#include <SDL2/SDL_timer.h>
#include "core/DirectionalLight.h"

void DirectionalLight::prepare() {
    float near_plane = 1.0f, far_plane = 100.0f;
    _lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, near_plane, far_plane);
    _lightIntense = 0.1f;
}

void DirectionalLight::update(std::vector<std::reference_wrapper<Shader>> shaders) {

    float time = SDL_GetTicks() * 0.0001f;
    glm::vec3 _lightColor = glm::normalize(glm::vec3(sinf(time), cosf(time + 1), sinf(time + 2)));
    glm::vec3 lightPosition = glm::vec3(0.0f, 4.0f, 0.0f);
    _lightDirection = glm::vec3(sinf(time) * 5.0f, 8.0f, cosf(time) * 5.0f);
    _lightView = glm::lookAt(_lightDirection, lightPosition, glm::vec3(0.0f, 1.0f, 0.0));

    for (std::reference_wrapper<Shader> shader : shaders) {
        shader.get().use();
        shader.get().setUniform("lightPos", lightPosition - _lightDirection);
        shader.get().setUniform("lightView", _lightView);
        shader.get().setUniform("lightProjection", _lightProjection);
        shader.get().setUniform("lightColor", _lightColor);
        shader.get().setUniform("lightIntense", _lightIntense);
    }
}

glm::mat4 DirectionalLight::getProjection() {
    return _lightProjection;
}

glm::vec3 DirectionalLight::getDirection() {
    return _lightDirection;
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

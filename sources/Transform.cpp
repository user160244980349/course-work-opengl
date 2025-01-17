#include <glm/gtc/matrix_transform.hpp>

#include "../include/core/Transform.h"

void Transform::translate(glm::vec3 position) {
    _model = glm::translate(_model, position);
}

Transform::Transform() {
    _model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f));
    scale(glm::vec3(1.0f));
}

void Transform::rotate(float angle, glm::vec3 axis) {
    _model = glm::rotate(_model, angle, axis);
}

glm::mat4 Transform::getModel() {
    return _model;
}

void Transform::scale(glm::vec3 size) {
    _model = glm::scale(_model, size);
}

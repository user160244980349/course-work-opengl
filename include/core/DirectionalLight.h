#ifndef OPENGL_DIRECTIONALLIGHT_H
#define OPENGL_DIRECTIONALLIGHT_H


#include <vector>
#include <glm/vec3.hpp>
#include <glm/detail/type_mat4x4.hpp>

#include "Shader.h"

class DirectionalLight {
public:
    void prepare();
    void update(std::vector<std::reference_wrapper<Shader>> shaders);
    glm::mat4 getProjection();
    glm::vec3 getDirection();
    glm::mat4 getView();
    glm::vec3 getLightColor();
    float getLightIntense();

protected:
    glm::mat4 _lightProjection;
    glm::vec3 _lightDirection;
    glm::mat4 _lightView;
    glm::vec3 _lightColor;
    float _lightIntense;
};


#endif //OPENGL_DIRECTIONALLIGHT_H

#ifndef OPENGL_TRANSFORM_H
#define OPENGL_TRANSFORM_H


#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

#include "../interfaces/ITransform.h"

class Transform : public ITransform {
public:
    Transform();
    void translate(glm::vec3 position) override;
    void rotate(float angle, glm::vec3 axis) override;
    void scale(glm::vec3 size) override;
    glm::mat4 getModel() override;

protected:
    glm::mat4 _model;
};


#endif //OPENGL_TRANSFORM_H

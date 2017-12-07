//
// Created by user on 07.12.2017.
//

#ifndef OPENGL_TRANSFORM_H
#define OPENGL_TRANSFORM_H


#include <interfaces/ITransform.h>
#include <glm/detail/type_mat.hpp>
#include <glm/detail/type_mat4x4.hpp>

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

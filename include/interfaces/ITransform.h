//
// Created by user on 07.12.2017.
//

#ifndef OPENGL_ITRANSFORM_H
#define OPENGL_ITRANSFORM_H

#include <glm/vec3.hpp>
#include <glm/detail/type_mat.hpp>

class ITransform {
public:
    virtual ~ITransform() = default;;

    virtual void translate(glm::vec3 position) {};

    virtual void rotate(float angle, glm::vec3 axis) {};

    virtual void scale(glm::vec3 size) {};

    virtual glm::mat4 getModel() {};
};

#endif //OPENGL_ITRANSFORM_H

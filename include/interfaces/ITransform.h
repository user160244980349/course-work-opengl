#ifndef OPENGL_ITRANSFORM_H
#define OPENGL_ITRANSFORM_H


#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

class ITransform {
public:
    virtual ~ITransform() = default;;
    virtual void translate(glm::vec3 position) = 0;
    virtual void rotate(float angle, glm::vec3 axis) = 0;
    virtual void scale(glm::vec3 size) = 0;
    virtual glm::mat4 getModel() = 0;
};


#endif //OPENGL_ITRANSFORM_H

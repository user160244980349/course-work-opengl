#ifndef OPENGL_ABSTRACTCAMERA_H
#define OPENGL_ABSTRACTCAMERA_H


#include <vector>
#include <core/Shader.h>
#include <GL/glcorearb.h>
#include <glm/vec3.hpp>
#include <glm/detail/type_mat.hpp>
#include <glm/detail/type_mat4x4.hpp>

class ICamera {
public:
    virtual ~ICamera() = default;
    virtual void prepare() {};
    virtual void update(std::vector<std::reference_wrapper<Shader>> shaders) {};
    virtual glm::mat4 getView() {};
    virtual glm::mat4 getProjection() {};
    virtual glm::vec3 getPosition() {};
};


#endif //OPENGL_ABSTRACTCAMERA_H

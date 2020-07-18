#ifndef OPENGL_ABSTRACTCAMERA_H
#define OPENGL_ABSTRACTCAMERA_H


#include <vector>
#include <GL/glcorearb.h>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

#include "../core/Shader.h"

class ICamera {
public:
    virtual ~ICamera() = default;
    virtual void prepare() = 0;
    virtual void update(std::vector<std::reference_wrapper<Shader>> shaders) = 0;
    virtual glm::mat4 getView() = 0;
    virtual glm::mat4 getProjection() = 0;
    virtual glm::vec3 getPosition() = 0;
};


#endif //OPENGL_ABSTRACTCAMERA_H

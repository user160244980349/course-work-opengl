//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_ABSTRACTCAMERA_H
#define OPENGL_ABSTRACTCAMERA_H

#include <GL/glcorearb.h>
#include <glm/detail/type_mat.hpp>
#include <glm/vec3.hpp>
#include <glm/detail/type_mat4x4.hpp>


class ICamera {
public:
    virtual int use(GLuint shaderProgramId) {};
    virtual int update() {};
};


#endif //OPENGL_ABSTRACTCAMERA_H

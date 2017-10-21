//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_ABSTRACTCAMERA_H
#define OPENGL_ABSTRACTCAMERA_H


#include <glm/detail/type_mat.hpp>
#include <glm/vec3.hpp>
#include <glm/detail/type_mat4x4.hpp>
#include <graphics/ubo.h>

namespace application::objects {

    class AbstractCamera {
    public:
        virtual int use(GLuint shaderProgramId) = 0;
    protected:
        graphics::ubo _ubo;
        struct {
            glm::mat4 projection;
            glm::mat4 viewPoint;
        } _transform;
        glm::vec3 _cameraPos;
        glm::vec3 _cameraUp;
        glm::vec3 _cameraFront;
    };

}


#endif //OPENGL_ABSTRACTCAMERA_H

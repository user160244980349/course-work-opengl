//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_ABSTRACTOBJECT_H
#define OPENGL_ABSTRACTOBJECT_H

#include <graphics/Vao.h>
#include <graphics/Vbo.h>
#include <graphics/Ubo.h>
#include <graphics/Ebo.h>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <graphics/Shader.h>

namespace application::objects {

    class AbstractObject {
    protected:
        struct {
            graphics::Vao vao;
            graphics::Vbo vbo;
            graphics::Ebo ebo;
            graphics::Ubo ubo;
        } _buffers;

        struct {
            glm::mat4 model = glm::mat4(1.0f);
        } _transform;

        std::vector <graphics::Vertex3d> _vertices{};
        std::vector <GLuint> _order{};
        std::vector <graphics::Shader> _shaders{};
    };

}


#endif //OPENGL_ABSTRACTOBJECT_H

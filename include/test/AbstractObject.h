//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_ABSTRACTOBJECT_H
#define OPENGL_ABSTRACTOBJECT_H

#include <graphics/vao.h>
#include <graphics/vbo.h>
#include <graphics/ubo.h>
#include <glm/detail/type_mat.hpp>
#include <graphics/ebo.h>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <graphics/shader.h>

namespace application::test {

    class AbstractObject {
    protected:
        struct {
            graphics::vao vao;
            graphics::vbo vbo;
            graphics::ebo ebo;
            graphics::ubo ubo;
        } _buffers;

        glm::mat4 _transform = glm::mat4(1.0f);

        std::vector <graphics::vertex_3d> _vertices;
        std::vector <GLuint> _order;
        std::vector <graphics::shader> _shaders;
    };

}


#endif //OPENGL_ABSTRACTOBJECT_H

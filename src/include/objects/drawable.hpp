//
// Created by user on 15.10.2017.
//

#ifndef OPENGL_DRAWABLE_HPP
#define OPENGL_DRAWABLE_HPP


#include <graphics/vao.hpp>
#include <graphics/vbo.hpp>
#include <graphics/ebo.hpp>
#include <graphics/ubo.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <graphics/vertex_3d.hpp>
#include <vector>
#include <graphics/shader.hpp>

namespace application::objects {

    class drawable {
    public:
        virtual int prepare() = 0;
        virtual int draw() = 0;

    protected:
        struct {
            graphics::vao vao;
            graphics::vbo vbo;
            graphics::ebo ebo;
            graphics::ubo ubo;
        } _buffers;

        struct {
            glm::mat4 perspective = glm::perspective(glm::radians(50.0f), 16.0f / 9.0f, 0.1f, 100.0f);
            glm::mat4 view;
            glm::mat4 model = glm::mat4(1.0f);
        } _transform;

        std::vector<graphics::vertex_3d> _vertices;
        std::vector<GLuint> _order;
        std::vector<graphics::shader> _shaders;
    };

}


#endif //OPENGL_DRAWABLE_HPP

//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_BASE_OBJECT_HPP
#define OPENGL_BASE_OBJECT_HPP

#include <vector>
#include <buffers/ubo.hpp>
#include "abstract_object.hpp"
#include "shader.hpp"
#include "vertex_3d.hpp"
#include "buffers/vao.hpp"
#include "buffers/vbo.hpp"
#include "buffers/ebo.hpp"

namespace application::objects {

    class base_object : public abstract_object {
    protected:

        struct {
            graphics::vao vao;
            graphics::vbo vbo;
            graphics::ebo ebo;
            graphics::ubo ubo;
        } buffers;

        std::vector<graphics::vertex_3d> verices;
        std::vector<GLuint> order;
        std::vector<graphics::shader> shaders;

    public:

        int prepare() override;
        int draw() override;
    };

}


#endif //OPENGL_BASE_OBJECT_HPP

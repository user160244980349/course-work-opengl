//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_BASE_OBJECT_HPP
#define OPENGL_BASE_OBJECT_HPP

#include <vector>
#include "abstract_object.hpp"
#include "shader.hpp"
#include "vertex_3d.hpp"
#include "base_vao_vbo.hpp"

namespace application::objects {

    class base_object : public abstract_object {
    protected:
        graphics::base_vao_vbo buffers;
        std::vector<graphics::vertex_3d> verices;
        std::vector<GLuint> order;
        std::vector<graphics::shader> shaders;

    public:
        int prepare() override;
        int draw() override;
        int draw_wf();
    };

}


#endif //OPENGL_BASE_OBJECT_HPP

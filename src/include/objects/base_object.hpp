//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_BASE_OBJECT_HPP
#define OPENGL_BASE_OBJECT_HPP

#include <vector>
#include "objects/abstractions/abstract_object.hpp"
#include "application/shader.hpp"
#include "application/vertex_2d.hpp"
#include "application/base_vao_vbo.hpp"

namespace application::objects {

    class base_object : public abstract_object {
    protected:
        graphics::base_vao_vbo buffers;
        std::vector<graphics::vertex_2d> verices;
        std::vector<graphics::shader> shaders;

    public:
        int prepare() override;
        int draw() override;
    };

}


#endif //OPENGL_BASE_OBJECT_HPP

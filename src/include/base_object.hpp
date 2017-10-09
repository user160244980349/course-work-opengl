//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_BASE_OBJECT_HPP
#define OPENGL_BASE_OBJECT_HPP

#include <vector>
#include <vec3.hpp>
#include "shader.hpp"
#include "vertex.hpp"
#include "vao_vbo.hpp"

namespace application::objects {

    class base_object {
    protected:
        graphics::vao_vbo buffers;
        std::vector<graphics::vertex> verices;
        std::vector<graphics::shader> shaders;

    public:
        virtual int prepare();
        virtual int draw();
    };

}


#endif //OPENGL_BASE_OBJECT_HPP

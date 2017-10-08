//
// Created by user on 08.10.2017.
//

#ifndef OPENGL_BASE_OBJECT_HPP
#define OPENGL_BASE_OBJECT_HPP

#include "shader.hpp"
#include "vao_vbo.hpp"
#include "vao.hpp"
#include "vbo.hpp"

namespace application::objects {

    class base_object {
    private:

        struct {
            graphics::shader s1;
        } shaders;

        struct {
            graphics::vao vao_buffer;
            graphics::vbo vbo_buffer;
        } buffers;

    public:
        int prepare_shaders();
        int draw();
    };

}


#endif //OPENGL_BASE_OBJECT_HPP

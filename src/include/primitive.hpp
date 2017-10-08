//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_PRIMITIVE_HPP
#define OPENGL_PRIMITIVE_HPP

#include "shader.hpp"

namespace application::objects {

    class primitive {
    private:

        struct {
            graphics::shader s1;
        } shaders;

    public:
        int prepare_shaders();
        int draw();
    };

}

#endif //OPENGL_PRIMITIVE_HPP

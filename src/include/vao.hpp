//
// Created by user on 08.10.2017.
//

#ifndef OPENGL_VAO_HPP
#define OPENGL_VAO_HPP

#include "GL/glew.h"
#include "vbo.hpp"

namespace application::graphics {

    class vao {
    private:
        GLuint buffer;

    public:
        ~vao();
        int create();
        int set(vbo b);
        int bind();
    };

}


#endif //OPENGL_VAO_HPP
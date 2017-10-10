//
// Created by user on 11.10.2017.
//

#ifndef OPENGL_BUFFERS_COMBO_HPP
#define OPENGL_BUFFERS_COMBO_HPP


#include <GL/glew.h>

namespace application::graphics {

    typedef struct {
        GLuint vao;
        GLuint vbo;
        GLuint ds;
    } buffers_combo;

}


#endif //OPENGL_BUFFERS_COMBO_HPP

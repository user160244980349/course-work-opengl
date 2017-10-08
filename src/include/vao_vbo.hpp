//
// Created by user on 08.10.2017.
//

#ifndef OPENGL_VAO_VBO_HPP
#define OPENGL_VAO_VBO_HPP

#include <GL/glew.h>

namespace application::graphics {

    class vao_vbo {
    private:
        struct {
            GLuint VAO;
            GLuint VBO;
        } buffers;

    public:
        ~vao_vbo();
        int prepare();
        int draw();
    };

}

#endif //OPENGL_VAO_VBO_HPP

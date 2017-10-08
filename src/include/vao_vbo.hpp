//
// Created by user on 08.10.2017.
//

#ifndef OPENGL_VAO_VBO_HPP
#define OPENGL_VAO_VBO_HPP

#include <GL/glew.h>

namespace application::graphics {

    class vao_vbo {
    private:
        GLuint VAO;
        GLuint VBO;

    public:
        ~vao_vbo();
        int prepare(GLfloat *vertices, int count);
        int draw(int count);
    };

}

#endif //OPENGL_VAO_VBO_HPP

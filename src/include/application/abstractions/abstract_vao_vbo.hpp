//
// Created by user on 11.10.2017.
//

#ifndef OPENGL_ABSTRACT_VAO_VBO_HPP
#define OPENGL_ABSTRACT_VAO_VBO_HPP


#include <GL/glew.h>

namespace application::graphics {

    class abstract_vao_vbo {
    protected:

    public:
        virtual int delete_buffer_combo(unsigned int n);
        virtual int bind(unsigned int n, unsigned int  count, GLuint *o);
    };

}


#endif //OPENGL_ABSTRACT_VAO_VBO_HPP

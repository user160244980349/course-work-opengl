//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_VAO_VBO_HPP
#define OPENGL_VAO_VBO_HPP


#include <GL/glew.h>
#include <vector>
#include <vertex.hpp>

namespace application::graphics {

    typedef struct {
        GLuint vao;
        GLuint vbo;
        GLuint ds;
    } buffers_combo;

    class vao_vbo {
    protected:
        std::vector<buffers_combo> buffers;

    public:
        ~vao_vbo();
        int new_buffer_combo(GLuint draw_style, std::vector<vertex> &v);
        int delete_buffer_combo(unsigned int n);
        int bind(unsigned int n, std::vector<application::graphics::vertex> v);
    };

}

#endif //OPENGL_VAO_VBO_HPP

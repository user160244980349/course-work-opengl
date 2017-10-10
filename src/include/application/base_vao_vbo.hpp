//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_BASE_VAO_VBO_HPP
#define OPENGL_BASE_VAO_VBO_HPP


#include <GL/glew.h>
#include <vector>
#include "vertex_2d.hpp"
#include "buffers_combo.hpp"
#include "application/abstractions/abstract_vao_vbo.hpp"

namespace application::graphics {

    class base_vao_vbo : public abstract_vao_vbo {
    protected:
        std::vector<buffers_combo> buffers;

    public:
        ~base_vao_vbo();
        int new_buffer_combo(GLuint ds, std::vector<vertex_2d> &v);
        int delete_buffer_combo(unsigned int n) override;
        int bind(unsigned int i, unsigned int  c, GLuint *o) override;
    };

}

#endif //OPENGL_VAO_VBO_HPP

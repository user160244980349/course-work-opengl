//
// Created by user on 13.10.2017.
//

#ifndef OPENGL_VAO_HPP
#define OPENGL_VAO_HPP


#include "abstract_buffer.hpp"

namespace application::graphics {

    class vao : public abstract_buffer {
    protected:

    public:
        ~vao();
        int create() override;
        int bind();
        int unbind();
        int bind(GLuint draw_style, GLuint used_vertices);
    };

}


#endif //OPENGL_VAO_HPP

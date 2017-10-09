//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_SHADER_HPP
#define OPENGL_SHADER_HPP

#include <GL/glew.h>

namespace application::graphics {

    class shader {
    private:

        struct {
            GLuint shader_program = 0;
            GLuint vertex_shader = 0;
            GLuint fragment_shader = 0;
        } shader_variables;

    public:
        shader(const GLchar *vertex_path, const GLchar *fragment_path);
        ~shader();
        int use();
    };

}

#endif //OPENGL_SHADER_HPP

//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_SHADER_HPP
#define OPENGL_SHADER_HPP

#include <GL/glew.h>

namespace application::graphics {

    class shader {
    private:

        GLuint VAO = 0;
        GLuint VBO = 0;

        GLfloat vertices[9] = {
                -0.5f, -0.5f, 1.0f,
                0.5f, -0.5f, 1.0f,
                0.0f,  0.5f, 1.0f
        };

        struct {
            GLuint shader_program = 0;
            GLuint vertex_shader = 0;
            GLuint fragment_shader = 0;
        } shader_variables;

    public:
        ~shader();
        int prepare(const GLchar *vertex_path, const GLchar *fragment_path);
        int draw();
    };

}

#endif //OPENGL_SHADER_HPP

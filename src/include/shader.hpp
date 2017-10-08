//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_SHADER_HPP
#define OPENGL_SHADER_HPP

#include <GL/glew.h>

namespace application::graphics {

    class shader {
    private:

        GLuint VAO;
        GLuint VBO;

        struct {
            GLuint shader_program;
            GLuint vertex_shader;
            GLuint fragment_shader;
        } shader_variables;

    public:
        int prepare(const GLchar *vertex_path, const GLchar *fragment_path);
        int draw();
    };

}

#endif //OPENGL_SHADER_HPP

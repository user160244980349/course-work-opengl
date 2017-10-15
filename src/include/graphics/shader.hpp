//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_SHADER_HPP
#define OPENGL_SHADER_HPP

#include <GL/glew.h>

namespace application::graphics {

    class shader {
    protected:

    public:

        GLuint shader_program_id = 0;

        shader(const GLchar *vertex_path, const GLchar *fragment_path);
        int use();
    };

}

#endif //OPENGL_SHADER_HPP

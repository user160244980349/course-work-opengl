//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H

#include <GL/glew.h>

namespace application::graphics {

    class shader {
    public:
        GLuint shader_program_id = 0;

        shader(const GLchar *vertex_path, const GLchar *fragment_path);
        int use();

    protected:

    };

}

#endif //OPENGL_SHADER_H

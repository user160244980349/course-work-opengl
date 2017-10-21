//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H

#include <GL/glew.h>

namespace application::graphics {

    class Shader {
    public:
        GLuint ShaderProgramId = 0;

        Shader(const GLchar *vertexPath, const GLchar *fragmentPath);
        int use();
    };

}

#endif //OPENGL_SHADER_H
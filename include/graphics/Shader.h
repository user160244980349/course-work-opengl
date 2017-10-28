//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H

#include <glcorearb.h>


namespace application::graphics {

    class Shader {
    public:
        GLuint shaderProgramId = 0;

        Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
        int use();
    };

}

#endif //OPENGL_SHADER_H

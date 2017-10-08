//
// Created by user on 08.10.2017.
//

#ifndef OPENGL_VBO_HPP
#define OPENGL_VBO_HPP

#include "GL/glew.h"

namespace application::graphics {

    class vbo {
    private:

        GLuint buffer;

    public:
        ~vbo();
        int create();
        int set();
        GLuint get();
    };

}


#endif //OPENGL_VBO_HPP

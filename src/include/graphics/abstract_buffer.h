//
// Created by user on 13.10.2017.
//

#ifndef OPENGL_ABSTRACT_BUFFER_H
#define OPENGL_ABSTRACT_BUFFER_H


#include <GL/glew.h>

namespace application::graphics {

    class abstract_buffer {
    public:
        GLuint id;

        virtual int create() = 0;

    protected:

    };

}


#endif //OPENGL_ABSTRACT_BUFFER_H

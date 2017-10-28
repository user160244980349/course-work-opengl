//
// Created by user on 13.10.2017.
//

#ifndef OPENGL_ABSTRACT_BUFFER_H
#define OPENGL_ABSTRACT_BUFFER_H

#include <glcorearb.h>

namespace application::graphics {

    class ABuffer {
    public:
        GLuint id{};

        virtual int create() = 0;
    };

}


#endif //OPENGL_ABSTRACT_BUFFER_H

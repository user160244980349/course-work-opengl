//
// Created by user on 13.10.2017.
//

#ifndef OPENGL_ABSTRACT_BUFFER_H
#define OPENGL_ABSTRACT_BUFFER_H

#include <GL/glcorearb.h>


class ABuffer {
public:
    GLuint id{};
    virtual ~ABuffer() {};
    virtual void create() {};
    virtual void remove() {};
};


#endif //OPENGL_ABSTRACT_BUFFER_H

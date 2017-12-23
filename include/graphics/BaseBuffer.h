//
// Created by user on 13.10.2017.
//

#ifndef OPENGL_ABSTRACT_BUFFER_H
#define OPENGL_ABSTRACT_BUFFER_H

#include <GL/glcorearb.h>

class BaseBuffer {
public:
    virtual ~BaseBuffer() = default;;

    virtual void create() {};

    virtual void remove() {};

    virtual unsigned int getId();

protected:
    unsigned int _id{};
};

#endif //OPENGL_ABSTRACT_BUFFER_H

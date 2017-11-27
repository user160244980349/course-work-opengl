//
// Created by user on 13.10.2017.
//

#ifndef OPENGL_EBO_H
#define OPENGL_EBO_H

#include <graphics/ABuffer.h>


class Ebo : public ABuffer {
public:
    ~Ebo();
    int create() override;
    int set(GLuint *o, GLuint size);
};


#endif //OPENGL_EBO_H

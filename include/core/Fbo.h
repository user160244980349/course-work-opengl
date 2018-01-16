//
// Created by user on 16.01.2018.
//

#ifndef OPENGL_FBO_H
#define OPENGL_FBO_H


#include "BaseBuffer.h"

class Fbo : public BaseBuffer {
public:

    void create() override;

    void remove() override;

    void bind();

    void render(GLuint drawStyle, unsigned long long int usedVertices);

    void render(GLuint drawStyle, unsigned int first, unsigned long long int usedVertices);
};


#endif //OPENGL_FBO_H

//
// Created by user on 13.10.2017.
//

#ifndef OPENGL_VAO_H
#define OPENGL_VAO_H

#include "BaseBuffer.h"

class Vao : public BaseBuffer {
public:
    void create() override;

    void remove() override;

    void bind();

    void render(GLuint drawStyle, unsigned long long int usedVertices);
};


#endif //OPENGL_VAO_H

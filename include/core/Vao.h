#ifndef OPENGL_VAO_H
#define OPENGL_VAO_H


#include "BaseBuffer.h"

class Vao : public BaseBuffer {
public:
    void create() override;
    void remove() override;
    void bind();
    void render(GLuint drawStyle, unsigned long long int usedVertices);
    void render(GLuint drawStyle, unsigned int first, unsigned long long int usedVertices);
};


#endif //OPENGL_VAO_H

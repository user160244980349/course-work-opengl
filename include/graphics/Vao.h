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
    void bind(GLuint draw_style, GLuint used_vertices);
};


#endif //OPENGL_VAO_H

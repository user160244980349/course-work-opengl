//
// Created by user on 13.10.2017.
//

#ifndef OPENGL_VAO_H
#define OPENGL_VAO_H

#include "ABuffer.h"

namespace application::graphics {

    class Vao : public ABuffer {
    public:
        ~Vao();
        int create() override;
        int bind();
        int bind(GLuint draw_style, GLuint used_vertices);
    };

}


#endif //OPENGL_VAO_H

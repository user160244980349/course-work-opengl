//
// Created by user on 13.10.2017.
//

#ifndef OPENGL_VBO_H
#define OPENGL_VBO_H


#include <graphics/AbstractBuffer.h>
#include "graphics/Vertex3d.h"

namespace application::graphics {

    class Vbo : public AbstractBuffer {
    public:
        ~Vbo();
        int create() override;
        int set(Vertex3d *v, GLuint size);
    };

}


#endif //OPENGL_VBO_H

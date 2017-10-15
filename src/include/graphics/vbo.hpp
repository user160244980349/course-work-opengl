//
// Created by user on 13.10.2017.
//

#ifndef OPENGL_VBO_HPP
#define OPENGL_VBO_HPP


#include <graphics/abstract_buffer.hpp>
#include "graphics/vertex_3d.hpp"

namespace application::graphics {

    class vbo : public abstract_buffer {
    public:
        int create() override;
        int set(vertex_3d *v, GLuint size);

    protected:

    };

}


#endif //OPENGL_VBO_HPP

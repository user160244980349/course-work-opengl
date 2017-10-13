//
// Created by user on 13.10.2017.
//

#ifndef OPENGL_VBO_HPP
#define OPENGL_VBO_HPP


#include <buffers/abstract_buffer.hpp>

namespace application::graphics {

    class vbo : public abstract_buffer {
    protected:

    public:

        int create() override;
        int set(vertex_3d *v);
    };

}


#endif //OPENGL_VBO_HPP

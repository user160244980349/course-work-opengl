//
// Created by user on 13.10.2017.
//

#ifndef OPENGL_EBO_HPP
#define OPENGL_EBO_HPP


#include <buffers/abstract_buffer.hpp>

namespace application::graphics {

    class ebo : public abstract_buffer {
    protected:

    public:

        int create() override;
        int set(GLuint *v);
    };

}


#endif //OPENGL_EBO_HPP

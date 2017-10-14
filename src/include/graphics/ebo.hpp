//
// Created by user on 13.10.2017.
//

#ifndef OPENGL_EBO_HPP
#define OPENGL_EBO_HPP


#include <graphics/abstract_buffer.hpp>

namespace application::graphics {

    class ebo : public abstract_buffer {
    protected:

    public:

        int create() override;
        int set(GLuint *o, GLuint size);
    };

}


#endif //OPENGL_EBO_HPP

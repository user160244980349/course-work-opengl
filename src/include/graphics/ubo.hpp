//
// Created by user on 14.10.2017.
//

#ifndef OPENGL_UBO_HPP
#define OPENGL_UBO_HPP


#include <graphics/abstract_buffer.hpp>

namespace application::graphics {

    class ubo : public abstract_buffer {
    public:
        ~ubo();
        int create() override;
        int set(GLvoid *data, GLuint size);
        int update(GLvoid *data, GLuint size);
        int connect(GLuint program);
    };

}


#endif //OPENGL_UBO_HPP

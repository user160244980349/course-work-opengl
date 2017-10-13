//
// Created by user on 14.10.2017.
//

#ifndef OPENGL_UBO_HPP
#define OPENGL_UBO_HPP


#include <glm/mat4x4.hpp>
#include <buffers/abstract_buffer.hpp>

namespace application::graphics {

    class ubo : public abstract_buffer {
    protected:

    public:

        int create() override;
        int set();
        int update();
        int connect(GLuint program);
    };

}


#endif //OPENGL_UBO_HPP

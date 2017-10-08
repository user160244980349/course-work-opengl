//
// Created by user on 08.10.2017.
//

#ifndef OPENGL_BASE_OBJECT_HPP
#define OPENGL_BASE_OBJECT_HPP

#include <vector>
#include <vec3.hpp>
#include "shader.hpp"
#include "vao.hpp"
#include "vbo.hpp"

namespace application::objects {

    class base_object {
    private:

        struct {
            graphics::vao vao_buffer;
            graphics::vbo vbo_buffer;
        } buffers;

        std::vector<glm::vec3> verices;
        std::vector<graphics::shader> shaders;

    public:
        int prepare();
        int draw();
    };

}


#endif //OPENGL_BASE_OBJECT_HPP

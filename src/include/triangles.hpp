//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_TRIANGLES_HPP
#define OPENGL_TRIANGLES_HPP

#include "base_object.hpp"

namespace application::objects {

    class triangles : protected base_object {
    protected:
        graphics::vao_vbo buffers;
        std::vector<graphics::vertex> verices;
        std::vector<graphics::shader> shaders;

    public:
        int prepare() override;
        int draw() override;
    };

}


#endif //OPENGL_TRIANGLES_HPP

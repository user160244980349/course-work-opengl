//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_VERTEX_2D_HPP
#define OPENGL_VERTEX_2D_HPP


#include <vec3.hpp>
#include <vec2.hpp>


namespace application::graphics {

    typedef struct  {
        glm::vec2 position;
        glm::vec3 color;
    } vertex_2d;

}

#endif //OPENGL_VERTEX_HPP

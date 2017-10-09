//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_VERTEX_HPP
#define OPENGL_VERTEX_HPP


#include <vec3.hpp>
#include <vec2.hpp>


namespace application::graphics {

    typedef struct  {
        glm::vec2 position;
        glm::vec3 color;
    } vertex;

}

#endif //OPENGL_VERTEX_HPP

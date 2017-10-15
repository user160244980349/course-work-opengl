//
// Created by user on 14.10.2017.
//

#ifndef OPENGL_GLOBAL_VARIABLES_HPP
#define OPENGL_GLOBAL_VARIABLES_HPP

#include "glm/mat4x4.hpp"

namespace application {

    class kernel;



    namespace time {

        class timer;
        class interval_timer;

        extern timer&& world_time;
        extern interval_timer&& frame_update;

    }



    namespace objects {

        class abstract_object;
        class drawable;
        class base_object;
        class one_sheet_hyperboloid;
        class bicameral_hyperboloid;

    }



    namespace graphics {

        class shader;
        class abstract_buffer;
        class vao;
        class vbo;
        class ebo;
        class ubo;

        extern glm::mat4 perspective;

    }



    namespace scene {

        extern objects::base_object&& base_object;
        extern objects::one_sheet_hyperboloid&& one_sheet_hyperboloid;
        extern objects::bicameral_hyperboloid&& bicameral_hyperboloid;

    }
}

#endif //OPENGL_GLOBAL_VARIABLES_HPP

//
// Created by user on 14.10.2017.
//

#include "time/interval_timer.hpp"
#include "time/timer.hpp"
#include "objects/base_object.hpp"
#include "glm/mat4x4.hpp"


namespace application {

    class kernel;

    namespace time {

        class timer;
        class interval_timer;

        extern timer world_time;
        extern interval_timer frame_update;

    }

    namespace objects {

        class abstract_object;
        class base_object;

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

        extern objects::base_object base_object;

    }
}


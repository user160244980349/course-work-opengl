//
// Created by user on 14.10.2017.
//

#ifndef OPENGL_GLOBAL_VARIABLES_HPP
#define OPENGL_GLOBAL_VARIABLES_HPP


#include "time/interval_timer.hpp"
#include "time/timer.hpp"
#include "objects/base_object.hpp"

namespace application {

    namespace time {
        extern timer world_time;
        extern interval_timer frame_update;
    }

    namespace objects {

    }

    namespace graphics {

    }

    namespace scene {

        extern objects::base_object base_object;
    }
}


#endif //OPENGL_GLOBAL_VARIABLES_HPP

//
// Created by user on 14.10.2017.
//

#include <time/timer.hpp>
#include <time/interval_timer.hpp>
#include <glm/trigonometric.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <objects/base_object.hpp>
#include "global_variables.hpp"

namespace application {

    class kernel;

    namespace time {

        timer *world_time = new timer;
        interval_timer *frame_update = new interval_timer;

    }

    namespace objects {

    }

    namespace graphics {

        glm::mat4 perspective = glm::perspective(glm::radians(45.0f), 16.0f / 9.0f, 0.1f, 100.0f);

    }

    namespace scene {

        objects::base_object *base_object = new objects::base_object;

    }
}
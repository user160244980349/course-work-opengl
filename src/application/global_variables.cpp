//
// Created by user on 14.10.2017.
//

#include "global_variables.hpp"
#include <time/timer.hpp>
#include <time/interval_timer.hpp>
#include <glm/trigonometric.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <objects/base_object.hpp>
#include <objects/one_sheet_hyperboloid.hpp>
#include <objects/bicameral_hyperboloid.hpp>

namespace application {

    class kernel;



    namespace time {

        timer&& world_time = time::timer();
        interval_timer&& frame_update = time::interval_timer();

    }



    namespace objects {

    }



    namespace graphics {

        glm::mat4 perspective = glm::perspective(glm::radians(50.0f), 16.0f / 9.0f, 0.1f, 100.0f);

    }



    namespace scene {

        objects::base_object&& base_object = objects::base_object();
        objects::one_sheet_hyperboloid&& one_sheet_hyperboloid = objects::one_sheet_hyperboloid();
        objects::bicameral_hyperboloid&& bicameral_hyperboloid = objects::bicameral_hyperboloid();

    }

}
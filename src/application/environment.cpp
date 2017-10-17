//
// Created by user on 16.10.2017.
//

#include "environment.hpp"


application::time::timer&& environment::world_time = application::time::timer();
float environment::sensetivety = 0.1f;
float environment::mouse_x = 0;
float environment::mouse_y = 0;
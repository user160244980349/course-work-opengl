//
// Created by user on 15.10.2017.
//

#include "objects/bicameral_hyperboloid.h"


float application::objects::bicameral_hyperboloid::function_x(float y, float a,
                                                              float z, float c, float b) {

    return sqrtf((-1.0 - (y*y) / (a*a) + (z*z) / (c*c)) * (b*b));
}



float application::objects::bicameral_hyperboloid::function_y(float x, float a,
                                                              float z, float c, float b) {

    return sqrtf((-1.0 - (x*x) / (a*a) + (z*z) / (c*c)) * (b*b));
}



float application::objects::bicameral_hyperboloid::function_z(float x, float a,
                                                              float y, float c, float b) {

    return sqrtf((1.0 + (x*x) / (a*a) + (y*y) / (c*c)) * (b*b));
}
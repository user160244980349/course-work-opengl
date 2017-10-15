//
// Created by user on 15.10.2017.
//

#ifndef OPENGL_ONE_SHEET_HYPERBOLOID_HPP
#define OPENGL_ONE_SHEET_HYPERBOLOID_HPP


#include "abstract_object.hpp"
#include "drawable.hpp"

namespace application::objects {

    class one_sheet_hyperboloid : protected abstract_object, drawable {
    public:
        int prepare() override;
        int draw() override;

    protected:
        float function_x(float y, float a,
                      float z, float c, float b);
        float function_y(float x, float a,
                      float z, float c, float b);
        float function_z(float x, float a,
                      float y, float c, float b);
        int rotate();

    };

}


#endif //OPENGL_ONE_SHEET_HYPERBOLOID_HPP

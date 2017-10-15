//
// Created by user on 15.10.2017.
//

#ifndef OPENGL_BICAMERAL_HYPERBOLOID_HPP
#define OPENGL_BICAMERAL_HYPERBOLOID_HPP


#include "objects/one_sheet_hyperboloid.hpp"

namespace application::objects {

    class bicameral_hyperboloid : public one_sheet_hyperboloid {
    public:

    protected:
        float function_x(float y, float a,
                         float z, float c, float b) override;
        float function_y(float x, float a,
                         float z, float c, float b) override;
        float function_z(float x, float a,
                         float y, float c, float b) override;
        int rotate();

    };

}


#endif //OPENGL_BICAMERAL_HYPERBOLOID_HPP
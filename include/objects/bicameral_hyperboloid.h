//
// Created by user on 15.10.2017.
//

#ifndef OPENGL_BICAMERAL_HYPERBOLOID_H
#define OPENGL_BICAMERAL_HYPERBOLOID_H


#include "objects/one_sheet_hyperboloid.h"

namespace application::objects {

    class bicameral_hyperboloid : public one_sheet_hyperboloid {
    protected:
        float function_x(float y, float a, float z, float c, float b) override;
        float function_y(float x, float a, float z, float c, float b) override;
        float function_z(float x, float a, float y, float c, float b) override;
    };

}


#endif //OPENGL_BICAMERAL_HYPERBOLOID_H

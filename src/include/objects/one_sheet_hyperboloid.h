//
// Created by user on 15.10.2017.
//

#ifndef OPENGL_ONE_SHEET_HYPERBOLOID_H
#define OPENGL_ONE_SHEET_HYPERBOLOID_H


#include "objects/abstract_object.h"
#include "objects/drawable.h"

namespace application::objects {

    class one_sheet_hyperboloid : public abstract_object, drawable {
    public:
        int prepare() override;
        int draw() override;

    protected:
        virtual float function_x(float y, float a,
                      float z, float c, float b);
        virtual float function_y(float x, float a,
                      float z, float c, float b);
        virtual float function_z(float x, float a,
                      float y, float c, float b);
        int rotate();
    };

}


#endif //OPENGL_ONE_SHEET_HYPERBOLOID_H

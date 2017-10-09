//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_ISOSCELES_TRIANGLE_HPP
#define OPENGL_ISOSCELES_TRIANGLE_HPP


#include <triangles.hpp>

namespace application::objects {

    class isosceles_triangle : public triangles {
    protected:

    public:
        int draw() override;
    };

}


#endif //OPENGL_ISOSCELES_TRIANGLE_HPP

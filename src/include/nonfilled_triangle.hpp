//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_NONFILLED_TRIANGLE_HPP
#define OPENGL_NONFILLED_TRIANGLE_HPP


#include <base_object.hpp>


namespace application::objects {

    class nonfilled_triangle : protected base_object {
    protected:

    public:
        int prepare() override;
        int draw() override;
    };

}


#endif //OPENGL_NONFILLED_TRIANGLE_HPP

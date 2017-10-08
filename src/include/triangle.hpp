//
// Created by user on 08.10.2017.
//

#ifndef OPENGL_TRIANGLE_HPP
#define OPENGL_TRIANGLE_HPP


#include "base_object.hpp"

namespace application::objects {

    class triangle : protected base_object {
    protected:

    public:
        int prepare() override;
        int draw() override;
    };

}


#endif //OPENGL_BASE_OBJECT_HPP

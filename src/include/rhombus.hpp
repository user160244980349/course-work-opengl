//
// Created by user on 10.10.2017.
//

#ifndef OPENGL_RHOMBUS_HPP
#define OPENGL_RHOMBUS_HPP


#include "triangles.hpp"

namespace application::objects {

    class rhombus : public triangles {
    protected:

    public:
        int draw() override;
    };

}


#endif //OPENGL_RHOMBUS_HPP

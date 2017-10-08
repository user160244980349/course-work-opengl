//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_RHOMBUS_HPP
#define OPENGL_RHOMBUS_HPP


#include <base_object.hpp>

namespace application::objects {

    class rhombus : protected base_object {
    protected:

    public:
        int prepare() override;
        int draw() override;
    };

}


#endif //OPENGL_RHOMBUS_HPP

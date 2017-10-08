//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_RECTANGLE_HPP
#define OPENGL_RECTANGLE_HPP

#include <base_object.hpp>


namespace application::objects {

    class rectangle : protected base_object {
    protected:

    public:
        int prepare() override;
        int draw() override;
    };

}

#endif //OPENGL_RECTANGLE_HPP

//
// Created by user on 10.10.2017.
//

#ifndef OPENGL_RANDOM_DOTS_HPP
#define OPENGL_RANDOM_DOTS_HPP


#include <base_object.hpp>

namespace application::objects {

    class random_dots : public base_object {
    protected:

    public:
        int prepare() override;
        int draw() override;
    };

}


#endif //OPENGL_RANDOM_DOTS_HPP

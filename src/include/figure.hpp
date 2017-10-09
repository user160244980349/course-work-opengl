//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_FIGURE_HPP
#define OPENGL_FIGURE_HPP


#include "base_object.hpp"

namespace application::objects {

    class figure : protected base_object {
    protected:

    public:
        int prepare() override;
        int draw() override;
    };

}


#endif //OPENGL_FIGURE_HPP

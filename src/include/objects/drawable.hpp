//
// Created by user on 15.10.2017.
//

#ifndef OPENGL_DRAWABLE_HPP
#define OPENGL_DRAWABLE_HPP


#include "abstract_object.hpp"

namespace application::objects {

    class drawable {
    protected:

    public:
        virtual int prepare();
        virtual int draw();
    };

}


#endif //OPENGL_DRAWABLE_HPP

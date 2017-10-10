//
// Created by user on 11.10.2017.
//

#ifndef OPENGL_ABSTRACT_OBJECT_HPP
#define OPENGL_ABSTRACT_OBJECT_HPP


#include <application/base_vao_vbo.hpp>

namespace application::objects {

    class abstract_object {
    protected:

    public:
        virtual int prepare();
        virtual int draw();
    };

}


#endif //OPENGL_ABSTRACT_OBJECT_HPP

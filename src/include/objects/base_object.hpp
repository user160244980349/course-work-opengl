//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_BASE_OBJECT_HPP
#define OPENGL_BASE_OBJECT_HPP


#include "abstract_object.hpp"
#include "drawable.hpp"

namespace application::objects {

    class base_object : public abstract_object, drawable {
    public:
        int prepare() override;
        int draw() override;
        int rotate();

    protected:

    };

}


#endif //OPENGL_BASE_OBJECT_HPP

//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_BASE_OBJECT_H
#define OPENGL_BASE_OBJECT_H


#include "abstract_object.h"
#include "drawable.h"

namespace application::objects {

    class base_object : public abstract_object, drawable {
    public:
        int prepare() override;
        int draw() override;
    };

}


#endif //OPENGL_BASE_OBJECT_HPP

//
// Created by user on 10.10.2017.
//

#ifndef OPENGL_RECTANGLE_HPP
#define OPENGL_RECTANGLE_HPP


#include <triangles.hpp>

namespace application::objects {

    class rectangle : public triangles {
    protected:

    public:
        int draw() override;
    };

}


#endif //OPENGL_RECTANGLE_HPP

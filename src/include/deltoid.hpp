//
// Created by user on 10.10.2017.
//

#ifndef OPENGL_DELTOID_HPP
#define OPENGL_DELTOID_HPP


#include "triangles.hpp"

namespace application::objects {

    class deltoid : public triangles {
    protected:

    public:
        int draw() override;
    };

}


#endif //OPENGL_DELTOID_HPP

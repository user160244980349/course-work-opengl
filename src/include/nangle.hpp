//
// Created by user on 10.10.2017.
//

#ifndef OPENGL_NANGLE_HPP
#define OPENGL_NANGLE_HPP


#include <triangles.hpp>

namespace application::objects {

    class nangle : public triangles {
    protected:

    public:
        int draw() override;
    };

}


#endif //OPENGL_NANGLE_HPP

//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_LINES_HPP
#define OPENGL_LINES_HPP


#include <triangles.hpp>

namespace application::objects {

    class lines : public triangles {
    protected:

    public:
        int draw() override;
    };

}


#endif //OPENGL_LINES_HPP

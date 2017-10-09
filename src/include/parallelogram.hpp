//
// Created by user on 10.10.2017.
//

#ifndef OPENGL_PARALLELOGRAM_HPP
#define OPENGL_PARALLELOGRAM_HPP


#include <triangles.hpp>

namespace application::objects {

    class parallelogram : public triangles {
    protected:

    public:
        int draw() override;
    };

}

#endif //OPENGL_PARALLELOGRAM_HPP

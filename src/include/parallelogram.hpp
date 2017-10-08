//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_PARALLELOGRAM_HPP
#define OPENGL_PARALLELOGRAM_HPP


#include <base_object.hpp>


namespace application::objects {

    class parallelogram : protected base_object {
    protected:

    public:
        int prepare() override;
        int draw() override;
    };

}


#endif //OPENGL_PARALLELOGRAM_HPP

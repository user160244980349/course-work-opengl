//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_TRAPEZE_HPP
#define OPENGL_TRAPEZE_HPP

#include <base_object.hpp>


namespace application::objects {

    class trapeze : protected base_object {
    protected:

    public:
        int prepare() override;
        int draw() override;
    };

}

#endif //OPENGL_TRAPEZE_HPP

//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_DELTOID_HPP
#define OPENGL_DELTOID_HPP


#include <base_object.hpp>

namespace application::objects {

    class deltoid : protected base_object {
    protected:

    public:
        int prepare() override;
        int draw() override;
    };

}


#endif //OPENGL_DELTOID_HPP

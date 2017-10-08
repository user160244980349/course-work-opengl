//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_NANGLE_HPP
#define OPENGL_NANGLE_HPP


#include <base_object.hpp>


namespace application::objects {

    class nangle : protected base_object {
    protected:

    public:
        int prepare() override;
        int draw() override;
    };

}


#endif //OPENGL_NANGLE_HPP

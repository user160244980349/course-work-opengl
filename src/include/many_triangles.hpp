//
// Created by user on 09.10.2017.
//

#ifndef OPENGL_MANY_TRIANGLES_HPP
#define OPENGL_MANY_TRIANGLES_HPP

#include <base_object.hpp>


namespace application::objects {

    class many_triangles : protected base_object {
    protected:

    public:
        int prepare() override;
        int draw() override;
    };

}



#endif //OPENGL_MANY_TRIANGLES_HPP

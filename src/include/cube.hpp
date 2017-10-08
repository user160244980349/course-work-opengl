//
// Created by user on 07.10.2017.
//

#ifndef OPENGL_CUBE_HPP
#define OPENGL_CUBE_HPP

namespace application::objects {

    class cube {
    private:

        struct {
            float xrf = 0;
            float yrf = 0;
            float zrf = 0;
        } rotation;

    public:

        cube();
        int rotate();
        int draw();
    };

}

#endif //OPENGL_CUBE_HPP

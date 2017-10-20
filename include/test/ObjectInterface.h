//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_OBJECTINTERFACE_H
#define OPENGL_OBJECTINTERFACE_H

namespace application::test {

    class ObjectInterface {
    public:
        virtual int draw() = 0;
        virtual int prepare() = 0;
    };

}

#endif //OPENGL_OBJECTINTERFACE_H

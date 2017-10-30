//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_ABSTRACTSCENE_H
#define OPENGL_ABSTRACTSCENE_H

#include <list>

namespace application::interfaces {

    class IScene {
    public:
        virtual int prepare() = 0;
        virtual int draw() = 0;
    };

}

#endif //OPENGL_ABSTRACTSCENE_H

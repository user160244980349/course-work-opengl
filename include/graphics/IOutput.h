//
// Created by user on 24.10.2017.
//

#ifndef OPENGL_IOUTPUT_H
#define OPENGL_IOUTPUT_H

#include <objects/IScene.h>

namespace application::graphics {

    class IOutput {
    public:
        virtual int prepare(objects::IScene* scene) = 0;
        virtual int draw(objects::IScene* scene) = 0;
    };

}

#endif //OPENGL_IOUTPUT_H

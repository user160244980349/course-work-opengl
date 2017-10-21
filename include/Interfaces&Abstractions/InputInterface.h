//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_INPUTINTERFACE_H
#define OPENGL_INPUTINTERFACE_H

namespace application::input {

    class InputInterface {
    public:
        virtual int perform() = 0;
    };

}


#endif //OPENGL_INPUTINTERFACE_H

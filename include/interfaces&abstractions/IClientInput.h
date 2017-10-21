//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_CLIENTINPUTINTERFACE_H
#define OPENGL_CLIENTINPUTINTERFACE_H


#include "ISubject.h"
#include "IInput.h"

namespace application::input {

    class IClientInput : public IInput, public templates::ISubject {

    };

}


#endif //OPENGL_CLIENTINPUTINTERFACE_H

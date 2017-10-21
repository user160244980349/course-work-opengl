//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_CLIENTINPUTINTERFACE_H
#define OPENGL_CLIENTINPUTINTERFACE_H

#include "InputInterface.h"
#include "SubjectInterface.h"

namespace application::input {

    class ClientInputInterface : public InputInterface, public templates::SubjectInterface {

    };

}


#endif //OPENGL_CLIENTINPUTINTERFACE_H

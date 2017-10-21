//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_DYNAMICCAMERAINTERFACE_H
#define OPENGL_DYNAMICCAMERAINTERFACE_H


#include "ICamera.h"
#include "IControlable.h"

namespace application::objects {

    class IDynamicCamera : public ICamera, public input::IControlable {

    };

}


#endif //OPENGL_DYNAMICCAMERAINTERFACE_H

//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_DYNAMICCAMERAINTERFACE_H
#define OPENGL_DYNAMICCAMERAINTERFACE_H


#include "AbstractCamera.h"
#include "ControlableInterface.h"
#include "ObserverInterface.h"

namespace application::objects {

    class DynamicCameraInterface : public AbstractCamera, public input::ControlableInterface {

    };

}


#endif //OPENGL_DYNAMICCAMERAINTERFACE_H

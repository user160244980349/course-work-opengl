//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_CAMERA_H
#define OPENGL_CAMERA_H

#include "AbstractCamera.h"

namespace application::test {

    class Camera : public AbstractCamera {
    public:
        Camera();
        int use(GLuint shaderProgramId) override;
    };

}


#endif //OPENGL_CAMERA_H

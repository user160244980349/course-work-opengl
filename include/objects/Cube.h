//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_CUBE_H
#define OPENGL_CUBE_H

#include "Interfaces&Abstractions/DrawableInterface.h"
#include "Interfaces&Abstractions/AbstractObject.h"

namespace application::objects {

    class Cube : public graphics::DrawableInterface, public objects::AbstractObject {
    public:
        int prepare() override;
        int draw(AbstractCamera* camera) override;
    };

}


#endif //OPENGL_CUBE_H

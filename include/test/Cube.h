//
// Created by user on 21.10.2017.
//

#ifndef OPENGL_CUBE_H
#define OPENGL_CUBE_H

#include "DrawableInterface.h"
#include "AbstractObject.h"

namespace application::test {

    class Cube : public DrawableInterface, public AbstractObject {
    public:
        int prepare() override;
        int draw(AbstractCamera* camera) override;
    };

}


#endif //OPENGL_CUBE_H

//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_ABSTRACTSCENE_H
#define OPENGL_ABSTRACTSCENE_H

#include "ObjectInterface.h"
#include <list>
#include <objects/base_object.h>

namespace application::test {

    class AbstractScene {
    public:
        virtual int prepare() = 0;
        virtual int draw() = 0;
    protected:
//        std::list<ObjectInterface*> _objects{};
        std::list<application::objects::base_object*> _objects{};
    };

}


#endif //OPENGL_ABSTRACTSCENE_H

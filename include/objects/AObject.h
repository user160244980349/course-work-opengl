//
// Created by user on 27.10.2017.
//

#ifndef OPENGL_AOBJECT_H
#define OPENGL_AOBJECT_H

#include <string>
#include <interfaces/IObject.h>

namespace application::objects {
    class AObject : public interfaces::IObject {
    public:
        AObject();
        explicit AObject(std::string name);
        std::string getName() override;
        int getId() override;

    protected:
        static unsigned int _count;
        unsigned int _id;
        std::string _name;
    };
}

#endif //OPENGL_AOBJECT_H

#ifndef OPENGL_AOBJECT_H
#define OPENGL_AOBJECT_H


#include <string>

#include "../interfaces/IObject.h"
#include "../core/Transform.h"

class BaseObject : public IObject {
public:
    Transform transform;

    BaseObject();
    explicit BaseObject(std::string name);
    std::string getName() override;
    unsigned int getId() override;

protected:
    static unsigned int _count;
    unsigned int _id;
    std::string _name;
};


#endif //OPENGL_AOBJECT_H

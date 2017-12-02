//
// Created by user on 27.10.2017.
//

#ifndef OPENGL_AOBJECT_H
#define OPENGL_AOBJECT_H

#include <string>
#include <objects/IObject.h>


class AObject : public IObject {
public:
    AObject();
    explicit AObject(std::string name);
    virtual ~AObject() override;

    std::string getName() override;
    int getId() override;

protected:
    static unsigned int _count;
    unsigned int _id;
    std::string _name;
};


#endif //OPENGL_AOBJECT_H

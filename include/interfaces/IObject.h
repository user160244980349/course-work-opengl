#ifndef OPENGL_ABSTRACTOBJECT_H
#define OPENGL_ABSTRACTOBJECT_H


#include <string>
#include <glm/gtc/matrix_transform.hpp>

class IObject {
public:
    virtual ~IObject() = default;;
    virtual std::string getName() = 0;
    virtual unsigned int getId() = 0;
    virtual void update() = 0;
};


#endif //OPENGL_ABSTRACTOBJECT_H

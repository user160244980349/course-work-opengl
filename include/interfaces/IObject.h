#ifndef OPENGL_ABSTRACTOBJECT_H
#define OPENGL_ABSTRACTOBJECT_H


#include <string>
#include <glm/gtc/matrix_transform.hpp>

class IObject {
public:
    virtual ~IObject() = default;;
    virtual std::string getName() {};
    virtual unsigned int getId() {};
    virtual void update() {};
};


#endif //OPENGL_ABSTRACTOBJECT_H

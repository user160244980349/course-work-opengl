#ifndef OPENGL_ISCENE_H
#define OPENGL_ISCENE_H


#include <string>

class IScene {
public:
    virtual ~IScene() {};
    virtual void prepare() {};
    virtual void render() {};
    virtual void update() {};
    virtual std::string getName() {};
    virtual unsigned int getId() {};
};


#endif //OPENGL_ISCENE_H

#ifndef OPENGL_ISCENE_H
#define OPENGL_ISCENE_H


#include <string>

class IScene {
public:
    virtual ~IScene() = default;
    virtual void prepare() = 0;
    virtual void render() = 0;
    virtual void update() = 0;
    virtual std::string getName() = 0;
    virtual unsigned int getId() = 0;
};


#endif //OPENGL_ISCENE_H

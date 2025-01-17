#ifndef OPENGL_BASESCENE_H
#define OPENGL_BASESCENE_H


#include "../interfaces/IScene.h"
#include "../interfaces/IObject.h"
#include "../interfaces/IDrawable.h"
#include "DynamicCamera.h"

class BaseScene : public IScene {
public:
    BaseScene();
    explicit BaseScene(std::string name);
    std::string getName() override;
    unsigned int getId() override;

protected:
    static unsigned int _count;
    unsigned int _id;
    std::string _name;
    DynamicCamera _camera;
    std::list<IDrawable *> _objects {};
};


#endif //OPENGL_BASESCENE_H

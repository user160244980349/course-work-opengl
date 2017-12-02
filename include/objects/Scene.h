//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_SCENE_H
#define OPENGL_SCENE_H

#include <objects/IScene.h>
#include <objects/IObject.h>
#include <objects/DynamicCamera.h>


class Scene : public IScene {
public:
    explicit Scene();
    ~Scene();
    int draw() override;

protected:
    DynamicCamera _camera;
    std::list<IObject*> _objects{};
};


#endif //OPENGL_SCENE_H

//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_SCENE_H
#define OPENGL_SCENE_H

#include <objects/IObject.h>
#include <objects/DynamicCamera.h>


class Scene {
public:
    Scene();
    ~Scene();
    int draw();

protected:
    DynamicCamera _camera;
    std::list<IObject*> _objects{};
};


#endif //OPENGL_SCENE_H

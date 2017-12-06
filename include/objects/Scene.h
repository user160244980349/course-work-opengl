//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_SCENE_H
#define OPENGL_SCENE_H

#include <interfaces/IObject.h>
#include <objects/DynamicCamera.h>

class Scene {
public:
    Scene();
    ~Scene();
    void draw();

protected:
    DynamicCamera _camera;
    std::list<IObject*> _objects{};
};


#endif //OPENGL_SCENE_H

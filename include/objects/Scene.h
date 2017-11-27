//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_SCENE_H
#define OPENGL_SCENE_H

#include <objects/IScene.h>
#include <graphics/IDrawable.h>
#include <input/IInput.h>


class Scene : public IScene {
public:
    explicit Scene(IInput* input);
    ~Scene();
    int prepare() override;
    int draw() override;

protected:
    IInput* _input;
    ICamera* _camera;
    std::list<IDrawable*> _objects{};
};


#endif //OPENGL_SCENE_H

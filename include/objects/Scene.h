//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_SCENE_H
#define OPENGL_SCENE_H

#include "BaseScene.h"
#include "interfaces/IDrawable.h"
#include <vector>

class Scene : public BaseScene {
public:
    ~Scene();

    void prepare() override;

    void render() override;

    void update() override;

protected:
    Shader _shader;
    std::vector<IDrawable *> _objects{};

};


#endif //OPENGL_SCENE_H

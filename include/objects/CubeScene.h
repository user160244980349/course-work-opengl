//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_SCENE_H
#define OPENGL_SCENE_H

#include "BaseScene.h"

class CubeScene : public BaseScene {
public:
    CubeScene();
    ~CubeScene();
    void render() override;
    void update() override;
};


#endif //OPENGL_SCENE_H
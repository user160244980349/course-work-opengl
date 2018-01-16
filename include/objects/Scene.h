//
// Created by user on 20.10.2017.
//

#ifndef OPENGL_SCENE_H
#define OPENGL_SCENE_H

#include <core/DirectionalLight.h>
#include <core/ShadowMap.h>
#include "BaseScene.h"

class Scene : public BaseScene {
public:
    ~Scene();

    void prepare() override;

    void render() override;

    void update() override;

protected:
    Shader _shader;
    Shader _depthShader;
    Shader _skyBoxShader;
    SkyBox _skyBox;
    DirectionalLight _light;
    ShadowMap _shadowMap;
};


#endif //OPENGL_SCENE_H

//
// Created by user on 11.01.2018.
//

#ifndef OPENGL_MODEL_H
#define OPENGL_MODEL_H


#include <interfaces/ICamera.h>
#include "Mesh.h"

class Model {
public:
    void build(std::vector<Mesh> meshes);

    void prepare(Shader shader);

    void render(Shader shader, ICamera &camera, SkyBox &skyBox);

protected:
    std::vector<Mesh> _meshes;

};


#endif //OPENGL_MODEL_H

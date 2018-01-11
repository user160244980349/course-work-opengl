//
// Created by user on 11.01.2018.
//

#ifndef OPENGL_MODEL_H
#define OPENGL_MODEL_H


#include "Mesh.h"

class Model {
public:
    void setMeshes(std::vector<Mesh> meshes);

    void prepare(ShaderProgram shader);

    void render(ShaderProgram shader);

protected:
    std::vector<Mesh> _meshes;

};


#endif //OPENGL_MODEL_H

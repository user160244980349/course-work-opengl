#ifndef OPENGL_MODEL_H
#define OPENGL_MODEL_H


#include "Mesh.h"
#include "../interfaces/ICamera.h"

class Model {
public:
    void build(std::vector<Mesh> meshes);
    void prepare(Shader shader);
    void render(Shader shader, ICamera &camera);

protected:
    std::vector<Mesh> _meshes;
};


#endif //OPENGL_MODEL_H

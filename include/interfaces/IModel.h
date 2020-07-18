#ifndef OPENGL_IMODEL_H
#define OPENGL_IMODEL_H


#include "../core/Shader.h"
#include "../core/Mesh.h"

class IModel {
public:
    virtual ~IModel() = default;
    virtual void build(std::vector<Mesh> meshes) {};
    virtual void prepare(Shader shader) {};
    virtual void render(Shader shader) {};
};


#endif //OPENGL_IMODEL_H

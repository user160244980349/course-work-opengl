#ifndef OPENGL_IMODEL_H
#define OPENGL_IMODEL_H


#include "../core/Shader.h"
#include "../core/Mesh.h"

class IModel {
public:
    virtual ~IModel() = default;
    virtual void build(std::vector<Mesh> meshes) = 0;
    virtual void prepare(Shader shader) = 0;
    virtual void render(Shader shader) = 0;
};


#endif //OPENGL_IMODEL_H

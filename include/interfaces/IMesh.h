#ifndef OPENGL_IMESH_H
#define OPENGL_IMESH_H


#include "../core/Vertex.h"
#include "../core/Material.h"

class IMesh {
public:
    virtual ~IMesh() = default;
    virtual void build(std::vector<Vertex> vertices, std::vector<unsigned int> indices, Material material) {};
    virtual void prepare(Shader &shader) {};
    virtual void render(Shader &shader) {};
};


#endif //OPENGL_IMESH_H

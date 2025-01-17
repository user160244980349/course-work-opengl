#ifndef OPENGL_MODELLOADER_H
#define OPENGL_MODELLOADER_H


#include <vector>
#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.h"
#include "Model.h"

class ModelLoader {
public:
    static ModelLoader &getInstacne();
    Model load(std::string path);

protected:
    std::vector<Mesh> _meshes;
    std::string _directory;

    ModelLoader() = default;
    void sceneBypass(aiNode *node, const aiScene *scene);
    Mesh buildMesh(aiMesh *mesh, const aiScene *scene);
    std::vector<Texture> loadMaps(aiMaterial *mat);
};


#endif //OPENGL_MODELLOADER_H

//
// Created by user on 07.12.2017.
//

#ifndef OPENGL_IMESH_H
#define OPENGL_IMESH_H


class IMesh {
public:
    virtual ~IMesh() = default;;

    virtual void prepare(ShaderProgram &shader) {};

    virtual void render(ShaderProgram &shader) {};
};


#endif //OPENGL_IMESH_H

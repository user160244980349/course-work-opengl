//
// Created by user on 11.01.2018.
//

#ifndef OPENGL_TEXTURE_H
#define OPENGL_TEXTURE_H

#include <string>

class Texture {
public:
    void load(std::string path, unsigned int type);

    void bind();

protected:
    static unsigned int _id;
    static std::string _path;
};


#endif //OPENGL_TEXTURE_H

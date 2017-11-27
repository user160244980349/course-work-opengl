//
// Created by user on 14.10.2017.
//

#ifndef OPENGL_UBO_H
#define OPENGL_UBO_H

#include <graphics/ABuffer.h>
#include <graphics/UboBindIndexes.h>
#include <string>


class Ubo : public ABuffer {
public:
    ~Ubo();
    int create() override;
    int set(GLvoid *data, GLuint size);
    int update(GLvoid *data, GLuint size);
    int connect(GLuint program, UboBindIndex bindIndex, std::string blockName);
};


#endif //OPENGL_UBO_H

//
// Created by user on 14.10.2017.
//

#ifndef OPENGL_UBO_H
#define OPENGL_UBO_H


#include <graphics/AbstractBuffer.h>
#include <string>

namespace application::graphics {

    class Ubo : public AbstractBuffer {
    public:
        ~Ubo();
        int create() override;
        int set(GLvoid *data, GLuint size);
        int update(GLvoid *data, GLuint size);
        int connect(GLuint program, GLuint bindIndex, std::string blockName);
    };

}


#endif //OPENGL_UBO_H

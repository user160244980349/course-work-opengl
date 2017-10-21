//
// Created by user on 14.10.2017.
//

#ifndef OPENGL_UBO_H
#define OPENGL_UBO_H


#include <graphics/abstract_buffer.h>
#include <string>

namespace application::graphics {

    class ubo : public abstract_buffer {
    public:
        ~ubo();
        int create() override;
        int set(GLvoid *data, GLuint size);
        int update(GLvoid *data, GLuint size);
        int connect(GLuint program, std::string blockName);
    };

}


#endif //OPENGL_UBO_H

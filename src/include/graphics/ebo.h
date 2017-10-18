//
// Created by user on 13.10.2017.
//

#ifndef OPENGL_EBO_H
#define OPENGL_EBO_H


#include <graphics/abstract_buffer.h>

namespace application::graphics {

    class ebo : public abstract_buffer {
    public:
        ~ebo();
        int create() override;
        int set(GLuint *o, GLuint size);

    protected:

    };

}


#endif //OPENGL_EBO_H

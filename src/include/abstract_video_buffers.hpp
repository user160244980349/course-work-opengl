//
// Created by user on 12.10.2017.
//

#ifndef OPENGL_ABSTRACT_VIDEO_BUFFERS_HPP
#define OPENGL_ABSTRACT_VIDEO_BUFFERS_HPP


#include <GL/glew.h>

namespace application::graphics {

    class abstract_video_buffers {
    protected:

    public:
        virtual int delete_buffer_combo(unsigned int n);
        virtual int bind(unsigned int i);
    };

}


#endif //OPENGL_ABSTRACT_VIDEO_BUFFERS_HPP

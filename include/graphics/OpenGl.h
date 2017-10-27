//
// Created by user on 27.10.2017.
//

#ifndef OPENGL_OPENGL_H
#define OPENGL_OPENGL_H

#include <glcorearb.h>

namespace application::graphics {

    class OpenGl {
    public:
        static OpenGl* getInstance();

        PFNGLCLIPCONTROLPROC                    glClipControl;
        PFNGLVIEWPORTINDEXEDFPROC               glViewportIndexedf;
        PFNGLCLEARNAMEDFRAMEBUFFERFVPROC        glClearNamedFramebufferfv;
        PFNGLCREATEBUFFERSPROC                  glCreateBuffers;
        PFNGLNAMEDBUFFERDATAPROC                glNamedBufferData;
        PFNGLCREATEVERTEXARRAYSPROC             glCreateVertexArrays;
        PFNGLENABLEVERTEXARRAYATTRIBPROC        glEnableVertexArrayAttrib;
        PFNGLVERTEXARRAYATTRIBFORMATPROC        glVertexArrayAttribFormat;
        PFNGLVERTEXARRAYVERTEXBUFFERPROC        glVertexArrayVertexBuffer;
        PFNGLBINDVERTEXARRAYPROC                glBindVertexArray;
        PFNGLGENBUFFERSPROC                     glGenBuffers;
        PFNGLDELETEBUFFERSPROC                  glDeleteBuffers;
        PFNGLBINDBUFFERPROC                     glBindBuffer;
        PFNGLBUFFERDATAPROC                     glBufferData;
        PFNGLVERTEXATTRIBPOINTERPROC            glVertexAttribPointer;
        PFNGLENABLEVERTEXATTRIBARRAYPROC        glEnableVertexAttribArray;
        PFNGLENABLEPROC                         glEnable;
        PFNGLCLEARPROC                          glClear;
        PFNGLCREATESHADERPROC                   glCreateShader;
        PFNGLSHADERSOURCEPROC                   glShaderSource;
        PFNGLCOMPILESHADERPROC                  glCompileShader;
        PFNGLGETSHADERIVPROC                    glGetShaderiv;
        PFNGLGETSHADERINFOLOGPROC               glGetShaderInfoLog;
        PFNGLCREATEPROGRAMPROC                  glCreateProgram;
        PFNGLATTACHSHADERPROC                   glAttachShader;
        PFNGLLINKPROGRAMPROC                    glLinkProgram;
        PFNGLGETPROGRAMIVPROC                   glGetProgramiv;
        PFNGLGETPROGRAMINFOLOGPROC              glGetProgramInfoLog;
        PFNGLUSEPROGRAMPROC                     glUseProgram;
        PFNGLGETUNIFORMBLOCKINDEXPROC           glGetUniformBlockIndex;
        PFNGLBINDBUFFERBASEPROC                 glBindBufferBase;
        PFNGLUNIFORMBLOCKBINDINGPROC            glUniformBlockBinding;
        PFNGLMAPBUFFERPROC                      glMapBuffer;
        PFNGLUNMAPBUFFERPROC                    glUnmapBuffer;
        PFNGLDELETEVERTEXARRAYSPROC             glDeleteVertexArrays;
        PFNGLGENVERTEXARRAYSPROC                glGenVertexArrays;
        PFNGLDRAWELEMENTSPROC                   glDrawElements;

    protected:
        static OpenGl* _instance;

        OpenGl();
    };

}


#endif //OPENGL_OPENGL_H

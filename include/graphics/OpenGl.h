//
// Created by user on 27.10.2017.
//

#ifndef OPENGL_OPENGL_H
#define OPENGL_OPENGL_H

#include <GL/glcorearb.h>

namespace application::graphics {

    class OpenGl {
    public:
        static OpenGl* getInstance();

        PFNGLBINDVERTEXARRAYPROC                bindVertexArray;
        PFNGLGENBUFFERSPROC                     genBuffers;
        PFNGLDELETEBUFFERSPROC                  deleteBuffers;
        PFNGLBINDBUFFERPROC                     bindBuffer;
        PFNGLBUFFERDATAPROC                     bufferData;
        PFNGLVERTEXATTRIBPOINTERPROC            vertexAttribPointer;
        PFNGLENABLEVERTEXATTRIBARRAYPROC        enableVertexAttribArray;
        PFNGLENABLEPROC                         enable;
        PFNGLCLEARPROC                          clear;
        PFNGLCREATESHADERPROC                   createShader;
        PFNGLSHADERSOURCEPROC                   shaderSource;
        PFNGLCOMPILESHADERPROC                  compileShader;
        PFNGLGETSHADERIVPROC                    getShaderiv;
        PFNGLGETSHADERINFOLOGPROC               getShaderInfoLog;
        PFNGLCREATEPROGRAMPROC                  createProgram;
        PFNGLATTACHSHADERPROC                   attachShader;
        PFNGLLINKPROGRAMPROC                    linkProgram;
        PFNGLGETPROGRAMIVPROC                   getProgramiv;
        PFNGLGETPROGRAMINFOLOGPROC              getProgramInfoLog;
        PFNGLUSEPROGRAMPROC                     useProgram;
        PFNGLGETUNIFORMBLOCKINDEXPROC           getUniformBlockIndex;
        PFNGLBINDBUFFERBASEPROC                 bindBufferBase;
        PFNGLUNIFORMBLOCKBINDINGPROC            uniformBlockBinding;
        PFNGLMAPBUFFERPROC                      mapBuffer;
        PFNGLUNMAPBUFFERPROC                    unmapBuffer;
        PFNGLDELETEVERTEXARRAYSPROC             deleteVertexArrays;
        PFNGLGENVERTEXARRAYSPROC                genVertexArrays;
        PFNGLDRAWELEMENTSPROC                   drawElements;
        PFNGLFLUSHPROC                          flush;
        PFNGLFINISHPROC                         finish;
        PFNGLCLEARCOLORPROC                     clearColor;

    protected:
        static OpenGl* _instance;

        OpenGl();
    };

}

#endif //OPENGL_OPENGL_H

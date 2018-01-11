//
// Created by user on 28.10.2017.
//

#include <SDL2/SDL_video.h>
#include <iostream>
#include "core/OpenGl.h"

OpenGl::OpenGl() {

    if (SDL_GL_LoadLibrary(nullptr) != 0) {
        std::cerr << "Error: " << SDL_GetError() << '\n';
        exit(7);
    }

    bindVertexArray = (PFNGLBINDVERTEXARRAYPROC) SDL_GL_GetProcAddress("glBindVertexArray");
    genBuffers = (PFNGLGENBUFFERSPROC) SDL_GL_GetProcAddress("glGenBuffers");
    deleteBuffers = (PFNGLDELETEBUFFERSPROC) SDL_GL_GetProcAddress("glDeleteBuffers");
    bindBuffer = (PFNGLBINDBUFFERPROC) SDL_GL_GetProcAddress("glBindBuffer");
    bufferData = (PFNGLBUFFERDATAPROC) SDL_GL_GetProcAddress("glBufferData");
    vertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC) SDL_GL_GetProcAddress("glVertexAttribPointer");
    enableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC) SDL_GL_GetProcAddress("glEnableVertexAttribArray");
    enable = (PFNGLENABLEPROC) SDL_GL_GetProcAddress("glEnable");
    disable = (PFNGLDISABLEPROC) SDL_GL_GetProcAddress("glDisable");
    clear = (PFNGLCLEARPROC) SDL_GL_GetProcAddress("glClear");
    createShader = (PFNGLCREATESHADERPROC) SDL_GL_GetProcAddress("glCreateShader");
    shaderSource = (PFNGLSHADERSOURCEPROC) SDL_GL_GetProcAddress("glShaderSource");
    compileShader = (PFNGLCOMPILESHADERPROC) SDL_GL_GetProcAddress("glCompileShader");
    getShaderiv = (PFNGLGETSHADERIVPROC) SDL_GL_GetProcAddress("glGetShaderiv");
    getShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC) SDL_GL_GetProcAddress("glGetShaderInfoLog");
    createProgram = (PFNGLCREATEPROGRAMPROC) SDL_GL_GetProcAddress("glCreateProgram");
    attachShader = (PFNGLATTACHSHADERPROC) SDL_GL_GetProcAddress("glAttachShader");
    linkProgram = (PFNGLLINKPROGRAMPROC) SDL_GL_GetProcAddress("glLinkProgram");
    getProgramiv = (PFNGLGETPROGRAMIVPROC) SDL_GL_GetProcAddress("glGetProgramiv");
    getProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC) SDL_GL_GetProcAddress("glGetProgramInfoLog");
    useProgram = (PFNGLUSEPROGRAMPROC) SDL_GL_GetProcAddress("glUseProgram");
    getUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC) SDL_GL_GetProcAddress("glGetUniformBlockIndex");
    bindBufferBase = (PFNGLBINDBUFFERBASEPROC) SDL_GL_GetProcAddress("glBindBufferBase");
    uniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC) SDL_GL_GetProcAddress("glUniformBlockBinding");
    mapBuffer = (PFNGLMAPBUFFERPROC) SDL_GL_GetProcAddress("glMapBuffer");
    unmapBuffer = (PFNGLUNMAPBUFFERPROC) SDL_GL_GetProcAddress("glUnmapBuffer");
    deleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC) SDL_GL_GetProcAddress("glDeleteVertexArrays");
    genVertexArrays = (PFNGLGENVERTEXARRAYSPROC) SDL_GL_GetProcAddress("glGenVertexArrays");
    drawElements = (PFNGLDRAWELEMENTSPROC) SDL_GL_GetProcAddress("glDrawElements");
    flush = (PFNGLFLUSHPROC) SDL_GL_GetProcAddress("glFlush");
    finish = (PFNGLFINISHPROC) SDL_GL_GetProcAddress("glFinish");
    clearColor = (PFNGLCLEARCOLORPROC) SDL_GL_GetProcAddress("glClearColor");
    (PFNGLPOLYGONMODEPROC) SDL_GL_GetProcAddress("glPolygonMode");
    bindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC) SDL_GL_GetProcAddress("glBindAttribLocation");
    bindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC) SDL_GL_GetProcAddress("glBindFragDataLocation");
    getUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC) SDL_GL_GetProcAddress("glGetUniformLocation");
    uniform3f = (PFNGLUNIFORM3FPROC) SDL_GL_GetProcAddress("glUniform3f");
    uniform4f = (PFNGLUNIFORM4FPROC) SDL_GL_GetProcAddress("glUniform4f");
    uniform2f = (PFNGLUNIFORM2FPROC) SDL_GL_GetProcAddress("glUniform2f");
    uniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC) SDL_GL_GetProcAddress("glUniformMatrix4fv");
    uniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC) SDL_GL_GetProcAddress("glUniformMatrix3fv");
    uniform1f = (PFNGLUNIFORM1FPROC) SDL_GL_GetProcAddress("glUniform1f");
    uniform1i = (PFNGLUNIFORM1IPROC) SDL_GL_GetProcAddress("glUniform1i");
    uniform1ui = (PFNGLUNIFORM1UIPROC) SDL_GL_GetProcAddress("glUniform1ui");
    getProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIVPROC) SDL_GL_GetProcAddress("glGetProgramInterfaceiv");
    getProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIVPROC) SDL_GL_GetProcAddress("glGetProgramResourceiv");
    getProgramResourceName = (PFNGLGETPROGRAMRESOURCENAMEPROC) SDL_GL_GetProcAddress("glGetProgramResourceName");

    SDL_GL_UnloadLibrary();

}

OpenGl &OpenGl::getInstance() {
    static OpenGl instance;
    return instance;
}


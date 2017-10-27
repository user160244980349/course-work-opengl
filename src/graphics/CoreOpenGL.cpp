//
// Created by user on 27.10.2017.
//


#include <SDL_video.h>
#include <iostream>
#include "graphics/OpenGl.h"

application::graphics::OpenGl* application::graphics::OpenGl::_instance = nullptr;

application::graphics::OpenGl::OpenGl() {

    if (SDL_GL_LoadLibrary(nullptr) != 0) {
        std::cerr << "Error: " << SDL_GetError() << '\n';
        exit(7);
    }

    clipControl = (PFNGLCLIPCONTROLPROC)SDL_GL_GetProcAddress("glClipControl");
    viewportIndexedf = (PFNGLVIEWPORTINDEXEDFPROC)SDL_GL_GetProcAddress("glViewportIndexedf");
    clearNamedFramebufferfv = (PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)SDL_GL_GetProcAddress("glClearNamedFramebufferfv");
    createBuffers = (PFNGLCREATEBUFFERSPROC)SDL_GL_GetProcAddress("glCreateBuffers");
    namedBufferData = (PFNGLNAMEDBUFFERDATAPROC)SDL_GL_GetProcAddress("glNamedBufferData");
    createVertexArrays = (PFNGLCREATEVERTEXARRAYSPROC)SDL_GL_GetProcAddress("glCreateVertexArrays");
    enableVertexArrayAttrib = (PFNGLENABLEVERTEXARRAYATTRIBPROC)SDL_GL_GetProcAddress("glEnableVertexArrayAttrib");
    vertexArrayAttribFormat = (PFNGLVERTEXARRAYATTRIBFORMATPROC)SDL_GL_GetProcAddress("glVertexArrayAttribFormat");
    vertexArrayVertexBuffer = (PFNGLVERTEXARRAYVERTEXBUFFERPROC)SDL_GL_GetProcAddress("glVertexArrayVertexBuffer");
    bindVertexArray = (PFNGLBINDVERTEXARRAYPROC)SDL_GL_GetProcAddress("glBindVertexArray");
    genBuffers = (PFNGLGENBUFFERSPROC)SDL_GL_GetProcAddress("glGenBuffers");
    deleteBuffers = (PFNGLDELETEBUFFERSPROC)SDL_GL_GetProcAddress("glDeleteBuffers");
    bindBuffer = (PFNGLBINDBUFFERPROC)SDL_GL_GetProcAddress("glBindBuffer");
    bufferData = (PFNGLBUFFERDATAPROC)SDL_GL_GetProcAddress("glBufferData");
    vertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)SDL_GL_GetProcAddress("glVertexAttribPointer");
    enableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)SDL_GL_GetProcAddress("glEnableVertexAttribArray");
    enable = (PFNGLENABLEPROC)SDL_GL_GetProcAddress("glEnable");
    clear = (PFNGLCLEARPROC)SDL_GL_GetProcAddress("glClear");
    createShader = (PFNGLCREATESHADERPROC)SDL_GL_GetProcAddress("glCreateShader");
    shaderSource = (PFNGLSHADERSOURCEPROC)SDL_GL_GetProcAddress("glShaderSource");
    compileShader = (PFNGLCOMPILESHADERPROC)SDL_GL_GetProcAddress("glCompileShader");
    getShaderiv = (PFNGLGETSHADERIVPROC)SDL_GL_GetProcAddress("glGetShaderiv");
    getShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)SDL_GL_GetProcAddress("glGetShaderInfoLog");
    createProgram = (PFNGLCREATEPROGRAMPROC)SDL_GL_GetProcAddress("glCreateProgram");
    attachShader = (PFNGLATTACHSHADERPROC)SDL_GL_GetProcAddress("glAttachShader");
    linkProgram = (PFNGLLINKPROGRAMPROC)SDL_GL_GetProcAddress("glLinkProgram");
    getProgramiv = (PFNGLGETPROGRAMIVPROC)SDL_GL_GetProcAddress("glGetProgramiv");
    getProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)SDL_GL_GetProcAddress("glGetProgramInfoLog");
    useProgram = (PFNGLUSEPROGRAMPROC)SDL_GL_GetProcAddress("glUseProgram");
    getUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)SDL_GL_GetProcAddress("glGetUniformBlockIndex");
    bindBufferBase = (PFNGLBINDBUFFERBASEPROC)SDL_GL_GetProcAddress("glBindBufferBase");
    uniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)SDL_GL_GetProcAddress("glUniformBlockBinding");
    mapBuffer = (PFNGLMAPBUFFERPROC)SDL_GL_GetProcAddress("glMapBuffer");
    unmapBuffer = (PFNGLUNMAPBUFFERPROC)SDL_GL_GetProcAddress("glUnmapBuffer");
    deleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)SDL_GL_GetProcAddress("glDeleteVertexArrays");
    genVertexArrays = (PFNGLGENVERTEXARRAYSPROC)SDL_GL_GetProcAddress("glGenVertexArrays");
    drawElements = (PFNGLDRAWELEMENTSPROC)SDL_GL_GetProcAddress("glDrawElements");

    SDL_GL_UnloadLibrary();

}

application::graphics::OpenGl* application::graphics::OpenGl::getInstance() {

    if (_instance == nullptr)
        _instance = new OpenGl;

    return _instance;
}

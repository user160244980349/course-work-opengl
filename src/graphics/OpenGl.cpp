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

    glClipControl = (PFNGLCLIPCONTROLPROC)SDL_GL_GetProcAddress("glClipControl");
    glViewportIndexedf = (PFNGLVIEWPORTINDEXEDFPROC)SDL_GL_GetProcAddress("glViewportIndexedf");
    glClearNamedFramebufferfv = (PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)SDL_GL_GetProcAddress("glClearNamedFramebufferfv");
    glCreateBuffers = (PFNGLCREATEBUFFERSPROC)SDL_GL_GetProcAddress("glCreateBuffers");
    glNamedBufferData = (PFNGLNAMEDBUFFERDATAPROC)SDL_GL_GetProcAddress("glNamedBufferData");
    glCreateVertexArrays = (PFNGLCREATEVERTEXARRAYSPROC)SDL_GL_GetProcAddress("glCreateVertexArrays");
    glEnableVertexArrayAttrib = (PFNGLENABLEVERTEXARRAYATTRIBPROC)SDL_GL_GetProcAddress("glEnableVertexArrayAttrib");
    glVertexArrayAttribFormat = (PFNGLVERTEXARRAYATTRIBFORMATPROC)SDL_GL_GetProcAddress("glVertexArrayAttribFormat");
    glVertexArrayVertexBuffer = (PFNGLVERTEXARRAYVERTEXBUFFERPROC)SDL_GL_GetProcAddress("glVertexArrayVertexBuffer");
    glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)SDL_GL_GetProcAddress("glBindVertexArray");
    glGenBuffers = (PFNGLGENBUFFERSPROC)SDL_GL_GetProcAddress("glGenBuffers");
    glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)SDL_GL_GetProcAddress("glDeleteBuffers");
    glBindBuffer = (PFNGLBINDBUFFERPROC)SDL_GL_GetProcAddress("glBindBuffer");
    glBufferData = (PFNGLBUFFERDATAPROC)SDL_GL_GetProcAddress("glBufferData");
    glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)SDL_GL_GetProcAddress("glVertexAttribPointer");
    glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)SDL_GL_GetProcAddress("glEnableVertexAttribArray");
    glEnable = (PFNGLENABLEPROC)SDL_GL_GetProcAddress("glEnable");
    glClear = (PFNGLCLEARPROC)SDL_GL_GetProcAddress("glClear");
    glCreateShader = (PFNGLCREATESHADERPROC)SDL_GL_GetProcAddress("glCreateShader");
    glShaderSource = (PFNGLSHADERSOURCEPROC)SDL_GL_GetProcAddress("glShaderSource");
    glCompileShader = (PFNGLCOMPILESHADERPROC)SDL_GL_GetProcAddress("glCompileShader");
    glGetShaderiv = (PFNGLGETSHADERIVPROC)SDL_GL_GetProcAddress("glGetShaderiv");
    glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)SDL_GL_GetProcAddress("glGetShaderInfoLog");
    glCreateProgram = (PFNGLCREATEPROGRAMPROC)SDL_GL_GetProcAddress("glCreateProgram");
    glAttachShader = (PFNGLATTACHSHADERPROC)SDL_GL_GetProcAddress("glAttachShader");
    glLinkProgram = (PFNGLLINKPROGRAMPROC)SDL_GL_GetProcAddress("glLinkProgram");
    glGetProgramiv = (PFNGLGETPROGRAMIVPROC)SDL_GL_GetProcAddress("glGetProgramiv");
    glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)SDL_GL_GetProcAddress("glGetProgramInfoLog");
    glUseProgram = (PFNGLUSEPROGRAMPROC)SDL_GL_GetProcAddress("glUseProgram");
    glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)SDL_GL_GetProcAddress("glGetUniformBlockIndex");
    glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)SDL_GL_GetProcAddress("glBindBufferBase");
    glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)SDL_GL_GetProcAddress("glUniformBlockBinding");
    glMapBuffer = (PFNGLMAPBUFFERPROC)SDL_GL_GetProcAddress("glMapBuffer");
    glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)SDL_GL_GetProcAddress("glUnmapBuffer");
    glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)SDL_GL_GetProcAddress("glDeleteVertexArrays");
    glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)SDL_GL_GetProcAddress("glGenVertexArrays");
    glDrawElements = (PFNGLDRAWELEMENTSPROC)SDL_GL_GetProcAddress("glDrawElements");

    SDL_GL_UnloadLibrary();

}

application::graphics::OpenGl& application::graphics::OpenGl::getInstance() {

    if (_instance == nullptr)
        _instance = new OpenGl;

    return *_instance;
}

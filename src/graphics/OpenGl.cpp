//
// Created by user on 27.10.2017.
//


#include <SDL_video.h>
#include <iostream>
#include "graphics/OpenGl.h"

application::graphics::OpenGl::OpenGl() {

    if (SDL_GL_LoadLibrary(nullptr) != 0) {
        std::cerr << "Error: " << SDL_GetError() << '\n';
        exit(7);
    }

//    glClipControl = (PFNGLCLIPCONTROLPROC)SDL_GL_GetProcAddress("glClipControl");

    SDL_GL_UnloadLibrary();

}

application::graphics::OpenGl& application::graphics::OpenGl::getInstance() {

    if (_instance == nullptr) {
        _instance = new OpenGl;
        return *_instance;
    } else
        return *_instance;
}

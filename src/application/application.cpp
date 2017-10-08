//
// Created by user on 07.10.2017.
//

#include "application.hpp"
#include <iostream>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <GL/glew.h>
//#include <SDL_opengl.h>


application::application::application() {

    init();
    flow();
    drop();

}

int application::application::init() {
// инициализация SDL
    if ( SDL_Init(SDL_INIT_EVERYTHING) != 0 ){
        std::cout << "Unable to init SDL, error: " << SDL_GetError() << std::endl;
        exit(1);
    }

//     инициализация TTF
    if ( TTF_Init() != 0 ){
        std::cout << "Unable to init TTF, error: " << TTF_GetError() << std::endl;
        exit(3);
    }

//    инициализация IMG
    if ( IMG_Init(IMG_INIT_PNG) == 0 ){
        std::cout << "Unable to init IMG, error: " << IMG_GetError() << std::endl;
        exit(4);
    }

//     Создаем окно с заголовком расположенным по центру экрана.
   sdl_variables.window = SDL_CreateWindow("Cube", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_parameters.width, window_parameters.height, SDL_WINDOW_OPENGL);

//     если не получилось создать окно, то выходим
    if(sdl_variables.window == NULL){
        std::cout << "Unable to create window, error: " << SDL_GetError() << std::endl;
        exit(5);
    }

//     создаем контекст OpenGL
    SDL_GLContext glcontext = SDL_GL_CreateContext(sdl_variables.window);

//     если не получилось создать контекст, то выходим
    if(glcontext == NULL){
        std::cout << "Unable to create OpenGL context, error: " << SDL_GetError() << std::endl;
        exit(6);
    }

//     Включаем двойной буфер, настраиваем цвета
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 6);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);

//    Инициализация OpenGL
//    PFNGLCLEARCOLORIIEXTPROC glClearColor = (PFNGLCLEARCOLORIIEXTPROC)SDL_GL_GetProcAddress("glClearColor");
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // устанавливаем фоновый цвет на черный
    glClearDepth(1.0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST); // включаем тест глубины
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float) window_parameters.width / (float) window_parameters.height, 0.1f, 100.0f); // настраиваем трехмерную перспективу
    glMatrixMode(GL_MODELVIEW); // переходим в трехмерный режим

    return 0;
}

int application::application::flow() {

    glClear(GL_COLOR_BUFFER_BIT);

    while(state_variables.running){

        SDL_PollEvent(&sdl_variables.event);
        switch(sdl_variables.event.type){
            case SDL_QUIT:
                state_variables.running = false;
                break;

            case SDL_KEYDOWN:
                switch(sdl_variables.event.key.keysym.sym){
                    case SDLK_q:
                        if (sdl_variables.last_key_pressed.type == SDL_KEYDOWN &&
                            sdl_variables.last_key_pressed.key.keysym.sym == SDLK_LCTRL)
                            state_variables.running = false;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
//        запоминаем предыдущее событие
        sdl_variables.last_key_pressed = sdl_variables.event;

//        рисуем
        draw();

//        обновляем экран
        SDL_GL_SwapWindow(sdl_variables.window);
    }

    return 0;
}

int application::application::drop() {

    SDL_Quit();

    return 0;
}

int application::application::draw() {

    objects.c1.draw();
    objects.c1.rotate();

    return 0;
}


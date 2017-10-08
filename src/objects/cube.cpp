//
// Created by user on 07.10.2017.
//

#include <SDL_opengl.h>
#include "cube.hpp"

application::objects::cube::cube() {

    rotation.xrf = 0;
    rotation.yrf = 0;
    rotation.zrf = 0;

}

int application::objects::cube::draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);	// Сдвинуть вглубь экрана

    glRotatef(rotation.xrf, 1.0f, 0.0f, 0.0f);	// Вращение куба по X, Y, Z
    glRotatef(rotation.yrf, 0.0f, 1.0f, 0.0f);	// Вращение куба по X, Y, Z
    glRotatef(rotation.zrf, 0.0f, 0.0f, 1.0f);	// Вращение куба по X, Y, Z

    glBegin(GL_QUADS);		// Рисуем куб

    glColor3f(0.0f, 1.0f, 0.0f);		// Синяя сторона (Верхняя)
    glVertex3f( 1.0f, 1.0f, -1.0f);		// Верхний правый угол квадрата
    glVertex3f(-1.0f, 1.0f, -1.0f);		// Верхний левый
    glVertex3f(-1.0f, 1.0f,  1.0f);		// Нижний левый
    glVertex3f( 1.0f, 1.0f,  1.0f);		// Нижний правый

    glColor3f(1.0f, 0.5f, 0.0f);		// Оранжевая сторона (Нижняя)
    glVertex3f( 1.0f, -1.0f,  1.0f);	// Верхний правый угол квадрата
    glVertex3f(-1.0f, -1.0f,  1.0f);	// Верхний левый
    glVertex3f(-1.0f, -1.0f, -1.0f);	// Нижний левый
    glVertex3f( 1.0f, -1.0f, -1.0f);	// Нижний правый

    glColor3f(1.0f, 0.0f, 0.0f);		// Красная сторона (Передняя)
    glVertex3f( 1.0f,  1.0f, 1.0f);		// Верхний правый угол квадрата
    glVertex3f(-1.0f,  1.0f, 1.0f);		// Верхний левый
    glVertex3f(-1.0f, -1.0f, 1.0f);		// Нижний левый
    glVertex3f( 1.0f, -1.0f, 1.0f);		// Нижний правый

    glColor3f(1.0f,1.0f,0.0f);			// Желтая сторона (Задняя)
    glVertex3f( 1.0f, -1.0f, -1.0f);	// Верхний правый угол квадрата
    glVertex3f(-1.0f, -1.0f, -1.0f);	// Верхний левый
    glVertex3f(-1.0f,  1.0f, -1.0f);	// Нижний левый
    glVertex3f( 1.0f,  1.0f, -1.0f);	// Нижний правый

    glColor3f(0.0f,0.0f,1.0f);			// Синяя сторона (Левая)
    glVertex3f(-1.0f,  1.0f,  1.0f);	// Верхний правый угол квадрата
    glVertex3f(-1.0f,  1.0f, -1.0f);	// Верхний левый
    glVertex3f(-1.0f, -1.0f, -1.0f);	// Нижний левый
    glVertex3f(-1.0f, -1.0f,  1.0f);	// Нижний правый

    glColor3f(1.0f,0.0f,1.0f);			// Фиолетовая сторона (Правая)
    glVertex3f( 1.0f,  1.0f, -1.0f);	// Верхний правый угол квадрата
    glVertex3f( 1.0f,  1.0f,  1.0f);	// Верхний левый
    glVertex3f( 1.0f, -1.0f,  1.0f);	// Нижний левый
    glVertex3f( 1.0f, -1.0f, -1.0f);	// Нижний правый

    glEnd();	// Закончили квадраты
    return 0;
}

int application::objects::cube::rotate() {

    rotation.xrf -= 0.5;
    rotation.yrf -= 0.5;
    rotation.zrf -= 0.5;

    return 0;
}



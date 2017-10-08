//
// Created by user on 08.10.2017.
//

#include "vbo.hpp"

int application::graphics::vbo::create() {

    glGenBuffers( 1, &buffer );

    return 0;
}

application::graphics::vbo::~vbo() {

}

int application::graphics::vbo::set() {

    GLfloat vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };

    glBufferData( GL_ARRAY_BUFFER, sizeof( vertices ), vertices, GL_STATIC_DRAW );
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof( GLfloat ), ( GLvoid * ) 0 );
    glEnableVertexAttribArray( 0 );

    return 0;
}

GLuint application::graphics::vbo::get() {
    return buffer;
}

#ifndef OPENGL_EBO_H
#define OPENGL_EBO_H


#include "BaseBuffer.h"

class Ebo : public BaseBuffer {
public:
    void create() override;
    void remove() override;
    void set(void *indices, unsigned int long long size);
};


#endif //OPENGL_EBO_H

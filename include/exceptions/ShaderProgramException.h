//
// Created by user on 23.12.2017.
//

#ifndef OPENGL_SHADERPROGRAMEXCEPTION_H
#define OPENGL_SHADERPROGRAMEXCEPTION_H


#include "BaseException.h"

class ShaderProgramException : public BaseException {
public:
    explicit ShaderProgramException(std::string msg);
};


#endif //OPENGL_SHADERPROGRAMEXCEPTION_H
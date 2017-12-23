//
// Created by user on 23.12.2017.
//

#include "exceptions/ShaderProgramException.h"

ShaderProgramException::ShaderProgramException(std::string msg) : BaseException("ShaderProgramException:\n" + msg) {

}

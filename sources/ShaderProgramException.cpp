#include "../include/exceptions/ShaderProgramException.h"

ShaderProgramException::ShaderProgramException(std::string msg) : BaseException("ShaderProgramException:\n" + msg) {

}

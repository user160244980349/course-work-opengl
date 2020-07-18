#include <utility>

#include "../include/exceptions/BaseException.h"

const char *BaseException::what() const _GLIBCXX_USE_NOEXCEPT {
    return _msg.c_str();
}

BaseException::BaseException(std::string msg) {
    _msg = std::move(msg);
}

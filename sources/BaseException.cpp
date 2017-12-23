//
// Created by user on 23.12.2017.
//


#include <utility>

#include "exceptions/BaseException.h"

const char *BaseException::what() const _GLIBCXX_USE_NOEXCEPT {
    return _msg.c_str();
}

BaseException::BaseException(std::string msg) {
    _msg = std::move(msg);
}
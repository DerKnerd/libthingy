//
// Created by imanuel on 08.03.22.
//

#include "../../libthingy.h"

const char *thingy::ThingiverseException::what() const noexcept {
    return cause.c_str();
}

thingy::ThingiverseException::ThingiverseException(std::string cause) : cause(std::move(cause)) {}
//
// Created by imanuel on 05.03.22.
//

#include "thingiverseClient.h"

namespace thingy {
    const char *ThingiverseException::what() const noexcept {
        return cause.c_str();
    }

    ThingiverseException::ThingiverseException(std::string cause) : cause(std::move(cause)) {}
}
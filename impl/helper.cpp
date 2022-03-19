//
// Created by imanuel on 06.03.22.
//

#include "../helper.h"

std::string thingy::toLower(std::string string) {
    auto result = std::string("");
    result.resize(string.length());
    std::transform(string.begin(), string.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    return result;
}